// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MobilityAbility.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MobilityAbility_RushBase.generated.h"


class AMyCharacter;
/**
 * 
 */
UCLASS()
class CLASSPROJECT2_API AMobilityAbility_RushBase : public AMobilityAbility
{
	GENERATED_BODY()

	

public:
	virtual void BeginPlay() override;

	AMobilityAbility_RushBase(const class FObjectInitializer& ObjectInitializer);
	~AMobilityAbility_RushBase();

	UFUNCTION()
	void OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//UFUNCTION()
	//void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void Knockback(AMyCharacter* InflictedTarget);

	bool KBTimerExpired;
	FTimerHandle KnockbackTimerHandle;
	FVector Knockbackstep;
	int increments;

	UPROPERTY()
	class UMyElementalAffinity* OwnerAffinity;


	AActor* Instigator;
	AMyCharacter* CustomOwner;

	class UProjectileMovementComponent* Movement;

	UFUNCTION()
	void Deactivate(); //deactive movement and collision, go in to a state resolving momentum infliction
};
