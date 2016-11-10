// Copyright Patrik Jarnesand 2016

#include "Escape.h"
#include "React.h"

// Sets default values for this component's properties
UReact::UReact()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UReact::BeginPlay()
{
	Super::BeginPlay();

	//Get the door's starting rotation and set it as the Initial Rotation and Target Rotation
	ActorInitialRotation = TargetRotation = Owner->GetActorRotation();
	//Add the value we want the door to open to
	TargetRotation.Yaw += Rotation;
}

void UReact::HandleProgress(float Value)
{
	//Create a lerp between the object's initial rotation and the target rotation
	FRotator NewRotation = FMath::Lerp(ActorInitialRotation, TargetRotation, Value);
	//Rotate the object
	Owner->SetActorRotation(NewRotation);
	UE_LOG(LogTemp, Warning, TEXT("Handling rotation progress"));
}

void UReact::UReaction()
{
	/* If any text has been entered into MyNote string it will be displayed,
		otherwise nothing will show */
	if (MyNote != "")
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *MyNote);
	}

	/* If set, the object will be rotated when interacted with */
	if (bShouldRotate == true)
	{
		if (bCanRotateBack == true && bRotated == false)
		{
			Rotate();
			bRotated = true;
		}
		else if (bCanRotateBack == true && bRotated == true)
		{
			RotateBack();
			bRotated = false;
		}
		else if (bCanRotateBack == false && bRotated == false)
		{
			Rotate();
			bRotated = true;
		}
	}
}

void UReact::Rotate()
{
	//Make sure a Curve has been assigned to avoid errors
	if (CurveFloat)
	{
		//Assigning function that handles the rotation of the object
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));

		//Set up the timeline and set looping to false
		NewTimeline.AddInterpFloat(CurveFloat, ProgressFunction);
		NewTimeline.SetLooping(false);

		//Play timeline to rotate the object
		NewTimeline.Play();
		UE_LOG(LogTemp, Warning, TEXT("%s is rotating to %s"), *Owner->GetName(), *Owner->GetActorRotation().ToString());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Curve Float"), *Owner->GetName());
	}
}

void UReact::RotateBack()
{
	//Make sure a Curve has been assigned to avoid errors
	if (CurveFloat)
	{
		//Assigning function that handles the rotation of the object
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));

		//Set up the timeline and set looping to false
		NewTimeline.AddInterpFloat(CurveFloat, ProgressFunction);
		NewTimeline.SetLooping(false);

		//Play timeline in reverse to rotate the object back
		NewTimeline.Reverse();
		UE_LOG(LogTemp, Warning, TEXT("%s is rotating back to %s"), *Owner->GetName(), *Owner->GetActorRotation().ToString());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Curve Float"), *Owner->GetName());
	}
}

// Called every frame
void UReact::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Tick the timeline every frame
	NewTimeline.TickTimeline(DeltaTime);
}