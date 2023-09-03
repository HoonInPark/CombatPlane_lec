// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_CombatPlane.h"
#include "CP_Pawn_Tick.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_Pawn_Tick : public ACP_Pawn_CombatPlane
{
	GENERATED_BODY()
	
public:
	ACP_Pawn_Tick();

private:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	void MoveForward(float _DeltaTime);
	void MoveForwardAfterTakeOff(float _DeltaTime);
	void MoveForwardWhileTakeOff(float _DeltaTime);
	void MoveForwardWithCurve(float _DeltaTime);
};
