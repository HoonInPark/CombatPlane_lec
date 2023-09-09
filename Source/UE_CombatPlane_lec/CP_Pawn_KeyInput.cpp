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

	FRotator DelatRotation;
	DelatRotation.Pitch = CurrentSpeed_Pitch * DeltaTime;
	DelatRotation.Yaw = CurrentSpeed_Yaw * DeltaTime;

	AddActorLocalRotation(DelatRotation);
}

void ACP_Pawn_KeyInput::SetupPlayerInputComponent(UInputComponent* _InputComponent)
{
	Super::SetupPlayerInputComponent(_InputComponent);
	/*
	* Roll : °¼¿ì¶×(X)
	* Pitch : ²ô´ö²ô´ö(Y)
	* Yaw : µµ¸®µµ¸®(Z)
	*/
	_InputComponent->BindAxis(TEXT("LookUp"), this, &ACP_Pawn_KeyInput::ProcessPitch);
	_InputComponent->BindAxis(TEXT("TurnAround"), this, &ACP_Pawn_KeyInput::ProcessYaw);
}

void ACP_Pawn_KeyInput::ProcessPitch(float _Value)
{
	const float TargetSpeedPitch = _Value * AxisSpeed;
	CurrentSpeed_Pitch = TargetSpeedPitch;
}

void ACP_Pawn_KeyInput::ProcessYaw(float _Value)
{
	const float TargetSpeedYaw = _Value * AxisSpeed;
	CurrentSpeed_Yaw = TargetSpeedYaw;
}
