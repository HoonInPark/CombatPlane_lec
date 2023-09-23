// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Character.h"

// Sets default values
ACP_Character::ACP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMREA"));

	pSpringArm->SetupAttachment(GetCapsuleComponent());
	pSpringArm->TargetArmLength = 1000.f;
	pSpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));

	pCamera->SetupAttachment(pSpringArm);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_PLANE(TEXT("/Script/Engine.SkeletalMesh'/Game/_01_BasicSettings/SkeletalMeshes/SK_West_UAV_MQ1.SK_West_UAV_MQ1'"));
	if (SK_PLANE.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_PLANE.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator::ZeroRotator);
	}

}

// Called when the game starts or when spawned
void ACP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

