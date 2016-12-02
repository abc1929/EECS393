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

	dlratio = (Affin[3]+Affin[2]) > 0 ? Affin[3]/(Affin[3]+Affin[2]) : 0.f;

}


//0:burn+def weak; 1:stun+movslow; 2:ministun+drain; 3:drain,def weak 4:atk&movslow+atk weak
//2's drain doesn't behave like leech, while 3 does

//88888

//does the fireball do any residual DoT ?
// just linear ramp down
float AFireball_Effect::dmgCurve(float t) 
{ 
	return Affin[0] / 8; 
	//also make effect on Target
}




//not used currently
FVector AFireball_Effect::mmtCurve(float t){ return FVector(0,0,0); }


float AFireball_Effect::stamdrainCurve(float t) 
{
	 return 1.f; 
}
 // float


float AFireball_Effect::movSlowCurve(float t)
{
	 return 1.f; 
}
 //this is less than 1 : %
// 0.9 to reduce to 90% of the movement speed

bool AFireball_Effect::stunCurve(float t)
{
	 return 1.f; 
}
 //this will be a step func

float AFireball_Effect::atkSlowCurve(float t)
{
	 return 1.f; 
}
 //this is less than 1 : %


float AFireball_Effect::defWeakenCurve(float t) 
{
	 return 1.f; 
}
 //this is less than 1 : %

float AFireball_Effect::atkWeakenCurve(float t) 
{
	 return 1.f; 
}
 //this is less than 1 : %




// I'm not sure if those can be written in the parent class
// right now just copy those for each effect files
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

void AFireball_Effect::applystamdrain(float start, float end, float d, int n)
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

void AFireball_Effect::applystun(float start, float end, float d, int n)
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(stunCurveTimerHandler);
		Target->SetStun(false);
		break;
	}
	TimerDel.BindUFunction(this,"applystun", start, end ,d, n+1); //determining d manually
	if(stunCurve(n*d)) {Target->SetStun(true);}
	World->GetTimerManager().SetTimer(stunCurveTimerHandler, TimerDel, d, false, -d); 	
}

void AFireball_Effect::applymovslow(float start, float end, float d, int n)
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(movSlowCurveTimerHandler);
		Target->SetMovementSpeedDebuffMultiplier(1.f); // reset back to default base speed
		break;
	}
	TimerDel.BindUFunction(this,"applymovslow", start, end ,d, n+1); //determining d manually
	//Target->TakeDmg(movSlowCurve(n*d));//add another parameter for MyChar I guess;
	Target->SetMovementSpeedDebuffMultiplier(movSlowCurve(n*d));
	World->GetTimerManager().SetTimer(movSlowCurveTimerHandler, TimerDel, d, false, -d); 	
}

void AFireball_Effect::applyatkslow(float start, float end, float d, int n)
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(atkSlowCurveTimerHandler);
		Target->SetAttackSpeedDebuffMultiplier(1.f);
		break;
	}
	TimerDel.BindUFunction(this,"applyatkslow", start, end ,d, n+1); //determining d manually
	Target->SetAttackSpeedDebuffMultiplier(atkSlowCurve(n*d));
	World->GetTimerManager().SetTimer(atkSlowCurveTimerHandler, TimerDel, d, false, -d); 	
}

void AFireball_Effect::applydefweak(float start, float end, float d, int n)
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(defWeakenCurveTimerHandler);
		Target->SetDefenseDebuffMultiplier(1.f);
		break;
	}
	TimerDel.BindUFunction(this,"applydefweak", start, end ,d, n+1); //determining d manually
	Target->SetDefenseDebuffMultiplier(defWeakenCurve(n*d));
	World->GetTimerManager().SetTimer(defWeakenCurveTimerHandler, TimerDel, d, false, -d); 	
}

void AFireball_Effect::applyatkweak(float start, float end, float d, int n)
{
	UWorld* const World = GetWorld();
	FTimerDelegate TimerDel;
	if(start>=end)
	{
		World->GetTimerManager().ClearTimer(atkWeakenCurveTimerHandler);
		Target->SetAttackDmgDebuffMultiplier(1.0f);
		break;
	}
	TimerDel.BindUFunction(this,"applyatkweak", start, end ,d, n+1); //determining d manually
	Target->SetAttackDmgDebuffMultiplier(atkWeakenCurve(n*d));
	World->GetTimerManager().SetTimer(atkWeakenCurveTimerHandler, TimerDel, d, false, -d); 	
}


//A timer spawns for each effect at its TimeInterval; do increment tracks for each? functionally

void ApplyAll()
{
	applydmg(0, 2, 0.2, 0); //let basic attack's effect last 2 seconds
	
}