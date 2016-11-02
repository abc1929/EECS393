// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AbilityEffect.generated.h"

class AAbility;

UCLASS(ABSTRACT)
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
	int priority; //when does this effect occurs in the enire list
	float tickInterval; //for dot and such, 0 for instant
	int effectCategory; //offensive? basic? 


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
	virtual float dmgCurve(float t) = 0;
	virtual FVector mmtCurve(float t) = 0; //this gonna be per tick location offset for the target
	virtual float stamdrainCurve(float t) = 0;


	// how momentum penalty of MyCharacter is should be written at 

	// example other effect: slow(boost speed), stun, immobilize (slow 100%), dmg(heal
	virtual float movSlowCurve(float t) = 0;
	virtual float stunCurve(float t) = 0;
	virtual float atkSlowCurve(float t) = 0;

	//regen suppression? defense boost, attack dmg boost? assume all negative effects, but can be written other way 
	virtual float defWeakenCurve(float t) = 0;
	virtual float atkWeakenCurve(float t) = 0;


};
