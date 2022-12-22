// Fill out your copyright notice in the Description page of Project Settings.


#include "ARLevel.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AARLevel::AARLevel()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	HeroComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Hero"));
	HeroComponent->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AARLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARLevel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
