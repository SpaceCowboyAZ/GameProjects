// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoPickup.h"

// Sets default values
AAutoPickup::AAutoPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");
}

void AAutoPickup::Collect_Implementation(APlayerController* Controller)
{
	AInventoryController* IController = Cast<AInventoryController>(Controller);
	if (IController->AddItemToInventoryByID(ItemID))
		Destroy();
}

FName AAutoPickup::GetItemID()
{
	return ItemID;
}

// Called when the game starts or when spawned
void AAutoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAutoPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

