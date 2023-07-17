// Copyright Epic Games, Inc. All Rights Reserved.

#include "testEcsGameMode.h"
#include "testEcsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AtestEcsGameMode::AtestEcsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
