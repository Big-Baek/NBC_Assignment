// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Roll1.generated.h"

UCLASS()
class CH3ASSIGNMENT6_API ARoll1 : public AActor
{
	GENERATED_BODY()
	
protected:	
	ARoll1();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp1;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float RotationSpeed1;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
