#include "Search.h"
#include "Search2.h"
#include "Scene.h"
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"
#include "Bg.h"
#include "Hit.h"
#include "Menu.h"
#include "Text.h"
#include "Item.h"

extern TextBoxData textbox;
extern MenuData menu;


void InitSearch2Scene();

void MainSearch2Scene();

SceneId FinishSearch2Scene();


SceneId UpdateSearch2Scene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitSearch2Scene();
		break;
	case SceneStep::MainStep:
		MainSearch2Scene();
		break;
	case SceneStep::EndStep:
		return FinishSearch2Scene();
		break;
	}

	return SceneId::Search2Scene;
}

void DrawSearch2Scene()
{
	DrawSearchBg();
	DrawSearchPlayer();
	DrawMenu();
	DrawTime();
}

void InitSearch2Scene()
{

	LoadSearch2FurnitureTex();

	LoadTexture("Res/廊下_修正.png", TEXTURE_SEARCH2, Search2CategoryTextureList::Search2BgTex);
	LoadTexture("Res/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/アイテムメニュー.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/アイテムボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

	InitSearch2Player();
	InitMenu();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearch2Scene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(455.0f, 835.0f, 0.0f, 1920.0f);
	}

	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (searchplayer.pos_x + 64.0f >= 1900.0f)
	{
		areadata.searcharea2 = false;
		areadata.searcharea1 = true;
		areadata.cangearea = true;
		areadata.cangearea2 = false;
		ChangeSceneStep(SceneStep::EndStep);
	}

	//キャラの幅+20程判定を大きくしている
	if (HitNextArea(1430.0f, 1550.0f,440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searcharea2 = false;
		areadata.searchgamearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (HitNextArea(820.0f, 945.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searcharea2 = false;
		areadata.searchtunderearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}

	if (HitNextArea(225.0f, 350.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searcharea2 = false;
		areadata.searchyuruhuwaarea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}

	UpDateMenu();
}

SceneId FinishSearch2Scene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH2);

	if (areadata.searcharea1 == true)
	{
		return SceneId::SearchScene;
	}
	else if (areadata.searchgamearea == true)
	{
		return SceneId::SearchGameScene;
	}
	else if (areadata.searchtunderearea == true)
	{
		return SceneId::TundereRoomScene;
	}
	else if (areadata.searchyuruhuwaarea == true)
	{
		return SceneId::YuruhuwaRoomScene;
	}
		

}