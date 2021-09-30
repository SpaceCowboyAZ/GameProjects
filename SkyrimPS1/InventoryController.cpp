// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryController.h"

#include "InventoryGameState.h"
#include "InventoryCharacter.h"

AInventoryController::AInventoryController()
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 200;
}

int32 AInventoryController::GetInventoryWeight()
{
	int32 Weight = 0;
	for (auto& Item : Inventory)  
	{										//Deduces the type of a declared variable from its initialization expression
											//To use the auto keyword, use it instead of a type to declare a variable, and specify an initialization expression.
											// you can modify the auto keyword by using specifiers and declarators such as const, volatile, pointer(*), reference(&), and rvalue reference(&&).
											//The compiler evaluates the initialization expressionand then uses that information to deduce the type of the variable.
		Weight += Item.Weight;
	}

	return Weight;
}

bool AInventoryController::AddItemToInventoryByID(FName ID)
{
	AInventoryGameState* GameState = Cast<AInventoryGameState>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FSword* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		// If a Slot- or WeightLimit are not needed remove them in this line
		if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			Inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}

void AInventoryController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Interact", IE_Pressed, this, &AInventoryController::Interact);
}

void AInventoryController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}