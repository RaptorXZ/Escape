// Copyright Patrik Jarnesand 2016

#pragma once

#include "Components/ActorComponent.h"
#include "React.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UReact : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReact();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Rotates the object
	virtual void Rotate();

	// Rotates the object back
	virtual void RotateBack();

	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Function called when player interacts with this object
	UFUNCTION()
	void UReaction();

	// Function handling the object's rotation progress
	UFUNCTION()
	void HandleProgress(float Value);

	UPROPERTY()
	AActor* Owner = GetOwner();

private:
	// Text displayed when this object is interacted with.
	// If left blank, no text will be displayed.
	UPROPERTY(EditAnywhere, Category = "Reaction: Text", meta = (MultiLine))
	FString MyNote = "";

	// If true, this object will rotate when interacted with
	UPROPERTY(EditAnywhere, Category = "Reaction: Rotation")
	bool bShouldRotate = false;

	// If true, this object can be rotated back to its original rotation
	// if interacted with again
	UPROPERTY(EditAnywhere, Category = "Reaction: Rotation", meta = (EditCondition = bShouldRotate))
	bool bCanRotateBack = false;

	// Amount by which this object will rotate when interacted with
	UPROPERTY(EditAnywhere, Category = "Reaction: Rotation", meta = (EditCondition = bShouldRotate))
	float Rotation;

	// Curve used to lerp the object between rotations
	UPROPERTY(EditAnywhere, Category = "Reaction: Rotation", meta = (EditCondition = bShouldRotate))
	UCurveFloat* CurveFloat = nullptr;

	// Checks whether to rotate the object forth or in reverse
	bool bRotated = false;

	// Object's starting rotation
	FRotator ActorInitialRotation;

	// Object's end rotation
	FRotator TargetRotation;

	// Timeline using the CurveFloat
	FTimeline NewTimeline;
};