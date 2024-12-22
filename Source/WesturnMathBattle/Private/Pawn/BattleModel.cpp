// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/BattleModel.h"
#include "WesturnMathBattle/WesturnMathBattle.h"
#include "Character/BattleCharacter.h"
#include "Controller/BattlePlayerController.h"

// Sets default values
ABattleModel::ABattleModel()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABattleModel::ChangeFocusCharacterBefore()
{
	currentFocusIndex--;
	currentFocusIndex = FMath::Clamp(currentFocusIndex, 0, battleCharactersArray.Num()-1);
	battleController->ChangePlayerCamera(battleCharactersArray[currentFocusIndex]);
}

void ABattleModel::ChangeFocusCharacterAfter()
{
	currentFocusIndex++;
	currentFocusIndex = FMath::Clamp(currentFocusIndex, 0, battleCharactersArray.Num() - 1);
	battleController->ChangePlayerCamera(battleCharactersArray[currentFocusIndex]);
}

void ABattleModel::CharacterSelect()
{
	if (battleCharactersArray.Num() > currentFocusIndex && battleController)
	{
		battleCharactersArray[currentFocusIndex]->SelectedByModel();
		battleController->SetInputBlockTimer(CAMERA_CHANGETIME_SELECT);
	}
	
}

void ABattleModel::SkillSelect()
{
	if (battleCharactersArray.Num() > 0)
	{
		battleCharactersArray[currentFocusIndex]->SelectSkill();
	}
	
}

void ABattleModel::Back()
{
	if (battleCharactersArray.Num() > currentFocusIndex && battleController)
	{
		battleCharactersArray[currentFocusIndex]->Back();
		battleController->SetInputBlockTimer(CAMERA_CHANGETIME_SELECT);

	}
}

void ABattleModel::AddBattleCharacter(ABattleCharacter* battleCharacter)
{
	battleCharactersArray.Add(battleCharacter);
}

void ABattleModel::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABattleModel::PossessedBy(AController* NewController)
{
	APawn::PossessedBy(NewController);
	battleController = Cast<ABattlePlayerController>(NewController);
}

void ABattleModel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


