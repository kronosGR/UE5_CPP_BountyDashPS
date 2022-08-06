// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"

#include "BountyDashCharacter.h"
#include "DatasmithDefinitions.h"
#include "UE5_CPP_BountyDashPS.h"
#include "UE5_CPP_BountyDashPSGameModeBase.h"

// Sets default values
AFloor::AFloor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> myMesh(
		TEXT("/Game/Geometry/Meshes/Floor_Mesh_BountyDash.Floor_Mesh_BountyDash"));
	ConstructorHelpers::FObjectFinder<UMaterial> myMaterial(
		TEXT("/Game/StarterContent/Materials/M_Concrete_Tiles.M_Concrete_Tiles"));

	if (myMesh.Succeeded())
	{
		NumRepeatingMesh = 80;

		FBoxSphereBounds myBounds = myMesh.Object->GetBounds();
		float XBounds = myBounds.BoxExtent.X * 2;
		float ScenePos = ((XBounds * (NumRepeatingMesh - 1)) / 2.0f) * -1;

		KillPoint = ScenePos - (XBounds * 0.5f);
		SpawnPoint = (ScenePos * -1) + (XBounds * 0.5f);

		for (int i = 0; i < NumRepeatingMesh; ++i)
		{
			// Initialize Scene
			FString SceneName = "Scene" + FString::FromInt(i);
			FName SceneID = FName(*SceneName);
			USceneComponent* thisScene = CreateDefaultSubobject<USceneComponent>(SceneID);
			check(thisScene);

			thisScene->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			thisScene->SetRelativeLocation(FVector(ScenePos, 0.0f, 0.0f));
			ScenePos += XBounds;

			FloorMeshScenes.Add(thisScene);

			// Initialize Mesh
			FString MeshName = "Mesh" + FString::FromInt(i);
			UStaticMeshComponent* thisMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(*MeshName));
			check(thisMesh);

			thisMesh->AttachToComponent(FloorMeshScenes[i],FAttachmentTransformRules::KeepRelativeTransform);
			thisMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
			thisMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

			if (myMaterial.Succeeded())
			{
				thisMesh->SetStaticMesh(myMesh.Object);
				thisMesh->SetMaterial(0, myMaterial.Object);
			}

			FloorMeshes.Add(thisMesh);
		} // <--Closing For(int i = 0; i < numReapeatingMesh; ++i)

		CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollsionBox"));
		check(CollisionBox);

		CollisionBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		CollisionBox->SetBoxExtent(FVector(SpawnPoint, myBounds.BoxExtent.Y, myBounds.BoxExtent.Z));
		CollisionBox->SetCollisionProfileName(TEXT("BlockAllDynamic"));

	} // <-- 
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (auto Scene : FloorMeshes)
	{
		Scene->AddLocalOffset(
			FVector(GetCustomGameMode<AUE5_CPP_BountyDashPSGameModeBase>(GetWorld())->GetInvGameSpeed(), 0.f, 0.f));

		if (Scene->GetComponentTransform().GetLocation().X <= KillPoint)
		{
			Scene->SetRelativeLocation(FVector(SpawnPoint, 0.f, 0.f));
		}
	}
}

float AFloor::GetKillPoint()
{
	return KillPoint;
}

float AFloor::GetSpawnPoint()
{
	return SpawnPoint;
}
