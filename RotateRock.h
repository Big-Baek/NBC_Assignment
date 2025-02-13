// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MeshFactory.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateRock.generated.h"

UCLASS()
class CH3ASSIGNMENT6_API ARotateRock : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ARotateRock();
protected:
	// Root Scene Component, 에디터에서 볼 수만 있고 수정 불가
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot; //에디터상에서 수정 가능
	// Static Mesh, 에디터와 Blueprint에서 수정 가능

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp7;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp8;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float RotationSpeed1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float RotationSpeed2;
	
};

