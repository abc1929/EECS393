// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "AbilityEffect.h"
#include "public/MyCharacter.h"

// Sets default values
AAbilityEffect::AAbilityEffect(const class FObjectInitializer& ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbilityEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbilityEffect::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//float AAbilityEffect::dmgCurve(float t) {};
//FVector AAbilityEffect::mmtCurve(float t); //this gonna be per tick location offset for the target
//float AAbilityEffect::stamdrainCurve(float t);


// how momentum penalty of MyCharacter is should be written at 

// example other effect: slow(boost speed), stun, immobilize (slow 100%), dmg(heal
//float AAbilityEffect::movSlowCurve(float t);
//float AAbilityEffect::stunCurve(float t);
//float AAbilityEffect::atkSlowCurve(float t);

//regen suppression? defense boost, attack dmg boost? assume all negative effects, but can be written other way 
//float AAbilityEffect::defWeakenCurve(float t);
//float AAbilityEffect::atkWeakenCurve(float t);



void AAbilityEffect::_initialize()
{
	Affin = CustomOwner->MyAffinity->GetProcessedElementAffinities();
	PrimaryAffin = CustomOwner->MyAffinity->PrimaryElementalPrefix;
	dlratio = (Affin[3] + Affin[2]) > 0 ? Affin[3] / (Affin[3] + Affin[2]) : 0.f;
}