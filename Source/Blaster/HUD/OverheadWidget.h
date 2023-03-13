#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 显示玩家名字的3D UI
 */
UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* DisplayText;

	void SetDisplayText(FString TextToDisplay);

	// 依据Pawn的网络类型来来打印不同的3D UI
	UFUNCTION(BlueprintCallable)
		void ShowPlayerNetRole(APawn* InPawn);

protected:
	// 覆写OnLevelRemovedFromWorld; 当传送至新地图时会被调用
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
};