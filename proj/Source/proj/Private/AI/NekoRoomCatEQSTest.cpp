// 
// @brief 猫の移動計算用
// 

#include "proj.h"
#include "NekoRoomCatEQSTest.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"

//-----------------------------------------------------------------
/*	@brief	コンストラクタ
*/
//-----------------------------------------------------------------
UNekoRoomCatEQSTest::UNekoRoomCatEQSTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// testのコスト？
	Cost = EEnvTestCost::Low;

	// アイテムは何のパラメーターを受け取れるか。多分。
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
}

//-----------------------------------------------------------------
/*	@brief	テスト実行
*/
//-----------------------------------------------------------------
void UNekoRoomCatEQSTest::RunTest(FEnvQueryInstance& queryInstance) const
{
	UObject* queryOwner = queryInstance.Owner.Get();
	if(queryOwner == nullptr) {
		return;
	}

	//FName name("FinalPosX");
	//queryInstance.NamedParams[]


	//UNavigationSystem* navSys = UNavigationSystem::GetCurrent(GetWorld());
	//if(navSys == nullptr) {
	//	//queryInstance.bFoundSingleResult = false;
	//	return;
	//}

	FloatValueMin.BindData(queryOwner, queryInstance.QueryID);
	FloatValueMax.BindData(queryOwner, queryInstance.QueryID);

	// 最終到達位置
	FinalPosX.BindData(queryOwner, queryInstance.QueryID);
	FinalPosY.BindData(queryOwner, queryInstance.QueryID);
	FinalPosZ.BindData(queryOwner, queryInstance.QueryID);
	FVector finalPos(FinalPosX.GetValue(), FinalPosY.GetValue(), FinalPosZ.GetValue());
	UE_LOG(LogTemp, Warning, TEXT("finalPos (%f, %f, %f)"), finalPos.X, finalPos.Y, finalPos.Z);

	//FPathFindingQuery queryParam;
	//queryParam.StartLocation = ;
	//queryParam.EndLocation = ;
	//FNavLocation result;
	//bool pathExist = navSys->TestPathSync(queryParam);
	//queryInstance.ContextCache.;

	float score = 0.0f;
	for(FEnvQueryInstance::ItemIterator it(this, queryInstance); it; ++it) {
		
		UE_LOG(LogTemp, Log, TEXT("it %d"), it.GetIndex());
		//const AActor* point = queryInstance.GetItemAsActor(it.GetIndex());
		score += 0.10f;
		it.SetScore(TestPurpose, FilterType, score, FloatValueMin.GetValue(), FloatValueMax.GetValue());
	}
}


FText UNekoRoomCatEQSTest::GetDescriptionTitle() const
{
	return Super::GetDescriptionTitle();
}

FText UNekoRoomCatEQSTest::GetDescriptionDetails() const
{
	return DescribeFloatTestParams();
}
