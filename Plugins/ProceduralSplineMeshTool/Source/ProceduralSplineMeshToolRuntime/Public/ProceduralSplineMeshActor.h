// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ProceduralMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Components/BillboardComponent.h"

#include "ProceduralSplineMeshActor.generated.h"

UCLASS()
class PROCEDURALSPLINEMESHTOOLRUNTIME_API AProceduralSplineMeshActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProceduralSplineMeshActor(const class FObjectInitializer& ObjectInitializer);

private:
	#if WITH_EDITORONLY_DATA

	/** Billboard used to see the actor in the editor */
	TObjectPtr<UBillboardComponent> SpriteComponent;
	#endif

	TObjectPtr<USceneComponent> DefaultRoot;

	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<UProceduralMeshComponent> ProceduralMeshComponent;

	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<USplineComponent> SplineComponent;

	TArray<FVector> Verts;
	TArray<int32> Tris;
	TArray<FVector2D> UVs;
	
	UPROPERTY(EditAnywhere)
	float Width;

	UPROPERTY(EditAnywhere)
	FIntPoint Subdivision = FIntPoint(0, 0);

protected:
	// Similar functionality to Blueprint's construction script
	virtual void OnConstruction(const FTransform& Transform) override;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void SetupComponents();
	void DrawMesh();
};
