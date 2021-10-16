// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoneyAutoPickup.h"
#include "Explosive.generated.h"

/**
 * 
 */
UCLASS()
class SKYRIMPS1_API AExplosive : public AMoneyAutoPickup
{
	GENERATED_BODY()
	  
public:

	AExplosive();



		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;


};
