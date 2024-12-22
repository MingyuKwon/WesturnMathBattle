// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/BattleCharacterInterface.h"
#include "BattleCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;


UCLASS()
class WESTURNMATHBATTLE_API ABattleCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABattleCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SelectCameraSpring;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* SelectCamera;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SelectedByModel();

	virtual void SelectSkill();


};
