// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Fireball.generated.h"

class AMyCharacter;

UCLASS()
class CLASSPROJECT2_API AFireball : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireball();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FVector Knockbackstep;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UFUNCTION()
	void Knockback(AActor* InflictedTarget);

	bool KBTimerExpired;

protected:
	
	class USphereComponent* Collision;
	class UStaticMeshComponent* FireballMesh;
	class UProjectileMovementComponent* Movement;
	class UParticleSystemComponent* Firetrail;
	FTimerHandle KnockbackTimerHandle;
	int increments;
	float CastTime;
};
