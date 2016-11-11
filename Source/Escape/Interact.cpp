// Copyright Patrik Jarnesand 2016

#include "Escape.h"
#include "Interact.h"

#define OUT

// Sets default values for this component's properties
UInteract::UInteract()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UInteract::BeginPlay()
{
	Super::BeginPlay();
	FindInputComponent();
}

/// Look for attached Input Component (only appears at run-time)
void UInteract::FindInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Interact", IE_Pressed, this, &UInteract::Interact);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName());
	}
}

void UInteract::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Interact pressed"));

	////Line trace and see if we reach any actors set to Interactable
	//FHitResult HitResult = GetFirstInteractableInReach();
	//AActor* ActorHit = HitResult.GetActor();

	if (ActorHit != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()));

		if (ReactComp != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Actor Component found: %s"), *(ReactComp->GetName()));
			ReactComp->UReaction();
		}
	}
}

UReact* UInteract::GetReactComponent(AActor* ActorValue)
{
	UReact* ReactComponent = nullptr;
	TArray<UReact*> Components;
	ActorValue->GetComponents<UReact>(Components);
	for (int32 i = 0; i < Components.Num(); i++)
	{
		ReactComponent = Cast<UReact>(Components[i]);

		if (TEXT("React") == ReactComponent->GetName())
		{
			break;
		}
		else
			ReactComponent = nullptr;
	}
	return ReactComponent;
}

const FHitResult UInteract::GetFirstInteractableInReach()
{
	/// Setup  query parameters
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	/// Linetrace (ray-cast)
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType
		(OUT HitResult,
		 GetReachLineStart(),
		 GetReachLineEnd(),
		 FCollisionObjectQueryParams(ECollisionChannel::ECC_GameTraceChannel1), //GameTraceChannel1 = Interactable
		 TraceParams);
	
	return HitResult;
}

FVector UInteract::GetReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewPointLocation,
			OUT PlayerViewPointRotation);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

FVector UInteract::GetReachLineStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation);

	return PlayerViewPointLocation;
}

// Called every frame
void UInteract::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Line trace and see if we reach any actors set to Interactable
	FHitResult HitResult = GetFirstInteractableInReach();
	ActorHit = HitResult.GetActor();

	if (ActorHit != nullptr)
		ReactComp = GetReactComponent(ActorHit);

	if (ReactComp != nullptr)
		if (ReactComp->bShouldHighlight == true)
			ReactComp->CreateOutline();
}