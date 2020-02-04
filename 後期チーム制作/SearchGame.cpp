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
#include "Talk.h"

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

	DrawSearchPlayerAndRobot();
	
	
	DrawMenu();
	DrawTime();
	DrawTalkSearchGameRobot();
	DrawTalkBoyish();

	SearchObject();
}

void InitSearchGameScene()
{
	LoadSearchGameItem();

	LoadCharacter();

	LoadTexture("Res/å¬é∫ÅièóéqïîâÆÅj.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex);
	LoadTexture("Res/â∆ãÔ/ë´ûg.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameFetters);

	
	
	LoadUI();
	
	InitBoyish();
	InitSearchGameRobot();

	InitChoiceTexture();
	InitRobotLoadFile();
	InitJKLoadFile();
	InitSearchGameObject();
	InitGameRoomPlayer();
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

	UpDataBoyishTalk();

	UpDateTalkSearchGameRobot();

	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
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