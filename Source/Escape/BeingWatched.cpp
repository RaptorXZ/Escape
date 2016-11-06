// Copyright Patrik Jarnesand 2016

#include "Escape.h"
#include "BeingWatched.h"


// Sets default values for this component's properties
UBeingWatched::UBeingWatched()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBeingWatched::BeginPlay()
{
	Super::BeginPlay();

	//Find the controlled player Pawn
	ActorThatSees = GetWorld()->GetFirstPlayerController()->GetPawn();

	//Find the location of the owning Actor
	OwnerLoc = Owner->GetActorLocation();
}


// Called every frame
void UBeingWatched::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Find out if the player is looking at the owning Actor
	ActorThatSees->GetActorEyesViewPoint(LookVector, LookRotation);

	// Rotation in which the player is looking at Actor
	PlayerRot = FRotationMatrix::MakeFromX(LookVector - OwnerLoc).Rotator();

	if (LookRotation == PlayerRot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Changing material..."));
		TArray<UStaticMeshComponent*> Components;
		Owner->GetComponents<UStaticMeshComponent>(Components);
		for (int32 i = 0; i < Components.Num(); i++)
		{
			UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(Components[i]);
			MeshComp->SetMaterial(0, NewMat);
		}
	}
}