// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_GameModeBase.h"

ACP_GameModeBase::ACP_GameModeBase()
{
	DefaultPawnClass = ACP_Pawn::StaticClass();
	PlayerControllerClass = ACP_PlayerController::StaticClass();
}

void ACP_GameModeBase::PostLogin(APlayerController* _NewPlayer)
{
	Super::PostLogin(_NewPlayer);
}
