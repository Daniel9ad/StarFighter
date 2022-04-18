// Fill out your copyright notice in the Description page of Project Settings.


#include "NavePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "NavePawn.h"

ANavePlayerController::ANavePlayerController()
{
}

void ANavePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &ANavePlayerController::MoveHorizontal);
	InputComponent->BindAxis("MoveVertical", this, &ANavePlayerController::MoveVertical);
}

void ANavePlayerController::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void ANavePlayerController::MoveHorizontal(float xValue)
{
	auto MyPawn = Cast<ANavePawn>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(xValue);
	}
}

void ANavePlayerController::MoveVertical(float zValue)
{
	auto MyPawn = Cast<ANavePawn>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveVertical(zValue);
	}
}
