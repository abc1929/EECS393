// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilityEffect.h"
#include "Fireball_Effect.generated.h"

class AMyCharacter;
/**
 * 
 */
UCLASS()
class CLASSPROJECT2_API AFireball_Effect : public AAbilityEffect
{
	GENERATED_BODY()

public:
	AFireball_Effect(const class FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;

	AMyCharacter* CustomOwner; 
	AMyCharacter* Target;

	TArray<float> Affin;
	
	int PrimaryAffin;
	float dlratio; //determine stam leech for affin 3 and 2 


	UFUNCTION()
	float dmgCurve(float t);
	UFUNCTION()
	FVector mmtCurve(float t); 
	UFUNCTION()
	float stamdrainCurve(float t);

	UFUNCTION()
	float movSlowCurve(float t);
	UFUNCTION()
	bool stunCurve(float t);
	UFUNCTION()
	float atkSlowCurve(float t);

	UFUNCTION()
	float defWeakenCurve(float t);
	UFUNCTION()
	float atkWeakenCurve(float t);


	// curves themselves don't handle delays, apply does
	// curve tracks starting the moment itself initiate effects
	UFUNCTION()
	void applydmg(float start, float end, float d, int n);
	UFUNCTION()
	void applystamdrain(float start, float end, float d, int n);
	UFUNCTION()
	void applymovslow(float start, float end, float d, int n);
	UFUNCTION()
	void applystun(float start, float end, float d, int n);
	UFUNCTION()
	void applyatkslow(float start, float end, float d, int n);
	UFUNCTION()
	void applydefweak(float start, float end, float d, int n);
	UFUNCTION()
	void applyatkweak(float start, float end, float d, int n);
	
	//not used
	UFUNCTION()
	void applymmt();	


};
