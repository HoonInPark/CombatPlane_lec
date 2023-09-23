// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_KeyInput.h"
#include "CP_Pawn_To_AnimInstance.h"
#include "CP_Pawn_AnimInst.generated.h"

/**
 * <언리얼에서의 속도 가속도 개념>
 * 다음 예시를 통해 속도 가속도를 알아보자.
 * 
 * 속도 10으로 시작. 근데 프레임당 가속도 1이 붙음.
 *	   1   1   1   1   1      F''(X)
 *	10	11	12	13	14	15    F'(X)
 * 0  10  21  33  47  62  77  F(X)
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_Pawn_AnimInst : public ACP_Pawn_KeyInput, public ICP_Pawn_To_AnimInstance
{
	GENERATED_BODY()
	
	ACP_Pawn_AnimInst();

protected:
	virtual void BeginPlay() override;

private:
	virtual void Tick(float _DelatTime) override;
	virtual void PostInitializeComponents() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=CombatPlane)
	UAnimInstance* pAnimInstance;

private:
	float LocalMove_Delta{ 0.f };
	float AddLocalMove(float _DeltaTime);

private:
	virtual void PropellerTypeTick_Implementation(FPawnMovement _PawnMovement) override;
	virtual void JetEngineTypeTick_Implementation(FPawnMovement _PawnMovement) override;

};
