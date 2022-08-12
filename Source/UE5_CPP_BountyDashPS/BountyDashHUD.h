// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BountyDashHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPP_BOUNTYDASHPS_API ABountyDashHUD : public AHUD
{
	GENERATED_BODY()
public:
	ABountyDashHUD();

	UPROPERTY()
	UFont* HUDFont;

	virtual void DrawHUD() override;
};
