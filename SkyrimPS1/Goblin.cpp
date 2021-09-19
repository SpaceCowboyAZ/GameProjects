

// .cpp files implement the .h files

#include "Goblin.h"

// Sets default values
AGoblin::AGoblin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false; // will allow camera to rotate but not character

	GetCharacterMovement()->bOrientRotationToMovement = true; // allows character look forward  where you're moving. hope that makes sense 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2; //slight control while in air

	CameraBoom = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom")); //name of spring arm in unreal
	CameraBoom->SetupAttachment(RootComponent); //root component is capsule inside unreal
	CameraBoom->TargetArmLength = 300.0f; //sets how far camera is from player
	CameraBoom->bUsePawnControlRotation = true; // rotate arm based on conttroller (spring arm)

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera")); 
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); //attaches camera to spring arm
	FollowCamera->bUsePawnControlRotation = false; //camera does not rotate relative to the arm


	bDead = false; //default value so you are not dead.
}



// Called when the game starts or when spawned
void AGoblin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoblin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGoblin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGoblin::MoveForward(float Axis)
{



}

void AGoblin::MoveRight(float Axis)
{


}
