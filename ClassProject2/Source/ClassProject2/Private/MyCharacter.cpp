// Fill out your copyright notice in the Description page of Project Settings.
// JW,JD

#include "ClassProject2.h"
#include "ClassProject2GameMode.h"
#include "GameFramework/InputSettings.h"
#include "public/MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100.f;
	Stamina = 100.f;
	SprintSpeedModifier = 2.2f;
	NormalSpeed = this->GetCharacterMovement()->MaxWalkSpeed;
	exhausted = false;
	CurrentCastElapse = 0.f;

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
	GetCharacterMovement()->JumpZVelocity = 600.f;
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
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();
	FTimerDelegate TimerDele;
	TimerDele.BindUFunction(this, FName("StaminaIncrease"), 1.0f);
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

	if (Stamina > 20) 
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
		this->GetCharacterMovement()->MaxWalkSpeed = NormalSpeed * SprintSpeedModifier;
		UWorld* const World = GetWorld();
		FTimerDelegate TimerDele;
		TimerDele.BindUFunction(this, FName("StaminaIncrease"), -2.0f);
		World->GetTimerManager().SetTimer(SprintTimer, TimerDele, 0.1f, true, 0.f);
	}
}
void AMyCharacter::OnSprintFinish()
{
	UWorld* const World = GetWorld();
	this->GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
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
	return GetClass()->GetDefaultObject<AMyCharacter>()->Health;
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

void AMyCharacter::TakeDmg(float x)
{
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
	return GetClass()->GetDefaultObject<AMyCharacter>()->Stamina;
}
// float GetStamina() const;
float AMyCharacter::GetStamina() const
{
	return Stamina;
}

void AMyCharacter::SetStamina(float sta)
{
	if (sta >= 100) {
		Stamina = 99;
	}
	else
	if (sta <= 0) {
		Stamina = 0;
		exhausted = true;
	}
	else
	// for debug
	if (GEngine && (int) floor(Stamina) % 10 == 0 && Stamina<100)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Setting stamina!"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(Stamina));
	} 
	Stamina = sta;
}

void AMyCharacter::StaminaIncrease(float x)
{
	if (Stamina > 100) { SetStamina(99); }
	else if (Stamina < 0) { SetStamina(0); exhausted = true; }
	else { SetStamina(GetStamina() + x); }
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
		TimerDel.BindUFunction(this, FName("CastIncrement"), 1.2f);
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
// need handle later if we would cast something else rather than basic attack
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
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation() + 150 * FRotationMatrix(SpawnRotation).GetScaledAxis(EAxis::X);

		// spawn the projectile at the muzzle
		FActorSpawnParameters params;
		params.Owner = this;


		World->SpawnActor<AFireball>(SpawnLocation, SpawnRotation, params);
		CurrentCastSuccess = false;
		CurrentCastElapse = 0;
	}
}
// bool isCasting() const;
// bool canCast() const;
// float GetCurrentCastElapse() const;
// float GetCurrentCastMax() const;


//Misc
//Timing