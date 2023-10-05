// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

ABall::ABall()
{
    PrimaryActorTick.bCanEverTick = true;
    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
    RootComponent = BallMesh;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Sphere"));
    if (MeshAsset.Succeeded())
    {
        BallMesh->SetStaticMesh(MeshAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/BlackMaterial"));
    if (MaterialAsset.Succeeded()) {
        BallMesh->SetMaterial(0, MaterialAsset.Object);
    }
    UProjectileMovementComponent* ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->UpdatedComponent = RootComponent;
    ProjectileMovement->InitialSpeed = BallSpeed;
    ProjectileMovement->MaxSpeed = BallSpeed;
    ProjectileMovement->bShouldBounce = true; 
    ProjectileMovement->Bounciness = 1.0f;

    /*cCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    if (CollisionComponent)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "xcc");
        CollisionComponent->SetupAttachment(RootComponent);
        CollisionComponent->SetSimulatePhysics(true);
        BallVelocity = FVector::ZeroVector;
    }*/
    //ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
    //ProjectileMovementComponent->InitialSpeed = 1500.0f; 
    //ProjectileMovementComponent->MaxSpeed = 3000.0f;    
    //ProjectileMovementComponent->bShouldBounce = true;
    /*BallCollision = CreateDefaultSubobject<USphereComponent>(TEXT("BallCollision"));
    BallCollision->SetupAttachment(RootComponent);
    BallCollision->SetCollisionProfileName(TEXT("BlockAllDynamic"));
    float CollisionRadius = 200.f;
    BallCollision->SetSphereRadius(CollisionRadius);*/
}

void ABall::BeginPlay()
{
    Super::BeginPlay();
    BallVelocity = FVector(0.0f, BallSpeed, 0.0f);
}

void ABall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FVector NewLocation = GetActorLocation() + BallVelocity * DeltaTime;
    SetActorLocation(NewLocation);
}

/*void ABall::LaunchBall()
{
    FVector ImpulseDirection = FVector(1.0f, 0.0f, 0.0f);
    float ImpulseStrength = 1000.0f;

    BallMesh->AddImpulse(ImpulseDirection * ImpulseStrength);
}*/
void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "df");
    BallVelocity = BallVelocity - 2 * FVector::DotProduct(BallVelocity, Hit.ImpactNormal) * Hit.ImpactNormal;
}

