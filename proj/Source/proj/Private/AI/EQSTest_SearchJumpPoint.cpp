// Fill out your copyright notice in the Description page of Project Settings.

#include "proj.h"
#include "EQSTest_SearchJumpPoint.h"

#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "Runtime/Core/Public/Math/Box.h"

//-----------------------------------------------------------------
/*	@brief	�R���X�g���N�^
*/
//-----------------------------------------------------------------
UEQSTest_SearchJumpPoint::UEQSTest_SearchJumpPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// test�̃R�X�g�H
	Cost = EEnvTestCost::Low;

	// �A�C�e���͉��̃p�����[�^�[���󂯎��邩�B
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();

}
