// Fill out your copyright notice in the Description page of Project Settings.

#include "SkyrimPS1.h"
#include "swordPickup.h"

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
	PickupMesh->AttachTo(RootComponent);

	// Enable the generation of overlapping events and assign a function to be run when it happens.
	BaseCollisionComponent->bGenerateOverlapEvents = true;
	BaseCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AswordPickup::OnOverlapBegin);

	// Disable Overlap Events on the Mesh
	PickupMesh->bGenerateOverlapEvents = false;
}

void AswordPickup::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// OtherActor is the actor that triggered the event. Check that is not ourself
	if ((OtherActor == nullptr) || (OtherActor == this) || (OtherComp == nullptr))
		return;

	UE_LOG(MyCriticalErrors, Warning, TEXT("Picked up."));
}

