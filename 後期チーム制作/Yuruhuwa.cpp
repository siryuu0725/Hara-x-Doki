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
#include "JK.h"
#include "Talk.h"

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
	DrawYuruhuwa();

	DrawSearchPlayerAndRobot();
	//プレイヤーの奥行きを出すため描画位置変更
	DrawTexture(1330.0f, 780.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight));
	
	DrawTalkYuruhuwa();
	DrawMenu();
	DrawTime();
	DrawTalkPuzzleGameRobot();
	SearchObject();
}

void InitYuruhuwaRoomScene()
{
	LoadYuruhuwaFurnitureTex();
	LoadSearchGameItem();

	LoadTexture("Res/キャラ/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/キャラ/ちび執事.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex);
	LoadTexture("Res/キャラ/立ち絵執事.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkRobotTex);
	LoadTexture("Res/キャラ/ボーイッシュちび.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);
	LoadTexture("Res/キャラ/ゆるふわ立ち絵１.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex);
	LoadTexture("Res/キャラ/立ち絵執事.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobotTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);

	LoadUI();
	
	InitLoadFile();

	InitYuruhuwaRoomObject();
	InitYuruhuwa();
	InitGameRoomPlayer();
	InitPuzzleGameRobot();
	InitTextBox();
	InitMenu();
	getitem.yuruhuwadoorkey = true;
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

	HitEyeYuruhuwaRoomObject();

	UpDateMenu();

	UpDataDescriptionText();

	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchyuruhuwaarea = false;
		areadata.corridor = true;
		areadata.cangearea2 = 3;
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (yuruhuwaobject.robot == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishYuruhuwaRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_YURUHUWA_ROOM);

	if (yuruhuwaobject.robot == true)
	{
		return SceneId::PuzzleGameScene;
	}
	if (areadata.cangearea2 == 3)
	{
		return SceneId::CorridorScene;
	}
}