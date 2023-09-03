// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Pawn.h"

// Sets default values
ACP_Pawn::ACP_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BODY"));
	pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	RootComponent = pMeshComponent;
	pCamera->SetupAttachment(pMeshComponent);
	pCamera->SetRelativeLocation(FVector(-500.f, 0.f, 300.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(TEXT("/Script/Engine.SkeletalMesh'/Game/_01_BasicSettings/SkeletalMeshes/SK_West_UAV_MQ1.SK_West_UAV_MQ1'"));
	if (SK_BODY.Succeeded())
	{
		pMeshComponent->SetSkeletalMesh(SK_BODY.Object);
	}
	/*
	* 책에 나온 대로 Pawn 인스턴스를 월드에 배치한 상태로 각 컴포넌트를 선택하여 위치를 조정한 뒤 그것의 값을 C++ 클래스 내에 코딩해 주어도 된다.
	* 다만 그렇게 하면 좀 번거로우니, 블프로 상속해서 변경하는 법을 알아보자.
	* 이 때, 블프를 DefaultPawn으로 설정하려면 GameModeBase와 PlayerController도 블프로 상속하여서 설정해야 한다.
	* C++에셔 블프를 참조하는 건 비추! 즉 [C++ -> 블프]로 워크플로우를 짜는 게 좋다.
	*/
	
	
}

// Called when the game starts or when spawned
void ACP_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACP_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACP_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

