// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ChangeLevel.generated.h"

UCLASS()
class FANTASIA_API AChangeLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChangeLevel();
	UPROPERTY(EditAnywhere, Category="ChangeLevelCollider")
	UBoxComponent* BoxCollider;
	UPROPERTY(EditAnywhere, Category = "MeshChangeLevel")
	UStaticMeshComponent* ChangeLevelButton;
	UPROPERTY(EditAnywhere, Category = "LevelToChange")
	TSoftObjectPtr<UWorld> LevelToChange;
	UFUNCTION()
	void Change(UPrimitiveComponent* Component, AActor* actor, UPrimitiveComponent* otherComponent, 
		int i, bool b, const FHitResult& hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
