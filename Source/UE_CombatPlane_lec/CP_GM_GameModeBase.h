// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
//#include "CP_Pawn_CombatPlane.h"
#include "CP_Pawn_Tick.h"
#include "CP_PC_CombatPlaneController.h"

#include "GameFramework/GameModeBase.h"
#include "CP_GM_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_GM_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	ACP_GM_GameModeBase();

public:
	virtual void PostLogin(APlayerController* _NewPlayer) override;
};
