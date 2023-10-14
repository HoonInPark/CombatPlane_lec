// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_CharacterMovementComp.h"
#include "CP_Character.h"

UCP_CharacterMovementComp::UCP_CharacterMovementComp()
{
	PrimaryComponentTick.bCanEverTick = true;

	MovementMode = EMovementMode::MOVE_Flying;
	GravityScale = 0.f;

	MaxFlySpeed = 1000.f;
	bOrientRotationToMovement = false;
	RotationRate = FRotator(0.f, 720.f, 0.f);
}

void UCP_CharacterMovementComp::InitializeComponent()
{
	Super::InitializeComponent();

	//pAnimInst = CastChecked<ACP_Character>(GetOwner()->GetThisAnimIn)
}

#pragma region ForMultiplay
void UCP_CharacterMovementComp::SimulatedTick(float _DeltaSeconds)
{
}

void UCP_CharacterMovementComp::SimulateMovement(float _DeltaTime)
{
}

void UCP_CharacterMovementComp::OnMovementUpdated(float _DeltaSeconds, const FVector& _OldLocation, const FVector& OldVelocity)
{
}
#pragma endregion ForMultiplay

void UCP_CharacterMovementComp::PropellerTypeTick_Implementation(FPawnMovement _PawnMovement)
{
}

void UCP_CharacterMovementComp::JetEngineTypeTick_Implementation(FPawnMovement _PawnMovement)
{
}

void UCP_CharacterMovementComp::TickComponent(float _DeltaSeconds, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction)
{
	Super::TickComponent(_DeltaSeconds, _TickType, _ThisTickFunction);

	AddForce(FVector(MaxFlySpeed, 0.f, 0.f));

	const FPawnMovement PawnMovement = { GetDeltaRotation(_DeltaSeconds), MaxFlySpeed * _DeltaSeconds };
	//Execute_PropellerTypeTick();
}
