// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_Construct.h"
#include "CP_Pawn_KeyInput.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_Pawn_KeyInput : public ACP_Pawn_Construct
{
	GENERATED_BODY()

	ACP_Pawn_KeyInput();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* _InputComponent) override;

public:
	UPROPERTY()
	USpringArmComponent* pSpringArm;

private:
	const FRotator DefaultSpringArmRotation{ FRotator(-15.f, 0.f, 0.f) };

	void ProcessPitch(float _Value);
	void ProcessYaw(float _Value);
};
