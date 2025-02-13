// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshFactory.h"

uint16 UMeshFactory::numbering = 0;


UMeshFactory::UMeshFactory()
{
}

void UMeshFactory::build(UStaticMeshComponent* type)
{
	FString naming = FString::Printf(TEXT("RollingRock%d"), ++numbering);
	FText namingtext = FText::FromString(naming);

	type = CreateDefaultSubobject<UStaticMeshComponent>(*naming);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Pipe_180.Shape_Pipe_180"));
	if (MeshAsset.Succeeded())
	{
		type->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Game/Resources/Materials/M_Brick_Clay_Old.M_Brick_Clay_Old"));
	if (MaterialAsset.Succeeded())
	{
		type->SetMaterial(0, MaterialAsset.Object);
	}

	
}
