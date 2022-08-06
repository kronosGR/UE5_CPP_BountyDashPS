// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"

ACoin::ACoin()
{
}

void ACoin::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	Mesh->AddLocalRotation(FRotator(5.f, 0.f, 0.f));
}

void ACoin::MyOnActorOverlap(AActor* actor, AActor* otherActor)
{
	Super::MyOnActorOverlap(actor, otherActor);

	if (otherActor->GetClass()->IsChildOf(AObstacle::StaticClass()))
	{
		USphereComponent* thisSphere = Cast<USphereComponent>(GetComponentByClass(USphereComponent::StaticClass()));

		USphereComponent* otherSphere = Cast<USphereComponent>(
			otherActor->GetComponentByClass(USphereComponent::StaticClass()));
		if (otherSphere)
		{
			AddActorLocalOffset(FVector(
				0.f, 0.f, (otherSphere->GetUnscaledSphereRadius() * 2.f) + Collider->GetUnscaledSphereRadius()));
		}
	}
}
