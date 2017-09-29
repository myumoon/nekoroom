// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EQSTest_SearchJumpPoint.generated.h"

/*!	@brief  �L�̃W�����v�|�C���g�v�Z�p�e�X�g
*/
UCLASS()
class PROJ_API UEQSTest_SearchJumpPoint : public UEnvQueryTest {
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = TestParam)
	float CanJumpRange;    // �W�����v�ł��鋗��

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosX; // �ŏI�ړI�nX

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosY; // �ŏI�ړI�nY

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosZ; // �ŏI�ړI�nZ
};
