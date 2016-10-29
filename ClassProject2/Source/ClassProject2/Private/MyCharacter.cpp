// Fill out your copyright notice in the Description page of Project Settings.
// JW,JD

#include "ClassProject2.h"
#include "MyCharacter.h"
#include "ClassProject2GameMode.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;
	Stamina = 100;

	// GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// // set our turn rates for input
	// BaseTurnRate = 45.f;
	// BaseLookUpRate = 45.f;

	// // Don't rotate when the controller rotates. Let that just affect the camera.
	// bUseControllerRotationPitch = false;
	// bUseControllerRotationYaw = false;
	// bUseControllerRotationRoll = false;

	// // Configure character movement
	// GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	// GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	// GetCharacterMovement()->JumpZVelocity = 600.f;
	// GetCharacterMovement()->AirControl = 0.2f;

	// // Create a camera boom (pulls in towards the player if there is a collision)
	// CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// CameraBoom->SetupAttachment(RootComponent);
	// CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	// CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// // Create a follow camera
	// FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	// FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame, DeltaTime is internal frame ticking time.

void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);
	check(InputComponent);
	// Binding inputs to actions
	//we can, for example press WASD to move 
	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	//by default we bind mouse to turn camera
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//by default we bind spacebar to execute jump
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);
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


// not yet implemented
// void OnJump();
// void OnJumpFinish();
// void OnSprint();
// void OnSprintFinish();
// virtual void SetIsSprinting(bool IsSprinting);

// UPROPERTY(Transient, Replicated)
// bool IsJumping;

// //bool TryJump();
// bool IsSprinting() const;

// bool InAir() const;
// bool CanSprint() const;

// float GetSprintSpeedModifier() const;

// // other properties
// float GetMaxHP() const;
// float GetHP() const;
// float GetMaxStamina() const;
// float GetStamina() const;
// bool IsAlive() const;

// // basic attack
// bool TryCast();
// bool OnCast();
// bool isCasting() const;
// bool canCast() const;
// float GetCurrentCastElapse() const;
// float GetCurrentCastMax() const;