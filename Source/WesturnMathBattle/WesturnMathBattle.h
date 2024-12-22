// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#define CAMERA_CHANGETIME_NONSELECT 0.2f
#define CAMERA_CHANGETIME_SELECT 0.3f


UENUM(BlueprintType) 
enum class EBattleInput : uint8 
{
    EBI_None = 0,
    EBI_SelectCharacter = 1,
    EBI_SelectSkill = 2,
    EBI_SelectItem = 3,
    EBI_SelectTarget = 4,
    EBI_Max=5

};