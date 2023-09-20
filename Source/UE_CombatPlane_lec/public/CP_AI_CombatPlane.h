// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_To_AnimInstance.h"
#include "Animation/AnimInstance.h"
#include "CP_AI_CombatPlane.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API UCP_AI_CombatPlane : public UAnimInstance, public ICP_Pawn_To_AnimInstance
{
	GENERATED_BODY()
	
	UCP_AI_CombatPlane();

public:
	virtual void NativeUpdateAnimation(float _DeltaSeconds) override;

private:
	virtual void PropellerTypeTick_Implementation(FPawnMovement _PawnMovement) override;
	virtual void JetEngineTypeTick_Implementation(FPawnMovement _PawnMovement) override;

};
