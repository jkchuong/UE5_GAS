// Copyright JKChuong


#include "AbilitySystem/Data/CharacterClassInfo.h"

#include "AuraLogs.h"

FCharacterClassDefaultInfo UCharacterClassInfo::GetClassDefaultInfo(const FGameplayTag CharacterClass)
{
	if (FCharacterClassDefaultInfo* Info = CharacterClassInformation.Find(CharacterClass))
	{
		return *Info;
	}
	
	UE_LOG(LogAura, Error, TEXT("Could not find Character Class [%s] in Character Class DataAsset [%s]"), *CharacterClass.ToString(), *GetPathName());
	return FCharacterClassDefaultInfo();
}
