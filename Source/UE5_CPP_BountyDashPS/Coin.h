// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BountyDashObject.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPP_BOUNTYDASHPS_API ACoin : public ABountyDashObject
{
	GENERATED_BODY()

	ACoin();

	virtual void Tick(float DeltaSeconds) override;

	virtual void MyOnActorOverlap(AActor* actor, AActor* otherActor) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

public:
	bool BeingPulled;
};
