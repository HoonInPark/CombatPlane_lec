// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Pawn_KeyInput.h"

ACP_Pawn_KeyInput::ACP_Pawn_KeyInput()
{
	pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));

	pSpringArm->SetupAttachment(pMeshComp);
	pCamera->SetupAttachment(pSpringArm);
	pCamera->SetRelativeLocation(FVector::ZeroVector);

	pSpringArm->TargetArmLength = 1000.f;
	pSpringArm->SetRelativeLocationAndRotation(FVector(0.f, 0.f, 150.f), DefaultSpringArmRotation);
}

void ACP_Pawn_KeyInput::BeginPlay()
{
	Super::BeginPlay();

	//CPLOG(Warning, TEXT(" pMeshComp is %s"), *pMeshComp->GetName());
}

void ACP_Pawn_KeyInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACP_Pawn_KeyInput::SetupPlayerInputComponent(UInputComponent* _InputComponent)
{
	Super::SetupPlayerInputComponent(_InputComponent);

	_InputComponent->BindAxis(TEXT("LookUp"), this, &ACP_Pawn_KeyInput::ProcessPitch);
	_InputComponent->BindAxis(TEXT("TurnAround"), this, &ACP_Pawn_KeyInput::ProcessYaw);
}

void ACP_Pawn_KeyInput::ProcessPitch(float _Value)
{
}

void ACP_Pawn_KeyInput::ProcessYaw(float _Value)
{
}
