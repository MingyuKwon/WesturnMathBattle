// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BattleCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Controller/BattlePlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/PlayerCameraManager.h"

// Sets default values
ABattleCharacter::ABattleCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	NonSelectCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("NonSelectCamera"));
	NonSelectCamera->SetupAttachment(GetMesh(), USpringArmComponent::SocketName);

	SelectCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SelectCamera"));
	SelectCamera->SetupAttachment(GetMesh(), USpringArmComponent::SocketName);

    LookCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("LookCamera"));
    LookCamera->SetupAttachment(GetMesh(), USpringArmComponent::SocketName);

    LookCamera-> bAutoActivate = true;
	NonSelectCamera->bAutoActivate = false;
	SelectCamera->bAutoActivate = false;


}

// Called when the game starts or when spawned
void ABattleCharacter::BeginPlay()
{
	Super::BeginPlay();

	ABattlePlayerController* battlePlayerController = Cast<ABattlePlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	battlePlayerController->AddBattleCharacter(this);

    if (LookCamera)
    {
        LookCamera->SetRelativeLocation(NonSelectCamera->GetRelativeLocation());
        LookCamera->SetRelativeRotation(NonSelectCamera->GetRelativeRotation());

    }
}

// Called every frame
void ABattleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleCharacter::SelectedByModel()
{
	UE_LOG(LogTemp, Warning, TEXT("%s :: SelectedByModel"), *GetName());
    BlendCamera(SelectCamera, CAMERA_CHANGETIME_SELECT);

}

void ABattleCharacter::SelectSkill()
{
	UE_LOG(LogTemp, Warning, TEXT("%s :: SelectSkill"), *GetName());

}

void ABattleCharacter::Back()
{
	UE_LOG(LogTemp, Warning, TEXT("%s :: Back"), *GetName());
    BlendCamera(NonSelectCamera, CAMERA_CHANGETIME_SELECT);

}

void ABattleCharacter::BlendCamera(UCameraComponent* ToCamera, float Duration)
{
    if (!LookCamera || !ToCamera) return;

    FVector StartLocation = LookCamera->GetRelativeLocation();
    FRotator StartRotation = LookCamera->GetRelativeRotation();
    
    FVector TargetLocation = ToCamera->GetRelativeLocation();
    FRotator TargetRotation = ToCamera->GetRelativeRotation();

    float ElapsedTime = 0.0f;

    
    GetWorld()->GetTimerManager().SetTimer(BlendTimerHandle, FTimerDelegate::CreateLambda([this, ElapsedTime, Duration, StartLocation, StartRotation, TargetLocation, TargetRotation]() mutable {
        ElapsedTime += GetWorld()->DeltaTimeSeconds;
        float Alpha = FMath::Clamp(ElapsedTime / Duration, 0.0f, 1.0f);

        FVector BlendedLocation = FMath::Lerp(LookCamera->GetRelativeLocation(), TargetLocation, Alpha);
        FRotator BlendedRotation = FMath::Lerp(LookCamera->GetRelativeRotation(), TargetRotation, Alpha);

        if (LookCamera)
        {
            UE_LOG(LogTemp, Warning, TEXT("%s :: Alpha : %f"), *GetName(), Alpha);

            LookCamera->SetRelativeLocation(BlendedLocation);
            LookCamera->SetRelativeRotation(BlendedRotation);
        }

        if (Alpha >= 1.0f)
        {
            GetWorld()->GetTimerManager().ClearTimer(BlendTimerHandle);
        }
        }), GetWorld()->DeltaTimeSeconds, true);
}


