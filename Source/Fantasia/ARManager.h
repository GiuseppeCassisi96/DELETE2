// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AugmentedReality/Public/ARBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "ARLevel.h"
#include "ARHero.h"
#include "RootLevel.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "ARManager.generated.h"

UCLASS()
class FANTASIA_API AARManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AARManager();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ARSessionData")
	UARSessionConfig* ARSession;
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere, Category = "Hero")
	TSubclassOf<AARHero> hero;
	UPROPERTY(EditAnywhere, Category = "CurrentLevel")
	TSubclassOf<APawn> levelClass;
	UPROPERTY(EditAnywhere, Category = "SpawnPoints")
	TSubclassOf<AActor> Spawns;

	UPROPERTY()
	AARHero* sHero;
	UPROPERTY()
	APawn* sLevel;
	TArray<AActor*> sSpawns;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY()
	UARTrackedGeometry* ARCorePlane;
	UPROPERTY(BlueprintReadWrite)
	bool bScanIsComplete;
	UPROPERTY(BlueprintReadWrite)
	bool bIsTracked;
	UPROPERTY(BlueprintReadWrite)
	bool bIsSpawned;
	FTransform planeTr;
	FVector2D ScreenSize;
	TArray<UARTrackedGeometry*> Results;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void InputTouch(ETouchIndex::Type fingerIndex, FVector location);
	void ForwardMovement(float inputValue);
	void RightMovement(float inputValue);
	void JumpAction();
	void StopJumpAction();

};
