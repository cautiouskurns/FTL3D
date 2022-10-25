// Copyright Epic Games, Inc. All Rights Reserved.

#include "FTL3DGameMode.h"
#include "FTL3DPlayerController.h"
#include "FTL3DCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFTL3DGameMode::AFTL3DGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AFTL3DPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}