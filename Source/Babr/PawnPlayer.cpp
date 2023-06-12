// Copyright 2023 Mohammad Jamal Sarvarian. All Rights Reserved.


#include "PawnPlayer.h"

#include "GameFramework/GameUserSettings.h"

// Sets default values
APawnPlayer::APawnPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MovementVector = ConsumeMovementInputVector();
	if (MovementVector.SizeSquared() > 1.0f)
	{
		MovementVector.Normalize(1.0f);
	}
	// UE_LOG(LogTemp, Display, TEXT("X: %f, Y: %f, Z: %f"), MovementVector.X, MovementVector.Y, MovementVector.Z);

	AddActorLocalOffset(DeltaTime * MovementVector * MoveSpeed, true);

}

// Called to bind functionality to input
void APawnPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Quit"), IE_Released, this, &APawnPlayer::OnQuitAction);
	PlayerInputComponent->BindAction(TEXT("Fullscreen"), IE_Pressed, this, &APawnPlayer::OnFullscreenAction);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APawnPlayer::OnMoveRightAxis);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &APawnPlayer::OnMoveUpAxis);
	
}

void APawnPlayer::OnQuitAction()
{
	FGenericPlatformMisc::RequestExit(false);
}

void APawnPlayer::OnFullscreenAction()
{
	UGameUserSettings* GameSetting = GEngine->GameUserSettings; 
	const EWindowMode::Type CurrentState = GameSetting->GetFullscreenMode();
	if (CurrentState == EWindowMode::Type::Windowed)
	{
		GameSetting->SetFullscreenMode(EWindowMode::Type::WindowedFullscreen);
	}
	else
	{
		GameSetting->SetFullscreenMode(EWindowMode::Type::Windowed);
	}
}

void APawnPlayer::OnMoveRightAxis(float Value)
{
	AddMovementInput(FVector(1.0f, 0.0f,0.0f), Value);
}

void APawnPlayer::OnMoveUpAxis(float Value)
{
	AddMovementInput(FVector(0.0f, 0.0f,1.0f), Value);
}



