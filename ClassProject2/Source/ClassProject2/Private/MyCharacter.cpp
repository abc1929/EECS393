// Fill out your copyright notice in the Description page of Project Settings.
// JW,JD

#include "ClassProject2.h"
#include "ClassProject2GameMode.h"
#include "GameFramework/InputSettings.h"
#include "public/MyCharacter.h"
#include "public/AbilityList.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxHealth = 100.f;
	Health = MaxHealth;
	MaxStamina = 100.f;
	Stamina = MaxStamina;
	SprintSpeedModifier = 1.8f;
	AttackDmgDebuffMultiplier = 1.0f;
	DefenseDebuffMultiplier = 1.0f;
	AttackSpeedDebuffMultiplier = 1.0f;
	isStunned = false;
	isCharging = false;

	DefaultNormalSpeed = this->GetCharacterMovement()->MaxWalkSpeed /1.5; // default normal speed is passive speed set semistatically, not a current walkspeed reflection
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultNormalSpeed;
	CurrentNormalSpeed = DefaultNormalSpeed;
	exhausted = false;
	CanJumpOverload = false;
	BasicAttackCDFinished = true; MobilityAbilityCDFinished = true; OffensiveAbilityCDFinished = true;
	CurrentCastElapse = 0.f;
	MyAffinity = CreateDefaultSubobject<UMyElementalAffinity>(TEXT("Affinity")); // default to all 0

	//debug
	//MyAffinity->UpdateElements(5, 0); //Fire
	//MyAffinity->UpdateElements(4, 1); //Earth
	//MyAffinity->UpdateElements(8, 2); //Lightning
	//MyAffinity->UpdateElements(7, 3); //Darkness
	//MyAffinity->UpdateElements(2, 4); //Ice




	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//Getting character mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> mmesh(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (mmesh.Object) 
	{
		PlayerMesh = GetMesh();
		PlayerMesh->SetSkeletalMesh(mmesh.Object);
		PlayerMesh->AddLocalOffset(FVector(0, 0, -98.0f));
		PlayerMesh->SetRelativeRotation(FRotator(0, -90.0f, 0));
	}


	

	// this part doesnt work in packaged game. Maybe have to wrap the character in a Blueprint class at the end.

	//static ConstructorHelpers::FObjectFinder<UAnimBlueprint> MeshAnim(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'"));
	//if (MeshAnim.Object) 
	//{
	//	SampleBP = MeshAnim.Object;
	//	GetMesh()->SetAnimInstanceClass(SampleBP->GetAnimBlueprintGeneratedClass());
	//}

	
	// set our turn rates for input
	// BaseTurnRate = 45.f;
	// BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 400.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (camera collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 350.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	FollowCamera->SetFieldOfView(110);
	FollowCamera->AddLocalOffset(FVector(0,0,110));

	//initializing movement effect
	//movementcomponent = CreateDefaultSubobject<UProjectileMovementComponent>(" ");

	InGameMenuOn = false;
	CharacterSheetOn = false;
	ScoreSheetOn = false;
	GameInputDisabled = false;
}


// Called when the game starts or when spawned, added to world state
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDele;
	TimerDele.BindUFunction(this, FName("StaminaIncrease"), 1.0f); // multiplier handled in StaminaIncrease
	World->GetTimerManager().SetTimer(RegenTimer, TimerDele, 0.1f, true, 0.f);
}


// Called every frame, DeltaTime is internal frame ticking time.
// Good for quick shallow branching checks, avoiding heavy computation here
void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (exhausted&&Stamina > 20)
		exhausted = false;
	if (Stamina < 0.2)
	{
		exhausted = true;
		StopJumping();
		OnSprintFinish();
	}


}

