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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterTest2, "MyCharacter.SetHP_2", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterTest2::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		TestEqual(TEXT("Default health"), t->GetHP(), 100.f);
		t->Destroy();
	}

	return true;
}

//testing if set to 100 edge case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterTest3, "MyCharacter.SetHP_3", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterTest3::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->SetHP(100.f);
		TestEqual(TEXT("Default health"), t->GetHP(), 100.f);
		t->Destroy();
	}

	return true;
}
//testing the reassignment is 50
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterTest4, "MyCharacter.SetHP_4", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterTest4::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->SetHP(50.f);
		TestEqual(TEXT("Default health"), t->GetHP(), 50.f);
		t->Destroy();
	}

	return true;
}

//edge case of 0 test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterTest5, "MyCharacter.SetHP_5", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterTest5::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->SetHP(0.f);
		TestEqual(TEXT("Default health"), t->GetHP(), 0.f);
		t->Destroy();
	}

	return true;
}

//checking that the prefix element changed from default (0)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test1, "MyCharacter.Affinity1", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test1::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 1);
		TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		t->Destroy();
	}

	return true;
}
//checking that health buff changed
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test2, "MyCharacter.Affinity2", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test2::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 1);
		TestNotEqual(TEXT("MaxHealth Buffed"), t->GetMaxHP(), 100.f);
	}

	return true;
}
//testing double prefix case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test3, "MyCharacter.Affinity3", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test3::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(5, 1);
		//TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		TestNotEqual(TEXT("MaxHealth Buffed"), t->GetMaxHP(), 100.f);
		t->MyAffinity->UpdateElements(5, 3);
		TestEqual(TEXT("Prefix changed again"), t->MyAffinity->GetAbilityElementalPrefix(), 31);

	}

	return true;
}
//testing a double prefix edge case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test4, "MyCharacter.Affinity4", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test4::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 1);
		//TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		TestNotEqual(TEXT("MaxHealth Buffed"), t->GetMaxHP(), 100.f);
		t->MyAffinity->UpdateElements(10, 2);
		TestEqual(TEXT("Prefix changed again"), t->MyAffinity->GetAbilityElementalPrefix(), 21);

	}

	return true;
}

//testing reverting back to a single prefix
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test5, "MyCharacter.Affinity5", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test5::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 3);
		TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 3);
		t->MyAffinity->UpdateElements(4, 2);
		TestEqual(TEXT("Prefix changed again"), t->MyAffinity->GetAbilityElementalPrefix(), 32);
		t->MyAffinity->UpdateElements(9, 2);
		TestEqual(TEXT("Prefix changed to singular"), t->MyAffinity->GetAbilityElementalPrefix(), 2);
		t->Destroy();
	}

	return true;
}

//testing reverting back to a single prefix edge
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test5b, "MyCharacter.Affinity5b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test5b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 3);
		TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 3);
		t->MyAffinity->UpdateElements(4, 0);
		TestEqual(TEXT("Prefix changed again"), t->MyAffinity->GetAbilityElementalPrefix(), 30);
		t->MyAffinity->UpdateElements(9, 0);
		TestEqual(TEXT("Prefix changed to singular"), t->MyAffinity->GetAbilityElementalPrefix(), 0);
		t->Destroy();
	}

	return true;
}
//testing that the crit multiplyer changed from lighting affinity
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test6, "MyCharacter.Affinity6", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test6::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 2);
		t->MyAffinity->UpdateElements(9, 2);
		TestNotEqual(TEXT("CritChanceMultiplier changed to " + FString::SanitizeFloat(t->GetCritChanceMultiplier())), t->GetCritChanceMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}


//Testing hp multiplier is correctly changing for earth
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test7, "MyCharacter.Affinity7", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test7::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 1);
		TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		t->MyAffinity->UpdateElements(4, 2);
		t->MyAffinity->UpdateElements(10, 1);
		TestNotEqual(TEXT("HPMultiplier changed to " + FString::SanitizeFloat(t->GetHPMultiplier())), t->GetHPMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}

//Hp mult edge case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test7b, "MyCharacter.Affinity7b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test7b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 1);
		TestEqual(TEXT("GetHPMultiplier changed to " + FString::SanitizeFloat(t->GetHPMultiplier())), t->GetHPMultiplier(), 1.8f);
		t->Destroy();
	}

	return true;
}

//Testing move mult from fire
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test8, "MyCharacter.Affinity8", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test8::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 0);
		t->MyAffinity->UpdateElements(10, 0);
		TestNotEqual(TEXT("SpeedMultiplier changed to " + FString::SanitizeFloat(t->GetMovSpeedMultiplier())), t->GetMovSpeedMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}

//Testing move mult from fire
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test8b, "MyCharacter.Affinity8b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test8b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 0);
		TestEqual(TEXT("SpeedMultiplier changed to " + FString::SanitizeFloat(t->GetMovSpeedMultiplier())), t->GetMovSpeedMultiplier(), 1.2f);
		t->Destroy();
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test9, "MyCharacter.Affinity9", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test9::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 1);
		TestEqual(TEXT("Prefix changed"), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		t->MyAffinity->UpdateElements(4, 3);
		t->MyAffinity->UpdateElements(9, 3);
		TestNotEqual(TEXT("DamageMultiplier changed to " + FString::SanitizeFloat(t->GetAtkDmgMultiplier())), t->GetAtkDmgMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test9b, "MyCharacter.Affinity9b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test9b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 3);
		TestEqual(TEXT("DamageMultiplier changed to " + FString::SanitizeFloat(t->GetAtkDmgMultiplier())), t->GetAtkDmgMultiplier(), 1.5f);
		t->Destroy();
	}

	return true;
}

