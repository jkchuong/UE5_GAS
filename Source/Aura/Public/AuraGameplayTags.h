// Copyright JKChuong

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *  Singleton containing native Gameplay Tags
 */
struct FAuraGameplayTags
{
	static const FAuraGameplayTags& Get(){ return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Secondary_Armor;

private:
	static FAuraGameplayTags GameplayTags;
};