
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SkeletalMeshComponent.h"

#include "Aircraft.generated.h"

UCLASS()
class EXAMPLE_API AAircraft : public APawn
{
	GENERATED_BODY()

public:
	AAircraft();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		bool bHorizontal;
	UPROPERTY(VisibleAnywhere)

	bool bVertical;
	UPROPERTY(VisibleAnywhere)

	bool bMouseY;
	UPROPERTY(VisibleAnywhere)

	bool bMouseX;

private:
	void MouseX(float Value);
	void MouseY(float Value);
	void Horizontal(float Value);
	void Vertical(float Value);
	
};
