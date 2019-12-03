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
#include "Yuruhuwa.h"

// 犯人部屋シーンの初期化
void InitYuruhuwaRoomScene();
// 犯人部屋シーンのメイン
void MainYuruhuwaRoomScene();
// 犯人部屋シーンの終了
SceneId FinishYuruhuwaRoomScene();

SceneId UpdateYuruhuwaRoomScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitYuruhuwaRoomScene();
		break;
	case SceneStep::MainStep:
		MainYuruhuwaRoomScene();
		break;
	case SceneStep::EndStep:
		return FinishYuruhuwaRoomScene();
		break;
	}

	return SceneId::YuruhuwaRoomScene;
}

void DrawYuruhuwaRoomScene()
{
	DrawSearchBg();
	DrawSearchPlayer();
	DrawTextBox();
	DrawMenu();
}

void InitYuruhuwaRoomScene()
{
	LoadTexture("Res/部屋(空).png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRoomBgTex);
	LoadTexture("Res/カーペット03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCarpet);
	LoadTexture("Res/窓.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaWindow);
	LoadTexture("Res/ソファ02.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaSofa);
	LoadTexture("Res/箪笥03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCloset);
	LoadTexture("Res/ライト.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight);
	LoadTexture("Res/ベッド.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaBed);
	LoadTexture("Res/テーブル03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDesk);
	LoadTexture("Res/ぬいぐるみ03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDoll);
	LoadTexture("Res/時計.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaClock);
	LoadTexture("Res/キャビネット.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCabinet);

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

void MainYuruhuwaRoomScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}
	HitYuruhuwaRoomObject();

	UpDataPlayerPos();


	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchyuruhuwaarea = false;
		areadata.searcharea2 = true;
		areadata.cangearea2 = 3;
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishYuruhuwaRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_YURUHUWA_ROOM);

	if (areadata.cangearea2 == 3)
	{
		return SceneId::Search2Scene;
	}
}