// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	
		Name = "Interactable";
		Action = "interact";
	}

	void AInteractable::Interact_Implementation(APlayerController * Controller)
	{
		return;
	}

	FString AInteractable::GetInteractText() const
	{
		return FString::Printf(TEXT("%s: Press F to %s"), *Name, *Action);
	}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

