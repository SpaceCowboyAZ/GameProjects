// Fill out your copyright notice in the Description page of Project Settings.


#include "MoneyAutoPickup.h"

// Sets default values
AMoneyAutoPickup::AMoneyAutoPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

