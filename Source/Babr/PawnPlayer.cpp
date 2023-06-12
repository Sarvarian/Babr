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

}

// Called to bind functionality to input
void APawnPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Quit"), IE_Released, this, &APawnPlayer::OnQuitAction);
	PlayerInputComponent->BindAction(TEXT("Fullscreen"), IE_Pressed, this, &APawnPlayer::OnFullscreenAction);

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



