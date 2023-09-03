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
	* å�� ���� ��� Pawn �ν��Ͻ��� ���忡 ��ġ�� ���·� �� ������Ʈ�� �����Ͽ� ��ġ�� ������ �� �װ��� ���� C++ Ŭ���� ���� �ڵ��� �־ �ȴ�.
	* �ٸ� �׷��� �ϸ� �� ���ŷο��, ������ ����ؼ� �����ϴ� ���� �˾ƺ���.
	* �� ��, ������ DefaultPawn���� �����Ϸ��� GameModeBase�� PlayerController�� ������ ����Ͽ��� �����ؾ� �Ѵ�.
	* C++���� ������ �����ϴ� �� ����! �� [C++ -> ����]�� ��ũ�÷ο츦 ¥�� �� ����.
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

