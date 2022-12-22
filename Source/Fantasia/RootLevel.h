// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RootLevel.generated.h"

UCLASS()
class FANTASIA_API ARootLevel : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARootLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void GoToNewLocation(const FVector& newPos, const FRotator& newRot);
};
