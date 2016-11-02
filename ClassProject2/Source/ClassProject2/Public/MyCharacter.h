// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Fireball.h"
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
	UFUNCTION(Category = "Character")
	virtual bool CanJump();
	UFUNCTION(Category = "Character")
	virtual void Jump();
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

	float SprintSpeedModifier;
	float NormalSpeed;

	bool InForceField;

	//other properties
	float GetMaxHP() const;
	float GetHP() const;
	
	UFUNCTION()
	void SetHP(float hp);

	UFUNCTION()
	void TakeDmg(float x);

	UFUNCTION()
	void TakingForceFieldDamage(bool yeah);

	UFUNCTION()
	float GetMaxStamina() const;

	UFUNCTION()
	float GetStamina() const;

	UFUNCTION()
	void SetStamina(float sta);

	UFUNCTION()
	void StaminaIncrease(float x);

	bool IsAlive() const;

	// basic attack
	bool TryCast();
	bool isCasting() const;
	bool CurrentCastSuccess;
	float GetCurrentCastElapse() const;
	float GetCurrentCastMax() const;
	void OnCast();
	void OnCastFinish();

	UFUNCTION()
	void CastIncrement(float RequiredTime);

	UFUNCTION()
	void CastAbility(); // need to make a interface for abiilities

private:	
	// Maybe takedmg needs more handles later on
	//virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
	float Health;
	float Stamina;
	float CurrentCastMax;
	float CurrentCastElapse;
	bool casting;
	bool exhausted; //unable to sprint at current status

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	FTimerHandle DamageTimer;
	FTimerHandle RegenTimer;
	FTimerHandle SprintTimer;
	FTimerHandle CastTimer;

	
// camera collision
UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
// camera logic - we'll use a follow camera for 3rd person
UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

UPROPERTY(VisibleAnywhere, Category = SkeletalMesh)
	class USkeletalMeshComponent* PlayerMesh;
	
// projectile, maybe needed later
UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AFireball> ProjectileClass;

};
