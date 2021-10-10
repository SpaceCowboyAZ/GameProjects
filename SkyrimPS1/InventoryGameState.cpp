// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGameState.h"

AInventoryGameState::AInventoryGameState()  //creates our database four our items. 
{
	static ConstructorHelpers::FObjectFinder<UDataTable> BP_ItemDB(TEXT("DataTable'/SkyrimPS1/Content/Blueprints/Goblin_BP.uasset'"));
	ItemDB = BP_ItemDB.Object;
}

UDataTable* AInventoryGameState::GetItemDB() const
{
	return ItemDB;
}