// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "Fireball.h"


// Sets default values
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
	if (mmesh.Object) {
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

	TArray<TSharedPtr<FName>> CollisionList;
	UCollisionProfile::Get()->GetProfileNames(CollisionList);
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Collision->SetNotifyRigidBodyCollision(true);
	Collision->OnComponentHit.AddDynamic(this, &AFireball::OnHit);



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


void AFireball::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	UE_LOG(LogTemp, Warning, TEXT("OnMyActorHit worked!"));
	Destroy();
}