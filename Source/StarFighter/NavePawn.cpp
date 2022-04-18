// Fill out your copyright notice in the Description page of Project Settings.


#include "NavePawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ANavePawn::ANavePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Nave = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Nave"));
	RootComponent = SM_Nave;

	SM_Nave->SetEnableGravity(false);
	SM_Nave->SetConstraintMode(EDOFMode::XZPlane);
	SM_Nave->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Nave->SetCollisionProfileName(TEXT("PhisicActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
}

// Called when the game starts or when spawned
void ANavePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANavePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANavePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ANavePawn::MoveHorizontal(float xValue)
{
	AddMovementInput(FVector(xValue, 0.0f, 0.0f), 1.0f, false);
}

void ANavePawn::MoveVertical(float zValue)
{
	AddMovementInput(FVector(0.0f, 0.0f, zValue), 1.0f, false);
}

