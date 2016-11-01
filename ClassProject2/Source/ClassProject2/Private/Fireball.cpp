// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "public/Fireball.h"
#include "public/MyCharacter.h"


// Sets default cas
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
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mmesh(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	if (mmesh.Object) 
	{
		FireballMesh->SetStaticMesh(mmesh.Object);
		FireballMesh->SetWorldScale3D(FVector(0.5f));
		FireballMesh->SetRelativeLocation(FVector(0.0f, 0.0f,0.f));
		static ConstructorHelpers::FObjectFinder<UMaterial> grime(TEXT("Material'/Game/StarterContent/Materials/M_Concrete_Grime.M_Concrete_Grime'"));
		if (grime.Object)
			FireballMesh->SetMaterial(0,grime.Object);
	}

	//Fire
	Firetrail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireTrail"));
	Firetrail->SetupAttachment(FireballMesh);
	Firetrail->bAutoActivate = true;
	Firetrail->SetRelativeLocation(FVector(0.0f, 0.0f, 35.0f));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleAsset.Succeeded())
	{
		Firetrail->SetTemplate(ParticleAsset.Object);
		Firetrail->SetWorldScale3D(FVector(1.2f));
	}


	//Movement
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collision;
	Movement->InitialSpeed = 800.f;
	Movement->MaxSpeed = 800.f;
	Movement->bRotationFollowsVelocity = false;
	Movement->ProjectileGravityScale = 0.01;

	//TArray<TSharedPtr<FName>> CollisionList;
	//UCollisionProfile::Get()->GetProfileNames(CollisionList);
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Collision->SetNotifyRigidBodyCollision(true);
	Collision->OnComponentHit.AddDynamic(this, &AFireball::OnHit);


	//Knockback variables
	increments = 0;
	CastTime = 1.2f;
}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();
	this->SetLifeSpan(20.f);
}

// Called every frame
void AFireball::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AFireball::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	Knockbackstep = this->GetVelocity()/300;
	if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {

		if (targethit == GetOwner())
		{
			Destroy();
		}
		else 
		//more complex damage inflicting mechanisms can be implemented
		{ 
			targethit->SetHP(targethit->GetHP() - 15.0f);
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

void AFireball::Knockback(AActor* InflictedTarget)
{
	//possible to do AOE this way as well, but right now we're just doing single target
	InflictedTarget->AddActorWorldOffset(Knockbackstep);

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
