// Fill out your copyright notice in the Description page of Project Settings.


#include "BountyDashPowerUp.h"

#include "BountyDashCharacter.h"
#include "Obstacle.h"

ABountyDashPowerUp::ABountyDashPowerUp()
{
	PrimaryActorTick.bCanEverTick = true;

	PowerUp = CreateDefaultSubobject<UPowerUpObject>(TEXT("PowerUp"));
	check(PowerUp);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	check(Mesh);

	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Mesh->SetCollisionProfileName("OverlapAllDynamic");

	FString AssetName;
	switch (PowerUp->GetType())
	{
	case EPowerUp::SPEED:
		AssetName = "/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid";
		break;
	case EPowerUp::SMASH:
		AssetName = "/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule";
		break;
	case EPowerUp::MAGNET:
		AssetName = "/Game/StarterContent/Shapes/Shape_Pipe_180.Shape_Pipe_180";
		break;
	default:
		break;
	}

	ConstructorHelpers::FObjectFinder<UStaticMesh> myMesh(&AssetName.GetCharArray()[0]);

	if (myMesh.Succeeded())
	{
		Mesh->SetStaticMesh(myMesh.Object);
	}
}

void ABountyDashPowerUp::MyOnActorOverlap(AActor* Actor, AActor* otherActor)
{
	Super::MyOnActorOverlap(Actor, otherActor);

	if (otherActor->GetClass()->IsChildOf(AObstacle::StaticClass()))
	{
		USphereComponent* otherSphere = Cast<USphereComponent>(
			otherActor->GetComponentByClass(UShapeComponent::StaticClass()));
		if (otherSphere)
		{
			AddActorLocalOffset(FVector(
				0.f, 0.f, (otherSphere->GetUnscaledSphereRadius()) + Collider->GetUnscaledSphereRadius() * 2));
		}
	}

	if (otherActor->GetClass()->IsChildOf(ABountyDashCharacter::StaticClass()))
	{
		ABountyDashCharacter* thisChar = Cast<ABountyDashCharacter>(otherActor);
		if (thisChar)
		{
			thisChar->PowerUp(PowerUp->GetType());
			GetWorld()->DestroyActor(this);
		}
	}
}
