// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#define CAMERA_CHANGETIME_NONSELECT 0.2f
#define CAMERA_CHANGETIME_SELECT 0.15f


UENUM(BlueprintType) 
enum class EBattleInput : uint8 
{
    EBI_None,
    EBI_SelectCharacter,
    EBI_SelectSkill,
    EBI_SelectItem,
    EBI_SelectTarget,
    EBI_Max

};