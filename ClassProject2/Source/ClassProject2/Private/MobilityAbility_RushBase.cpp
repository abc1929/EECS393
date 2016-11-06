// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "public/Safevolume.h"
#include "MobilityAbility_RushBase.h"



AMobilityAbility_RushBase::AMobilityAbility_RushBase(const class FObjectInitializer& ObjectInitializer)
{
	auto Owner = Cast<AMyCharacter>(GetOwner());
	auto Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent_Collision"));
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	//AttachToActor(Owner, FAttachmentTransformRules::KeepRelativeTransform);
	


	Collision->InitCapsuleSize(90.f, 110.0f);
	RootComponent = Collision;
	Collision->SetCollisionProfileName(TEXT("Character Collision Enlarged"));

	Collision->OnComponentHit.AddDynamic(this, &AMobilityAbility_RushBase::OnHit);
	//Base rush distance 1200
	//Base dmg
	//Base momentum -> speed

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collision;
	Movement->InitialSpeed = 1200.f;
	Movement->MaxSpeed = 1200.f;
	Movement->bRotationFollowsVelocity = false;
	Movement->ProjectileGravityScale = 0.0f;
	
}

void AMobilityAbility_RushBase::BeginPlay()
{
	Super::BeginPlay();
	this->SetLifeSpan(3.f);
}


AMobilityAbility_RushBase::~AMobilityAbility_RushBase()
{
	//auto Owner = Cast<AMyCharacter>(GetOwner());
	//Owner->GainController();

}




void AMobilityAbility_RushBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (GetOwner() != OtherActor)
	{	
		Movement->DestroyComponent();
		Knockbackstep = this->GetVelocity() / 500;
		if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {
			if (targethit != GetOwner())
			{
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Waaa RushBase Test!"));
				targethit->SetHP(targethit->GetHP() - 15.0f);
				UWorld* const World = GetWorld();
				FTimerDelegate TimerDel;
				TimerDel.BindUFunction(this, FName("Knockback"), targethit);
				World->GetTimerManager().SetTimer(KnockbackTimerHandle, TimerDel, 0.01f, true, 0.f);
			}
			this->SetActorHiddenInGame(true);
			this->SetActorEnableCollision(false);
		}
	}
}

void AMobilityAbility_RushBase::Knockback(AActor* InflictedTarget)
{
	//possible to do AOE this way as well, but right now we're just doing single target
	InflictedTarget->AddActorWorldOffset(Knockbackstep);

	if (increments >= 100)
	{
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
		UWorld* const World = GetWorld();
		World->GetTimerManager().ClearTimer(KnockbackTimerHandle);
		auto Owner = Cast<AMyCharacter>(GetOwner());
		Owner->SetActorEnableCollision(true);
		Destroy();
	}
	increments++;
}