// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnvironmentQuery/EnvQueryTest.h"
#include "NekoRoomCatEQSTest.generated.h"

/**
 * 
 */
UCLASS()
class PROJ_API UNekoRoomCatEQSTest : public UEnvQueryTest
{
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(EditAnywhere, Category = TestParam)
	float CanJumpRange;    // �W�����v�ł��鋗��

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosX;

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosY;

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosZ;
	
	// �e�X�g���s
	virtual void RunTest(FEnvQueryInstance& queryInstance) const override;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;
};
