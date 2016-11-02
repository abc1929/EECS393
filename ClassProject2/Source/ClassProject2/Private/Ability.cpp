// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "Ability.h"


// Sets default values
AAbility::AAbility()
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

