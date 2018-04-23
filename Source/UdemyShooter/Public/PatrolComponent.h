// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMYSHOOTER_API UPatrolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolComponent();

	TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }

private:
	
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray <AActor*> PatrolPoints;
	
};
