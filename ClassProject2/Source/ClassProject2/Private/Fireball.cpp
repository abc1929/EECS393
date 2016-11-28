// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "public/Fireball.h"
#include "public/MyCharacter.h"


// Even though it is called Fireball, well this class is for all basic ranged attack.
AFireball::AFireball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Setup collision sphere and static mesh
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = Collision;
	Collision->InitSphereRadius(28.0f);
	Collision->SetCollisionProfileName(TEXT("Projectile"));
	Collision->BodyInstance.SetCollisionProfileName("Projectile");
	FireballMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ballmesh"));
	FireballMesh->SetupAttachment(RootComponent);
	Firetrail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireTrail"));
	Firetrail->SetupAttachment(FireballMesh);
	
	Firetrail->bAutoActivate = true;
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collision;
	Movement->InitialSpeed = 100.f; //* Cast<AMyCharacter>(GetOwner())->MyAffinity->GetAtkSpeedMultiplier();
	Movement->MaxSpeed = 50000.f; //* Cast<AMyCharacter>(GetOwner())->MyAffinity->GetAtkSpeedMultiplier();
	GetAssets();


	//Knockback variables
	increments = 0;

}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();
	this->SetLifeSpan(20.f);
	CreateMesh(CustomOwner->MyAffinity->PrimaryElementalPrefix);


	Movement->Velocity=Movement->Velocity * Cast<AMyCharacter>(CustomOwner)->MyAffinity->GetAtkSpeedMultiplier();
	Movement->UpdateComponentVelocity();
	
}

// Called every frame
void AFireball::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (this->GetActorLocation().Size() > 10000) {
		this->Destroy();
	}
	if (CustomOwner->MyAffinity->PrimaryElementalPrefix==2) {
		Firetrail->SetBeamTargetPoint(0, FireballMesh->GetComponentLocation(), 0);
		Firetrail->SetBeamSourcePoint(0, CustomOwner->GetActorLocation() + 50 * FRotationMatrix(CustomOwner->GetActorRotation()).GetScaledAxis(EAxis::X), 0);
	}
}

