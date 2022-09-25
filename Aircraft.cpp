

#include "Aircraft.h"

AAircraft::AAircraft()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
}

void AAircraft::BeginPlay()
{
	Super::BeginPlay();

}

void AAircraft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (!bHorizontal && !bMouseY && !bMouseX)

	{
		this->SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, 0), 0.01f));

	}

}

void AAircraft::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Horizontal", this, &AAircraft::Horizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &AAircraft::Vertical);
	PlayerInputComponent->BindAxis("MouseX", this, &AAircraft::MouseX);
	PlayerInputComponent->BindAxis("MouseY", this, &AAircraft::MouseY);

}

void AAircraft::MouseX(float Value)
{


	bMouseX = Value == 0 ? false : true;
	//	int V = bMouseX > 0.9f ? 1 : bMouseX < -0.9f ? -1 : 0;


	RootComponent->AddRelativeRotation(FRotator(0, Value / 15.0f, 0).Quaternion());
	SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, Value * 90), 0.01f));

	//RootComponent->AddRelativeRotation(FRotator(0, Value/15.0f, Value).Quaternion());

	//this->SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(0,0, 90*V), 0.01f));

}

void AAircraft::MouseY(float Value)
{
	if (bMouseX) { return; }
	bMouseY = Value == 0 ? false : true;

	RootComponent->AddRelativeRotation(FRotator(Value / 3.0f, 0, 0).Quaternion());
	//this->SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, 0), 0.01f));
	this->SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, 0), 0.01f));

}

void AAircraft::Horizontal(float Value)
{

	bHorizontal = Value == 0 ? false : true;
	RootComponent->AddRelativeRotation(FRotator(0, 0, Value));
	//RootComponent->AddLocalRotation(FRotator(0, 0, Value).Quaternion());

}

void AAircraft::Vertical(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value * 4000);

}

