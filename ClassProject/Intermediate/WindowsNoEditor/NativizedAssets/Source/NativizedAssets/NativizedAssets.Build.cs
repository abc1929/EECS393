// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class NativizedAssets : ModuleRules
{
	public NativizedAssets(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "Engine", "ClassProject" });

		PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "ClassProject", "InputCore", "UMG", "AnimGraphRuntime", "SlateCore" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
