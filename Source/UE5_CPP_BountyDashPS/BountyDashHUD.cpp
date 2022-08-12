// Fill out your copyright notice in the Description page of Project Settings.


#include "BountyDashHUD.h"


ABountyDashHUD::ABountyDashHUD()
{
	static ConstructorHelpers::FObjectFinder<UFont> OurHudFont(TEXT("/Game/BountyDashFont.BountyDashFont"));
	HUDFont = OurHudFont.Object;
}

void ABountyDashHUD::DrawHUD()
{
	Super::DrawHUD();
}

