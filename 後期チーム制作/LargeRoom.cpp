
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
	//DrawYuruhuwa();
	DrawMaidRobot();

	DrawSearchPlayer();
	DrawTexture(960.0f, 755.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::Searchhanger));
	DrawTexture(160.0f, 770.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchFlowerpot));
	

	DrawMenu();
	DrawTime();
	DrawTalkText();
	DrawTalkMaid();
	DrawTalkYuruhuwa();
	
	SearchObject();
}

void InitLargeRoomScene()
{
	LoadSearchGameItem();

	LoadTexture("Res/大部屋B.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex);
	
	LoadTexture("Res/キャラ/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/キャラ/ボーイッシュちび.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);

	LoadTexture("Res/キャラ/メイド_立ち絵.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex);
	LoadTexture("Res/キャラ/メイド_ちび.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchMaidRobotTex);
	
	LoadTexture("Res/探索ゲーム/鍵.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemKeyTex);

	LoadTexture("Res/家具/観葉植物B.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchFlowerpot);
	LoadTexture("Res/家具/コート掛け.png", TEXTURE_SEARCH, SearchCategoryTextureList::Searchhanger);

	LoadUI();

	InitBoyish();
	//InitYuruhuwa();
	InitArea();
	InitLargeRoomPlayer();
	InitMaidRobot();
	InitLoadFile();
	InitTextBox();
	InitMenu();
	InitTimeCounter();

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

	
	if (OnMouseDown(Left) == true)
	{
		LoadText();
		textdata.nexttext = true;
	}
	

	if (searchplayer.pos_x <= 70.0f && searchplayer.pos_y >= 390.0f && searchplayer.pos_y <= 500.0f)
	{
		areadata.largeroom = false;
		areadata.corridor = true;

		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (searchplayer.pos_x >= 1770.0f && searchplayer.pos_y >= 370.0f && searchplayer.pos_y <= 500.0f)
	{
		areadata.largeroom = false;
		areadata.searchcriminalarea = true;

		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (searchplayer.pos_x >= 870.0f && searchplayer.pos_x <= 900.0f && searchplayer.pos_y >= 950.0f && yuruhuwa.clear == true)
	{
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
	else if (yuruhuwa.clear == true)
	{
		return SceneId::GameClearScene;
	}
	else if (time.end == true)
	{
		return SceneId::GameOverScene;
	}
}