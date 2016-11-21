// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "MyAutomationTestSettings.h"
#include "AutomationTest.h"
#include "ClassProject2GameMode.h"
#include "GameFramework/InputSettings.h"
#include "public/MyCharacter.h"
#include "public/MyElementalAffinity.h"



IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterTest, "MyCharacter.SetHP", EAutomationTestFlags::EditorContext |EAutomationTestFlags::EngineFilter)
bool FMyCharacterTest::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->SetHP(50);
		TestNotEqual(TEXT("Default health"), t->GetHP(), 100.f);
		t->Destroy();
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test, "MyCharacter.Affinity", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 1);
		TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		TestNotEqual(TEXT("MaxHealth Buffed"), t->GetMaxHP(), 100.f);
		t->MyAffinity->UpdateElements(4, 2);
		TestEqual(TEXT("Prefix changed again"), t->MyAffinity->GetAbilityElementalPrefix(), 21);
		t->MyAffinity->UpdateElements(9, 2);
		TestEqual(TEXT("Prefix changed to singular"), t->MyAffinity->GetAbilityElementalPrefix(), 2);
		TestNotEqual(TEXT("CritChanceMultiplier changed to " + FString::SanitizeFloat(t->GetCritChanceMultiplier())), t->GetCritChanceMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin2Test, "MyCharacter.Affinity_2", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin2Test::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(2, 0);
		TestEqual(TEXT("Prefix changed" + FString::FromInt(t->MyAffinity->GetAbilityElementalPrefix())), t->MyAffinity->GetAbilityElementalPrefix(), 0);
		t->MyAffinity->UpdateElements(1, 3);
		TestEqual(TEXT("Prefix Not changed, primary element not high enough"), t->MyAffinity->GetAbilityElementalPrefix(), 0);
		t->Destroy();
	}

	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAffinityTest, "MyElementalAffinity.AffinityCalculation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FAffinityTest::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		//testing penalty
		auto s = NewObject<AMyCharacter>();
		s->MyAffinity->UpdateElements(4, 1);
		s->MyAffinity->UpdateElements(5, 2);
		TestTrue(FString::SanitizeFloat(s->MyAffinity->GetProcessedElementAffinities()[2]),s->MyAffinity->GetProcessedElementAffinities()[2] < 5);
		s->Destroy();
	}

	return true;
}


// void FCustomTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray <FString>& OutTestCommands) const
// {

// }

// bool FCustomTest::RunTest(const FString& Parameters)
// {
// 	return true;
// }
