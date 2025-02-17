#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.generated.h"


USTRUCT(BlueprintType)
struct FItemSpawnRow: public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass; //하드 레퍼런스 반대인 소프트레퍼런스는 TSoftClassPtr
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnChance;


};
