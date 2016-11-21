// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "MyElementalAffinity.generated.h"

/**
 * 
 */
UCLASS()
class CLASSPROJECT2_API UMyElementalAffinity : public UActorComponent
{
	GENERATED_BODY()

	UMyElementalAffinity();
	UMyElementalAffinity(TArray<float> elements);


public:
	float PenaltyCurve(float ratio);
	UFUNCTION(BlueprintCallable, Category = "Affin")
	void UpdateElements(float newamount, int element); //01234 -> FELDI
	void CalculateAffinities();

	int GetAbilityElementalPrefix();
	TArray<float> GetElements(); //raw
	TArray<float> GetProcessedElementAffinities();
	void CalculateMultipliers();
	float opeCurve(float firstAffinity, float secondAffinity = 0, int AffinityCount = 1);
	float opfCurve(float firstAffinity, float secondAffinity = 0, int AffinityCount = 1);
	float optCurve(float affinity);

	UFUNCTION(BlueprintCallable, Category = "Affin")
	void UpdateAll(TArray<float> elements);
	void Update();
	TArray<float> Elements; //[8,3,7,2,0] FELDI
	TArray<float> ProcessedElementAffinities; // Penalized Elements
	int AbilityElementalPrefix; //majority of morphable abilities are determined by this (15 total)
	int PrimaryElementalPrefix; //basic attack is only morphed on primary affinity (5 total)


	float AtkSpeedMultiplier; //Fire, Lightning <1.5, cast & projectile speed
	float AtkDmgMultiplier; //Darkness <1.5
	float MovSpeedMultiplier;  //Fire <1.2
	float CritChanceMultiplier; //Lightning <1.8
	float CritDmgMultiplier; //? Lightning, Darkness 1.5
	float HPMultiplier; //Earth <1.8
	float MomentumResistanceMultiplier; //Earth <1.2
	float StamRegenMultiplier; //Ice <1.5
	float DefenseMultiplier; //Earth, Ice <1.8


	UFUNCTION() float GetAtkSpeedMultiplier();
	UFUNCTION() float GetAtkDmgMultiplier();
	UFUNCTION() float GetMovSpeedMultiplier();
	UFUNCTION() float GetCritChanceMultiplier(); // Criting not implemented yet
	UFUNCTION() float GetCritDmgMultiplier(); //
	UFUNCTION() float GetHPMultiplier();
	UFUNCTION() float GetMomentumResistanceMultiplier();
	UFUNCTION() float GetStamRegenMultiplier();
	UFUNCTION() float GetDefenseMultiplier();
	
	
};
