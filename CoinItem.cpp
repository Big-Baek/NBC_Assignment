// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"
#include "Engine/World.h"
#include "SpartaGameState.h"

ACoinItem::ACoinItem()
{
	PointValue = 0;
	ItemType = "DefaultCoin";
}

void ACoinItem::ActivateItem(AActor* Activator) //오버라이딩
{
	Super::ActivateItem(Activator);

	if (Activator && Activator->ActorHasTag("Player")) //이거 검사했는데 또한다...
	{
		if (UWorld* World = GetWorld()) // 초기화시 평가.  초기화를 함과 동시에 null인지 확인. 즉 월드가 존재한다면
		{
			if (ASpartaGameState* GameState = World->GetGameState<ASpartaGameState>()) //동일. GameState가 유효하다면
			{
				GameState->AddScore(PointValue); //점수획득

				GameState->OnCoinCollected(); //획득한 점수 기록?
			}
		}

		DestroyItem();
	}
}