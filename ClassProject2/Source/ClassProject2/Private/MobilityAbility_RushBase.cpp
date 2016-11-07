// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "public/Safevolume.h"
#include <algorithm> 
#include <math.h>  
#include "MobilityAbility_RushBase.h"
#include "public/MyCharacter.h"



AMobilityAbility_RushBase::AMobilityAbility_RushBase(const class FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	Owner = Cast<AMyCharacter>(GetOwner());
	auto Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent_Collision"));
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	//AttachToActor(Owner, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	


	Collision->InitCapsuleSize(90.f, 110.0f);
	RootComponent = Collision;
	Collision->SetCollisionProfileName(TEXT("Character Collision Enlarged"));
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AMobilityAbility_RushBase::OnStartOverlapping);
	//Base rush distance 1000
	//Base dmg
	//Base momentum -> speed
	
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collision;


	//float test = Cast<AMyCharacter>(GetOwner())->GetAtkSpeedMultiplier();
	if (Cast<AMyCharacter>(GetOwner()))
	{
		Movement->InitialSpeed = 1000.f * std::pow(Cast<AMyCharacter>(GetOwner())->GetAtkSpeedMultiplier(), 1.5) * Cast<AMyCharacter>(GetOwner())->GetMovSpeedMultiplier(); // 0.5 power from atkspd is actual weight, 1.0 to counter mycharacter side
		Movement->MaxSpeed = 1000.f * std::pow(Cast<AMyCharacter>(GetOwner())->GetAtkSpeedMultiplier(), 1.5) * Cast<AMyCharacter>(GetOwner())->GetMovSpeedMultiplier();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Rushspeed buffed!");
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(Movement->InitialSpeed));
	}
	else
	{	
		FString sd;
		if(GetOwner())
			FString sd = GetOwner()->GetName();
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, sd);
		Movement->InitialSpeed = 1000.f;
		Movement->MaxSpeed = 1000.f;
	}
	Movement->bRotationFollowsVelocity = false;
	Movement->ProjectileGravityScale = 0.0f;
	
}

void AMobilityAbility_RushBase::BeginPlay()
{
	Super::BeginPlay();
	Owner = Cast<AMyCharacter>(GetOwner());
	this->SetLifeSpan(3.f);
}


AMobilityAbility_RushBase::~AMobilityAbility_RushBase()
{
	//auto Owner = Cast<AMyCharacter>(GetOwner());
	//Owner->GainController();

}




void AMobilityAbility_RushBase::OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GetOwner() != OtherActor && !OtherActor->IsA(ASafevolume::StaticClass())) //hit something valid
	{	
		Deactivate();
		//Movement->DestroyComponent();
		UWorld* const World = GetWorld();
		Cast<AMyCharacter>(GetOwner())->isCharging = false;
		Cast<AMyCharacter>(GetOwner())->EnableInput(World->GetFirstPlayerController());
		if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {
			if (targethit != GetOwner())
			{
				Knockbackstep = this->GetVelocity() / 500;
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Waaa RushBase Test!"));

				
				targethit->TakeDmg(15.0f); //* Cast<AMyCharacter>(GetOwner())->MyAffinity->GetAtkDmgMultiplier());
				FTimerDelegate TimerDel;
				TimerDel.BindUFunction(this, FName("Knockback"), targethit);
				World->GetTimerManager().SetTimer(KnockbackTimerHandle, TimerDel, 0.01f, true, 0.f);
			}
			this->SetActorHiddenInGame(true);
			this->SetActorEnableCollision(false);
		}
	}
}

void AMobilityAbility_RushBase::Knockback(AMyCharacter* InflictedTarget)
{
	//possible to do AOE this way as well, but right now we're just doing single target
	InflictedTarget->AddActorWorldOffset(Knockbackstep);// / InflictedTarget->MyAffinity->GetMomentumResistanceMultiplier()); //maybe even square the multiplier if gameplay wise knockback resistance too underpowered

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

void AMobilityAbility_RushBase::Deactivate()
{
	Movement->DestroyComponent();
	this->SetActorEnableCollision(false);
}