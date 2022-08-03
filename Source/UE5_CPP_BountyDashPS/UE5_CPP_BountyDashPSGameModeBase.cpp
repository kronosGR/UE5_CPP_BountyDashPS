// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE5_CPP_BountyDashPSGameModeBase.h"

#include "BountyDashCharacter.h"

AUE5_CPP_BountyDashPSGameModeBase::AUE5_CPP_BountyDashPSGameModeBase()
{
	 DefaultPawnClass = ABountyDashCharacter::StaticClass();

	numCoinsForSpeedIncrease = 5;
	gameSpeed= 10.f;
	gameSpeedIncrease = 5.0f;
	gameLevel =1;
}

void AUE5_CPP_BountyDashPSGameModeBase::CharScoreUp(unsigned charScore)
{
}

float AUE5_CPP_BountyDashPSGameModeBase::GetInvGameSpeed()
{
}

float AUE5_CPP_BountyDashPSGameModeBase::GetGameSpeed()
{
}

int32 AUE5_CPP_BountyDashPSGameModeBase::GetGameLevel()
{
}
