// Fill out your copyright notice in the Description page of Project Settings.


#include "RootLevel.h"

// Sets default values
ARootLevel::ARootLevel()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARootLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARootLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARootLevel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARootLevel::GoToNewLocation(const FVector& newPos, const FRotator& newRot)
{
	TeleportTo(newPos, newRot);
}


