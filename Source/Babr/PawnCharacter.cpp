// Copyright 2023 Mohammad Jamal Sarvarian. All Rights Reserved.

#include "PawnCharacter.h"

#include "Paper2D/Classes/PaperSpriteComponent.h"

// Sets default values
APawnCharacter::APawnCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void APawnCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnCharacter::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector MoveVec = ProcessMovement(DeltaTime);

	if (IsMoving(MoveVec))
	{
		Sprite->SetRelativeLocation(FVector(0.0f, 0.0f, 1.0f));
	}
	else
	{
		Sprite->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	
}

bool APawnCharacter::IsMoving(const FVector MoveVector)
{
	return MoveVector.X != 0 || MoveVector.Y != 0;
}

FVector APawnCharacter::ProcessMovement(const float DeltaTime)
{
	FVector MovementVector = ConsumeMovementInputVector();
	if (MovementVector.SizeSquared() > 1.0f)
	{
		MovementVector.Normalize(1.0f);
	}
	AddActorLocalOffset(DeltaTime * MovementVector * MoveSpeed, true);
	return MovementVector;
}