void AFireball::GetAssets() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> t_mmesh(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	if (t_mmesh.Object) { mmesh = t_mmesh.Object; }
	static ConstructorHelpers::FObjectFinder<UParticleSystem> t_ParticleAsset_sparks(TEXT("ParticleSystem'/Game/ThirdPersonCPP/Blueprints/pLightningBeam.pLightningBeam'"));
	if (t_ParticleAsset_sparks.Object) { ParticleAsset_sparks = t_ParticleAsset_sparks.Object; }
	static ConstructorHelpers::FObjectFinder<UMaterial> t_grime(TEXT("Material'/Game/StarterContent/Materials/M_Concrete_Grime.M_Concrete_Grime'"));
	if (t_grime.Object) { grime = t_grime.Object; }
	static ConstructorHelpers::FObjectFinder<UParticleSystem> t_ParticleAsset_fire(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (t_ParticleAsset_fire.Object) { ParticleAsset_fire = t_ParticleAsset_fire.Object; }
}


//This determines 
void AFireball::CreateMesh(int PrimaryElementalPrefix)
{
	switch (PrimaryElementalPrefix)
	{
		// fire/default case Fireball - slow projectile
		case 0:
		{
			if (mmesh)
			{
				FireballMesh->SetStaticMesh(mmesh);
				FireballMesh->SetWorldScale3D(FVector(0.5f));
				FireballMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.f));
		
				if (grime)
					FireballMesh->SetMaterial(0, grime);
			}

			//Fire
			Firetrail->SetRelativeLocation(FVector(0.0f, 0.0f, 35.0f));
			if (ParticleAsset_fire)
			{
				Firetrail->SetTemplate(ParticleAsset_fire);
				Firetrail->SetWorldScale3D(FVector(1.2f));
			}

			//Movement
	
			// speed:800 = 100*8
			Movement->Velocity = Movement->Velocity * 8;
		
			Movement->bRotationFollowsVelocity = false;
			Movement->ProjectileGravityScale = 0.01;

			//TArray<TSharedPtr<FName>> CollisionList;
			//UCollisionProfile::Get()->GetProfileNames(CollisionList);
			Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
			Collision->SetNotifyRigidBodyCollision(true);
			Collision->OnComponentHit.AddDynamic(this, &AFireball::OnHit);

			break;
		}
		
		// Earth, I guess I'll call it Chasm - slow projectile travels on the ground rather than mid air
		case 1:
		{

			CreateMesh(0);
			break;
		}

		// Lightning bolt - ultra fast projectile
		case 2:
		{
			if (mmesh)
			{
				FireballMesh->SetStaticMesh(mmesh);
				FireballMesh->SetWorldScale3D(FVector(0.1f));
				FireballMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.f));
				if (grime)
					FireballMesh->SetMaterial(0, grime);
			}

			//This gonna be sparks
			
			Firetrail->SetRelativeLocation(FVector(0.0f, 0.0f, 35.0f));
			if (ParticleAsset_sparks)
			{

				Firetrail->SetTemplate(ParticleAsset_sparks);
				//Firetrail->SetupAttachment(FireballMesh);
				//Firetrail->SetupAttachment(FireballMesh);

				Firetrail->SetWorldScale3D(FVector(1.5f));
			}

			//Movement
			Movement->Velocity = Movement->Velocity * 32;
			Movement->bRotationFollowsVelocity = false;
			Movement->ProjectileGravityScale = 0.01;

			//TArray<TSharedPtr<FName>> CollisionList;
			//UCollisionProfile::Get()->GetProfileNames(CollisionList);
			Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
			Collision->SetNotifyRigidBodyCollision(true);
			Collision->OnComponentHit.AddDynamic(this, &AFireball::OnHit);


			break;
		}

		// Agony - a instant reach basic attack. afflict dmg and knock back after some time period
		case 3:
		{
			CreateMesh(0);
			break;
		}

		// Frost Lance - faster than Fireball
		case 4:
		{
			CreateMesh(0);
			break;
		}


		default:
			break;
	}


	
}


void AFireball::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	switch (CustomOwner->MyAffinity->PrimaryElementalPrefix)
	{
		case 0: {Knockbackstep = this->GetVelocity() / 300; break; } //Fire
		case 1: {Knockbackstep = FVector(0, 0, 0);  break; } //I'll make this knockback and up for Earth
		case 2: {Knockbackstep = this->GetVelocity() / 1200; break; } //Lightning
		case 3: {Knockbackstep = FVector(0,0,0); break; } //Death
		case 4: {Knockbackstep = this->GetVelocity() / 450;  break; } //Ice
		default:
			break;
	}
	
	if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {

		if (targethit == CustomOwner)
		{
			Destroy();
		}
		else 
		//more complex damage inflicting mechanisms can be implemented
		{ 
			targethit->TakeDmg(
				Cast<AMyCharacter>(CustomOwner)->AtkDebuffMultiplier 
				* 15.0f 
				* Cast<AMyCharacter>(CustomOwner)->MyAffinity->GetAtkDmgMultiplier()
			);
			UWorld* const World = GetWorld();
			FTimerDelegate TimerDel;
			TimerDel.BindUFunction(this, FName("Knockback"), targethit);
			World->GetTimerManager().SetTimer(KnockbackTimerHandle, TimerDel, 0.01f, true, 0.f);
		}
		// deactivating fireball immediately, it only hits once
		this->SetActorHiddenInGame(true);
		this->SetActorEnableCollision(false);
		
	} 
	else 
	{ //should spawn a explosion effect to be implemented
		Destroy(); 
	}
	
}

void AFireball::Knockback(AMyCharacter* InflictedTarget)
{
	//possible to do AOE this way as well, but right now we're just doing single target
	InflictedTarget->AddActorWorldOffset(Knockbackstep / InflictedTarget->MyAffinity->GetMomentumResistanceMultiplier());

	if (increments >= 100)
	{
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
		UWorld* const World = GetWorld();
		World->GetTimerManager().ClearTimer(KnockbackTimerHandle);
		Destroy();
	}
	increments++;
}
