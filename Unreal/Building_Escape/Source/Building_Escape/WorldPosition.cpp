// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();
	FString ObjectLocation = GetOwner()->GetActorLocation().ToString();
	FVector ObjectVector = GetOwner()->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s is at location: %s."), *ObjectName, *ObjectLocation);
	UE_LOG(LogTemp, Warning, TEXT("%s is at location X:%f, Y:%f, Z:%f."), *ObjectName, ObjectVector.X, ObjectVector.Y, ObjectVector.Z);
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


/*
	// LOGS
	// Logged once for every AActor with WorldPosition component
	UE_LOG(LogTemp, Display, TEXT("This is just a log."));
	UE_LOG(LogTemp, Warning, TEXT("This is a warning!"));
	UE_LOG(LogTemp, Error, TEXT("ERROR"));

	// POINTERS
	FString Log = TEXT("Hello!");
	FString* PtrLog = &Log;
	Log.Len();

	// * has a lower precedence over . operator so we need () to de-reference
	(*PtrLog).Len();
	// But this is messy so we have -> as sintactic sugar, called chevron or something like that
	PtrLog->Len();

	// This way also suck with two *, one overloaded, one the derefence, but whatever.
	UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog);

	FString ObjectName = GetOwner()->GetName();
	FString* PtrName = &ObjectName;
	UE_LOG(LogTemp, Warning, TEXT("This component name is %s."), *ObjectName);
	UE_LOG(LogTemp, Warning, TEXT("This pointer name is %s."), **PtrName);
}
*/