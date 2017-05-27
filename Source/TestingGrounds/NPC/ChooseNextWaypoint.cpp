// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp)
	{
		UPatrolRoute* PatrolRouteComp = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();
		if (PatrolRouteComp)
		{
			if (PatrolRouteComp->GetPatrolPoints().Num() != 0)
			{
				int32 Index = BlackboardComp->GetValueAsInt(PatrolIndex.SelectedKeyName);

				// Set new waypoint
				BlackboardComp->SetValueAsObject(PatrolPoint.SelectedKeyName, PatrolRouteComp->GetPatrolPoints()[Index]);

				// Cycle the index
				BlackboardComp->SetValueAsInt(PatrolIndex.SelectedKeyName, (Index + 1) % PatrolRouteComp->GetPatrolPoints().Num());

				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
