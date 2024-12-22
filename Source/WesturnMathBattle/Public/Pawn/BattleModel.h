// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interface/BattleCharacterInterface.h"

#include "BattleModel.generated.h"

class ABattleCharacter;
class AController;
class ABattlePlayerController;

UCLASS()
class WESTURNMATHBATTLE_API ABattleModel : public APawn
{
	GENERATED_BODY()

public:
	ABattleModel();

	UFUNCTION()
	virtual void AddBattleCharacter(ABattleCharacter* battleCharacter);


	UFUNCTION()
	virtual void CharacterSelect();
	UFUNCTION()
	virtual void ChangeFocusCharacterBefore();
	UFUNCTION()
	virtual void ChangeFocusCharacterAfter();

	UFUNCTION()
	virtual void SkillSelect();

	UFUNCTION()
	virtual void Back();


protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

	int32 currentFocusIndex = 0;

	TArray<ABattleCharacter*> battleCharactersArray;

	UPROPERTY()
	ABattlePlayerController* battleController;

public:	
	virtual void Tick(float DeltaTime) override;

};
