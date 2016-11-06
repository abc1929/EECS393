// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include <algorithm> 
#include <math.h>  
#include "ElementalAffinity.h"

ElementalAffinity::ElementalAffinity()
{
	Elements.Init(0,5);
}


ElementalAffinity::ElementalAffinity(TArray<float> elements)
{
	Elements = elements;
	CalculateAffinities();
}

ElementalAffinity::~ElementalAffinity()
{
}


void ElementalAffinity::UpdateElements(float newamount, int element) //01234 -> FELDI
{
	Elements[element] = newamount;
	CalculateAffinities();
}

float ElementalAffinity::PenaltyCurve(float ratio)
{
	if (ratio > 0.4)
		return pow(ratio - 0.4, 1.5) / 8.09543f;
	else
		return 0.0f;
}

void ElementalAffinity::CalculateAffinities()
{
	int total = 0;
	int FirstAffinityIndex = 0;
	int SecondAffinityIndex = 0;

	if (Elements[0] > Elements[1]) {
		SecondAffinityIndex = 1;
		FirstAffinityIndex = 0;
	}
	else {
		SecondAffinityIndex = 0;
		FirstAffinityIndex = 1;
	}
	// we simply need first and second elemental type that the character has the most points allocated
	// sorting is kind of unnecessary, just do this
	for (int i = 2; i < 5; i++) {
		if (Elements[i] >= Elements[FirstAffinityIndex]) {
			SecondAffinityIndex = FirstAffinityIndex;
			FirstAffinityIndex = i;
		}
		else if (Elements[i] > Elements[SecondAffinityIndex]) {
			SecondAffinityIndex = i;
		}
	}

	for (int index = 0; index<5;index++){total += Elements[index];}//there isn't a native function to sum. 
	TArray<float> weight; //temp stores elements weight , ranging from 0,1
	TArray<float> penalty; //penalty array;
	weight.Init(0, 5);
	penalty.Init(0, 5);
	if (total>0)
	{ 
		//calculating penalties
		for (int index = 0; index<5; index++)
		{
			weight[index] = [&, total](auto s)->auto {return s / total; }(Elements[index]);
		}

		for (int index = 0; index<5; index++)
		{
			//elemental supressions, let's say you have 2 ice and 5 fire, it would be the tipping point where fire gets penalized
			//while if you have 3 ice then you won't
			if (weight[index % 5] == 0 || weight[(index + 1) % 5]) //compiler is kinda dumb
				continue;
			if (weight[index % 5] / weight[(index + 1) % 5] > 0.4) {
				penalty[(index + 1) % 5] = std::min(PenaltyCurve(weight[index % 5] / weight[(index + 1) % 5]), 0.25f);
			}

		}

		//determining prefixes
		//special two element combination need weight combined >0.6, otherwise single element
		//if highest is more than 100% than second, it would be single element
		//if element value is not yet 3, compound type not available.

		AbilityElementalPrefix = FirstAffinityIndex;
		//this makes priority FELDI as well in case you have complete equivalent first and second while in the single Elemental state
		// 
		if (weight[FirstAffinityIndex] + weight[SecondAffinityIndex] > 0.6 && weight[FirstAffinityIndex] / weight[SecondAffinityIndex] < 2 && Elements[FirstAffinityIndex]>3)
			//if (weight[FirstAffinityIndex] / weight[SecondAffinityIndex] < 2)
		{
			AbilityElementalPrefix = std::max(10 * FirstAffinityIndex + SecondAffinityIndex, FirstAffinityIndex + 10 * SecondAffinityIndex);
		}

		// I think it is more appropriate to process buff multipliers and stuff otherwhere, not in this class, just keep the data pure
		ProcessedElementAffinities.Init(0, 5);
		for (int index = 0; index < 5; index++)
		{
			ProcessedElementAffinities[index] = Elements[index] * (1 - penalty[index]);
		}


	} //this bracket encloses total!=0 info

}


TArray<float> ElementalAffinity::GetElements() //raw
{
	return Elements;
}

TArray<float> ElementalAffinity::GetProcessedElementAffinities()
{
	return ProcessedElementAffinities;
}

int ElementalAffinity::GetAbilityElementalPrefix()
{
	return AbilityElementalPrefix;
}