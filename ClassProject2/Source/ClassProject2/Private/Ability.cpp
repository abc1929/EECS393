// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "public/Ability.h"

// Abstract class for hierarchy, not really utilized currently

// Sets default values
AAbility::AAbility(const class FObjectInitializer& ObjectInitializer)
{
 	// an ability needs to be checked every frame
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbility::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//void AAbility::SelfSpecialization();
//AAbilityEffect* AAbility::CreateEffectList();

//Multipliers from elemental affinity of the owner (ability caster)
//float AAbility::GetFAffinity();