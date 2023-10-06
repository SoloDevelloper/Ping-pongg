// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"
UCLASS()
class PING_PONGB_API ABall : public AActor
{
	GENERATED_BODY()
	
public:
    ABall();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BallMesh;
    UPROPERTY(EditAnywhere)
    float BallSpeed = 500.0f;
    UPROPERTY(VisibleAnywhere)
    UPrimitiveComponent* CollisionComponent;
    UPROPERTY(VisibleAnywhere)
    UProjectileMovementComponent* ProjectileMovementComponent;
    UPROPERTY(VisibleAnywhere)
    USphereComponent* BallCollision;
    FVector BallVelocity;
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:

};

