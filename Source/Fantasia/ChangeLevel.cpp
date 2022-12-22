// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeLevel.h"

#include "ARBlueprintLibrary.h"
#include "ARHero.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AChangeLevel::AChangeLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("LevelCollider"));
	RootComponent = BoxCollider;
	ChangeLevelButton = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChangeLevelButton"));
	ChangeLevelButton->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AChangeLevel::BeginPlay()
{
	Super::BeginPlay();
	BoxCollider->OnComponentBeginOverlap.AddUniqueDynamic(this, &AChangeLevel::Change);
}

// Called every frame
void AChangeLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangeLevel::Change(UPrimitiveComponent* Component, AActor* actor, UPrimitiveComponent* otherComponent, 
	int i, bool b, const FHitResult& hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, actor->GetClass()->GetName());
	if(actor->GetClass()->GetName() == "ARHero_BP_C")
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, LevelToChange);
		UARBlueprintLibrary::StopARSession();
	}
	
}



