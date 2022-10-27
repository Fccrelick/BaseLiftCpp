// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftBase.h"
#include "ThirdPersonCharacterBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ALiftBase::ALiftBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates the root component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	// Create the static mesh component
	LiftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LiftMesh"));
	LiftMesh->SetupAttachment(RootSceneComponent);

	// Create the box component
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(LiftMesh);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALiftBase::OnLiftTriggered);

}

// Called when the game starts or when spawned
void ALiftBase::BeginPlay()
{
	Super::BeginPlay();
	
	StartingHeight = GetActorLocation().Z;
	EndingHeight = StartingHeight + LiftHeight;

}

// Called every frame
void ALiftBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALiftBase::OnLiftTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AThirdPersonCharacterBase* thirdPersonChar = Cast<AThirdPersonCharacterBase>(OtherActor);

	if (thirdPersonChar != nullptr)
	{
		// Update Lift Height
		UpdateLiftHeight();
	}

}

