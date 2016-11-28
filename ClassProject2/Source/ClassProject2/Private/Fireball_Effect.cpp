// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassProject2.h"
#include "Fireball_Effect.h"


AFireball_Effect::AFireball_Effect(const class FObjectInitializer& ObjectInitializer) : AAbilityEffect(ObjectInitializer){
	;
}

void AFireball_Effect::BeginPlay() {
	Super::BeginPlay();
	//now think of it the residual effect shall not be affected by the situation
	//where the caster's affinities got weakened during the timespan
	//that is the abilities should snapshot MyAffinity rather than accessing it in realtime
	//but I guess we're not worrying about this currently

	Affin = CustomOwner->MyAffinity->GetProcessedElementAffinities();
	
	PrimaryAffin = CustomOwner->MyAffinity->PrimaryElementalPrefix;

}


//0:burn+def weak; 1:stun+movslow; 2:ministun+drain; 3:drain,def weak 4:atk&movslow+atk weak
//2's drain doesn't behave like leech, while 3 does


//does the fireball do any residual DoT ?
float AFireball_Effect::dmgCurve(float t) 
{ 

	
	//also make effect on Target
}




//not used currently
FVector AFireball_Effect::mmtCurve(float t){ return FVector(0,0,0); }


float AFireball_Effect::stamdrainCurve(float t) { return 1.f; }

float AFireball_Effect::movSlowCurve(float t){ return 1.f; }
bool AFireball_Effect::stunCurve(float t){ return 1.f; }
float AFireball_Effect::atkSlowCurve(float t){ return 1.f; }

float AFireball_Effect::defWeakenCurve(float t) { return 1.f; }
float AFireball_Effect::atkWeakenCurve(float t) { return 1.f; }


void AFireball_Effect::applydmg(float start, float end, float d, int n)
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(dmgCurveTimerHandler);
		break;
	}
	TimerDel.BindUFunction(this,"applydmg", start, end ,d, n+1); //determining d manually
	Target->TakeDmg(dmgCurve(n*d));
	World->GetTimerManager().SetTimer(dmgCurveTimerHandler, TimerDel, d, false, -d); 	
}

void AFireball_Effect::applystamdrain()
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(stamdrainCurveTimerHandler);
		break;
	}
	TimerDel.BindUFunction(this,"applystamdrain", start, end ,d, n+1); //determining d manually
	Target->StaminaIncrease(-stamdrainCurve(n*d));
	CustomOwner->StaminaIncrease(dlratio*stamdrainCurve(n*d)); //could be 0
	World->GetTimerManager().SetTimer(stamdrainCurveTimerHandler, TimerDel, d, false, -d); 	
}
void AFireball_Effect::applymovslow()
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(movSlowCurveTimerHandler);
		break;
	}
	TimerDel.BindUFunction(this,"applymovslow", start, end ,d, n+1); //determining d manually
	Target->TakeDmg(movSlowCurve(n*d));//add another parameter for MyChar I guess;
	World->GetTimerManager().SetTimer(movSlowCurveTimerHandler, TimerDel, d, false, -d); 	
}
void AFireball_Effect::applystun()
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(stunCurveTimerHandler);
		break;
	}
	TimerDel.BindUFunction(this,"applydmg", start, end ,d, n+1); //determining d manually
	Target->TakeDmg(dmgCurve(n*d));
	World->GetTimerManager().SetTimer(stunCurveTimerHandler, TimerDel, d, false, -d); 	
}
void AFireball_Effect::applyatkslow()
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(atkSlowCurveTimerHandler);
		break;
	}
	TimerDel.BindUFunction(this,"applydmg", start, end ,d, n+1); //determining d manually
	Target->TakeDmg(dmgCurve(n*d));
	World->GetTimerManager().SetTimer(atkSlowCurveTimerHandler, TimerDel, d, false, -d); 	
}
void AFireball_Effect::applydefweak()
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(defWeakenCurveTimerHandler);
		break;
	}
	TimerDel.BindUFunction(this,"applydmg", start, end ,d, n+1); //determining d manually
	Target->TakeDmg(dmgCurve(n*d));
	World->GetTimerManager().SetTimer(defWeakenCurveTimerHandler, TimerDel, d, false, -d); 	
}
void AFireball_Effect::applyatkweak()
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(atkWeakenCurveTimerHandler);
		break;
	}
	TimerDel.BindUFunction(this,"applydmg", start, end ,d, n+1); //determining d manually
	Target->TakeDmg(dmgCurve(n*d));
	World->GetTimerManager().SetTimer(atkWeakenCurveTimerHandler, TimerDel, d, false, -d); 	
}


//A timer spawns for each effect at its TimeInterval; do increment tracks for each? functionally

void ApplyAll()
{
;
	
}