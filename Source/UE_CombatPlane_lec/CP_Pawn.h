// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "GameFramework/Pawn.h"
#include "CP_Pawn.generated.h"

UCLASS()
class UE_COMBATPLANE_LEC_API ACP_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACP_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, Category = CombatPlane)
	USkeletalMeshComponent* pMeshComponent;
	UPROPERTY(VisibleAnywhere, Category = CombatPlane)
	UCameraComponent* pCamera;
	
};
