// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UE5_CPP_BountyDashPSGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPP_BOUNTYDASHPS_API AUE5_CPP_BountyDashPSGameModeBase : public AGameMode
{
	GENERATED_BODY()

	UPROPERTY()
	float gameSpeed;

	UPROPERTY()
	int32 gameLevel;

public:
	AUE5_CPP_BountyDashPSGameModeBase();
	
	void CharScoreUp(unsigned int charScore);

	UFUNCTION()
	float GetInvGameSpeed();

	UFUNCTION()
	float GetGameSpeed();

	UFUNCTION()
	int32 GetGameLevel();

	void ReduceGameSpeed();
	float GetRunTime();

	UFUNCTION()
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	bool GetGameOver();

	UFUNCTION()
	void GameOver();
	
	UFUNCTION()
	void SetGamePaused(bool gamePaused);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 numCoinsForSpeedIncrease;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float gameSpeedIncrease;

	UPROPERTY()
	float RunTime;

	UPROPERTY()
	bool bGameOver;

	UPROPERTY()
	bool startGameOverCount;

	UPROPERTY()
	float timeTillGameOver;

	UPROPERTY()
	float gameOverTimer;
};
