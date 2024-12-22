// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/BattleModel.h"
#include "Character/BattleCharacter.h"
#include "Controller/BattlePlayerController.h"

// Sets default values
ABattleModel::ABattleModel()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABattleModel::CharacterSelect()
{
	if (battleCharactersArray.Num() > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Model :: CharacterSelect"));
		battleCharactersArray[0]->SelectedByModel();
		battleController->SetViewTargetWithBlend(battleCharactersArray[0], 0.3f, EViewTargetBlendFunction::VTBlend_Cubic);
	}
	
}

void ABattleModel::SkillSelect()
{
	if (battleCharactersArray.Num() > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Model :: SkillSelect"));
		battleCharactersArray[0]->SelectSkill();
	}
	
}

void ABattleModel::Back()
{
	if (battleCharactersArray.Num() > 1)
	{
		UE_LOG(LogTemp, Display, TEXT("Model :: Back"));
		battleController->SetViewTargetWithBlend(battleCharactersArray[1], 0.3f, EViewTargetBlendFunction::VTBlend_Cubic);

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


