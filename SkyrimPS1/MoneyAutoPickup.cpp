// Fill out your copyright notice in the Description page of Project Settings.


#include "MoneyAutoPickup.h"
#include "Components/SphereComponent.h"
//#include "InventoryController.h"


// Sets default values
AMoneyAutoPickup::AMoneyAutoPickup()
{

	PrimaryActorTick.bCanEverTick = true;

	//AUTOPICKUPS
	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	RootComponent = CollisionVolume;
}


 

// Called when the game starts or when spawned
void AMoneyAutoPickup::BeginPlay()
{
	
	
	
	Super::BeginPlay();

	//AUTOPICKUPS side note: safer to put in Begin play
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AMoneyAutoPickup::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AMoneyAutoPickup::OnOverlapEnd);
	
}

// Called every frame
void AMoneyAutoPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMoneyAutoPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin()"));
}


void AMoneyAutoPickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd()"));

}

