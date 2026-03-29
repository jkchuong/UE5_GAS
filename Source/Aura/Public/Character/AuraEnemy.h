// Copyright JKChuong

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/HighlightInterface.h"
#include "UI/Controller/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHighlightInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemy();
	virtual void BeginPlay() override;

	//~ Begin Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~ End Enemy Interface

	//~ Combat Interface
	virtual int32 GetPlayerLevel() const override;
	virtual void Die() override;
	//~ End Combat Interface
	
	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnMaxHealthChanged;

protected:
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
	
	UPROPERTY(BlueprintReadOnly, Category = "Combat ")
	float BaseWalkSpeed = 250.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat ")
	float LifeSpan = 5.f;
	
	UPROPERTY(BlueprintReadOnly, Category = "Combat ")
	bool bHitReacting = false;
};
