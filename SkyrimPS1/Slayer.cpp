// Fill out your copyright notice in the Description page of Project Settings.


#include "Slayer.h"
#include "Goblin.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuHUD.h"
#include "MenuController.h"

ASlayer::ASlayer()
{

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPCLass(TEXT("SkyrimPS1/GoblinCPP/Blueprints/goblin"));
	if (PlayerPawnBPCLass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPCLass.Class;
	}

	PlayerControllerClass = AMenuController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}
