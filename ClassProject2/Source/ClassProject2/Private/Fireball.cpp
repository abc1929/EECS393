// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "Fireball.h"


// Sets default values
AFireball::AFireball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireball::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

