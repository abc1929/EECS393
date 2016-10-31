// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "public/Safevolume.h"
#include "public/MyCharacter.h"


// Sets default values
ASafevolume::ASafevolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ZoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZoneMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mmesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (mmesh.Object)
	{
		
		ZoneMesh->SetStaticMesh(mmesh.Object);
		ZoneMesh->SetWorldScale3D(FVector(65, 65, 5));
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> mmaterial(TEXT("Material'/Engine/VREditor/WorldMovementGrid/GridMaterial.GridMaterial'"));
	if (mmaterial.Object)
	{
		 ZoneMesh->SetMaterial(0,mmaterial.Object);

	}
	ZoneMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	ZoneMesh->OnComponentBeginOverlap.AddDynamic(this, &ASafevolume::OnStartOverlapping);
	ZoneMesh->OnComponentEndOverlap.AddDynamic(this, &ASafevolume::OnComponentEndOverlap);
	ZoneMesh->bCastDynamicShadow = false;
}

// Called when the game starts or when spawned
void ASafevolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASafevolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASafevolume::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) 
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Taking Damage!"));
		targethit->TakingForceFieldDamage(true);
	}
}

void ASafevolume::OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UWorld* const World = GetWorld();
	if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Safe!"));
		targethit->TakingForceFieldDamage(false);
	}
}

