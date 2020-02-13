
#include "Scene.h"
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"
#include "Bg.h"
#include "Hit.h"
#include "Item.h"
#include "Menu.h"
#include "Text.h"
#include "Robot.h"
#include "JK.h"
#include "Talk.h"

extern SearchPlayerData serachplayer;
extern TextBoxData textbox;
extern MenuData menu;


void InitLargeRoomScene();

void MainLargeRoomScene();


SceneId FinishLargeRoomScene();


SceneId UpdateLargeRoomScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitLargeRoomScene();
		break;
	case SceneStep::MainStep:
		MainLargeRoomScene();
		break;
	case SceneStep::EndStep:
		return FinishLargeRoomScene();
		break;
	}

	return SceneId::LargeRoomScene;
}

void DrawLargeRoomScene()
{
	DrawSearchBg();
	DrawBoyish();
	DrawYuruhuwa();
	DrawTundere();
	DrawMaidRobot();

	DrawSearchPlayerAndRobot();
	DrawTexture(960.0f, 755.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomhanger));
	DrawTexture(160.0f, 770.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomFlowerpot));
	
	DrawDescription();

	DrawTime();
	SearchObject();
	DrawTalkMaid();
	DrawTalkBoyish();
	DrawTalkYuruhuwa();
	DrawTalkTundere();
	DrawMenu();
}

void InitLargeRoomScene()
{
	LoadSearchGameItem();

	LoadCharacter();

	LoadTexture("Res/ëÂïîâÆB.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomBgTex);
		
	LoadTexture("Res/íTçıÉQÅ[ÉÄ/åÆ.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemKeyTex);

	LoadTexture("Res/â∆ãÔ/äœótêAï®B.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomFlowerpot);
	LoadTexture("Res/â∆ãÔ/ÉRÅ[Égä|ÇØ.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomhanger);

	LoadUI();

	InitBoyish();
	InitYuruhuwa();
	InitTundere();
	InitArea();
	InitLargeRoomPlayer();
	InitMaidRobot();
	
	InitRobotLoadFile();
	InitJKLoadFile();

	InitTextBox();
	InitMenu();
	InitTimeCounter();

	InitChoiceTexture();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainLargeRoomScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}

	HitLargeRoomObject();

	HitEyeLargeRoomObject();

	UpDataPlayerPos();

	UpDateMenu();

	UpDataBoyishTalk();

	UpDataYuruhuwaTalk();

	UpDataTundereTalk();

	UpDataDescriptionText();

	UpDateTalkMaid();
	if (searchplayer.pos_x <= 70.0f && searchplayer.pos_y >= 390.0f && searchplayer.pos_y <= 500.0f)
	{
		areadata.largeroom = false;
		areadata.corridor = true;
		areadata.cangearea2 = 0;
		choicetexturedata.decision_2 = false;
		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (searchplayer.pos_x >= 1770.0f && searchplayer.pos_y >= 370.0f && searchplayer.pos_y <= 500.0f)
	{
		areadata.largeroom = false;
		areadata.searchcriminalarea = true;

		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (searchplayer.pos_x >= 860.0f && searchplayer.pos_x <= 920.0f && searchplayer.pos_y >= 950.0f
		&& (boyish.clear == true && yuruhuwa.clear == true && tundere.clear == true) && (boyish.heart != 3 || yuruhuwa.heart != 3 || tundere.heart != 3)
		&& GetKeyDown(SPACE_KEY) == true)
	{
		areadata.largeroom = false;
		areadata.cleararea = true;
		areadata.cangearea2 = 0;
		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (searchplayer.pos_x >= 860.0f && searchplayer.pos_x <= 920.0f && searchplayer.pos_y >= 950.0f 
		&& (boyish.clear == true || yuruhuwa.clear == true || tundere.clear == true) && (boyish.heart == 3 || yuruhuwa.heart == 3 || tundere.heart == 3)
		&& GetKeyDown(SPACE_KEY) == true)
	{
		areadata.largeroom = false;
		areadata.cleararea = true;
		areadata.cangearea2 = 0;
		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (time.end == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishLargeRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH);

	if (areadata.corridor == true)
	{
		return SceneId::CorridorScene;
	}
	else if (areadata.searchcriminalarea == true)
	{
		return SceneId::CriminalRoomScene;
	}
	else if (areadata.cleararea == true)
	{
		return SceneId::GameClearScene;
	}
	else if (time.end == true)
	{
		return SceneId::GameOverScene;
	}
}