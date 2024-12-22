// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/BattlePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Pawn/BattleModel.h"
#include "InputActionValue.h"


void ABattlePlayerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
	currentPossessBattleModel = Cast<ABattleModel>(pawn);
}

void ABattlePlayerController::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, [this]()
		{
			UE_LOG(LogTemp, Warning, TEXT("Battle Start"));
			ChangeInputContext(EBattleInput::EBI_SelectCharacter);
		}, 2.f, false);

}

void ABattlePlayerController::AddBattleCharacter(ABattleCharacter* battleCharacter)
{
	if (currentPossessBattleModel)
	{
		currentPossessBattleModel->AddBattleCharacter(battleCharacter);
	}
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
			Subsystem->RemoveMappingContext(IMC_SelectSkill);
			Subsystem->AddMappingContext(IMC_SelectCharacter, 0);
		}

		if (EnhancedInputComponent) {
			EnhancedInputComponent->ClearActionBindings();
			EnhancedInputComponent->BindAction(OkAction, ETriggerEvent::Started, this, &ThisClass::OnCharacterSelectAction);
			EnhancedInputComponent->BindAction(BackAction, ETriggerEvent::Started, this, &ThisClass::OnBackAction);
		}
		break;
	case EBattleInput::EBI_SelectSkill:

		if (EnhancedInputComponent) {
			EnhancedInputComponent->ClearActionBindings();
			EnhancedInputComponent->BindAction(OkAction, ETriggerEvent::Started, this, &ThisClass::OnSkillSelectAction);
			EnhancedInputComponent->BindAction(BackAction, ETriggerEvent::Started, this, &ThisClass::OnBackAction);
		}
		
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

	
}

void ABattlePlayerController::OnCharacterSelectAction()
{
	if (currentPossessBattleModel)
	{
		currentPossessBattleModel->CharacterSelect();
	}
}

void ABattlePlayerController::OnSkillSelectAction()
{
	if (currentPossessBattleModel)
	{
		currentPossessBattleModel->SkillSelect();
	}
}

void ABattlePlayerController::OnBackAction()
{
	if (currentPossessBattleModel)
	{
		currentPossessBattleModel->Back();
	}
}


