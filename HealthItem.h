// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "HealthItem.generated.h"

/**
 * 
 */
UCLASS()
class PJ_LEARNING_API AHealthItem : public ABaseItem
{
	GENERATED_BODY()
public:

	AHealthItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 HealAmount;

	virtual void ActivateItem(AActor* Activator) override;

	
};
