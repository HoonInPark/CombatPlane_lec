// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn.h"
#include "CP_PlayerController.h"
#include "GameFramework/GameModeBase.h"
#include "CP_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	ACP_GameModeBase();

public:
	virtual void PostLogin(APlayerController* _NewPlayer) override;
};
