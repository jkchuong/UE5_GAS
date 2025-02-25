// Copyright JKChuong


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
#include "AuraLogs.h"
#include "Interaction/CombatInterface.h"


void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAuraProjectileSpell::SpawnProjectile()
{
	if (!GetAvatarActorFromActorInfo()->HasAuthority())
		return;

	if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo()))
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		
		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
			ProjectileClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn
		);

		// TODO: Give Projectile Gameplay Effect Spec for causing Damage

		if (Projectile)
		{
			Projectile->FinishSpawning(SpawnTransform);
		}
		else
		{
			UE_LOG(LogAura, Error, TEXT("Failed to spawn projectile with spell [%s]"), *GetName());
		}
	}
}
