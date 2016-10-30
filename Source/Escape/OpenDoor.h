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

private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = 120.0f;

	UPROPERTY(VisibleAnywhere)
	float ClosedAngle = 180.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(VisibleAnywhere)
	AActor* ActorThatOpens; //Pawn inherits from actor
	
};
