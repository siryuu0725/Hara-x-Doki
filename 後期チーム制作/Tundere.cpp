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
#include "JK.h"
#include "Talk.h"


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
	DrawTundere();
	//DrawMysteryGameRobot();
	DrawSearchPlayerAndRobot();
	
	//プレイヤーの奥行きを出すため描画位置変更
	DrawTexture(450.0f, 610.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight));
	DrawMenu();
	DrawTime();
	DrawTalkTundere();
	DrawTalkMysteryGameRobot();
	SearchObject();
}

void InitTundereRoomScene()
{
	LoadTundereFurnitureTex();
	LoadSearchGameItem();
	LoadCharacter();
	LoadUI();

	InitRobotLoadFile();
	InitJKLoadFile();

	InitTundere();
	InitTundereRoomObject();
	InitGameRoomPlayer();
	InitMysteryGameRobot();
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
	UpDateMenu();
	HitEyeTundereRoomObject();
	UpDataTundereTalk();
	UpDateTalkMysteryGameRobot();
	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchtunderearea = false;
		areadata.corridor = true;
		areadata.cangearea2 = 2;
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishTundereRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_TUNDERE_ROOM);

	if (mysterygamerobot.play == true)
	{
		mysterygamerobot.play = false;
		return SceneId::MysteryGameScene;
	}
	if (areadata.cangearea2 == 2)
	{
		return SceneId::CorridorScene;
	}
	
}