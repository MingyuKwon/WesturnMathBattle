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

	NonSelectCameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("NonSelectCameraSpring"));
	NonSelectCameraSpring->SetupAttachment(GetMesh());
	NonSelectCameraSpring->TargetArmLength = 250.0f; 

	NonSelectCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("NonSelectCamera"));
	NonSelectCamera->SetupAttachment(NonSelectCameraSpring, USpringArmComponent::SocketName); 

	SelectCameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("SelectCameraSpring"));
	SelectCameraSpring->SetupAttachment(GetMesh());
	SelectCameraSpring->TargetArmLength = 200.0f;

	SelectCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SelectCamera"));
	SelectCamera->SetupAttachment(SelectCameraSpring, USpringArmComponent::SocketName);

	NonSelectCamera->bAutoActivate = true;
	SelectCamera->bAutoActivate = false;


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

	NonSelectCamera->SetActive(false);
	SelectCamera->SetActive(true);


}

void ABattleCharacter::SelectSkill()
{
	UE_LOG(LogTemp, Warning, TEXT("%s :: SelectSkill"), *GetName());

}

void ABattleCharacter::Back()
{
	UE_LOG(LogTemp, Warning, TEXT("%s :: Back"), *GetName());
	NonSelectCamera->SetActive(true);
	SelectCamera->SetActive(false);

}

