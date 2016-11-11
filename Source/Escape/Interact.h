// Copyright Patrik Jarnesand 2016

#pragma once

#include "React.h"
#include "Components/ActorComponent.h"
#include "Interact.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReact);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UInteract : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteract();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UClass* MyClass = UReact::StaticClass();
	TSubclassOf<UReact> ReactClass = MyClass;

	// Returns the React script on the hit actor
	UReact* GetReactComponent(class AActor* ActorValue);

private:
	// How far the player can interact with objects (in cm)
	UPROPERTY(EditAnywhere)
	float Reach = 130.0f;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and interact with what's in reach
	void Interact();

	// Find attached input component
	void FindInputComponent();

	// Return hit for first interactable in reach
	const FHitResult GetFirstInteractableInReach();

	// Returns current start of reach line
	FVector GetReachLineStart();

	// Returns current end of reach line
	FVector GetReachLineEnd();

	AActor* ActorHit = nullptr;

	UReact* ReactComp = nullptr;
};