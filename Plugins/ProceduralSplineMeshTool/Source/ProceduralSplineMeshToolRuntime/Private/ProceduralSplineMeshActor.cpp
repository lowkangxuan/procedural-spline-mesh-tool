// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\ProceduralSplineMeshActor.h"


// Sets default values
AProceduralSplineMeshActor::AProceduralSplineMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetupComponents();
}

void AProceduralSplineMeshActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	DrawMesh();
}

// Called when the game starts or when spawned
void AProceduralSplineMeshActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProceduralSplineMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Setting up components for when Actor is created
void AProceduralSplineMeshActor::SetupComponents()
{
	DefaultRoot = CreateDefaultSubobject<USceneComponent>("Default Root Component");
	SetRootComponent(DefaultRoot);
	
	ProceduralMeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>("Procedural Mesh Component");
	ProceduralMeshComponent->SetupAttachment(RootComponent);
	
	SplineComponent = CreateDefaultSubobject<USplineComponent>("Spline Component");
	SplineComponent->SetupAttachment(RootComponent);

	// Billboard for actor within the editor
	# if WITH_EDITORONLY_DATA
	SpriteComponent = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	if (SpriteComponent)
	{
		// Structure to hold one-time initialization
		struct FConstructorStatics
		{
			ConstructorHelpers::FObjectFinderOptional<UTexture2D> EmptyActorTextureObject;
			FName ID_Actor;
			FText NAME_Actor;
			FConstructorStatics()
				: EmptyActorTextureObject(TEXT("/Engine/EditorResources/EmptyActor"))
				, ID_Actor(TEXT("Actor"))
				, NAME_Actor(NSLOCTEXT( "SpriteCategory", "Actor", "Actor" ))
			{
			}
		};
		static FConstructorStatics ConstructorStatics;

		SpriteComponent->Sprite = ConstructorStatics.EmptyActorTextureObject.Get();
		SpriteComponent->bHiddenInGame = false;
		SpriteComponent->SpriteInfo.Category = ConstructorStatics.ID_Actor;
		SpriteComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_Actor;
		SpriteComponent->bIsScreenSizeScaled = true;
		SpriteComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
		SpriteComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	}
	# endif
}

void AProceduralSplineMeshActor::DrawMesh()
{

}

