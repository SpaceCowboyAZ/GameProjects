// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutoPickup.h"
#include "MoneyAutoPickup.generated.h"

UCLASS()
class SKYRIMPS1_API AMoneyAutoPickup : public AAutoPickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoneyAutoPickup();

	void Collect_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
