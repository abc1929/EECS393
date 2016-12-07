// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "DefensiveAbility_BlockBase.h"
#include "Public/MyCharacter.h"

// it should just be a collision volume attached to CustomOwner
// 0: explosion (last 2 seconds and if was hit during duration, blows back to the target)
// 1: stun? not implemented ()
// 02: cleanse (last 1 seconds, block a single attack, removes all debuffs, buff owner, does dmg to owner and attack source)
// 2: recharge, (last 1.5 seconds, block a single attack,ministun, buff Owner afterwards)
// 3, and other not implemented
// 4 ice (frost armor, shield for a certain amount for like 5 seconds)


// ADefensiveAbility_BlockBase::ADefensiveAbility_BlockBase(const class FObjectInitializer& ObjectInitializer)
// {
//     PrimaryActorTick.bCanEverTick = true;

//     auto Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent_Collision"));
// 	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
// 	Collision->InitCapsuleSize(110.f, 120.0f);
// 	RootComponent = Collision;
// 	Collision->SetCollisionProfileName(TEXT("A Larger collision box compared to charcter itself"));
// 	Collision->OnComponentBeginOverlap.AddDynamic(this, &ADefensiveAbility_BlockBase::OnStartOverlapping); 
// }

// void ADefensiveAbility_BlockBase::BeginPlay() 
// {

// }


// // generic hit registry
// void ADefensiveAbility_BlockBase::OnStartOverlapping(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
//     switch (CustomOwner->MyAffinity->GetAbilityElementalPrefix())
// 		{
// 			case 0: {
//                 //
// 				break;
//             }
//             case 20: {
// 				break;
//             }
//             case 2: {
// 				break;
//             }
//             case 4: {
// 				break;
//             }
//             default: 
//                 break;
// }