// Copyright Epic Games, Inc. All Rights Reserved.

#include "WesturnMathBattleGameMode.h"
#include "WesturnMathBattleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWesturnMathBattleGameMode::AWesturnMathBattleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
