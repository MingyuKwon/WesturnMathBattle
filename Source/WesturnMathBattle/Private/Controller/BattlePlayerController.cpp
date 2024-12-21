// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/BattlePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"


void ABattlePlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ABattlePlayerController::ChangeInputContext(EBattleInput battleInput)
{
	switch (battleInput)
	{
	case EBattleInput::EBI_None:
		break;
	case EBattleInput::EBI_SelectCharacter:
		if (Subsystem)
		{
			Subsystem->AddMappingContext(IMC_SelectCharacter, 0);
		}

		if (EnhancedInputComponent) {

			EnhancedInputComponent->BindAction(OkAction, ETriggerEvent::Started, this, &ThisClass::OnCharacterSelectAction);
			EnhancedInputComponent->BindAction(BackAction, ETriggerEvent::Started, this, &ThisClass::OnBackAction);
		}
		break;
	case EBattleInput::EBI_SelectSkill:
		break;
	case EBattleInput::EBI_SelectItem:
		break;
	case EBattleInput::EBI_SelectTarget:
		break;
	case EBattleInput::EBI_Max:
		break;
	default:
		break;
	}
}

void ABattlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	ChangeInputContext(EBattleInput::EBI_SelectCharacter);
}

void ABattlePlayerController::OnCharacterSelectAction()
{
	UE_LOG(LogTemp, Display, TEXT("OnCharacterSelectAction"));
}

void ABattlePlayerController::OnSkillSelectAction()
{
	UE_LOG(LogTemp, Display, TEXT("OnSkillSelectAction"));
}

void ABattlePlayerController::OnBackAction()
{
	UE_LOG(LogTemp, Display, TEXT("OnBackAction"));
}