// Called to bind functionality to input, actual input maps determined by .ini file generated by engine, can be changed manually as well
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* MyInputComponent)
{
	Super::SetupPlayerInputComponent(CreatePlayerInputComponent());
	check(MyInputComponent);
	// Binding inputs to actions
	// axes binding corresponds to set of inputs ()
	MyInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    MyInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	
	MyInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    MyInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	MyInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	MyInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);


	MyInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::OnCast);
	MyInputComponent->BindAction("Fire", IE_Released, this, &AMyCharacter::CastAbility);

	//MyInputComponent->BindAction("CastMobilityAbility", IE_Pressed, this, &AMyCharacter::OnCast);
	MyInputComponent->BindAction("CastMobilityAbility", IE_Released, this, &AMyCharacter::CastMobilityAbility);
	MyInputComponent->BindAction("CastOffensiveAbility", IE_Released, this, &AMyCharacter::CastOffensiveAbility);

	MyInputComponent->BindAction("SprintHold", IE_Pressed, this, &AMyCharacter::OnSprint);
	MyInputComponent->BindAction("SprintHold", IE_Released, this, &AMyCharacter::OnSprintFinish);

	MyInputComponent->BindAction("PauseMenu", IE_Released, this, &AMyCharacter::PauseMenu);
	MyInputComponent->BindAction("CharacterSheet", IE_Released, this, &AMyCharacter::CharSheet);
	MyInputComponent->BindAction("ScoreSheet", IE_Released, this, &AMyCharacter::ScoreSheet);
}

// camera control, use mouse/console controller to turn camera by default 
void AMyCharacter::AddControllerPitchInput(float Val)
{
	if (GameInputDisabled)
		return;
	if (Val != 0.f && Controller && Controller->IsLocalPlayerController())
	{
		APlayerController* const PC = CastChecked<APlayerController>(Controller);
		PC->AddPitchInput(Val);
	}
}

void AMyCharacter::AddControllerYawInput(float Val)
{
	if (GameInputDisabled)
		return;
	if (Val != 0.f && Controller && Controller->IsLocalPlayerController())
	{
		APlayerController* const PC = CastChecked<APlayerController>(Controller);
		PC->AddYawInput(Val);
	}
}


// MoveFoward handles moving forward and backwards
void AMyCharacter::MoveForward(float Value)
{
	if (isCharging)
		return;
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMyCharacter::MoveRight(float Value)
{
	if (isCharging)
		return;
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}


bool AMyCharacter::CanJump()
{
	// a bug where canjump locked to false?
	// this method is not used, avoided

	if (Stamina > 20 && !CanJumpOverload) 
	{
		return true;
	}
	else
		return false;
}


void AMyCharacter::Jump()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Stamina!"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(Stamina));
	if (exhausted || Stamina<20)
		return;
	Super::Jump();
	if (!GetCharacterMovement()->IsFalling()) {
		StaminaIncrease(-20);
	}
}

// sprinting stamina cost
void AMyCharacter::OnSprint()
{
	if (!exhausted)
	{
		this->GetCharacterMovement()->MaxWalkSpeed = 
		CurrentNormalSpeed*MyAffinity->GetMovSpeedMultiplier() * SprintSpeedModifier;
		UWorld* const World = GetWorld();
		FTimerDelegate TimerDele;
		TimerDele.BindUFunction(this, FName("StaminaIncrease"), -2.0f);
		World->GetTimerManager().SetTimer(SprintTimer, TimerDele, 0.1f, true, 0.f);
	}
}
void AMyCharacter::OnSprintFinish()
{
	UWorld* const World = GetWorld();
	this->GetCharacterMovement()->MaxWalkSpeed = 
	CurrentNormalSpeed*MyAffinity->GetMovSpeedMultiplier();
	World->GetTimerManager().ClearTimer(SprintTimer);
}

// Not used, replication of character jumping for networking
// void AMyCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
// {
//	 Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//	 DOREPLIFETIME_CONDITION(AMyCharacter, IsJumping, COND_SkipOwner);
// }



// // other properties

