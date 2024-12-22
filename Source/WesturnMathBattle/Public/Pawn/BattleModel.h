// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BattleModel.generated.h"

UCLASS()
class WESTURNMATHBATTLE_API ABattleModel : public APawn
{
	GENERATED_BODY()

public:
	ABattleModel();

	UFUNCTION()
	virtual void CharacterSelect();

	UFUNCTION()
	virtual void SkillSelect();

	UFUNCTION()
	virtual void Back();


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
