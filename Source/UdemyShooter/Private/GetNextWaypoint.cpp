// Fill out your copyright notice in the Description page of Project Settings.

#include "GetNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolComponent.h"


EBTNodeResult::Type UGetNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn * ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolComponent = ControlledPawn->FindComponentByClass<UPatrolComponent>();

	if (!ensure(PatrolComponent)) { return EBTNodeResult::Failed;  }

	TArray<AActor*> PatrolPoints = PatrolComponent->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no patrol points"), *ControlledPawn->GetName());
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent * BlackboardComp = OwnerComp.GetBlackboardComponent();

	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	int32 NextIndex = (Index + 1) % PatrolPoints.Num();

	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;

}


