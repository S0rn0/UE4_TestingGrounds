// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * For funzies
 */
UCLASS()
class TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector PatrolIndex; // We do not need this, just have a member variable (Only left it cause tutorial did...)

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector PatrolPoint;

};
