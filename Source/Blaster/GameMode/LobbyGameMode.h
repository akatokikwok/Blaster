
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * Lobby的GM
 * 继承自GameMode而非GameModeBase, 因此持有更多的功能
 */
UCLASS()
class BLASTER_API ALobbyGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	// 覆写PostLogin
	virtual void PostLogin(APlayerController* NewPlayer) override;
};