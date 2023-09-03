// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "GameFramework/PlayerController.h"
#include "CP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* _Pawn) override;
};
