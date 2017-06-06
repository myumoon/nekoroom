// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnvironmentQuery/EnvQueryTest.h"
#include "NekoRoomCatEQSTest.generated.h"

/*!	@brief  �L�̈ړ��ʒu�v�Z�pEQS�e�X�g
	
	�o���ǂ�����ꍇ�ɃX�R�A�������Ȃ�B
	�L���D���Ȃ��̂��u���Ă���ꏊ���X�R�A�������Ȃ�\��B
 */
UCLASS()
class PROJ_API UNekoRoomCatEQSTest : public UEnvQueryTest
{
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(EditAnywhere, Category = TestParam)
	float CanJumpRange;    // �W�����v�ł��鋗��

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosX; // �ŏI�ړI�nX

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosY; // �ŏI�ړI�nY

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosZ; // �ŏI�ړI�nZ
	
	/*!	@brief	�e�X�g���s
	*/
	virtual void RunTest(FEnvQueryInstance& queryInstance) const override;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;

private:
	/*! @brief   �w��ꏊ�Ɉ�ԋ߂��I�u�W�F�N�g���擾
	*/
	const AActor* GetNearestPoint(const FVector& point, const FEnvQueryInstance& queryInstance) const;

	/*! @brief   FinalPosX,Y,Z����̈ړ��R�X�g���v�Z
		@return  �R�X�g�i0�`1�j�F0�قǈړ��ʂ����Ȃ�
	*/
	float CalcWeight(const FVector& pos, float maxEdge, const FVector& finalPos) const;
};
