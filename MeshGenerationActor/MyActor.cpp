// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Square_1"));
	RootComponent = Mesh;

	Mesh2 = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Square_2"));
	Mesh2->SetupAttachment(Mesh);
	Mesh2->SetRelativeLocation(FVector(0.f, 100.f, 0.f));
	Mesh2->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	Mesh3 = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Square_3"));
	Mesh3->SetupAttachment(Mesh2);
	Mesh3->SetRelativeLocation(FVector(0.f, 100.f, 0.f));
	Mesh3->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	Mesh4 = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Square_4"));
	Mesh4->SetupAttachment(Mesh3);
	Mesh4->SetRelativeLocation(FVector(0.f, 100.f, 0.f));
	Mesh4->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	Mesh5 = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Square_5"));
	Mesh5->SetupAttachment(Mesh);
	Mesh5->SetRelativeLocation(FVector(100.f, 0.f, 0.f));
	Mesh5->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));

	Mesh6 = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Square_6"));
	Mesh6->SetupAttachment(Mesh);
	Mesh6->SetRelativeLocation(FVector(0.f, 0.f, 100.f));
	Mesh6->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::PostActorCreated()
{
	Super::PostActorCreated();
	GenerateMesh();
}

void AMyActor::PostLoad()
{
	Super::PostLoad();
	GenerateMesh();
}

void AMyActor::GenerateMesh()
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVMap;
	TArray<FProcMeshTangent> Tangent;
	TArray<FColor> VertexColors;

	Vertices.Add(FVector(0, 0, 0));
	Vertices.Add(FVector(0, 100, 0));
	Vertices.Add(FVector(0, 0, 100));
	Vertices.Add(FVector(0, 100, 100));

	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	Triangles.Add(3);
	Triangles.Add(2);
	Triangles.Add(1);

	for(int32 i=0; i<Vertices.Num(); i++)
	Normals.Add(FVector(1, 0, 0));

	UVMap.Add(FVector2D(0, 0));
	UVMap.Add(FVector2D(5, 0));
	UVMap.Add(FVector2D(0, 5));
	UVMap.Add(FVector2D(5, 5));

	Mesh->CreateMeshSection(0, Vertices, Triangles, Normals, UVMap, VertexColors, Tangent, false);
	Mesh2->CreateMeshSection(1, Vertices, Triangles, Normals, UVMap, VertexColors, Tangent, false);
	Mesh3->CreateMeshSection(2, Vertices, Triangles, Normals, UVMap, VertexColors, Tangent, false);
	Mesh4->CreateMeshSection(3, Vertices, Triangles, Normals, UVMap, VertexColors, Tangent, false);
	Mesh5->CreateMeshSection(4, Vertices, Triangles, Normals, UVMap, VertexColors, Tangent, false);
	Mesh6->CreateMeshSection(5, Vertices, Triangles, Normals, UVMap, VertexColors, Tangent, false);
}

