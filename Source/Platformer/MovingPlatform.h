#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PLATFORMER_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	void Move();

	FVector GetSinusoidLocation();

protected:
	UPROPERTY(EditAnywhere)
	float speed = 20.0f;

	UPROPERTY(EditAnywhere)
	float amplitude = 20.0f;

protected:
	FVector start_location_;

	FVector direction_;

};
