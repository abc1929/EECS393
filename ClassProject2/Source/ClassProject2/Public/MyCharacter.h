// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
//class CLASSPROJECT2_API AMyCharacter : public ACharacter
class AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input

	// called when character is being removed from a level

	// not implemented yet, commented for compiler complaint
	// virtual void EndPlay
	// (  
	// 	const EEndPlayReason::Type EndPlayReason
	// ) override;

	// movements
	void MoveForward(float Value);
	void MoveRight(float Value);

	// movements logics, movement properties
	void OnJump();
	void OnJumpFinish();
	void OnSprint();
	void OnSprintFinish();
	// not implemented yet, commented for compiler complaint
	//virtual void SetIsSprinting(bool IsSprinting);

	
	//UPROPERTY(Transient, Replicated)  
	//Some of the variables are network processed, not implemented yet
	bool IsJumping;

	//bool TryJump();
	bool IsSprinting() const;
	
	bool InAir() const;
	bool CanSprint() const;

	float GetSprintSpeedModifier() const;

	//other properties
	float GetMaxHP() const;
	float GetHP() const;
	float GetMaxStamina() const;
	float GetStamina() const;
	bool IsAlive() const;

	// basic attack
	bool TryCast();
	bool OnCast();
	bool isCasting() const;
	bool canCast() const;
	float GetCurrentCastElapse() const;
	float GetCurrentCastMax() const;

private:	
	// not implemented yet, commented for compiler complaint
	//virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
	float Health;
	float Stamina;
	float CurrentCastMax;
	float CurrentCastElapse;
	bool casting;
	bool exhausted; //unable to sprint at current status

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	

	
// camera configurations - location etc. via USpringArmComponent
UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
// camera logic - we'll use a follow camera for 3rd person
UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;



};
