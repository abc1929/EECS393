// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
ElementalAffinity is initialized by given a list of elements points allocation
ElementalAffinity is a signature that contains how the character would get buffed by how he allocated the elemental progression
Character has a ElementalAffinity, the ability that character cast would be constructed via elemental affinity, 
ElementalAffinity also determines how the character handles incoming abilityeffect 
 */
class CLASSPROJECT2_API ElementalAffinity
{
public:
	ElementalAffinity();
	ElementalAffinity(TArray<float> elements);
	~ElementalAffinity();

	//consider the fact that elementalAffinity would be a persistent object that has one to one relationship to characters 
	float PenaltyCurve(float ratio);
	void UpdateElements(float newamount, int element); //01234 -> FELDI
	void CalculateAffinities();

	int GetAbilityElementalPrefix();
	TArray<float> GetElements(); //raw
	TArray<float> GetProcessedElementAffinities();


private:
	TArray<float> Elements; //[8,3,7,2,0]
	TArray<float> ProcessedElementAffinities; // all 1.0 at first, minimum 1.0 for all, max 2.0, not necessarily representing percentages
	int AbilityElementalPrefix;

	// making buffs on characters AbilityEffect is unnecessarily expensive, I think keeping it simple as calculated/updated multipliers is good
};

