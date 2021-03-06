// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "public/Safevolume.h"
#include "public/MyCharacter.h"


// Sets default values
ASafevolume::ASafevolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ShrinkLevel = 0;
	ZoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZoneMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mmesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (mmesh.Object)
	{	
		
		ZoneMesh->SetStaticMesh(mmesh.Object);
		ZoneMesh->SetWorldScale3D(FVector(65, 65, 5));
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> mmaterial(TEXT("Material'/Engine/BufferVisualization/Specular.Specular'"));
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

	//Start shrinking logic

	UWorld* const World = GetWorld();
	World->GetTimerManager().SetTimer(ShrinkTimer,this, &ASafevolume::Shrink, 15.0f, true, 0.f);

}

// Called every frame
void ASafevolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called when character exit safezone
void ASafevolume::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) 
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Taking Damage!"));
		targethit->TakingForceFieldDamage(true);
	}
}

// Called when character reenters safezone
// need all characters to be spawned inside safezone
void ASafevolume::OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UWorld* const World = GetWorld();
	if (AMyCharacter* targethit = Cast<AMyCharacter>(OtherActor)) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Safe!"));
		targethit->TakingForceFieldDamage(false);
	}
}

void ASafevolume::Shrink() {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("SafeZone Shrinked!"));
	ZoneMesh->SetWorldScale3D(FVector(65-ShrinkLevel*11, 65-ShrinkLevel*11, 5)); //nerfing 20% to ~17%, 20% of the original is a bit too small
	if (ShrinkLevel == 4) {
		UWorld* const World = GetWorld();
		World->GetTimerManager().ClearTimer(ShrinkTimer);
	}
	ShrinkLevel++;
}