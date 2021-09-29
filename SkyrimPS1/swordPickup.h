// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "swordPickup.generated.h"


UCLASS()
class SKYRIMPS1_API AswordPickup : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AswordPickup();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
		UCapsuleComponent* BaseCollisionComponent;

	// StaticMeshComponent to represent the pickup in the level 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pickup)
		UStaticMeshComponent* PickupMesh;

	UFUNCTION()
		virtual void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};