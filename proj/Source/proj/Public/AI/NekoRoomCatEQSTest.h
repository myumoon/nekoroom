// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnvironmentQuery/EnvQueryTest.h"
#include "NekoRoomCatEQSTest.generated.h"

/*!	@brief  猫の移動位置計算用EQSテスト
	
	登れる壁がある場合にスコアが高くなる。
	猫が好きなものが置いてある場所もスコアが高くなる予定。
 */
UCLASS()
class PROJ_API UNekoRoomCatEQSTest : public UEnvQueryTest
{
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(EditAnywhere, Category = TestParam)
	float CanJumpRange;    // ジャンプできる距離

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosX; // 最終目的地X

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosY; // 最終目的地Y

	UPROPERTY(EditAnywhere, Category = TestParam)
	FAIDataProviderFloatValue FinalPosZ; // 最終目的地Z
	
	/*!	@brief	テスト実行
	*/
	virtual void RunTest(FEnvQueryInstance& queryInstance) const override;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;

private:
	/*! @brief   指定場所に一番近いオブジェクトを取得
	*/
	const AActor* GetNearestPoint(const FVector& point, const FEnvQueryInstance& queryInstance) const;

	/*! @brief   FinalPosX,Y,Zからの移動コストを計算
		@return  コスト（0～1）：0ほど移動量が少ない
	*/
	float CalcWeight(const FVector& pos, float maxEdge, const FVector& finalPos) const;
};
