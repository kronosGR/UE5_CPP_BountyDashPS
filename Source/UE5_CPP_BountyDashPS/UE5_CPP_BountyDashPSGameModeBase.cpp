// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE5_CPP_BountyDashPSGameModeBase.h"

#include "BountyDashCharacter.h"

AUE5_CPP_BountyDashPSGameModeBase::AUE5_CPP_BountyDashPSGameModeBase()
{
	DefaultPawnClass = ABountyDashCharacter::StaticClass();

	numCoinsForSpeedIncrease = 5;
	gameSpeed = 10.f;
	gameSpeedIncrease = 5.0f;
	gameLevel = 1;
}

void AUE5_CPP_BountyDashPSGameModeBase::CharScoreUp(unsigned int charScore)
{
	if (charScore != 0 && charScore % numCoinsForSpeedIncrease == 0)
	{
		gameSpeed += gameSpeedIncrease;
		gameLevel++;
	}
}

float AUE5_CPP_BountyDashPSGameModeBase::GetInvGameSpeed()
{
	return -gameSpeed;
}

float AUE5_CPP_BountyDashPSGameModeBase::GetGameSpeed()
{
	return gameSpeed;
}

int32 AUE5_CPP_BountyDashPSGameModeBase::GetGameLevel()
{
	return gameLevel;
}

void AUE5_CPP_BountyDashPSGameModeBase::ReduceGameSpeed()
{
	if (gameSpeed > 10.f)
	{
		gameSpeed -= gameSpeedIncrease;
		gameLevel--;
	}
}
