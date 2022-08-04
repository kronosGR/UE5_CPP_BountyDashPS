// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> myMesh(TEXT("/Game/Barrel_Hopper/Geometry/Floor_Mesh_BountyDash.Floor_Mesh_BountyDash"));
	ConstructorHelpers::FObjectFinder<UMaterial> myMaterial(TEXT("/Game/StarterContent/Materials/M_Concrete_Tiles.M_Concrete_Tiles"));

	if (myMesh.Succeeded())
	{
		NumRepeatingMesh = 3;

		FBoxSphereBounds myBounds = myMesh.Object->GetBounds();
		float XBounds = myBounds.BoxExtent.X*2;
		float ScenePos = ((XBounds* (NumRepeatingMesh-1)) / 2.f) *-1;

		KillPoint = ScenePos - (XBounds * 0.5f);
		SpawnPoint = (ScenePos * -1) + (XBounds * 0.5f);

		for (int i=0; i < NumRepeatingMesh; i++)
		{
			FString SceneName = "Scene"+FString::FromInt(i);
			FName SceneID = FName(*SceneName);
			USceneComponent* thisScene = CreateDefaultSubobject<USceneComponent>(SceneID);
			check(thisScene);

			thisScene->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			thisScene->SetRelativeLocation(FVector(ScenePos, 0.f, 0.f));
			ScenePos +=XBounds;

			FloorMeshScenes.Add(thisScene);

			FString MeshName = "Mesh" + FString::FromInt(i);
			UStaticMeshComponent* thisMesh  = CreateDefaultSubobject<UStaticMeshComponent>(FName(*MeshName));
			check(thisMesh);
			thisMesh->AttachToComponent(FloorMeshScenes[i], FAttachmentTransformRules::KeepRelativeTransform);
			thisMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
			thisMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

			if(myMaterial.Succeeded())
			{
				thisMesh->SetStaticMesh(myMesh.Object);
				thisMesh->SetMaterial(0, myMaterial.Object);
			}
			FloorMeshes.Add(thisMesh);
		}
		
	}

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

}

float AFloor::GetKillPoint()
{
}

float AFloor::GetSpawnPoint()
{
}

