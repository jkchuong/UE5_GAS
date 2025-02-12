// Copyright JKChuong


#include "AbilitySystem/AuraAbilitySystemFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/Controller/AuraWidgetController.h"
#include "UI/HUD/AuraHUD.h"

UOverlayWidgetController* UAuraAbilitySystemFunctionLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* Controller = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(Controller->GetHUD()))
		{
			AAuraPlayerState* PlayerState = Controller->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();
			return AuraHUD->GetOverlayWidgetController(FWidgetControllerParams(Controller, PlayerState, AbilitySystemComponent, AttributeSet));
		}
	}

	return nullptr;
}
