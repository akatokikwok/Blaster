#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	/** GameState is used to replicate game state relevant properties to all clients.
	* 即GameState字段包含了一系列客户端的状态.可以访问到所有的客户端PS
	*/
	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	if (NumberOfPlayers == 2) {
		UWorld* World = GetWorld();
		if (World) {
			// 启用无缝传输, 提升体验
			bUseSeamlessTravel = true;

			/** 使用UWorld::ServerTravel 把服务端无缝传送至一个新关卡; 同时所有链接至此服务器的所有客户端也会跟随传送 */
			World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
	}
}