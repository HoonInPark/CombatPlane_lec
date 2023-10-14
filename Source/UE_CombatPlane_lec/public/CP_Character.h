// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_AI_CombatPlane.h"
#include "GameFramework/Character.h"
#include "CP_Character.generated.h"

UCLASS()
class UE_COMBATPLANE_LEC_API ACP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACP_Character(const FObjectInitializer& _ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = Movement)
	class UCP_CharacterMovementComp* GetThisMovComp() const { return ThisMovComp; }
	UFUNCTION(BlueprintCallable, Category = AnimInst)
	class UAnimInstance* GetThisAnimInst() { return ThisAnimInst; }

private:
	UPROPERTY()
	UCP_CharacterMovementComp* ThisMovComp;
	UPROPERTY()
	UAnimInstance* ThisAnimInst;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PreInitializeComponents() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* pSpringArm;
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* pCamera;
};
