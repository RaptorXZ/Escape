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

	// Function called when player interacts with this object
	UFUNCTION()
	void UReaction();

	// Text displayed when this object is interacted with by the player
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	FString MyNote = "";

//private:
};