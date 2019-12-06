#include "Search.h"
#include "Search2.h"
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
	
	DrawRobotNeck();
	DrawSearchGameRobot();
	DrawSearchPlayer();
	DrawTextBox();
	DrawMenu();
}

void InitSearchGameScene()
{
	LoadTexture("Res/個室（女子部屋）.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex);
	LoadTexture("Res/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/ちびロボパーツ.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex);
	LoadTexture("Res/ちび執事(カオナシ).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);
	LoadTexture("Res/テキストボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextBoxTex);
	LoadTexture("Res/テキスト名前.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextnameTex);
	LoadTexture("Res/アイテムメニュー.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/アイテムボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);

	InitGameRoomPlayer();
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
		areadata.searcharea2 = true;
		areadata.cangearea2 = 1;
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishSearchGameScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH_GAME);

	if (areadata.searcharea2 == 1)
	{
		return SceneId::Search2Scene;
	}


}