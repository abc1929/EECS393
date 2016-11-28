// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AbilityEffect.generated.h"

class AAbility;

// UE4's internal objects don't really do true abstract since they need to exist in some instance that you run
// we use macro to do abstract methods
UCLASS()
class CLASSPROJECT2_API AAbilityEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbilityEffect(const class FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
private:
	float duration; //0 for apply once instantly
	int effectElementalType; //what elemental type this effect is 
	float tickInterval; //for dot and such, 0 for instant


	float totalDmg;
	float totalMomentum;
	float totalStaminaDrain;

	bool dmgValid;
	bool mmtValid;
	bool stamdrainValid;

	// applied amount at each tick
	// sum it up it should match the total. -> above 3 valid checks
	// it's fine that some effect might not inflicting dmg or momentum at all

	// these will be allocated timers so we have async
	virtual float dmgCurve(float t) PURE_VIRTUAL(AAbilityEffect::dmgCurve, return 1;);
	virtual FVector mmtCurve(float t) PURE_VIRTUAL(AAbilityEffect::mmtCurve, return FVector();); //this gonna be per tick location offset for the target
	virtual float stamdrainCurve(float t) PURE_VIRTUAL(AAbilityEffect::stamdrainCurve, return 1;);


	// how momentum penalty of MyCharacter is should be written at 

	// example other effect: slow(boost speed), stun, immobilize (slow 100%), dmg(heal)
	virtual float movSlowCurve(float t) PURE_VIRTUAL(AAbilityEffect::movSlowCurve, return 1;);
	virtual bool stunCurve(float t) PURE_VIRTUAL(AAbilityEffect::stunCurve, return 1;);
	virtual float atkSlowCurve(float t) PURE_VIRTUAL(AAbilityEffect::atkSlowCurve, return 1;);

	//regen suppression? defense boost, attack dmg boost? assume all negative effects, but can be written other way 
	virtual float defWeakenCurve(float t) PURE_VIRTUAL(AAbilityEffect::defWeakenCurve, return 1;);
	virtual float atkWeakenCurve(float t) PURE_VIRTUAL(AAbilityEffect::atkWeakenCurve, return 1;);


};
