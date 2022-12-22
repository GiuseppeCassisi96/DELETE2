// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	TutorialButton->OnClicked.AddUniqueDynamic(this, &UMainMenu::InitTutorial);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UMainMenu::QuitGame);
}
void UMainMenu::InitTutorial()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, levelToload);
}

void UMainMenu::QuitGame()
{
}
