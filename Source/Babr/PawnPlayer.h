// Copyright 2023 Mohammad Jamal Sarvarian. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PawnCharacter.h"
#include "GameFramework/Pawn.h"
#include "PawnPlayer.generated.h"

UCLASS()
class BABR_API APawnPlayer : public APawnCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	void OnQuitAction();
	void OnFullscreenAction();
	void OnMoveRightAxis(float Value);
	void OnMoveUpAxis(float Value);
	
};
