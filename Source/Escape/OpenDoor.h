// Copyright Patrik Jarnesand 2016

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called when pressure plate opens door
	virtual void OpenDoor();

	// Called when door closes
	virtual void CloseDoor();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Max rotation we want the door to open up to
	UPROPERTY(EditAnywhere, Category = "Timeline")
	float OpenDegree = -90.0f;

	// The Curve used to lerp the door between open and closed
	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* CurveFloat;

	// Bool that tells us if the door is open or closed. Editable in editor
	// so that doors can start as being either opened or closed initially
	UPROPERTY(EditAnywhere)
	bool Open = false;

private:
	// Door's starting rotation
	FRotator ActorInitialRotation;

	// Door's open rotation
	FRotator TargetRotation;

	// Timeline using the Curve
	FTimeline NewTimeline;

	// Function handling the door's rotation progress
	UFUNCTION()
	void HandleProgress(float Value);

	// The Trigger Volume causing the door to open
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	// The Actor able to open the door with the Trigger Volume
	UPROPERTY(VisibleAnywhere)
	AActor* ActorThatOpens; //Pawn inherits from actor

	// The door
	AActor* Owner = GetOwner();
};