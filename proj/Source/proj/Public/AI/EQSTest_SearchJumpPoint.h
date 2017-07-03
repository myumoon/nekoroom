// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EQSTest_SearchJumpPoint.generated.h"

/*!	@brief  猫のジャンプポイント計算用テスト
*/
UCLASS()
class PROJ_API UEQSTest_SearchJumpPoint : public UEnvQueryTest {
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = TestParam)
	float CanJumpRange;    // ジャンプできる距離

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosX; // 最終目的地X

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosY; // 最終目的地Y

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosZ; // 最終目的地Z
};
