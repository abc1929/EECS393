// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "public/AbilityEffect.h"
#include "public/MyCharacter.h"
#include "Ability.generated.h"

class AAbilityEffect;
class UMyElementalAffinity;

// this class is not used currently

UCLASS(ABSTRACT)
class CLASSPROJECT2_API AAbility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbility(const class FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//effect packages that the ability generates to apply to a or some targets, maybe a priority queue of "procedures"
	//this object will be accepted by a MyCharacter and process on it 
	//it can be dmg, slowing effect, buff, whatever.

	//what structure do we use? this is a single effect
	virtual TArray<AAbilityEffect> CreateEffectList() PURE_VIRTUAL(AAbility::CreateEffectList, return TArray<AAbilityEffect>(););

	
	//Multipliers from elemental affinity of the owner (ability caster)
	//virtual UMyElementalAffinity* GetAffinity() PURE_VIRTUAL(AAbility::GetAffinity, return new UMyElementalAffinity(););
	//... and so on

	//visual representation (spawn logic) of the ability actor and hit logic
	// variance from elemental affinity

	//self specialization from owner's affinity
private:
	virtual void SelfSpecialization() PURE_VIRTUAL(AAbility::SelfSpecialization, );

	//basic vars, cd; stamcost; casttime; distance; aoe?; targeted?; 
	float cd;
	float staminaCost;
	float castSlowing; //character shouldn't be running at 1.0 speed while casting some ability
	float castTime;
	int targetingType; //targeted, targeted aoe, non targeted projectile, non targeted spawn effect (flamestrike ish)
	
	float AtkSpeedMultiplier; //Fire
	float AtkDmgMultiplier; //Darkness
	float ProjectileSpeedMultiplier; //Lightning
	float CritChanceMultiplier; //Lightning
	float CritDmgMultiplier; //Lightning minor, Darkness

	

};
