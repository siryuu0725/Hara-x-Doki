#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Player.h"
#include "Bg.h"
#include "Robot.h"
#include "Menu.h"
#include "Item.h"
#include "Hit.h"
#include "Text.h"
#include "Tundere.h"


// 犯人部屋シーンの初期化
void InitTundereRoomScene();
// 犯人部屋シーンのメイン
void MainTundereRoomScene();
// 犯人部屋シーンの終了
SceneId FinishTundereRoomScene();

SceneId UpdateTundereRoomScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitTundereRoomScene();
		break;
	case SceneStep::MainStep:
		MainTundereRoomScene();
		break;
	case SceneStep::EndStep:
		return FinishTundereRoomScene();
		break;
	}

	return SceneId::TundereRoomScene;
}

void DrawTundereRoomScene()
{
	DrawSearchBg();
	DrawSearchPlayer();
	DrawTextBox();
	DrawMenu();
}

void InitTundereRoomScene()
{
	LoadTexture("Res/部屋(空).png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRoomBgTex);
	LoadTexture("Res/カーペット02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCarpet);
	LoadTexture("Res/窓.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereWindow);
	LoadTexture("Res/ソファ.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereSofa);
	LoadTexture("Res/観葉植物.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereFlowerpot);
	LoadTexture("Res/箪笥02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCloset);
	LoadTexture("Res/ライト.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight);
	LoadTexture("Res/ベッド04.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereBed);
	LoadTexture("Res/テーブル03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDesk);
	LoadTexture("Res/ぬいぐるみ03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDoll);


	LoadTexture("Res/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/テキストボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextBoxTex);
	LoadTexture("Res/テキスト名前.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextnameTex);
	LoadTexture("Res/アイテムメニュー.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/アイテムボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);


	InitSearchGamePlayer();
	InitTextBox();
	InitMenu();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainTundereRoomScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}
	HitTundereRoomObject();
	UpDataPlayerPos();

	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchtunderearea = false;
		areadata.searcharea2 = true;
		areadata.cangearea2 = 2;
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishTundereRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_TUNDERE_ROOM);

	if (areadata.cangearea2 == 2)
	{
		return SceneId::Search2Scene;
	}
	
}