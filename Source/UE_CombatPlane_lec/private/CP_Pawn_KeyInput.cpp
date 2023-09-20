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

#pragma region AxisMapping
	/*
	FRotator DelatRotation;
	DelatRotation.Pitch = CurrentSpeed_Pitch * DeltaTime;
	DelatRotation.Yaw = CurrentSpeed_Yaw * DeltaTime;

	AddActorLocalRotation(DelatRotation);
	AddActorLocalOffset(FVector(DeltaTime * 10000.f, 0.f, 0.f));
	*/
#pragma endregion AxisMapping

#pragma region InterpAxisMapping
	DeltaRotation.Pitch = CurrentSpeed_Pitch * DeltaTime;
	DeltaRotation.Yaw = CurrentSpeed_Yaw * DeltaTime;
	DeltaRotation.Roll = CurrentSpeed_Roll * DeltaTime + StabilizeRoll(DeltaTime);

	AddActorLocalRotation(DeltaRotation);
	AddActorLocalOffset(FVector(5000.f * DeltaTime, 0.f, 0.f));
#pragma endregion InterpAxisMapping

	pSpringArm->AddLocalRotation(0.1f * DeltaRotation.GetInverse());
	StabilizeSpringArm(DeltaTime);
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
	CurrentSpeed_Pitch = FMath::FInterpTo(CurrentSpeed_Pitch, TargetSpeedPitch, GetWorld()->GetDeltaSeconds(), 2.f);
}

void ACP_Pawn_KeyInput::ProcessYaw(float _Value)
{
	const float TargetSpeedYaw = _Value * AxisSpeed;
	CurrentSpeed_Yaw = FMath::FInterpTo(CurrentSpeed_Yaw, TargetSpeedYaw, GetWorld()->GetDeltaSeconds(), 2.f);

	const float TargetSpeed_Roll = _Value * AxisSpeed;
	CurrentSpeed_Roll = FMath::FInterpTo(CurrentSpeed_Roll, TargetSpeed_Roll, GetWorld()->GetDeltaSeconds(), 2.f);
}

float ACP_Pawn_KeyInput::StabilizeRoll(float _DeltaTime)
{
	const float CurrentAngle_Roll = GetActorRotation().Roll;
	const float TargetSpeed_Roll = -CurrentAngle_Roll * 1.f;
	CurrentSpeed_Roll = FMath::FInterpTo(CurrentSpeed_Roll, TargetSpeed_Roll, _DeltaTime, 2.f);

	return CurrentSpeed_Roll * _DeltaTime;
}

void ACP_Pawn_KeyInput::StabilizeSpringArm(float _DeltaTime)
{
	if (pSpringArm->GetRelativeRotation() != DefaultSpringArmRotation)
		pSpringArm->SetRelativeRotation(FMath::RInterpTo(pSpringArm->GetRelativeRotation(), DefaultSpringArmRotation, _DeltaTime, 1.f));
}
