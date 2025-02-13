// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateRock.h"
// Sets default values
ARotateRock::ARotateRock()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock1"));
	StaticMeshComp1->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	StaticMeshComp2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock2"));
	StaticMeshComp2->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	StaticMeshComp3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock3"));
	StaticMeshComp3->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	StaticMeshComp4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock4"));
	StaticMeshComp4->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	StaticMeshComp5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock5"));
	StaticMeshComp5->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	StaticMeshComp6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock6"));
	StaticMeshComp6->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	StaticMeshComp7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock7"));
	StaticMeshComp7->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	StaticMeshComp8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RollingRock8"));
	StaticMeshComp8->SetupAttachment(SceneRoot); //Mesh와 Scene 컴포넌트 구현

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Pipe_180.Shape_Pipe_180"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Game/Resources/Materials/M_Brick_Clay_Old.M_Brick_Clay_Old"));
	if (MeshAsset.Succeeded())StaticMeshComp1->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp1->SetStaticMesh(MeshAsset.Object);

	if (MeshAsset.Succeeded())StaticMeshComp2->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp2->SetStaticMesh(MeshAsset.Object);

	if (MeshAsset.Succeeded())StaticMeshComp3->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp3->SetStaticMesh(MeshAsset.Object);

	if (MeshAsset.Succeeded())StaticMeshComp4->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp4->SetStaticMesh(MeshAsset.Object);

	if (MeshAsset.Succeeded())StaticMeshComp5->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp5->SetStaticMesh(MeshAsset.Object);

	if (MeshAsset.Succeeded())StaticMeshComp6->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp6->SetStaticMesh(MeshAsset.Object);

	if (MeshAsset.Succeeded())StaticMeshComp7->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp7->SetStaticMesh(MeshAsset.Object);

	if (MeshAsset.Succeeded())StaticMeshComp8->SetStaticMesh(MeshAsset.Object);
	if (MaterialAsset.Succeeded())StaticMeshComp8->SetStaticMesh(MeshAsset.Object);

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorScale3D(FVector(4.0f));
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed1 = 90.0f;
	RotationSpeed2 = 90.0f;
}

void ARotateRock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateRock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!FMath::IsNearlyZero(RotationSpeed1))//0이 아니라면 실행
	{
		// 초당 RotationSpeed만큼, 한 프레임당 (RotationSpeed * DeltaTime)만큼 회전, 회전방향 어떻게 구현하지
		AddActorLocalRotation(FRotator(RotationSpeed2 * DeltaTime, RotationSpeed1 * DeltaTime, 0.0f)); //y, z, x 순
	}	
	
	
}
