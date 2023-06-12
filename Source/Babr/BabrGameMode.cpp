// Copyright Epic Games, Inc. All Rights Reserved.

#include "BabrGameMode.h"
#include "BabrCharacter.h"

ABabrGameMode::ABabrGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ABabrCharacter::StaticClass();	
}
