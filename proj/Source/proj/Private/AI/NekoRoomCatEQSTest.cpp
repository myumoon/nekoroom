// 
// @brief �L�̈ړ��v�Z�p
// 

#include "proj.h"
#include "NekoRoomCatEQSTest.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"

//-----------------------------------------------------------------
/*	@brief	�R���X�g���N�^
*/
//-----------------------------------------------------------------
UNekoRoomCatEQSTest::UNekoRoomCatEQSTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// test�̃R�X�g�H
	Cost = EEnvTestCost::Low;

	// �A�C�e���͉��̃p�����[�^�[���󂯎��邩�B�����B
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

	//FName name("FinalPosX");
	//queryInstance.NamedParams[]


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
