// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BountyDashObject.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class UE5_CPP_BOUNTYDASHPS_API AObstacle : public ABountyDashObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObstacle();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
};
