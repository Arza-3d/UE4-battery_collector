// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// in case we wanna do something with the mesh when the character pick it up, we need function that return the mesh
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }
	
	// return pickup state
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	// set pickup state, true for active, false for not
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

protected:
	// true when pickup can be used
	bool bIsActive;

private: // only can be accessed through this pickup code

	// mesh that represent our pickup in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
	
};
