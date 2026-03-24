// Copyright JKChuong


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	if (const FAuraInputAction* AuraInputAction = AbilityInputActions.FindByPredicate([InputTag](const FAuraInputAction& InputAction){ return  InputAction.InputTag.MatchesTagExact(InputTag); }))
	{
		return AuraInputAction->InputAction;
	}
	
	UE_CLOG(bLogNotFound, LogTemp, Warning, TEXT("Could not find input for tag [%s]"), *InputTag.ToString());
	return nullptr;
}
