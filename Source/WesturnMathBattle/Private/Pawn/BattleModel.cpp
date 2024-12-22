// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/BattleModel.h"

// Sets default values
ABattleModel::ABattleModel()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABattleModel::CharacterSelect()
{
	UE_LOG(LogTemp, Display, TEXT("Model :: CharacterSelect"));
}

void ABattleModel::SkillSelect()
{
	UE_LOG(LogTemp, Display, TEXT("Model :: SkillSelect"));
}

void ABattleModel::Back()
{
	UE_LOG(LogTemp, Display, TEXT("Model :: Back"));
}

// Called when the game starts or when spawned
void ABattleModel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleModel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


