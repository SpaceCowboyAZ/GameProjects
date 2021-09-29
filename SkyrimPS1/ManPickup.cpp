// Fill out your copyright notice in the Description page of Project Settings.


#include "ManPickup.h"

// Sets default values
AManPickup::AManPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AManPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AManPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

