// Copyright Patrik Jarnesand 2016

#include "Escape.h"
#include "React.h"

// Sets default values for this component's properties
UReact::UReact()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UReact::BeginPlay()
{
	Super::BeginPlay();
}

void UReact::UReaction()
{
	if (MyNote != "")
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *MyNote);
	}
}