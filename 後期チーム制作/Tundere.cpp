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
	DrawMysteryGameRobot();
	DrawSearchPlayer();
	
	//プレイヤーの奥行きを出すため描画位置変更
	DrawTexture(450.0f, 610.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight));
	DrawTextBox();
	DrawMenu();
	DrawTime();
}

void InitTundereRoomScene()
{
	LoadTundereFurnitureTex();

	LoadTexture("Res/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/ちび執事.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRobotTex);
	LoadTexture("Res/テキストボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextBoxTex);
	LoadTexture("Res/テキスト名前.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextnameTex);
	LoadTexture("Res/アイテムメニュー.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/アイテムボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);


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