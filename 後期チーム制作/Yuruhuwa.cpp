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
	
	DrawMenu();
	DrawTime();
	

	DrawTalkPuzzleGameRobot();

	DrawTalkYuruhuwa();
	SearchObject();
}

void InitYuruhuwaRoomScene()
{
	LoadYuruhuwaFurnitureTex();
	LoadSearchGameItem();

	LoadCharacter();

	

	LoadUI();
	InitYuruhuwa();
	InitGameRoomPlayer();
	InitPuzzleGameRobot();
	InitRobotLoadFile();
	InitJKLoadFile();
	InitYuruhuwaRoomObject();
	
	InitTextBox();
	InitMenu();
	InitChoiceTexture();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainYuruhuwaRoomScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}
	
	HitYuruhuwaRoomObject();

	HitEyeYuruhuwaRoomObject();

	UpDataPlayerPos();

	UpDateMenu();

	UpDataYuruhuwaTalk();

	UpDateTalkPuzzleGameRobot();


	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchyuruhuwaarea = false;
		areadata.corridor = true;
		areadata.cangearea2 = 3;
		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (puzzlegamerobot.play == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishYuruhuwaRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_YURUHUWA_ROOM);

	if (puzzlegamerobot.play == true)
	{
		puzzlegamerobot.play = false;
		return SceneId::PuzzleGameScene;
	}
	if (areadata.cangearea2 == 3)
	{
		return SceneId::CorridorScene;
	}
}