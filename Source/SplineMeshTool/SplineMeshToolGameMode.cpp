// Copyright Epic Games, Inc. All Rights Reserved.

#include "SplineMeshToolGameMode.h"
#include "SplineMeshToolCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASplineMeshToolGameMode::ASplineMeshToolGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
