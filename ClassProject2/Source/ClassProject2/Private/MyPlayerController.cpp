// Fill out your copyright notice in the Description page of Project Settings.

#include "ClassProject2.h"
#include "MyPlayerController.h"
#include "Public/MyCharacter.h"


AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::SetupInputComponent()
{
	// Somehow can't figure out how to transport binds here to player, guess just do those in player
	Super::SetupInputComponent();
	//InputComponent->BindAction("PauseMenu", IE_Pressed, this, &AMyPlayerController::PauseMenu);
	//InputComponent->BindAction("CharacterSheet", IE_Pressed, this, &AMyPlayerController::CharSheet);
	//InputComponent->BindAction("ScoreSheet", IE_Pressed, this, &AMyPlayerController::ScoreSheet);
}

void AMyPlayerController::PauseMenu()
{
	auto pawn = this->GetPawn();
	if (auto inner = Cast<AMyCharacter>(pawn))
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT(">>>"));
		inner->InGameMenuOn = inner->InGameMenuOn ? true : false;
	}
}

void AMyPlayerController::CharSheet()
{
	auto pawn = this->GetPawn();
	if (auto inner = Cast<AMyCharacter>(pawn))
	{
		inner->CharacterSheetOn = inner->CharacterSheetOn ? true : false;
	}
}

void AMyPlayerController::ScoreSheet()
{
	auto pawn = this->GetPawn();
	if (auto inner = Cast<AMyCharacter>(pawn))
	{
		inner->ScoreSheetOn = inner->ScoreSheetOn ? true : false;
	}
}