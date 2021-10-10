// Fill out your copyright notice in the Description page of Project Settings.

#include "SkyrimPS1.h"
#include "Item.h"
#include "Engine.h"
// Sets default values

AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	TBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	TBox->bGenerateOverlapEvents = true;
	TBox->OnComponentBeginOverlap.AddDynamic(this, &AItem::TriggerEnter);
	TBox->OnComponentEndOverlap.AddDynamic(this, &AItem::TriggerExit);
	
	RootComponent = TBox;

	SM_TBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SM_TBox->AttachTo(RootComponent);
}

void AItem::GetPlayer(AActor* Player)
{
	MyPlayerController = Cast<AGoblin>(Player);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Pickup()
{
	MyPlayerController->Inventory.Add(*ItemName);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Item picked up"));
	Destroy();
}
// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyPlayerController != NULL) //null check player controller
	{
	if (MyPlayerController->bIsPickingUp && bItemIsWithinRange)
	{
		Pickup();
	}

	}

}
void AItem::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bItemIsWithinRange = true;
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("Press F to pickup %s"), *ItemName));
	GetPlayer(OtherActor); //passing ourselves to the object
}
void AItem::TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bItemIsWithinRange = false;
}
