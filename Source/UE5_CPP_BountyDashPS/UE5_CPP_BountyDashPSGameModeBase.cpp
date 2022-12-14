// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE5_CPP_BountyDashPSGameModeBase.h"

#include "BountyDashCharacter.h"
#include "BountyDashHUD.h"

AUE5_CPP_BountyDashPSGameModeBase::AUE5_CPP_BountyDashPSGameModeBase()
{
	DefaultPawnClass = ABountyDashCharacter::StaticClass();

	numCoinsForSpeedIncrease = 5;
	gameSpeed = 10.f;
	gameSpeedIncrease = 5.0f;
	gameLevel = 1;

	HUDClass = ABountyDashHUD::StaticClass();

	RunTime = 0.f;
	bGameOver = false;
	startGameOverCount = false;
	timeTillGameOver = 2.f;
	gameOverTimer = 0.f;
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

float AUE5_CPP_BountyDashPSGameModeBase::GetRunTime()
{
	return RunTime;
}

void AUE5_CPP_BountyDashPSGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!startGameOverCount)
	{
		RunTime += DeltaSeconds;
	}
	else
	{
		gameOverTimer += DeltaSeconds;
		if (gameOverTimer >= timeTillGameOver)
		{
			bGameOver = true;
		}
	}
}

bool AUE5_CPP_BountyDashPSGameModeBase::GetGameOver()
{
	return bGameOver;
}

void AUE5_CPP_BountyDashPSGameModeBase::GameOver()
{
	startGameOverCount = true;
}

void AUE5_CPP_BountyDashPSGameModeBase::SetGamePaused(bool gamePaused)
{
	APlayerController* myPlayer = GetWorld()->GetFirstPlayerController();

	if (myPlayer != nullptr)
	{
		myPlayer->SetPause(gamePaused);
	}
}
