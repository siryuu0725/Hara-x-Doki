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
#include "Talk.h"

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
	//DrawBoyish();
	DrawYuruhuwa();
	DrawSearchPlayerAndRobot();
	
	
	DrawTime();
	DrawTalkYuruhuwa();
	DrawDoorTalk();
	DrawMenu();
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
	InitRobotLoadFile();
	InitChoiceTexture();

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

	UpDataDoorText();

	UpDateMenu();

	if (searchplayer.pos_x + 64.0f >= 1900.0f)
	{
		areadata.corridor = false;
		areadata.largeroom = true;
		areadata.cangearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}

	//キャラの幅+20程判定を大きくしている
	if (HitNextArea(1430.0f, 1550.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true && getitem.boyishdoorkey == true)
	{
		corridorobject.boyishdoor = true;
		
		areadata.searchgamearea = true;
		areadata.searchtunderearea = false;
		areadata.searchyuruhuwaarea = false;

	}
	else if (HitNextArea(820.0f, 945.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true && getitem.tunderedoorkey == true)
	{
		corridorobject.tunderedoor = true;
		
		areadata.searchtunderearea = true;
		areadata.searchgamearea = false;
		areadata.searchyuruhuwaarea = false;

	}
	else if (HitNextArea(225.0f, 350.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true && getitem.yuruhuwadoorkey == true)
	{
		corridorobject.yuruhuwadoor = true;
		
		areadata.searchyuruhuwaarea = true;
		areadata.searchgamearea = false;
		areadata.searchtunderearea = false;
		
	}
	else if(HitNextArea(1430.0f, 1550.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		corridorobject.boyishdoor = true;
	}
	else if (HitNextArea(820.0f, 945.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		corridorobject.tunderedoor = true;
	}
	else if(HitNextArea(225.0f, 350.0f, 440.0f, 450.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		corridorobject.yuruhuwadoor = true;
	}

	if (displaydata.displaynext == true)
	{
		areadata.corridor = false;
		getitem.breakdoorkey = true;
		ChangeSceneStep(SceneStep::EndStep);
	}

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