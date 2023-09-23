// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Pawn_AnimInst.h"
#include "CP_AI_CombatPlane.h"

ACP_Pawn_AnimInst::ACP_Pawn_AnimInst()
{
	/*
	pMeshComp->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> COMBATPLANE_ANIM(TEXT("/Game/_01_BasicSettings/Animations/ABP_CombatPlane.ABP_CombatPlane"));
	if (COMBATPLANE_ANIM.Succeeded())
	{
		pMeshComp->SetAnimInstanceClass(COMBATPLANE_ANIM.Class);
	}
	*/
}

void ACP_Pawn_AnimInst::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UAnimInstance* CurrentAnimInstance = pMeshComp->GetAnimInstance();

	if (!CurrentAnimInstance)
	{
		pAnimInstance = NewObject<UCP_AI_CombatPlane>(pMeshComp, UCP_AI_CombatPlane::StaticClass());
		pMeshComp->SetAnimInstanceClass(pAnimInstance->GetClass());
	}
	else 
	{
		pAnimInstance = Cast<UCP_AI_CombatPlane>(CurrentAnimInstance);
		CPLOG(Warning, TEXT(" pAnimInstance : "), *pAnimInstance->GetName());
	}
}

void ACP_Pawn_AnimInst::Tick(float _DelatTime)
{
	Super::Tick(_DelatTime);

	const FPawnMovement PawnMovement = { DeltaRotation, AddLocalMove(_DelatTime)};
	pAnimInstance = pMeshComp->GetAnimInstance();
	ICP_Pawn_To_AnimInstance::Execute_PropellerTypeTick(pAnimInstance, PawnMovement);
}

float ACP_Pawn_AnimInst::AddLocalMove(float _DeltaTime)
{
	LocalMove_Delta = FMath::FInterpTo(LocalMove_Delta, 10000.f, _DeltaTime, 0.25f);
	const FVector LocalMove_AnimInst = FVector(_DeltaTime * LocalMove_Delta, 0.f, 0.f);
	AddActorLocalOffset(LocalMove_AnimInst);

	return LocalMove_AnimInst.X;
}

void ACP_Pawn_AnimInst::PropellerTypeTick_Implementation(FPawnMovement _PawnMovement)
{
}

void ACP_Pawn_AnimInst::JetEngineTypeTick_Implementation(FPawnMovement _PawnMovement)
{
}

void ACP_Pawn_AnimInst::BeginPlay()
{
	Super::BeginPlay();
}
