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
	//CustomOwner->MyAffinity = CreateDefaultSubobject<UMyElementalAffinity>(TEXT("Affinity"));
	//CustomOwner->MyAffinity->RegisterComponent();

	auto Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent_Collision"));
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	//AttachToActor(Owner, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	//AttachToActor(CustomOwner, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));


	Collision->InitCapsuleSize(90.f, 110.0f);
	RootComponent = Collision;
	Collision->SetCollisionProfileName(TEXT("Character Collision Enlarged"));
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AMobilityAbility_RushBase::OnStartOverlapping);
	//Base rush distance 1000
	//Base dmg
	//Base momentum -> speed
	
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collision;


	Movement->InitialSpeed = 100.f;
	Movement->MaxSpeed = 30000.f;
	Movement->bRotationFollowsVelocity = false;
	Movement->ProjectileGravityScale = 0.0f;
	
}

void AMobilityAbility_RushBase::BeginPlay()
{
	Super::BeginPlay();
	this->SetLifeSpan(3.f);
	if (CustomOwner != nullptr)
	{
		Movement->Velocity = Movement->Velocity * 10;
		Movement->Velocity = Movement->Velocity *std::pow(CustomOwner->MyAffinity->GetAtkSpeedMultiplier(), 1.5) * CustomOwner->MyAffinity->GetMovSpeedMultiplier(); // 0.5 power from atkspd is actual weight, 1.0 to counter mycharacter side
		BaseVelocity = Movement->Velocity;
		Movement->UpdateComponentVelocity();
		//Movement->MaxSpeed = 1000.f *std::pow(CustomOwner->MyAffinity->GetAtkSpeedMultiplier(), 1.5) * CustomOwner->MyAffinity->GetMovSpeedMultiplier();
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Rushspeed buffed!, and elemental is " + FString::FromInt(CustomOwner->MyAffinity->GetAbilityElementalPrefix())));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(Movement->Velocity.Size()));
		}


		switch (CustomOwner->MyAffinity->GetAbilityElementalPrefix())
		{
			case 0: {
				break;
			}

			case 2:  //lightning based rush, will have slight zigzag movement
			case 21:
			case 20: {
				Zigzag(0);
				break;
			}

			default:
				break;
		}
	}
	else
	{
		Movement->InitialSpeed = 1000.f;
		Movement->MaxSpeed = 50000.f;
	}



}


AMobilityAbility_RushBase::~AMobilityAbility_RushBase()
{
	//auto Owner = Cast<AMyCharacter>(CustomOwner);
	//Owner->GainController();
	if (IsRooted())
		RemoveFromRoot();
}

void AMobilityAbility_RushBase::Zigzag(int count)
{
	UWorld* const World = GetWorld();
	Movement->UpdateComponentVelocity();

	World->GetTimerManager().ClearTimer(ZigzagTimerHandle);
	FTimerDelegate TimerDel;
	if (count == 0) {

		Movement->Velocity = BaseVelocity - 0.25 * FVector(-(BaseVelocity.Y), BaseVelocity.X, 0);
		Zigzag(1);
	}
	if (count == 1) {

		TimerDel.BindUFunction(this, FName("Zigzag"), 2);
		World->GetTimerManager().SetTimer(ZigzagTimerHandle, TimerDel, 0.2f, false, -0.2f);
		Movement->Velocity = BaseVelocity + 0.5*FVector(-(BaseVelocity.Y), BaseVelocity.X, 0);
		
	}

	if (count == 2) {
		TimerDel.BindUFunction(this, FName("Zigzag"), 1);
		World->GetTimerManager().SetTimer(ZigzagTimerHandle, TimerDel, 0.2f, false, -0.2f);
		Movement->Velocity = BaseVelocity + 0.5*FVector(BaseVelocity.Y, -(BaseVelocity.X), 0);
		//Movement->Velocity = Movement->Velocity + Movement->Velocity.RightVector * 2500;
		
	}
}


void AMobilityAbility_RushBase::OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CustomOwner != OtherActor && !OtherActor->IsA(ASafevolume::StaticClass())) //hit something valid
	{	
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(CustomOwner->MyAffinity->GetHPMultiplier()));
		Deactivate();
		//Movement->DestroyComponent();
		UWorld* const World = GetWorld();
		Cast<AMyCharacter>(CustomOwner)->isCharging = false;
		Cast<AMyCharacter>(CustomOwner)->EnableInput(World->GetFirstPlayerController());
		if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {
			if (targethit != CustomOwner)
			{
				Knockbackstep = this->BaseVelocity / 500;
				//if (GEngine)
				//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Waaa RushBase Test!"));

				
				targethit->TakeDmg(15.0f * Cast<AMyCharacter>(CustomOwner)->MyAffinity->GetAtkDmgMultiplier());
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
	InflictedTarget->AddActorWorldOffset(Knockbackstep / InflictedTarget->MyAffinity->GetMomentumResistanceMultiplier()); //maybe even square the multiplier if gameplay wise knockback resistance too underpowered

	if (increments >= 100)
	{
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
		UWorld* const World = GetWorld();
		World->GetTimerManager().ClearTimer(KnockbackTimerHandle);
		//auto Owner = Cast<AMyCharacter>(CustomOwner);
		//Owner->SetActorEnableCollision(true);
		Destroy();
	}
	increments++;
}

void AMobilityAbility_RushBase::Deactivate()
{
	Movement->DestroyComponent();
	this->SetActorEnableCollision(false);
}