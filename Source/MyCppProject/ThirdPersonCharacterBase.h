// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdPersonCharacterBase.generated.h"

UCLASS()
class MYCPPPROJECT_API AThirdPersonCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// The Health of the player.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ThirdPersonCharacterBase")
	float Health = 0.0f;

	// Gets the Player health.
	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	float GetHealth() const;

	// Sets the Player health.
	UFUNCTION(BlueprintCallable)
	void SetHealth(float new_health) { Health = new_health; }
public:
	// Sets default values for this character's properties
	AThirdPersonCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
