// Fill out your copyright notice in the Description page of Project Settings.

#include "proj.h"
#include "EQSTest_SearchJumpPoint.h"

#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "Runtime/Core/Public/Math/Box.h"

//-----------------------------------------------------------------
/*	@brief	コンストラクタ
*/
//-----------------------------------------------------------------
UEQSTest_SearchJumpPoint::UEQSTest_SearchJumpPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// testのコスト？
	Cost = EEnvTestCost::Low;

	// アイテムは何のパラメーターを受け取れるか。
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();

}
