// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GuideController.generated.h"

UCLASS()
class ASSIGNMENT_API AGuideController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGuideController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> GuideTextWidget;

	TWeakObjectPtr<class UUserWidget> pGuideTextWidget;

	TWeakObjectPtr<class UTextBlock> pGuideText;

	UFUNCTION(BlueprintCallable, Category = "Guide")
	void SetGuideText(FString guide);
};
