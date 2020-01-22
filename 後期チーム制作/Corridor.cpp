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
	DrawBoyish();
	DrawYuruhuwa();
	DrawSearchPlayerAndRobot();
	
	
	DrawTime();
	DrawTalkBoyish();
	DrawTalkYuruhuwa();
	DrawDoorTalk();
	DrawMenu();
}

void InitCorridorScene()
{

	LoadCorridorFurnitureTex();
	LoadSearchGameItem();

	LoadTexture("Res/˜L‰º_C³.png", TEXTURE_SEARCH2, CorridorCategoryTextureList::Search2BgTex);
	LoadCharacter();
	LoadUI();

	InitCorridorPlayer();
	InitBoyish();
	InitYuruhuwa();
	InitMenu();
	InitRobotLoadFile();
	InitJKLoadFile();
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

	HitEyeCorridorObject();

	UpDataPlayerPos();

	UpDataDoorText();

	UpDataBoyishTalk();
	UpDataYuruhuwaTalk();

	UpDateMenu();

	if (searchplayer.pos_x + 64.0f >= 1900.0f)
	{
		areadata.corridor = false;
		areadata.largeroom = true;
		areadata.cangearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}

	//ƒLƒƒƒ‰‚Ì•+20’ö”»’è‚ğ‘å‚«‚­‚µ‚Ä‚¢‚é
	
	
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