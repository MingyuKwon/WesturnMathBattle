// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WesturnMathBattle/WesturnMathBattle.h"
#include "Character/BattleCharacter.h"
#include "BattlePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputLocalPlayerSubsystem;
class UEnhancedInputComponent;
class APawn;
class ABattleModel;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class WESTURNMATHBATTLE_API ABattlePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void AddBattleCharacter(ABattleCharacter* battleCharacter);

	virtual void ChangePlayerCamera(AActor* actor);

protected:

	//////////////////////////////////////////////////////////////////////////////// for input system
	EBattleInput currentBattleInput;

	UPROPERTY()
	UEnhancedInputLocalPlayerSubsystem* Subsystem;
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent;

	UFUNCTION(BlueprintCallable)
	void ChangeInputContext(EBattleInput battleInput);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* IMC_SelectCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* IMC_SelectSkill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* OkAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* BackAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LBAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RBAction;


	virtual void SetupInputComponent() override;
	void OnCharacterSelectAction(); 
	void OnSkillSelectAction();
	void OnBackAction(); 
	void OnLBAction();
	void OnRBAction();
	//////////////////////////////////////////////////////////////////////////////// for input system

	UPROPERTY()
	ABattleModel* currentPossessBattleModel = nullptr;

	virtual void OnPossess(APawn* pawn) override;

	virtual void BeginPlay() override; 

 
};
