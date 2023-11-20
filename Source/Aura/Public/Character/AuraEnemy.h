// Copyright JKChuong

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/HighlightInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHighlightInterface
{
public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

private:
	GENERATED_BODY()
};
