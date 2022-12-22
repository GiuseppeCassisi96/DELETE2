// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class FANTASIA_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* TutorialButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* QuitButton;
	UPROPERTY(EditDefaultsOnly, Category= "LevelToLoad")
	TSoftObjectPtr<UWorld> levelToload;
	virtual void NativeConstruct() override;
	UFUNCTION()
		void InitTutorial();
	UFUNCTION()
		void QuitGame();
	
};
