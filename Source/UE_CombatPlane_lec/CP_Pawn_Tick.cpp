// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Pawn_Tick.h"

ACP_Pawn_Tick::ACP_Pawn_Tick()
{
}

void ACP_Pawn_Tick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MoveForwardWithCurve(DeltaTime);
}

void ACP_Pawn_Tick::BeginPlay()
{
	Super::BeginPlay();
}

void ACP_Pawn_Tick::MoveForward(float _DeltaTime)
{
	SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 1000.f, 0.f, 0.f));
}

void ACP_Pawn_Tick::MoveForwardAfterTakeOff(float _DeltaTime)
{
	if (GetActorLocation().Z < 1000.f)
		SetActorLocation(GetActorLocation() + FVector(0.f, 0.f, _DeltaTime * 500.f));
	else
		SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 1000.f, 0.f, 0.f));
}

void ACP_Pawn_Tick::MoveForwardWhileTakeOff(float _DeltaTime)
{
	SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 100.f, 0.f, _DeltaTime *_DeltaTime * 750.f));
}

void ACP_Pawn_Tick::MoveForwardWithCurve(float _DeltaTime)
{
	SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 100.f, 0.f, _DeltaTime *_DeltaTime * 750.f));
	SetActorRotation(GetActorRotation() + FRotator(_DeltaTime * 5.f, 0.f, 0.f));
}