void AMyCharacter::SetHP(float hp)
{
	if (GEngine && (Health-hp)<1) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(Health));
	}
	Health = hp;
	if (Health < 0)
	{
		Destroy();
	}
}

void AMyCharacter::TakeDmg(float x, bool canReduce)
{
	if(canReduce)
		SetHP(GetHP() - x/(DefenseDebuffMultiplier * MyAffinity->GetDefenseMultiplier()) );
	else 
		SetHP(GetHP() - x);
}

// Constant damage taken by character outside of safezone
void AMyCharacter::TakingForceFieldDamage(bool yeah)
{
	InForceField = yeah;
	UWorld* const World = GetWorld();
	if (InForceField)
	{
		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("TakeDmg"), 0.6f, false);
		World->GetTimerManager().SetTimer(DamageTimer, TimerDel, 0.1f, true, 0.f);
	}
	else
	{
		World->GetTimerManager().ClearTimer(DamageTimer);
	}
}


float AMyCharacter::GetMaxStamina() const
{
	return MaxStamina;
}

float AMyCharacter::GetStamina() const
{
	return Stamina;
}

float AMyCharacter::GetMaxHP() const
{
	return MaxHealth;
}

float AMyCharacter::GetHP() const
{
	return Health;
}

float AMyCharacter::GetCastProgress() const
{
	return CurrentCastElapse > CurrentCastMax? 1.0f : CurrentCastElapse / CurrentCastMax;
}

void AMyCharacter::SetStamina(float sta)
{
	if (sta >= MaxStamina) {
		Stamina = MaxStamina;
	}
	else
	if (sta <= 0) {
		Stamina = 0;
		exhausted = true;
	}
	else
	Stamina = sta;
}

void AMyCharacter::StaminaIncrease(float x)
{
	if (x < 0) // for stamina consumption
	{
		SetStamina(GetStamina() + x);
		return;
	}

	// for stamina regens
	if (this->GetCharacterMovement()->MaxWalkSpeed > CurrentNormalSpeed*MyAffinity->GetMovSpeedMultiplier()
		&& this->GetCharacterMovement()->Velocity.Size()<50) {return;} //holding sprint while not moving will not decrease stamina, but it blocks regen
	if (Stamina > MaxStamina) { SetStamina(MaxStamina-1.2f); } // needs to be reduced more than 1.f (regen is at 1.f, would have bugs)
	else if (Stamina < 0) { SetStamina(0); exhausted = true; }
	else { SetStamina(GetStamina() + x * MyAffinity->GetStamRegenMultiplier()); }
}

bool AMyCharacter::IsAlive() const
{
	return Health > 0;
}

// cooldown
float AMyCharacter::GetCD(int order) const
{
	UWorld* const World = GetWorld();
	switch (order)
	{
		case 1: return World->GetTimerManager().GetTimerRemaining(BasicAttackCD);
		case 2: return World->GetTimerManager().GetTimerRemaining(OffensiveAbilityCD);
		case 3: //defensive ability, not yet implemented
		case 4: return World->GetTimerManager().GetTimerRemaining(MobilityAbilityCD);
		case 5: //utility ability, not yet implemented
		default:
			break;
	}
	
	return 0.f;
}


// handling basic attack input pressed down
void AMyCharacter::OnCast()
{
	CurrentCastElapse = 0;
	if (!BasicAttackCDFinished || GetStamina() < 20) { return; }
	CurrentCastSuccess = false;
	FTimerDelegate TimerDel;
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		//Will be more logics on MaxCastTime if more ability added
		CurrentCastMax = AttackSpeedDebuffMultiplier * 1.2f / MyAffinity->GetAtkSpeedMultiplier();
		TimerDel.BindUFunction(this, FName("CastIncrement"), CurrentCastMax);
		
		World->GetTimerManager().SetTimer(CastTimer, TimerDel, 0.01f, true, 0.f);
	}
}

