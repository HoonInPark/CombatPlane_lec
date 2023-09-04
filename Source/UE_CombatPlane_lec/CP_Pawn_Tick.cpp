// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Pawn_Tick.h"

ACP_Pawn_Tick::ACP_Pawn_Tick()
{
}

void ACP_Pawn_Tick::BeginPlay()
{
	Super::BeginPlay();

}

void ACP_Pawn_Tick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//CPLOG(Warning, TEXT(" DelataTime : %f"), DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(DeltaTime * 500.f, 0.f, DeltaTime * DeltaTime * 5000.f));
	SetActorRotation(GetActorRotation() + FRotator(DeltaTime * 10.f, 0.f, 0.f));

}
