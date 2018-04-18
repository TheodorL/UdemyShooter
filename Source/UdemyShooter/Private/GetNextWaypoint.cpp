// Fill out your copyright notice in the Description page of Project Settings.

#include "GetNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingThirdPersonChar.h"


EBTNodeResult::Type UGetNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn * ControllerPawn = OwnerComp.GetAIOwner()->GetPawn();
	APatrollingThirdPersonChar * PatrollingChar = Cast<APatrollingThirdPersonChar>(ControllerPawn);
	TArray<AActor*> PatrolPoints = PatrollingChar->PatrolPointsCPP;
	UBlackboardComponent * BlackboardComp = OwnerComp.GetBlackboardComponent();

	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	int32 NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	UE_LOG(LogTemp, Warning, TEXT("%i"), Index);

	return EBTNodeResult::Succeeded;
}