// this counts current casting time spend trying to cast an ability, maybe it's faster to directly access timer?
void AMyCharacter::CastIncrement(float RequiredTime)
{
	if (CurrentCastElapse > RequiredTime) 
	{
		UWorld* const World = GetWorld();
		CurrentCastSuccess = true;
		World->GetTimerManager().ClearTimer(CastTimer);
	}
	CurrentCastElapse += 0.01f;
}
// this only casts basic attack despite the name
// handling basic attack button released
void AMyCharacter::CastAbility()
{
	UWorld* const World = GetWorld();
	if (World != NULL)
		World->GetTimerManager().ClearTimer(CastTimer);
	CurrentCastElapse = 0;
	if (!CurrentCastSuccess)
	{
		return; 
		// exit function call
	}
	if (!BasicAttackCDFinished) { return; }


	// try and fire a projectile
	if (World != NULL)
	{
		World->GetTimerManager().ClearTimer(CastTimer);
		World->GetTimerManager().SetTimer(BasicAttackCD, this, &AMyCharacter::BasicAttackCDRefresh, 3.f, false);
		//consume stamina
		StaminaIncrease(-20);
		const FRotator SpawnRotation = GetControlRotation();
		const FVector SpawnLocation = GetActorLocation() + 150 * FRotationMatrix(SpawnRotation).GetScaledAxis(EAxis::X);

		FTransform SpawnTransform(SpawnRotation, SpawnLocation);
		auto Fireballspawn = Cast<AFireball>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AFireball::StaticClass(), SpawnTransform));
		if (Fireballspawn != nullptr)
		{
			Fireballspawn->CustomOwner = this;
			//AbilityCasing->OwnerAffinity->UpdateAll(MyAffinity->GetElements()); //not working, maybe just directly access this's affinity

			UGameplayStatics::FinishSpawningActor(Fireballspawn, SpawnTransform);
		}
		CurrentCastSuccess = false;
		CurrentCastElapse = 0;
		BasicAttackCDFinished = false;
	}
}

void AMyCharacter::CastOffensiveAbility() 
{
	if (!OffensiveAbilityCDFinished || GetStamina() < 40)
	{
		return;
		// exit function call
	}

	UWorld* const World = GetWorld();
	if (World != NULL)
	{

		World->GetTimerManager().SetTimer(OffensiveAbilityCD, this, &AMyCharacter::OffensiveAbilityCDRefresh, 12.f, false);

		StaminaIncrease(-40);
		FRotator SpawnRotation = GetControlRotation();
		FActorSpawnParameters params2;
		params2.Owner = this;
		SpawnRotation.Pitch = 90;

		const FVector SpawnLocation = GetActorLocation() + 150 * FRotationMatrix(SpawnRotation).GetScaledAxis(EAxis::X);
		FTransform SpawnTransform(SpawnRotation, SpawnLocation);
		auto AbilityCasing = Cast<AOffensiveAbility_WaveBase>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AOffensiveAbility_WaveBase::StaticClass(), SpawnTransform));
		if (AbilityCasing != nullptr)
		{
			AbilityCasing->CustomOwner = this;
			if (MyAffinity->GetAbilityElementalPrefix() == 0){
				AbilityCasing->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
				AbilityCasing->AddActorLocalOffset(FVector(300, 0, 0.0f));
			} else {
				AbilityCasing->AddActorLocalOffset(FVector(300, 0, -200.0f));
			}
			AbilityCasing->AddActorLocalRotation(FRotator(90, 0, 0));
		
			//AbilityCasing->AddActorLocalOffset(FVector(0, 0, -300.0f));	


			UGameplayStatics::FinishSpawningActor(AbilityCasing, SpawnTransform);

		}
		AbilityCasing->Particle->SetVisibility(true);
		OffensiveAbilityCDFinished = false;



	}
}

