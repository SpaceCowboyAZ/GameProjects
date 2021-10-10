// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Goblin.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SKYRIMPS1_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	
	virtual void BeginPlay() override;


	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UShapeComponent* TBox;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_TBox;

	AGoblin* MyPlayerController;

	UPROPERTY(EditAnywhere)
		FString ItemName = FString(TEXT(""));

	void Pickup();

	void GetPlayer(AActor* Player);

	bool bItemIsWithinRange = false;

	UFUNCTION()
	void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
