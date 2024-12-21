// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

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