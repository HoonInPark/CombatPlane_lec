// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_To_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CP_CharacterMovementComp.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API UCP_CharacterMovementComp : public UCharacterMovementComponent, public ICP_Pawn_To_AnimInstance
{
	GENERATED_BODY()
	
	UCP_CharacterMovementComp();

protected:
	virtual void InitializeComponent() override;
	virtual void TickComponent(float _DeltaSeconds, enum ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction) override;
	
#pragma region ForMultiplay
	virtual void SimulatedTick(float _DeltaSeconds) override;
	virtual void SimulateMovement(float _DeltaTime) override;
	virtual void OnMovementUpdated(float _DeltaSeconds, const FVector& _OldLocation, const FVector& OldVelocity);
#pragma endregion ForMultiplay

private:
	virtual void PropellerTypeTick_Implementation(FPawnMovement _PawnMovement) override;
	virtual void JetEngineTypeTick_Implementation(FPawnMovement _PawnMovement) override;
};