void AMyCharacter::CastMobilityAbility()
{

	if (!MobilityAbilityCDFinished ||  GetStamina() < 20)
	{
		return;
		// exit function call
	}

	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		World->GetTimerManager().SetTimer(MobilityAbilityCD, this, &AMyCharacter::MobilityAbilityCDRefresh, 8.f, false);

		StaminaIncrease(-20);
		FRotator SpawnRotation = GetControlRotation();
		const FVector SpawnLocation = GetActorLocation();
		FActorSpawnParameters params2;
		params2.Owner = this;
		params2.Instigator = this;
		//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		SpawnRotation.Pitch = 0;
		//AMobilityAbility_RushBase* AbilityCasing = World->SpawnActor<AMobilityAbility_RushBase>(SpawnLocation, SpawnRotation, params2); //hardcoded for now

		FTransform SpawnTransform(SpawnRotation,SpawnLocation);
		auto AbilityCasing = Cast<AMobilityAbility_RushBase>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AMobilityAbility_RushBase::StaticClass(), SpawnTransform));
		if (AbilityCasing != nullptr)
		{
			AbilityCasing->CustomOwner = this;
			//AbilityCasing->OwnerAffinity->UpdateAll(MyAffinity->GetElements()); //not working, maybe just directly access this's affinity


			UGameplayStatics::FinishSpawningActor(AbilityCasing, SpawnTransform);

		}
		MobilityAbilityCDFinished = false;

		//debug
		//I assume that this part is messing with owner passing
		AbilityCasing->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		//AttachToActor(AbilityCasing, FAttachmentTransformRules(EAttachmentRule::SnapToTarget,true));
		//AbilityCasing->OwnerAffinity=MyAffinity;
		//DuplicateObject(MyAffinity, AbilityCasing->OwnerAffinity);


		AbilityCasing->Movement->UpdatedComponent = this->GetRootComponent();
		//auto sMovement = AbilityCasing->Movement;
		//sMovement->UpdatedComponent = RootComponent;
		//DisableInput(World->GetFirstPlayerController());	

		GameInputDisabled = true;

		FTimerDelegate local2;
		local2.BindUFunction(this, FName("GainController"), AbilityCasing);
		//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
		World->GetTimerManager().SetTimer(CastTimer, local2, AttackSpeedDebuffMultiplier * 1.0f/ MyAffinity->GetAtkSpeedMultiplier(), false);
		isCharging = true;
		
	}
}

// UI actions/ abilities could have the ability to lock player input during its effect, this function regains control appropriately
void AMyCharacter::GainController(AActor* effect)//, UProjectileMovementComponent* movementeffecthandle)
{
	if (!isCharging)
		return;
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		GameInputDisabled = false;
		if(ClickedUIButtons(1) || ClickedUIButtons(2) || ClickedUIButtons(3))
			GameInputDisabled = true;
		//EnableInput(World->GetFirstPlayerController());
		
		
		//if (movementeffecthandle->IsRooted()) {
			//movementeffecthandle->RemoveFromRoot();
		//}'
		if (Cast<AMobilityAbility_RushBase>(effect))
			if (effect->IsRooted())
				effect->RemoveFromRoot();
			(Cast<AMobilityAbility_RushBase>(effect))->Deactivate();
		//(Cast<AMobilityAbility_RushBase>(effect))->Movement->DestroyComponent();
		//(Cast<AMobilityAbility_RushBase>(effect))->Collision
		//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	}
	isCharging = false;
}


//Char Progression
UMyElementalAffinity* AMyCharacter::GetAffinity() {
	return MyAffinity;
}


