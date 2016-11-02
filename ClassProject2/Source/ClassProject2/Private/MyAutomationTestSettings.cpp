// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "MyAutomationTestSettings.h"
#include "AutomationTest.h"
#include "ClassProject2GameMode.h"
#include "GameFramework/InputSettings.h"
#include "public/MyCharacter.h"



IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterTest, "MyCharacter.SetHP", EAutomationTestFlags::EditorContext |EAutomationTestFlags::EngineFilter)
bool FMyCharacterTest::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->SetHP(50);
		TestEqual(TEXT("Default health"), t->GetHP(), 100.f);
		t->Destroy();
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
