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
	DefaultNormalSpeed = this->GetCharacterMovement()->MaxWalkSpeed /1.5;
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultNormalSpeed;
	exhausted = false;
	CanJumpOverload = false;
	CurrentCastElapse = 0.f;
	MyAffinity = CreateDefaultSubobject<UMyElementalAffinity>(TEXT("Affinity"));
	//debug
	MyAffinity->UpdateElements(4, 1); //FELDI
	MyAffinity->UpdateElements(3, 2);
	MyAffinity->UpdateElements(7, 3);
	MyAffinity->UpdateElements(2, 4);
	MyAffinity->UpdateElements(9, 0);
	MyAffinity->RegisterComponent();



	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//Mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> mmesh(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (mmesh.Object) 
	{
		PlayerMesh = GetMesh();
		PlayerMesh->SetSkeletalMesh(mmesh.Object);
		PlayerMesh->AddLocalOffset(FVector(0, 0, -98.0f));
		PlayerMesh->SetRelativeRotation(FRotator(0, -90.0f, 0));
	}

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> MeshAnim(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'"));
	GetMesh()->SetAnimInstanceClass(MeshAnim.Object->GetAnimBlueprintGeneratedClass());

	
	// // set our turn rates for input
	// BaseTurnRate = 45.f;
	// BaseLookUpRate = 45.f;

	// // Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// // Configure character movement
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
	movementcomponent = CreateDefaultSubobject<UProjectileMovementComponent>(" ");
}


// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	//debug
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(MyAffinity->GetAtkDmgMultiplier()));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(MyAffinity->GetAbilityElementalPrefix()));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(MyAffinity->GetCritDmgMultiplier()));
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDele;
	TimerDele.BindUFunction(this, FName("StaminaIncrease"), 1.0f); // multiplier handled in StaminaIncrease
	World->GetTimerManager().SetTimer(RegenTimer, TimerDele, 0.1f, true, 0.f);
}


// Called every frame, DeltaTime is internal frame ticking time.

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

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* MyInputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);
	check(MyInputComponent);
	// Binding inputs to actions
	//we can, for example press WASD to move 
	MyInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    MyInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	//by default we bind mouse to turn camera
	MyInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    MyInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//by default we bind spacebar to execute jump
	MyInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	MyInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);


	MyInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::OnCast);
	MyInputComponent->BindAction("Fire", IE_Released, this, &AMyCharacter::CastAbility);

	//MyInputComponent->BindAction("CastMobilityAbility", IE_Pressed, this, &AMyCharacter::OnCast);
	MyInputComponent->BindAction("CastMobilityAbility", IE_Released, this, &AMyCharacter::CastMobilityAbility);

	MyInputComponent->BindAction("SprintHold", IE_Pressed, this, &AMyCharacter::OnSprint);
	MyInputComponent->BindAction("SprintHold", IE_Released, this, &AMyCharacter::OnSprintFinish);
}

// MoveFoward handles moving forward and backwards
void AMyCharacter::MoveForward(float Value)
{
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


// void OnJump();
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

// void OnJumpFinish();
// void OnSprint();
// void OnSprintFinish();
// virtual void SetIsSprinting(bool IsSprinting);

void AMyCharacter::OnSprint()
{
	if (!exhausted)
	{
		this->GetCharacterMovement()->MaxWalkSpeed = DefaultNormalSpeed*MyAffinity->GetMovSpeedMultiplier() * SprintSpeedModifier;
		UWorld* const World = GetWorld();
		FTimerDelegate TimerDele;
		TimerDele.BindUFunction(this, FName("StaminaIncrease"), -2.0f);
		World->GetTimerManager().SetTimer(SprintTimer, TimerDele, 0.1f, true, 0.f);
	}
}
void AMyCharacter::OnSprintFinish()
{
	UWorld* const World = GetWorld();
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultNormalSpeed*MyAffinity->GetMovSpeedMultiplier();
	World->GetTimerManager().ClearTimer(SprintTimer);
}

// for network later
// void AMyCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
// {
//	 Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//	 DOREPLIFETIME_CONDITION(AMyCharacter, IsJumping, COND_SkipOwner);
// }


// //bool TryJump();
// bool IsSprinting() const;

// bool InAir() const;
// bool CanSprint() const;

// float GetSprintSpeedModifier() const;

// // other properties
// float GetMaxHP() const;
float AMyCharacter::GetMaxHP() const 
{
	return MaxHealth;
}
// float GetHP() const;
float AMyCharacter::GetHP() const
{
	return Health;
}

void AMyCharacter::SetHP(float hp)
{
	Health = hp;
	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Setting dmg!"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(Health));
	}
	if (Health < 0)
	{
		Destroy();
	}
}

void AMyCharacter::TakeDmg(float x, bool canReduce)
{
	if(canReduce)
		SetHP(GetHP() - x/(1.2*MyAffinity->GetDefenseMultiplier()));
	else 
		SetHP(GetHP() - x);
}

