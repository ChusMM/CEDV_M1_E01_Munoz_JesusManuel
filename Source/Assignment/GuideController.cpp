// Fill out your copyright notice in the Description page of Project Settings.

#include "GuideController.h"
#include "Blueprint/UserWidget.h"
#include "TextWidgetTypes.h"
#include "TextBlock.h"

// Sets default values
AGuideController::AGuideController() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGuideController::BeginPlay() {
	Super::BeginPlay();
	
	if (GuideTextWidget) {
		pGuideTextWidget = CreateWidget<UUserWidget>(GetGameInstance(), GuideTextWidget); // (1)

		if (pGuideTextWidget.IsValid()) {
			pGuideTextWidget->AddToViewport(); // (2)
			pGuideText = (UTextBlock*)pGuideTextWidget->GetWidgetFromName("GuideText"); // (3)
			SetGuideText("");
		}
	}
}

// Called every frame
void AGuideController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AGuideController::SetGuideText(FString guide) {
	if (pGuideText.IsValid()) {
		pGuideText->SetText(FText::FromString(guide));
	}
}

