// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_AI_CombatPlane.h"

void UCP_AI_CombatPlane::NativeUpdateAnimation(float _DeltaSeconds)
{
	Super::NativeUpdateAnimation(_DeltaSeconds);

	InterpPawnSpeed(_DeltaSeconds, PawnMovement_Tick);
	ProcessSpeed(PawnMovement_AnimInst);
}

void UCP_AI_CombatPlane::PropellerTypeTick_Implementation(FPawnMovement _PawnMovement)
{
	PawnMovement_Tick = _PawnMovement;
}

void UCP_AI_CombatPlane::JetEngineTypeTick_Implementation(FPawnMovement _PawnMovement)
{
}

void UCP_AI_CombatPlane::InterpPawnSpeed(float _DeltaSeconds, const FPawnMovement& _PawnMovement)
{
	PawnMovement_AnimInst.Speed_Rotator = FMath::RInterpTo(PawnMovement_AnimInst.Speed_Rotator, _PawnMovement.Speed_Rotator, _DeltaSeconds, 1.f);
	PawnMovement_AnimInst.Speed_Move = FMath::FInterpTo(PawnMovement_AnimInst.Speed_Move, _PawnMovement.Speed_Move, _DeltaSeconds, 1.f);
}

void UCP_AI_CombatPlane::ProcessSpeed(const FPawnMovement& _PawnMovement)
{
	Aileron_rt = FMath::Clamp(-40.f * _PawnMovement.Speed_Rotator.Roll - 40.f, -40.f, 40.f);
	Aileron_lf = FMath::Clamp(40.f * _PawnMovement.Speed_Rotator.Roll - 40.f, -40.f, 40.f);
	Elevator = FMath::Clamp(-40.f * _PawnMovement.Speed_Rotator.Pitch, -40.f, 40.f);
	Rudder = FMath::Clamp(-40.f * _PawnMovement.Speed_Rotator.Yaw, -40.f, 40.f);

	if (Propeller < 360.f)
		Propeller += PawnMovement_AnimInst.Speed_Move / 100.f * 360.f;
	else
		Propeller += -360.f + PawnMovement_AnimInst.Speed_Move / 100.f * 360.f;
}
