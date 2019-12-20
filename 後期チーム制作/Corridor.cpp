#include "LargeRoom.h"
#include "Corridor.h"
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
#include "JK.h"

extern TextBoxData textbox;
extern MenuData menu;


void InitCorridorScene();

void MainCorridorScene();

SceneId FinishCorridorScene();


SceneId UpdateCorridorScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitCorridorScene();
		break;
	case SceneStep::MainStep:
		MainCorridorScene();
		break;
	case SceneStep::EndStep:
		return FinishCorridorScene();
		break;
	}

	return SceneId::CorridorScene;
}

void DrawCorridorScene()
{
	DrawSearchBg();
	DrawBoyish();
	DrawYuruhuwa();
	DrawSearchPlayer();
	
	DrawMenu();
	DrawTime();
	DrawTalkYuruhuwa();
}

void InitCorridorScene()
{

	LoadCorridorFurnitureTex();
	LoadSearchGameItem();

	LoadTexture("Res/廊下_修正.png", TEXTURE_SEARCH2, Search2CategoryTextureList::Search2BgTex);
	LoadTexture("Res/キャラ/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	
    LoadTexture("Res/キャラ/ボーイッシュちび.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);
	LoadUI();

	InitCorridorPlayer();
	InitBoyish();
	InitYuruhuwa();
	InitMenu();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainCorridorScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(455.0f, 835.0f, 0.0f, 1920.0f);
	}

	HitCorridorObject();

	UpDataPlayerPos();

	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (searchplayer.pos_x + 64.0f >= 1900.0f)
	{
		areadata.corridor = false;
		areadata.largeroom = true;
		areadata.cangearea = true;
		areadata.cangearea2 = false;
		ChangeSceneStep(SceneStep::EndStep);
	}

	//キャラの幅+20程判定を大きくしている
	if (HitNextArea(1430.0f, 1550.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true && getitem.boyishdoorkey == true)
	{
		areadata.corridor = false;
		areadata.searchgamearea = true;
		getitem.breakdoorkey = true;

		getitem.tunderedoorkey = false;
		getitem.yuruhuwadoorkey = false;
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (HitNextArea(820.0f, 945.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true && getitem.tunderedoorkey == true)
	{
		areadata.corridor = false;
		areadata.searchtunderearea = true;
		getitem.breakdoorkey = true;
		if (boyish.clear != true)
		{
			getitem.boyishdoorkey = false;
			getitem.yuruhuwadoorkey = false;
		}
	
		ChangeSceneStep(SceneStep::EndStep);
	}

	if (HitNextArea(225.0f, 350.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true && getitem.yuruhuwadoorkey == true)
	{
		areadata.corridor = false;
		areadata.searchyuruhuwaarea = true;
		getitem.breakdoorkey = true;
		if (boyish.clear != true)
		{
			getitem.boyishdoorkey = false;
			getitem.tunderedoorkey = false;
		}
		
		ChangeSceneStep(SceneStep::EndStep);
	}

	UpDateMenu();
}

SceneId FinishCorridorScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH2);

	if (areadata.largeroom == true)
	{
		return SceneId::LargeRoomScene;
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