// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Character.h"
#include "CP_CharacterMovementComp.h"

// Sets default values
ACP_Character::ACP_Character(const FObjectInitializer& _ObjectInitializer) 
	: Super(_ObjectInitializer.SetDefaultSubobjectClass<UCP_CharacterMovementComp>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ThisMovComp = CastChecked<UCP_CharacterMovementComp>(GetCharacterMovement());

	pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMREA"));

	pSpringArm->SetupAttachment(GetCapsuleComponent());
	pSpringArm->TargetArmLength = 1000.f;
	pSpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));
	pSpringArm->bEnableCameraLag = true;

	pCamera->SetupAttachment(pSpringArm);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_PLANE(TEXT("/Script/Engine.SkeletalMesh'/Game/_01_BasicSettings/SkeletalMeshes/SK_West_UAV_MQ1.SK_West_UAV_MQ1'"));
	if (SK_PLANE.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_PLANE.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator::ZeroRotator);
	}

	bUseControllerRotationPitch = true;
	bUseControllerRotationRoll = true;
	bUseControllerRotationYaw = true;
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

void ACP_Character::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	UAnimInstance* CurrentAnimInstance = GetMesh()->GetAnimInstance();
	if (!CurrentAnimInstance)
	{
		ThisAnimInst = NewObject<UCP_AI_CombatPlane>(GetMesh(), UCP_AI_CombatPlane::StaticClass());
		GetMesh()->SetAnimInstanceClass(ThisAnimInst->GetClass());
		CPLOG(Warning, TEXT(" Anim Instance : %s"), *GetMesh()->GetAnimInstance()->GetName());
	}
	else
		ThisAnimInst = CurrentAnimInstance;
	
}

// Called to bind functionality to input
void ACP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

