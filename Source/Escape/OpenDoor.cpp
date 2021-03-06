// Copyright Patrik Jarnesand 2016

#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Pressure Plate"), *GetOwner()->GetName());
	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	//Get the door's starting rotation and set it as the Initial Rotation and Target Rotation
	ActorInitialRotation = TargetRotation = Owner->GetActorRotation();
	//Add the value we want the door to open to
	TargetRotation.Yaw += OpenDegree;

	/// Iterate through the object's components to get its Audio component
	TArray<UAudioComponent*> Components;
	Owner->GetComponents<UAudioComponent>(Components);
	for (int32 i = 0; i < Components.Num(); i++)
	{
		AudioComp = Cast<UAudioComponent>(Components[i]);
	}
}

// This function handles the actual rotation of the door
void UOpenDoor::HandleProgress(float Value)
{
	//Create a lerp between the door's initial rotation and the target rotation
	FRotator NewRotation = FMath::Lerp(ActorInitialRotation, TargetRotation, Value);
	//Rotate the door
	Owner->SetActorRotation(NewRotation);
}

// Called when door opens
void UOpenDoor::OpenDoor()
{
	//Make sure a Curve has been assigned to avoid errors
	if (CurveFloat)
	{
		//Assigning function that handles the rotation of the door
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));

		//Set up the timeline and set looping to false
		NewTimeline.AddInterpFloat(CurveFloat, ProgressFunction);
		NewTimeline.SetLooping(false);

		//Play timeline to open the door
		NewTimeline.Play();

		if (AudioComp != nullptr)
		{
			AudioComp->Play();
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Curve Float"), *GetOwner()->GetName());
	}
}

// Called when door closes
void UOpenDoor::CloseDoor()
{
	//Make sure a Curve has been assigned to avoid errors
	if (CurveFloat)
	{
		//Assigning function that handles the rotation of the door
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));

		//Set up the timeline and set looping to false
		NewTimeline.AddInterpFloat(CurveFloat, ProgressFunction);
		NewTimeline.SetLooping(false);

		//Play timeline in reverse to shut the door
		NewTimeline.Reverse();

		if (AudioComp != nullptr)
		{
			AudioComp->Play();
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Curve Float"), *GetOwner()->GetName());
	}
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll the Trigger Volume every frame
	//If the ActorThatOpens is in the volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//If the door isn't already open, open it
		if (!Open)
		{
			OpenDoor();
			Open = true;
		}
	}
	else //If the ActorThatOpens is not in the trigger volume
	{
		//If the door is open, close it
		if (Open)
		{
			CloseDoor();
			Open = false;
		}
	}

	//Tick the timeline every frame
	NewTimeline.TickTimeline(DeltaTime);
}