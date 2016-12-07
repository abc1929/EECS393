// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OffensiveAbility.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "OffensiveAbility_WaveBase.generated.h"


class AMyCharacter;
/**
 * 
 */
UCLASS()
class CLASSPROJECT2_API AOffensiveAbility_WaveBase : public AOffensiveAbility
{
	GENERATED_BODY()

public:
	AOffensiveAbility_WaveBase();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void Knockback(AMyCharacter* InflictedTarget);

	UPROPERTY()
	AMyCharacter* CustomOwner;

	void GetAssets();


	class UCapsuleComponent* Collision;
	class UProjectileMovementComponent* Movement;
	UStaticMeshComponent* Mesh;
	UParticleSystem* ParticleAsset_sparks;
	UParticleSystem* ParticleAsset_fire;
	UStaticMesh* mmesh;
	class UParticleSystemComponent* Particle;
	class UParticleSystemComponent* Particle2;

	bool KBTimerExpired;
	FTimerHandle Wavetick;
	FVector Knockbackstep;
	int increments;


	
};
