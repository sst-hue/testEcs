// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntitySpawnDataGeneratorBase.h"
#include "MySpawnDataGenerator.generated.h"

/**
 * 
 */
UCLASS()
class TESTECS_API UMySpawnDataGenerator : public UMassEntitySpawnDataGeneratorBase
{
	GENERATED_BODY()
public:
	UMySpawnDataGenerator();
	virtual void Generate(UObject& QueryOwner, TConstArrayView<FMassSpawnedEntityType> EntityTypes, int32 Count, FFinishedGeneratingSpawnDataSignature& FinishedGeneratingSpawnPointsDelegate) const override;
protected:
	UPROPERTY(Category = "Range", EditAnywhere)
	float Radius;
};
