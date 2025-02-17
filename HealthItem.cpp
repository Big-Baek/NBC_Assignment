#include "HealthItem.h"
#include "SpartaCharacter.h"



AHealthItem::AHealthItem()
{
	HealAmount = 20.0f;
	ItemType = "Healing";
}

void AHealthItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(Activator))
		{
			// 콜리전이 이루어진 캐릭터의 체력을 회복
			PlayerCharacter->AddHealth(HealAmount);
		}

		DestroyItem(); //이후 파괴
	}
}
