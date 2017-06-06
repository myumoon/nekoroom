// 
// @brief �L�̈ړ��v�Z�p
// 

#include "proj.h"
#include "NekoRoomCatEQSTest.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "Runtime/Core/Public/Math/Box.h"

//-----------------------------------------------------------------
/*	@brief	�R���X�g���N�^
*/
//-----------------------------------------------------------------
UNekoRoomCatEQSTest::UNekoRoomCatEQSTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// test�̃R�X�g�H
	Cost = EEnvTestCost::Low;

	// �A�C�e���͉��̃p�����[�^�[���󂯎��邩�B
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();

}

//-----------------------------------------------------------------
/*	@brief	�e�X�g���s
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

	// �ŏI���B�ʒu
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
		score += 0.10f; // todo : ���Őݒ�
		it.SetScore(TestPurpose, FilterType, score, FloatValueMin.GetValue(), FloatValueMax.GetValue());
	}
}

//-----------------------------------------------------------------
/*	@brief	��ԋ߂��|�C���g���擾
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

	// �擪�͂��ł�nearest�ɓ����Ă���̂ŏ��O
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
/*	@brief	�ړ��R�X�g�v�Z
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
