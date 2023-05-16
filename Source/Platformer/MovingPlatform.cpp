#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	start_location_ = GetActorLocation();
	auto arrow = static_cast<UArrowComponent*>(FindComponentByClass<UArrowComponent>());
	direction_ = arrow->GetForwardVector();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void AMovingPlatform::Move() {
	SetActorLocation(GetSinusoidLocation());
}

FVector AMovingPlatform::GetSinusoidLocation() {
	auto result = start_location_ +  amplitude * FMath::Sin(speed * GetWorld()->GetRealTimeSeconds()) * direction_;

	UE_LOG(LogTemp, Warning, TEXT("start_location: %s"), *start_location_.ToString());
	UE_LOG(LogTemp, Warning, TEXT("time: %f"), GetWorld()->GetRealTimeSeconds());
	UE_LOG(LogTemp, Warning, TEXT("result: %s"), *result.ToString());

	return result;
}
