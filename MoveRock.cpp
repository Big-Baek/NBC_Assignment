// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveRock.h"
#include "RotateRock.h"
// Sets default values
AMoveRock::AMoveRock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("moverock1"));
	StaticMeshComp1->SetupAttachment(SceneRoot);

	StaticMeshComp2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("moverock2"));
	StaticMeshComp2->SetupAttachment(SceneRoot);

	StaticMeshComp3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("moverock3"));
	StaticMeshComp3->SetupAttachment(SceneRoot);

	StaticMeshComp4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("moverock4"));
	StaticMeshComp4->SetupAttachment(SceneRoot);

	SetActorLocation(FVector(0.0f, 0.0f, 1500.0f));
	StaticMeshComp1->AddRelativeLocation(FVector(500.0f, 500.0f, 500.0f));
	StaticMeshComp2->AddRelativeLocation(FVector(-500.0f, -500.0f, 500.0f));
	StaticMeshComp3->AddRelativeLocation(FVector(500.0f, -500.0f, -500.0f));
	StaticMeshComp4->AddRelativeLocation(FVector(-500.0f, 500.0f, -500.0f));

	movespeed = 100.0f;
	Distance = 500.0f;
}

// Called when the game starts or when spawned
void AMoveRock::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMoveRock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (StaticMeshComp1->GetRelativeLocation().X >= Distance && StaticMeshComp1->GetRelativeLocation().Y > -Distance) {
		StaticMeshComp1->AddRelativeLocation(FVector(0.0f, -movespeed * DeltaTime, 0.0f));
		StaticMeshComp2->AddRelativeLocation(FVector(0.0f, movespeed * DeltaTime, 0.0f));

		StaticMeshComp3->AddRelativeLocation(FVector(0.0f, movespeed * DeltaTime, 0.0f));
		StaticMeshComp4->AddRelativeLocation(FVector(0.0f, -movespeed * DeltaTime, 0.0f));


	}
	else if (StaticMeshComp1->GetRelativeLocation().X > -Distance && StaticMeshComp1->GetRelativeLocation().Y <= -Distance) {
		StaticMeshComp1->AddRelativeLocation(FVector(-movespeed * DeltaTime, 0.0f, 0.0f));
		StaticMeshComp2->AddRelativeLocation(FVector(movespeed * DeltaTime, 0.0f, 0.0f));

		StaticMeshComp3->AddRelativeLocation(FVector(-movespeed * DeltaTime, 0.0f, 0.0f));
		StaticMeshComp4->AddRelativeLocation(FVector(movespeed * DeltaTime, 0.0f, 0.0f));

	}
	else if (StaticMeshComp1->GetRelativeLocation().X <= -Distance && StaticMeshComp1->GetRelativeLocation().Y < Distance) {
		StaticMeshComp1->AddRelativeLocation(FVector(0.0f, movespeed * DeltaTime, 0.0f));
		StaticMeshComp2->AddRelativeLocation(FVector(0.0f, -movespeed * DeltaTime, 0.0f));

		StaticMeshComp3->AddRelativeLocation(FVector(0.0f, -movespeed * DeltaTime, 0.0f));
		StaticMeshComp4->AddRelativeLocation(FVector(0.0f, movespeed * DeltaTime, 0.0f));

	}
	else if (StaticMeshComp1->GetRelativeLocation().X < Distance && StaticMeshComp1->GetRelativeLocation().Y >= Distance) {
		StaticMeshComp1->AddRelativeLocation(FVector(movespeed * DeltaTime, 0.0f, 0.0f));
		StaticMeshComp2->AddRelativeLocation(FVector(-movespeed * DeltaTime, 0.0f, 0.0f));

		StaticMeshComp3->AddRelativeLocation(FVector(movespeed * DeltaTime, 0.0f, 0.0f));
		StaticMeshComp4->AddRelativeLocation(FVector(-movespeed * DeltaTime, 0.0f, 0.0f));

	}

	
}

