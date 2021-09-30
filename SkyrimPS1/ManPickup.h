// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
//#include "GameFramework/Actor.h"
#include "ManPickup.generated.h"



UCLASS()
class SKYRIMPS1_API AManPickup : public AInteractable
{
	GENERATED_BODY()

public:
	AManPickup();

	void Interact_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;
};