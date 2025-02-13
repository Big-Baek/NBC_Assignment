// Fill out your copyright notice in the Description page of Project Settings.


#include "Roll2.h"

// Sets default values
ARoll2::ARoll2()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rolling2"));
	StaticMeshComp1->SetupAttachment(SceneRoot);

	RotationSpeed1 = 90.0f;
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoll2::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARoll2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed1))//0이 아니라면 실행
	{
		// 초당 RotationSpeed만큼, 한 프레임당 (RotationSpeed * DeltaTime)만큼 회전, 회전방향 어떻게 구현하지
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed1 * DeltaTime, 0.0f)); //y, z, x 순
	}
}

