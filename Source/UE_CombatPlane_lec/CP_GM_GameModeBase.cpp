// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_GM_GameModeBase.h"

ACP_GM_GameModeBase::ACP_GM_GameModeBase()
{
	DefaultPawnClass = ACP_Pawn_Tick::StaticClass();
	PlayerControllerClass = ACP_PC_CombatPlaneController::StaticClass();
}

void ACP_GM_GameModeBase::PostLogin(APlayerController* _NewPlayer)
{
	Super::PostLogin(_NewPlayer);
}
