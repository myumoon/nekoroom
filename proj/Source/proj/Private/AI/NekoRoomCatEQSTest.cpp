// 
// @brief 猫の移動計算用
// 

#include "proj.h"
#include "NekoRoomCatEQSTest.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "Runtime/Core/Public/Math/Box.h"

//-----------------------------------------------------------------
/*	@brief	コンストラクタ
*/
//-----------------------------------------------------------------
UNekoRoomCatEQSTest::UNekoRoomCatEQSTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// testのコスト？
	Cost = EEnvTestCost::Low;

	// アイテムは何のパラメーターを受け取れるか。
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
	
	FBox    box     = queryInstance.GetBoundingBox();
	FVector size    = box.GetSize();
	float   maxEdge = FMath::Max3(size.X, size.Y, size.Z);


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

	const AActor* nearest = GetNearestPoint(finalPos, queryInstance);
	if(nearest == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Not found nearest point"));
	}
	//CalcWeight(, maxEdge, finalPos);

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
		score += 0.10f; // todo : 仮で設定
		it.SetScore(TestPurpose, FilterType, score, FloatValueMin.GetValue(), FloatValueMax.GetValue());
	}
}

//-----------------------------------------------------------------
/*	@brief	一番近いポイントを取得
*/
//-----------------------------------------------------------------
const AActor* UNekoRoomCatEQSTest::GetNearestPoint(const FVector& pos, const FEnvQueryInstance& queryInstance) const
{
	TArray<AActor*> points = TArray<AActor*>();
	queryInstance.GetAllAsActors(points);

	if(points.Num() == 0) {
		return nullptr;
	}

	AActor* nearest      = points[0];
	float   nearestDist2 = (pos - nearest->GetActorLocation()).SizeSquared();

	// 先頭はすでにnearestに入っているので除外
	for(int i = 1; i < points.Num(); ++i) {
		AActor* point  = points[i];
		FVector length = pos - nearest->GetActorLocation();
		float   dist2  = length.SizeSquared();
		if(dist2 < nearestDist2) {
			nearest      = point;
			nearestDist2 = dist2;
		}
	}

	return nearest;
}

//-----------------------------------------------------------------
/*	@brief	移動コスト計算
*/
//-----------------------------------------------------------------
float UNekoRoomCatEQSTest::CalcWeight(const FVector& pos, float maxEdge, const FVector& finalPos) const
{
	return ((pos - finalPos).Size() / maxEdge);
}

FText UNekoRoomCatEQSTest::GetDescriptionTitle() const
{
	return Super::GetDescriptionTitle();
}

FText UNekoRoomCatEQSTest::GetDescriptionDetails() const
{
	return DescribeFloatTestParams();
}
