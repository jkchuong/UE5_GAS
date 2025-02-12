// Copyright JKChuong


#include "UI/HUD/AuraHUD.h"

#include "UI/Controller/AttributeMenuWidgetController.h"
#include "UI/Controller/OverlayWidgetController.h"
#include "UI/Widget/AuraUserWidget.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& InWidgetControllerParams)
{
	return Cast<UOverlayWidgetController>(GetWidgetController(OverlayWidgetController, OverlayWidgetControllerClass, InWidgetControllerParams));
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& InWidgetControllerParams)
{
	return Cast<UAttributeMenuWidgetController>(GetWidgetController(AttributeMenuWidgetController, AttributeMenuWidgetControllerClass, InWidgetControllerParams));
}

void AAuraHUD::InitOverlay(APlayerController* InPlayerController, APlayerState* InPlayerState,
                           UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(InPlayerController, InPlayerState, InAbilitySystemComponent, InAttributeSet);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}

UAuraWidgetController* AAuraHUD::GetWidgetController(UAuraWidgetController* WidgetController, const TSubclassOf<UAuraWidgetController> WidgetControllerClass, const FWidgetControllerParams& InWidgetControllerParams)
{
	if (!WidgetController)
	{
		WidgetController = NewObject<UAuraWidgetController>(this, WidgetControllerClass);
		WidgetController->SetWidgetControllerParam(InWidgetControllerParams);
		WidgetController->BindCallbacksToDependencies();
	}

	return WidgetController;
}

