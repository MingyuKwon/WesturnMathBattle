// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BattleCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Controller/BattlePlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABattleCharacter::ABattleCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SelectCameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("SelectCameraSpring"));
	SelectCameraSpring->SetupAttachment(GetMesh());
	SelectCameraSpring->TargetArmLength = 200.0f;

	SelectCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SelectCamera"));
	SelectCamera->SetupAttachment(SelectCameraSpring, USpringArmComponent::SocketName);


}

// Called when the game starts or when spawned
void ABattleCharacter::BeginPlay()
{
	Super::BeginPlay();

	ABattlePlayerController* battlePlayerController = Cast<ABattlePlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	battlePlayerController->AddBattleCharacter(this);
}

// Called every frame
void ABattleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleCharacter::SelectedByModel()
{
	UE_LOG(LogTemp, Warning, TEXT("%s :: SelectedByModel"), *GetName());

}

void ABattleCharacter::SelectSkill()
{
	UE_LOG(LogTemp, Warning, TEXT("%s :: SelectSkill"), *GetName());

}

