// Copyright JKChuong

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "AuraAbilityTypes.generated.h"

USTRUCT(BlueprintType)
struct FAuraGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()
	
	bool IsCriticalHit() const { return bIsCriticalHit; }
	void SetIsCriticalHit(const bool bInIsCriticalHit) { bIsCriticalHit = bInIsCriticalHit; }
	
	bool IsBlockedHit() const { return bIsBlockedHit; }
	void SetIsBlockedHit(const bool bInIsBlockedHit) { bIsBlockedHit = bInIsBlockedHit; }
	
	virtual UScriptStruct* GetScriptStruct() const override
	{
		return FGameplayEffectContext::GetScriptStruct();
	}
	
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) override;
	
protected:
	
	UPROPERTY()
	bool bIsCriticalHit = false;

	UPROPERTY()
	bool bIsBlockedHit = false;
};
