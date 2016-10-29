// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ClassProject2.h"
#include "ClassProject2GameMode.h"
#include "MyCharacter.h"

AClassProject2GameMode::AClassProject2GameMode()
{
	// set default pawn class to MyCharacter
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	// if (PlayerPawnBPClass.Class != NULL)
	// {
	// 	DefaultPawnClass = PlayerPawnBPClass.Class;
	// } else 
	// {
		DefaultPawnClass = AMyCharacter::StaticClass();
	//}
}
