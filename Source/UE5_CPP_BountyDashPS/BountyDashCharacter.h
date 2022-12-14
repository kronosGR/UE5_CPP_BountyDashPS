// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpObject.h"
#include "Camera/CameraComponent.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "BountyDashCharacter.generated.h"

UCLASS()
class UE5_CPP_BOUNTYDASHPS_API ABountyDashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABountyDashCharacter();

	UPROPERTY(EditAnywhere, Category=Logic)
	TArray<ATargetPoint*> TargetArray;

	UPROPERTY(EditAnywhere, Category=Login)
	float CharSpeed;

	UPROPERTY(EditAnywhere, Category=Sound)
	UAudioComponent* hitObstacleSound;

	UPROPERTY(EditAnywhere, Category = Sound)
	UAudioComponent* dingSound;

	void PowerUp(EPowerUp Type);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY(BlueprintReadOnly)
	int32 Score;

	void MoveRight();
	void MoveLeft();

	UFUNCTION()
	void MyOwnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void MyOwnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, Category=PowerUps)
	float SmashTime;


	UPROPERTY(EditAnywhere, Category=PowerUps)
	float MagnetTime;

	UPROPERTY(EditAnywhere, Category=PowerUps)
	float MagnetReach;

	UFUNCTION()
	void StopSmash();

	UFUNCTION()
	void StopMagnet();

	void CoinMagnet();

	UFUNCTION()
	virtual void Reset() override;

	float KillPoint;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ScoreUp();
	int GetScore();

private:
	short CurrentLocation;
	FVector DesiredLocation;
	bool bBeingPushed;
	bool CanSmash;
	bool CanMagnet;
};
