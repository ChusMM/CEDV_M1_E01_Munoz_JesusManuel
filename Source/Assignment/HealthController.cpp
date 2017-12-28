// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthController.h"
#include "Blueprint/UserWidget.h"
#include "TextWidgetTypes.h"
#include "TextBlock.h"

// Sets default values
AHealthController::AHealthController() : health(0) {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHealthController::BeginPlay() {
	Super::BeginPlay();

	if (HealthTextWidget) {
		pHealthTextWidget = CreateWidget<UUserWidget>(GetGameInstance(), HealthTextWidget); // (1)
		
		if (pHealthTextWidget.IsValid()) {
			pHealthTextWidget->AddToViewport(); // (2)
			pHealthText = (UTextBlock*)pHealthTextWidget -> GetWidgetFromName("HealthText"); // (3)
			SetHealth(20);
		}
	}
}

// Called every frame
void AHealthController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

int AHealthController::GetHealth() const {
	return health;
}

void AHealthController::SetHealth(int amount) {
	if (pHealthText.IsValid()) {
		health = amount;
		pHealthText->SetText(FText::FromString("Health: " + FString::FromInt(health)));
	}
}

void AHealthController::decreaseHealth(int amount) {
	if (pHealthText.IsValid()) {
		this->health -= amount;
		pHealthText->SetText(FText::FromString("Health: " + FString::FromInt(health)));
	}
}

