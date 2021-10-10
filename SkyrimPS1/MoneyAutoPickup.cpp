// Fill out your copyright notice in the Description page of Project Settings.


#include "MoneyAutoPickup.h"
#include "InventoryController.h"


// Sets default values
AMoneyAutoPickup::AMoneyAutoPickup()
{
	Super::ItemID = FName("Money");
	Value = 1;
}

void AMoneyAutoPickup::Collect_Implementation(APlayerController* Controller)
{
	AInventoryController* IController = Cast<AInventoryController>(Controller);
	IController->Money += Value;
	Destroy();
}
 

// Called when the game starts or when spawned
void AMoneyAutoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoneyAutoPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

