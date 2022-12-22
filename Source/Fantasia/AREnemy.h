// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/PawnSensingComponent.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "AREnemy.generated.h"

UCLASS()
class FANTASIA_API AAREnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAREnemy();
	UPROPERTY(EditAnywhere, Category="PawnAI")
	UPawnSensingComponent* PawnSensing;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void MoveTowardsTheHero(APawn* heroPawn);
};
