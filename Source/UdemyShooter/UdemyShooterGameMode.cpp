// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UdemyShooterGameMode.h"
#include "UdemyShooterHUD.h"
#include "UdemyShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUdemyShooterGameMode::AUdemyShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUdemyShooterHUD::StaticClass();
}
