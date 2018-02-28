// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProceduralMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MESHGENERATION_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostActorCreated() override;
	virtual void PostLoad() override;
	void GenerateMesh();
	
private:
	UPROPERTY(Visibleanywhere)
		UProceduralMeshComponent *Mesh;
	UPROPERTY(Visibleanywhere)
		UProceduralMeshComponent *Mesh2;
	UPROPERTY(Visibleanywhere)
		UProceduralMeshComponent *Mesh3;
	UPROPERTY(Visibleanywhere)
		UProceduralMeshComponent *Mesh4;
	UPROPERTY(Visibleanywhere)
		UProceduralMeshComponent *Mesh5;
	UPROPERTY(Visibleanywhere)
		UProceduralMeshComponent *Mesh6;

};