void AMyCharacter::TakingForceFieldDamage(bool yeah)
{
	InForceField = yeah;
	UWorld* const World = GetWorld();
	if (InForceField)
	{
		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("TakeDmg"), 0.5f);
		World->GetTimerManager().SetTimer(DamageTimer, TimerDel, 0.1f, true, 0.f);
	}
	else
	{
		World->GetTimerManager().ClearTimer(DamageTimer);
	}
}

// float GetMaxStamina() const;
float AMyCharacter::GetMaxStamina() const
{
	return MaxStamina;
}
// float GetStamina() const;
float AMyCharacter::GetStamina() const
{
	return Stamina;
}

void AMyCharacter::SetStamina(float sta)
{
	if (sta >= MaxStamina) {
		Stamina = MaxStamina-1;
	}
	else
	if (sta <= 0) {
		Stamina = 0;
		exhausted = true;
	}
	else
	// for debug
	if (GEngine && (int) floor(Stamina) % 10 == 0 && Stamina<MaxStamina)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Setting stamina!"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(Stamina));
	} 
	Stamina = sta;
}

void AMyCharacter::StaminaIncrease(float x)
{
	if (this->GetCharacterMovement()->MaxWalkSpeed > DefaultNormalSpeed*MyAffinity->GetMovSpeedMultiplier() 
		&& this->GetCharacterMovement()->Velocity.Size()<50) {return;} //holding sprint while not moving will not decrease stamina, but it blocks regen
	if (Stamina > MaxStamina) { SetStamina(MaxStamina-1.5f); } // needs to be reduced more than 1.f (regen is at 1.f, would have bugs)
	else if (Stamina < 0) { SetStamina(0); exhausted = true; }
	else { SetStamina(GetStamina() + x * MyAffinity->GetStamRegenMultiplier()); }
}

// bool IsAlive() const;
bool AMyCharacter::IsAlive() const
{
	return Health > 0;
}

// // basic attack
// bool TryCast();
//  OnCast();
void AMyCharacter::OnCast()
{
	CurrentCastSuccess = false;
	FTimerDelegate TimerDel;
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		//Will be more logics on MaxCastTime if more ability added
		TimerDel.BindUFunction(this, FName("CastIncrement"), 1.2f/ MyAffinity->GetAtkSpeedMultiplier());
		World->GetTimerManager().SetTimer(CastTimer, TimerDel, 0.01f, true, 0.f);
	}
}

void AMyCharacter::CastIncrement(float RequiredTime)
{
	if (CurrentCastElapse > RequiredTime) 
	{
		UWorld* const World = GetWorld();
		CurrentCastSuccess = true;
		World->GetTimerManager().ClearTimer(CastTimer);
		CurrentCastElapse = 0;
	}
	CurrentCastElapse += 0.01f;
}
// need handle later if we would cast something else rather than basic attack - nvm we only have 5 abilities, just write more functions
void AMyCharacter::CastAbility()
{
	if (!CurrentCastSuccess) 
	{
		CurrentCastElapse = 0;
		return; 
	}
	// try and fire a projectile
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		World->GetTimerManager().ClearTimer(CastTimer);

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
	}
}

void AMyCharacter::CastMobilityAbility()
{
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
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

		//debug
		//I assume that this part is messing with owner passing
		
		//AttachToActor(AbilityCasing, FAttachmentTransformRules(EAttachmentRule::SnapToTarget,true));
		AbilityCasing->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		//AbilityCasing->OwnerAffinity=MyAffinity;
		//DuplicateObject(MyAffinity, AbilityCasing->OwnerAffinity);
		AbilityCasing->Movement->UpdatedComponent = this->RootComponent;
		//auto sMovement = AbilityCasing->Movement;
		//sMovement->UpdatedComponent = RootComponent;
		DisableInput(World->GetFirstPlayerController());	
		//FTimerHandle local;
		FTimerDelegate local2;
		local2.BindUFunction(this, FName("GainController"), AbilityCasing);
		//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
		World->GetTimerManager().SetTimer(CastTimer, local2, 1.0f/ MyAffinity->GetAtkSpeedMultiplier(), false);
		isCharging = true;
	}
}

void AMyCharacter::GainController(AActor* effect)//, UProjectileMovementComponent* movementeffecthandle)
{
	if (!isCharging)
		return;
	UWorld* const World = GetWorld();
	if (World != NULL)
	{

		
		EnableInput(World->GetFirstPlayerController());
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

// bool canCast() const;
// float GetCurrentCastElapse() const;
// float GetCurrentCastMax() const;

//Char Progression
//UMyElementalAffinity* AMyCharacter::GetAffinity() {
//	return MyAffinity;
//}


// Can't access affinity directly from other class? have to do this
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
	MaxHealth = 100 * MyAffinity->GetHPMultiplier();
	Health = MaxHealth;
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultNormalSpeed*MyAffinity->GetMovSpeedMultiplier();
	//others not needed yet, those multipliers communicate with abilities directly
}


//Misc
//Timing