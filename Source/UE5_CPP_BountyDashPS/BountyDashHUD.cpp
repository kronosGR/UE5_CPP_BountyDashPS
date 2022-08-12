// Fill out your copyright notice in the Description page of Project Settings.


#include "BountyDashHUD.h"

#include "BountyDashCharacter.h"
#include "UE5_CPP_BountyDashPS.h"
#include "UE5_CPP_BountyDashPSGameModeBase.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"


ABountyDashHUD::ABountyDashHUD()
{
	static ConstructorHelpers::FObjectFinder<UFont> OurHudFont(TEXT("/Game/BountyDashFont.BountyDashFont"));
	HUDFont = OurHudFont.Object;
}

void ABountyDashHUD::DrawHUD()
{
	Super::DrawHUD();

	FVector2d ScreenDimensions = FVector2d(Canvas->SizeX, Canvas->SizeY);

	ABountyDashCharacter* DashCharacter = Cast<ABountyDashCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	AUE5_CPP_BountyDashPSGameModeBase* DashGameMode = GetCustomGameMode<AUE5_CPP_BountyDashPSGameModeBase>(GetWorld());

	FString HUDString = FString::Printf(TEXT("Score: %d Runtime: %.4f"), DashCharacter->GetScore(),
										DashGameMode->GetRunTime());
	DrawText(HUDString, FColor::Yellow, 50, 50, HUDFont);
}
