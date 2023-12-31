// Copyright JKChuong


#include "UI/Controller/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParam(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	// To be overriden in child class
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
	// To be overriden in child class
}
