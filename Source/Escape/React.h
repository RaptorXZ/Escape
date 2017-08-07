// Copyright Patrik Jarnesand 2016

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Components/TimelineComponent.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "React.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UReact : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReact();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Rotates the object
	virtual void Rotate();

	// Rotates the object back
	virtual void RotateBack();

	// Function called when player interacts with this object
	UFUNCTION()
	void UReaction();

	// Function handling the object's rotation progress
	UFUNCTION()
	void HandleProgress(float Value);

	/// Creates an outline around the object when it's looked at to highlight it
	UFUNCTION()
	void CreateOutline();

	UPROPERTY()
	AActor* Owner = GetOwner();

	UPROPERTY()
	UStaticMeshComponent* MeshComp = nullptr;

	// If true, this object will be highlighted when looked at within interactable
	// reach by the player
	UPROPERTY(EditAnywhere, Category = "Highlight")
	bool bShouldHighlight = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Text displayed when this object is interacted with.
	// If left blank, no text will be displayed.
	UPROPERTY(EditAnywhere, Category = "Text", meta = (MultiLine))
	FString Text = "";

	// If true, this object will rotate when interacted with
	UPROPERTY(EditAnywhere, Category = "Rotation")
	bool bShouldRotate = false;

	// If true, this object can be rotated back to its original rotation
	// if interacted with again
	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (EditCondition = bShouldRotate))
	bool bCanRotateBack = false;

	// Amount by which this object will rotate by Yaw when interacted with
	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (EditCondition = bShouldRotate))
	float YawRotation;

	// Amount by which this object will rotate by Pitch when interacted with
	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (EditCondition = bShouldRotate))
	float PitchRotation;

	// Amount by which this object will rotate by Roll when interacted with
	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (EditCondition = bShouldRotate))
	float RollRotation;

	// Curve used to lerp the object between rotations
	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (EditCondition = bShouldRotate))
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