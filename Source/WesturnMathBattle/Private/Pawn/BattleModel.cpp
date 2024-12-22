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
	battleController->ChangePlayerCamera(battleCharactersArray[0]);
}

void ABattleModel::ChangeFocusCharacterAfter()
{
	battleController->ChangePlayerCamera(battleCharactersArray[1]);
}

void ABattleModel::CharacterSelect()
{
	if (battleCharactersArray.Num() > 0)
	{
		battleCharactersArray[0]->SelectedByModel();
	}
	
}

void ABattleModel::SkillSelect()
{
	if (battleCharactersArray.Num() > 0)
	{
		battleCharactersArray[0]->SelectSkill();
	}
	
}

void ABattleModel::Back()
{
	if (battleCharactersArray.Num() > 1)
	{
		battleCharactersArray[0]->Back();

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