//earth defense mult test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test10, "MyCharacter.Affinity10", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test10::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 1);
		t->MyAffinity->UpdateElements(9, 1);
		TestEqual(TEXT("DefenseeMultiplier changed to " + FString::SanitizeFloat(t->GetDefenseMultiplier())), t->GetDefenseMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}
//earth edge case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test10b, "MyCharacter.Affinity10b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test10b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 1);
		TestNotEqual(TEXT("GetDefenseMultiplier changed to " + FString::SanitizeFloat(t->GetDefenseMultiplier())), t->GetDefenseMultiplier(), 1.8f);
		t->Destroy();
	}

	return true;
}

//ice stam regen test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test11, "MyCharacter.Affinity11", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test11::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 4);
		t->MyAffinity->UpdateElements(9, 4);
		TestNotEqual(TEXT("GetStamRegenMultiplier changed to " + FString::SanitizeFloat(t->GetStamRegenMultiplier())), t->GetStamRegenMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}
//stam regen edge case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test11b, "MyCharacter.Affinity11b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test11b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 4);
		TestEqual(TEXT("GetStamRegenMultiplier changed to " + FString::SanitizeFloat(t->GetStamRegenMultiplier())), t->GetStamRegenMultiplier(), 1.5f);
		t->Destroy();
	}

	return true;
}

//momentum resist earth test case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test12, "MyCharacter.Affinity12", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test12::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 1);
		t->MyAffinity->UpdateElements(9, 1);
		TestNotEqual(TEXT("GetMomentumResistanceMultiplier changed to " + FString::SanitizeFloat(t->GetMomentumResistanceMultiplier())), t->GetMomentumResistanceMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}
//momentum resist edge case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test12b, "MyCharacter.Affinity12b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test12b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 1);
		TestEqual(TEXT("GetMomentumResistanceMultiplier changed to " + FString::SanitizeFloat(t->GetMomentumResistanceMultiplier())), t->GetMomentumResistanceMultiplier(), 1.2f);
		t->Destroy();
	}

	return true;
}
//attack speed multi lightning
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test13, "MyCharacter.Affinity13", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
//attack speed lightning test
bool FMyCharacterAffin1Test13::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(4, 2);
		t->MyAffinity->UpdateElements(9, 2);
		TestNotEqual(TEXT("GetAtkSpeedMultiplier changed to " + FString::SanitizeFloat(t->GetAtkSpeedMultiplier())), t->GetAtkSpeedMultiplier(), 1.0f);
		t->Destroy();
	}

	return true;
}
//attack speed edge case
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin1Test13b, "MyCharacter.Affinity13b", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin1Test13b::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 2);
		TestEqual(TEXT("GetAtkSpeedMultiplier changed to " + FString::SanitizeFloat(t->GetAtkSpeedMultiplier())), t->GetAtkSpeedMultiplier(), 1.125f);
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
		t->Destroy();
	}

	return true;
}
//failure to change prefix
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin3Test, "MyCharacter.Affinity_3", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin3Test::RunTest(const FString& Parameters)
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
//failure edge case 
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin3Test2, "MyCharacter.Affinity_32", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin3Test2::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 0);
		TestEqual(TEXT("Prefix changed" + FString::FromInt(t->MyAffinity->GetAbilityElementalPrefix())), t->MyAffinity->GetAbilityElementalPrefix(), 0);
		t->MyAffinity->UpdateElements(1, 3);
		TestEqual(TEXT("Prefix Not changed, primary element not high enough"), t->MyAffinity->GetAbilityElementalPrefix(), 0);
		t->Destroy();
	}

	return true;
}


//failure diff element case 
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin3Test3, "MyCharacter.Affinity_33", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin3Test3::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(10, 2);
		TestEqual(TEXT("Prefix changed" + FString::FromInt(t->MyAffinity->GetAbilityElementalPrefix())), t->MyAffinity->GetAbilityElementalPrefix(), 2);
		t->MyAffinity->UpdateElements(1, 3);
		TestEqual(TEXT("Prefix Not changed, primary element not high enough"), t->MyAffinity->GetAbilityElementalPrefix(), 2);
		t->Destroy();
	}

	return true;
}

//failure diff element case 
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin3Test4, "MyCharacter.Affinity_34", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin3Test4::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(9, 1);
		TestEqual(TEXT("Prefix changed" + FString::FromInt(t->MyAffinity->GetAbilityElementalPrefix())), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		t->MyAffinity->UpdateElements(3, 0);
		TestEqual(TEXT("Prefix Not changed, primary element not high enough"), t->MyAffinity->GetAbilityElementalPrefix(), 1);
		t->Destroy();
	}

	return true;
}

//failure diff element case 
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyCharacterAffin3Test5, "MyCharacter.Affinity_35", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMyCharacterAffin3Test5::RunTest(const FString& Parameters)
{
	//AddError(FString::Printf(TEXT("The testing goat says NO! Hourray! Goto coding! ")));
	// constructors must create equal objects
	{
		AMyCharacter* t = NewObject<AMyCharacter>();
		t->MyAffinity->UpdateElements(9, 4);
		TestEqual(TEXT("Prefix changed" + FString::FromInt(t->MyAffinity->GetAbilityElementalPrefix())), t->MyAffinity->GetAbilityElementalPrefix(), 4);
		t->MyAffinity->UpdateElements(2, 2);
		TestEqual(TEXT("Prefix Not changed, primary element not high enough"), t->MyAffinity->GetAbilityElementalPrefix(), 4);
		t->Destroy();
	}

	return true;
}


//suppression test
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
