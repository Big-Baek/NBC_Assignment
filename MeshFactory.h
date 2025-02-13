// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MeshFactory.generated.h"


UCLASS()
class CH3ASSIGNMENT6_API UMeshFactory : public UObject
{
	GENERATED_BODY()

	

public:
	static uint16 numbering;
	
	UMeshFactory();
	void build(UStaticMeshComponent* type);
	
};
