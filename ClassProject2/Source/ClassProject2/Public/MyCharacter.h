// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "public/MyElementalAffinity.h"
#include "MyCharacter.generated.h"


UCLASS()
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

	// movements
	void MoveForward(float Value);
	void MoveRight(float Value);
	void AddControllerPitchInput(float Val);
	void AddControllerYawInput(float Val);
	bool GameInputDisabled;

	// movements logics, movement properties
	UFUNCTION(Category = "Character")
	virtual bool CanJump();
	UFUNCTION(Category = "Character")
	virtual void Jump();

	bool CanJumpOverload;
	void OnJump();
	void OnJumpFinish();
	void OnSprint();
	void OnSprintFinish();

	
	//UPROPERTY(Transient, Replicated)  
	//Some of the variables are network processed, not implemented yet
	bool IsJumping;

	//bool TryJump();
	bool IsSprinting() const;
	bool InAir() const;
	bool CanSprint() const;

	float SprintSpeedModifier;
	float DefaultNormalSpeed;
	float CurrentNormalSpeed;

	bool InForceField;

	//other properties
	
	UFUNCTION()
	void SetHP(float hp);

	UFUNCTION()
	void TakeDmg(float x, bool canReduce=true); //only forcefield dmg is not reduced, maybe some other manually specified

	UFUNCTION()
	void TakingForceFieldDamage(bool yeah);

	UFUNCTION(BlueprintCallable, Category="stam")
	float GetMaxStamina() const;

	UFUNCTION(BlueprintCallable, Category = "stam")
	float GetStamina() const;

	UFUNCTION(BlueprintCallable, Category = "hp")
	float GetMaxHP() const;

	UFUNCTION(BlueprintCallable, Category = "hp")
	float GetHP() const;

	UFUNCTION(BlueprintCallable, Category = "casting")
	float GetCastProgress() const;

	UFUNCTION(BlueprintCallable, Category = "stam")
	float GetCD(int order) const;

	UFUNCTION()
	void SetStamina(float sta);

	UFUNCTION()
	void StaminaIncrease(float x);

	bool IsAlive() const;

	// basic attack
	bool TryCast();
	bool isCasting;
	bool CurrentCastSuccess;
	float GetCurrentCastElapse() const;
	float GetCurrentCastMax() const;
	void OnCast();
	void OnCastFinish();

	UFUNCTION()
	void CastIncrement(float RequiredTime);

	UFUNCTION()
	void CastAbility(); // bind 1234 F/left mouse to this
	UFUNCTION()
	void CastMobilityAbility();
	UFUNCTION()
	void CastOffensiveAbility(); 
	/*
	UFUNCTION()
	void CastDefensiveAbility(); 
	UFUNCTION()
	void CastUtilityAbility(); 
*/
	UFUNCTION()
		void GainController(AActor* effect);//, UProjectileMovementComponent* movementeffecthandle=NULL);

private:	
	// Maybe takedmg needs more handles later on
	//virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
	float MaxHealth;
	float MaxStamina;
	float Health;
	float Stamina;
	float CurrentCastMax;
	float CurrentCastElapse;
	bool casting;
	bool exhausted; //unable to sprint at current status

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;



public:
	bool IsStunned;

//abilities and progression related
public:
	FTimerHandle DamageTimer;
	FTimerHandle RegenTimer;
	FTimerHandle SprintTimer;
	FTimerHandle CastTimer;

	FTimerHandle BasicAttackCD;
	bool BasicAttackCDFinished;
	void BasicAttackCDRefresh();
	FTimerHandle MobilityAbilityCD;
	bool MobilityAbilityCDFinished;
	void MobilityAbilityCDRefresh();
	FTimerHandle OffensiveAbilityCD;
	bool OffensiveAbilityCDFinished;
	void OffensiveAbilityCDRefresh();
	//Character progression records
	
	//beginning of each round gets 3 points, 21 totals
	//each element has cap of 10

	UPROPERTY(VisibleAnywhere, meta = (AllowPublicAccess = "true"))
	class UMyElementalAffinity* MyAffinity; 

	//TSubclassOf<class UMyElementalAffinity> MyAffinity;

	UFUNCTION(BlueprintCallable, Category = "Affin")
	UMyElementalAffinity* GetAffinity();
	//float BaseDmgReduction = 0.2f;
	//float EFire;
	//float EEarth;
	//float ELightning;
	//float EDarkness;
	//float EIce;

	float GetAtkSpeedMultiplier();

	float GetAtkDmgMultiplier();

	float GetMovSpeedMultiplier();

	float GetCritChanceMultiplier(); // Criting not implemented yet

	float GetCritDmgMultiplier(); //

	float GetHPMultiplier();

	float GetMomentumResistanceMultiplier();

	float GetStamRegenMultiplier();

	float GetDefenseMultiplier();

	//Sync between MyAffinity and self
	UFUNCTION()
	void UpdateStats();

	UFUNCTION()
	void SetStun(float duration);

	UFUNCTION()
	void SetMovementSpeedDebuffMultiplier(float MovespeedDebuffMultiplier); 

	UFUNCTION()
	void SetAttackSpeedDebuffMultiplier(float AttackSpeedDebuffMultiplier); // of base attack speed of 1.0

	UFUNCTION()
	void SetAttackDmgDebuffMultiplier(float AttackDmgDebuffMultiplier);

	UFUNCTION()
	void SetDefenseDebuffMultiplier(float DefenseDebuffMultiplier);

	//Ability related
	bool isCharging;
	bool isStunned;

	//movement effect on char
	class UProjectileMovementComponent* movementcomponent;

	UPROPERTY()
	AMyCharacter* CurrentTarget;

	UPROPERTY(EditAnywhere)
	UAnimBlueprint* SampleBP;

	//debuff multipliers from abilities


	float AttackDmgDebuffMultiplier;
	float DefenseDebuffMultiplier;
	float AttackSpeedDebuffMultiplier;


	//Player UI states
	bool InGameMenuOn;
	bool CharacterSheetOn;
	bool ScoreSheetOn;

	UFUNCTION(BlueprintCallable, Category = "buttons")
	void PauseMenu();
	UFUNCTION(BlueprintCallable, Category = "buttons")
	void CharSheet();
	UFUNCTION(BlueprintCallable, Category = "buttons")
	void ScoreSheet();

	// well enum not allowed besides an enum class, enum is required handled globally, I guess for this toy project just track int manually
	//UENUM() 
	//enum UIButtons { InGameMenu, CharacterSheet, ScoreSheet};

	UFUNCTION(BlueprintCallable, Category = "buttons")
	bool ClickedUIButtons(int x) const; //1,2,3


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
