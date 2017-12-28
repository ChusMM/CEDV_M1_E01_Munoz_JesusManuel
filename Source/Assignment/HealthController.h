// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthController.generated.h"

UCLASS()
class ASSIGNMENT_API AHealthController : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AHealthController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> HealthTextWidget;

	TWeakObjectPtr<class UUserWidget> pHealthTextWidget;

	TWeakObjectPtr<class UTextBlock> pHealthText;
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	int GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetHealth(int health);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void decreaseHealth(int amount);

private:
	int health;
	
};
