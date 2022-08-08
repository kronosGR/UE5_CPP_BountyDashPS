// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "BountyDashObject.generated.h"

UCLASS()
class UE5_CPP_BOUNTYDASHPS_API ABountyDashObject : public AActor
{
	GENERATED_BODY()

	float KillPoint;
	
public:	
	// Sets default values for this actor's properties
	ABountyDashObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetKillPoint(float point);
	float GetKillPoint();

protected:
	UFUNCTION()
	virtual void MyOnActorOverkap(AActor* otherActor);

	UFUNCTION()
	virtual void MyOnActorEndOverlap(AActor* otherActor);

	UPROPERTY(EditAnywhere)
	USphereComponent* Collider;
};
