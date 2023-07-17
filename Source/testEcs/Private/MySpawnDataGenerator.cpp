// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpawnDataGenerator.h"
#include "MassSpawnLocationProcessor.h"

UMySpawnDataGenerator::UMySpawnDataGenerator()
{
	Radius = 200.f;
}

void UMySpawnDataGenerator::Generate(UObject& QueryOwner, TConstArrayView<FMassSpawnedEntityType> EntityTypes,
	int32 Count, FFinishedGeneratingSpawnDataSignature& FinishedGeneratingSpawnPointsDelegate) const
{
	AActor* Spawner = Cast<AActor>(&QueryOwner);
	if (!Spawner)
	{
		return;
	}

	FVector Center = Spawner->GetActorLocation();

	TArray<FMassEntitySpawnDataGeneratorResult> Results;
	BuildResultsFromEntityTypes(Count, EntityTypes, Results);

	for (FMassEntitySpawnDataGeneratorResult& Result : Results)
	{
		Result.SpawnDataProcessor = UMassSpawnLocationProcessor::StaticClass();
		Result.SpawnData.InitializeAs<FMassTransformsSpawnData>();
		FMassTransformsSpawnData& Transforms = Result.SpawnData.GetMutable<FMassTransformsSpawnData>();

		Transforms.Transforms.Reserve(Result.NumEntities);
		for(int i = 0; i < Result.NumEntities; i++)
		{
			FTransform& Transform = Transforms.Transforms.AddDefaulted_GetRef();
			FVector newLocation = Center + FVector(FMath::RandPointInCircle(Radius), 0.f);
			Transform.SetLocation(newLocation);
		}
	}

	FinishedGeneratingSpawnPointsDelegate.Execute(Results);
}
