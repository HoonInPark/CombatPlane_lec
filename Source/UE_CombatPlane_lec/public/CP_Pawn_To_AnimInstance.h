// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "UObject/Interface.h"
#include "CP_Pawn_To_AnimInstance.generated.h"

USTRUCT(BlueprintType)
struct FPawnMovement 
{
	GENERATED_BODY()

	UPROPERTY()
	FRotator Speed_Rotator;
	UPROPERTY()
	float Speed_Move;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCP_Pawn_To_AnimInstance : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE_COMBATPLANE_LEC_API ICP_Pawn_To_AnimInstance
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void PropellerTypeTick(FPawnMovement _PawnMovement);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interface")
	void JetEngineTypeTick(FPawnMovement _PawnMovement);
};
