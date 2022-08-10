// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BountyDashObject.h"
#include "PowerUpObject.h"
#include "BountyDashPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPP_BOUNTYDASHPS_API ABountyDashPowerUp : public ABountyDashObject
{
	GENERATED_BODY()

public:
	ABountyDashPowerUp();

	virtual void MyOnActorOverlap(AActor* Actor, AActor* otherActor) override;

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

private:
	UPowerUpObject* PowerUp;
};