float AMyCharacter::GetAtkSpeedMultiplier() { return MyAffinity->GetAtkSpeedMultiplier(); }
float AMyCharacter::GetAtkDmgMultiplier() { return MyAffinity->GetAtkDmgMultiplier(); }
float AMyCharacter::GetMovSpeedMultiplier() { return MyAffinity->GetMovSpeedMultiplier(); }
float AMyCharacter::GetCritChanceMultiplier() { return MyAffinity->GetCritChanceMultiplier(); }
float AMyCharacter::GetCritDmgMultiplier() { return MyAffinity->GetCritDmgMultiplier(); }
float AMyCharacter::GetHPMultiplier() { return MyAffinity->GetHPMultiplier(); }
float AMyCharacter::GetMomentumResistanceMultiplier() { return MyAffinity->GetMomentumResistanceMultiplier(); }
float AMyCharacter::GetStamRegenMultiplier() { return MyAffinity->GetStamRegenMultiplier(); }
float AMyCharacter::GetDefenseMultiplier() { return MyAffinity->GetDefenseMultiplier(); }

// This should get called after allocating points
void AMyCharacter::UpdateStats()
{
	//this should only used in between rounds for character progression
	MaxHealth = 100 * MyAffinity->GetHPMultiplier();
	Health = MaxHealth;
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultNormalSpeed*MyAffinity->GetMovSpeedMultiplier();
	//others not needed yet, those multipliers communicate with abilities directly
}


//Misc
//Timing

//Cooldowns
void AMyCharacter::BasicAttackCDRefresh() { BasicAttackCDFinished = true; UWorld* const World = GetWorld(); 
if (World != NULL)
	World->GetTimerManager().ClearTimer(BasicAttackCD);
}
void AMyCharacter::MobilityAbilityCDRefresh() { MobilityAbilityCDFinished = true; UWorld* const World = GetWorld();
if (World != NULL)
	World->GetTimerManager().ClearTimer(MobilityAbilityCD);
}

void AMyCharacter::OffensiveAbilityCDRefresh() { OffensiveAbilityCDFinished = true; UWorld* const World = GetWorld();
	if (World != NULL)
		World->GetTimerManager().ClearTimer(OffensiveAbilityCD);
}




// Debuffs
void AMyCharacter::SetMovementSpeedDebuffMultiplier(float MovespeedDebuffMultiplier)
{
	CurrentNormalSpeed = DefaultNormalSpeed * MovespeedDebuffMultiplier;
	this->GetCharacterMovement()->MaxWalkSpeed = CurrentNormalSpeed;
}

void AMyCharacter::SetAttackSpeedDebuffMultiplier(float _AttackSpeedDebuffMultiplier)
{
	this->AttackSpeedDebuffMultiplier=_AttackSpeedDebuffMultiplier;
}

void AMyCharacter::SetAttackDmgDebuffMultiplier(float _AttackDmgDebuffMultiplier)
{
	this->AttackDmgDebuffMultiplier= _AttackDmgDebuffMultiplier;
}

void AMyCharacter::SetDefenseDebuffMultiplier(float _DefenseDebuffMultiplier)
{
	this->DefenseDebuffMultiplier=_DefenseDebuffMultiplier;	
}


void AMyCharacter::SetStun(float duration)
{
	// if already stunned just break
	this->IsStunned=true;
	// not implemented
}



void AMyCharacter::PauseMenu()
{
	InGameMenuOn = !InGameMenuOn ? true : false;
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();
	MyController->bShowMouseCursor = InGameMenuOn ? true : false;
	MyController->bEnableClickEvents = InGameMenuOn ? true : false;
	MyController->bEnableMouseOverEvents = InGameMenuOn ? true : false;

	GameInputDisabled = isCharging ? true : (!GameInputDisabled ? true : false);
}

// not implemented
void AMyCharacter::CharSheet()
{
	CharacterSheetOn = !CharacterSheetOn ? true : false;
}

void AMyCharacter::ScoreSheet()
{
	ScoreSheetOn = !ScoreSheetOn ? true : false;
}


bool AMyCharacter::ClickedUIButtons(int x) const
{
	switch (x)
	{
		case 1: 
			return InGameMenuOn;   break;
		case 2: 
			return CharacterSheetOn; break;
		case 3: 
			return ScoreSheetOn;  break;
		default: return false; break;
	}
}
