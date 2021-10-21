// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Goblin.h"
#include "Engine/SkeletalMeshSocket.h"

AWeapon::AWeapon()
{

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());
}

void 	AWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (OtherActor)
	{

		AGoblin* Goblin = Cast<AGoblin>(OtherActor);
		if (Goblin)
		{
			Equip(Goblin);
		}
	}
}

void 	AWeapon::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void AWeapon::Equip(class AGoblin* Char)
{
	if (Char)
	{
		SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		SkeletalMesh->SetSimulatePhysics(false);

		const USkeletalMeshSocket* RightHandSocket = Char->GetMesh()->GetSocketByName("hand_LSocket");
		if (RightHandSocket)
		{
			RightHandSocket->AttachActor(this, Char->GetMesh());

		}

	}

}