// Fill out your copyright notice in the Description page of Project Settings.

#include "swordPickup.h"
#include "Components/SceneComponent.h"
#include "SkyrimPS1.h"



// Sets default values

AswordPickup::AswordPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create the root CapsuleComponent to handle the pickup's collision
	BaseCollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BaseCapsuleComponent"));

	// Set the SphereComponent as the root component.
	RootComponent = BaseCollisionComponent;

	//Create the static mesh component 
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("sword"));

	// Start with physics simulation disabled, for easy manipulation on UE4 Editor.
	PickupMesh->SetSimulatePhysics(false);

	// Attach the StaticMeshComponent to the RootComponent.
	//PickupMesh->AttachToComponent(RootComponent); I don't think this syntax works anymore on this verison.

}
