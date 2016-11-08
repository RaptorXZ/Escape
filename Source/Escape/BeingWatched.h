// Copyright Patrik Jarnesand 2016

#pragma once

#include "Components/ActorComponent.h"
#include "BeingWatched.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UBeingWatched : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBeingWatched();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:

	UPROPERTY(VisibleAnywhere)
	AActor* ActorThatSees = nullptr; //Pawn inherits from actor

	UPROPERTY(VisibleAnywhere)
	AActor* Owner = GetOwner();

	UPROPERTY(EditAnywhere)
	UMaterial* NewMat = nullptr;

	//Player's viewpoint
	UPROPERTY(VisibleAnywhere)
	FRotator LookRotation;
	UPROPERTY(VisibleAnywhere)
	FVector LookVector;

	//Actor's location
	UPROPERTY(VisibleAnywhere)
	FVector OwnerLoc;

	//Rotation for player to look at Actor
	UPROPERTY(VisibleAnywhere)
	FRotator PlayerRot;
	
};
