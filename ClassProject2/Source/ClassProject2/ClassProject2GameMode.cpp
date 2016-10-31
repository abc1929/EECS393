// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ClassProject2.h"
#include "ClassProject2GameMode.h"
#include "public/MyCharacter.h"

AClassProject2GameMode::AClassProject2GameMode()
{	
	DefaultPawnClass = AMyCharacter::StaticClass();
}
