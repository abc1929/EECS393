// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "OffensiveAbility_WaveBase.h"
#include "public/MyCharacter.h"
#include "public/Safevolume.h"

// default offensive ability
AOffensiveAbility_WaveBase::AOffensiveAbility_WaveBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent_Collision"));

	RootComponent = Collision;
	Collision->BodyInstance.SetCollisionProfileName("Stationary");
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap); //ECR_Overlap
	Collision->InitCapsuleSize(120, 300);
	Collision->SetWorldRotation(FRotator(270,0,0));
	Collision->SetHiddenInGame(false);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ballmesh"));
	Mesh->SetupAttachment(RootComponent);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AOffensiveAbility_WaveBase::OnStartOverlapping);
	//Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	//Movement->UpdatedComponent = Collision;
	GetAssets();
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));

	Particle->SetupAttachment(Mesh);
	
	//Particle->bOverrideLODMethod = true;
	Particle->bAutoActivate = true;

	Particle2 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle2"));

	Particle2->SetupAttachment(RootComponent);

	//Particle->bOverrideLODMethod = true;
	Particle2->bAutoActivate = true;

}

void AOffensiveAbility_WaveBase::BeginPlay()
{
	Super::BeginPlay();
	this->SetLifeSpan(1.f);
	GetAssets();
	switch (CustomOwner->MyAffinity->GetAbilityElementalPrefix())
	{
		case 0: {
			if (ParticleAsset_fire)
			{
				Particle->SetTemplate(ParticleAsset_fire);
				Particle->SetWorldScale3D(FVector(1.4f, 3.2f, 6.0f));
				Collision->SetCapsuleSize(120, 300);
			}
			break;
		}

		case 2: {
			if (ParticleAsset_sparks)
			{
				Particle2->SetTemplate(ParticleAsset_sparks);
				//->SetWorldScale3D(FVector(0.5f));
				Collision->SetCapsuleSize(200, 20);
				Particle2->AddLocalOffset(FVector(-300, 0, 0));
				AddActorLocalOffset(FVector(0, 0, -100.0f));
				AddActorLocalRotation(FRotator(0, 180, 0));
			}
			break;
		}
		case 20: {
			if (ParticleAsset_sparks)
			{
				Particle2->SetTemplate(ParticleAsset_sparks);
				Particle->SetTemplate(ParticleAsset_fire);
				Particle->SetWorldScale3D(FVector(3.4f, 1.2f, 1.2f));
				//->SetWorldScale3D(FVector(0.5f));
				Particle2->AddLocalOffset(FVector(-300, 0, 0));
				Collision->SetCapsuleSize(200, 20);
				AddActorLocalOffset(FVector(0, 0, -100.0f));
			}
			break;
		}

		default:
			break;
	}

}

// Called every frame
void AOffensiveAbility_WaveBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOffensiveAbility_WaveBase::GetAssets() {


	static ConstructorHelpers::FObjectFinder<UParticleSystem> t_ParticleAsset_sparks(TEXT("ParticleSystem'/Game/ThirdPersonCPP/Blueprints/pLightningBeam_2.pLightningBeam_2'"));
	if (t_ParticleAsset_sparks.Object) { ParticleAsset_sparks = t_ParticleAsset_sparks.Object; }
	
	//static ConstructorHelpers::FObjectFinder<UParticleSystem> t_ParticleAsset_fire(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> t_ParticleAsset_fire(TEXT("ParticleSystem'/Game/ThirdPersonCPP/Blueprints/FireWaveBase2.FireWaveBase2'"));
	if (t_ParticleAsset_fire.Object) { ParticleAsset_fire = t_ParticleAsset_fire.Object; }
}


// Called when this ability hits enemy
void AOffensiveAbility_WaveBase::OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CustomOwner != OtherActor && !OtherActor->IsA(ASafevolume::StaticClass()) && OtherActor->IsA(AMyCharacter::StaticClass())) //hit something valid
	{
		UWorld* const World = GetWorld();

		if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {
			if (targethit != CustomOwner)
			{

				Knockbackstep = FRotationMatrix(CustomOwner->GetControlRotation()).GetScaledAxis(EAxis::X)*10;
				auto interval = 0.01f;
				auto affin = CustomOwner->MyAffinity->GetAbilityElementalPrefix();
				if (affin == 2 || affin == 20) {
					Knockbackstep = FVector(0,0,1) * 75;
					interval = 0.05;
				}

				FTimerDelegate TimerDel;
				TimerDel.BindUFunction(this, FName("Knockback"), targethit);
				World->GetTimerManager().SetTimer(Wavetick, TimerDel, interval, true, 0.f);
			}
		}
	}
}

// knock up or knock back depends
void AOffensiveAbility_WaveBase::Knockback(AMyCharacter* InflictedTarget)
{
	auto affin = CustomOwner->MyAffinity->GetAbilityElementalPrefix();
	auto dmgtick = 0.3f;
	if (affin == 2 || affin == 20) {
		dmgtick = 1.f;
	}
	InflictedTarget->TakeDmg(
		Cast<AMyCharacter>(CustomOwner)->AttackDmgDebuffMultiplier
		* dmgtick
		* Cast<AMyCharacter>(CustomOwner)->MyAffinity->GetAtkDmgMultiplier()
	);
	InflictedTarget->AddActorWorldOffset(0.9 * Knockbackstep / InflictedTarget->MyAffinity->GetMomentumResistanceMultiplier());
	if (increments >= 50)
	{

		UWorld* const World = GetWorld();
		World->GetTimerManager().ClearTimer(Wavetick);
		Destroy();
		return;
	}
	increments++;
}


