// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LiftBase.generated.h"

UCLASS()
class MYCPPPROJECT_API ALiftBase : public AActor
{
	GENERATED_BODY()

private:
	float StartingHeight = 0.0f;
	float EndingHeight = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LiftBase", Meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RootSceneComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LiftBase", Meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* LiftMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LiftBase", Meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* TriggerBox = nullptr;

public:	
	// Sets default values for this actor's properties
	ALiftBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LiftBase")
	float LiftHeight = 0.0f;

	UFUNCTION(BlueprintImplementableEvent, Category = "LifeBase")
	void UpdateLiftHeight();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "LiftBase")
	float GetStartingHeight() const { return StartingHeight; }

	UFUNCTION(BlueprintPure, Category = "LiftBase")
	float GetEndingHeight() const { return EndingHeight; }

private:
	UFUNCTION()
		void OnLiftTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
