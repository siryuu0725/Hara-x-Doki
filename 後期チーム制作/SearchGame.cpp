#include "LargeRoom.h"
#include "Corridor.h"
#include "Scene.h"
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"
#include "Bg.h"
#include "Robot.h"
#include "Menu.h"
#include "Item.h"
#include "Hit.h"
#include "Text.h"
#include "JK.h"

extern TextBoxData textbox;

void InitSearchGameScene();

void MainSearchGameScene();


SceneId FinishSearchGameScene();


SceneId UpdateSearchGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitSearchGameScene();
		break;
	case SceneStep::MainStep:
		MainSearchGameScene();
		break;
	case SceneStep::EndStep:
		return FinishSearchGameScene();
		break;
	}

	return SceneId::SearchGameScene;
}

void DrawSearchGameScene()
{
	DrawSearchBg();
	DrawBoyish();
	DrawRobotNeck();
	DrawSearchGameRobot();
	DrawSearchPlayer();
	//DrawTextBox();
	DrawMenu();
	DrawTime();
	DrawTalkSearchGameRobot();
}

void InitSearchGameScene()
{
	LoadSearchGameItem();

	LoadTexture("Res/個室（女子部屋）.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex);
	LoadTexture("Res/キャラ/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/キャラ/ボーイッシュちび.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);

	LoadTexture("Res/キャラ/ちびロボパーツ.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex);
	LoadTexture("Res/キャラ/ちび執事(カオナシ).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);
	LoadTexture("Res/キャラ/ちび執事.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameCompleteRobotTex);
	LoadTexture("Res/キャラ/立ち絵執事.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobotTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);

	LoadUI();

	InitSearchGameObject();
	InitGameRoomPlayer();
	InitBoyish();
	InitSearchGameRobot();
	InitTextBox();
	InitMenu();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearchGameScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}
	UpDataSearchGame();

	HitSearchGameObject();

	UpDataPlayerPos();

	HitEyeSearchGameObject();

	UpDateMenu();

	

	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchgamearea = false;
		areadata.corridor = true;
		areadata.cangearea2 = 1;
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishSearchGameScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH_GAME);

	if (areadata.corridor == 1)
	{
		return SceneId::CorridorScene;
	}


}