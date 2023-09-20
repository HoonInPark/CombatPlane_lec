// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CP_GM_AnimInst.generated.h"

/**
 *
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_GM_AnimInst : public AGameModeBase
{
	GENERATED_BODY()
	ACP_GM_AnimInst();

public:
	virtual void PostLogin(APlayerController* _NewPlayer) override;
};
