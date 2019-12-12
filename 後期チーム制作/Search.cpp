#include "Search.h"
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


void InitSearchScene();

void MainSearchScene();


SceneId FinishSearchScene();


SceneId UpdateSearchScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitSearchScene();
		break;
	case SceneStep::MainStep:
		MainSearchScene();
		break;
	case SceneStep::EndStep:
		return FinishSearchScene();
		break;
	}

	return SceneId::SearchScene;
}

void DrawSearchScene()
{
	DrawSearchBg();
	DrawBoyish();
	DrawMaidRobot();

	DrawSearchPlayer();
	DrawTexture(960.0f, 755.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::Searchhanger));
	DrawTexture(160.0f, 770.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchFlowerpot));
	

	DrawMenu();
	DrawTime();
	//DrawTxt();
	DrawTalkMaid();
}

void InitSearchScene()
{
	LoadSearchGameItem();

	LoadTexture("Res/�啔��B.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex);
	
	LoadTexture("Res/�L����/��l�������t�@�C��.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/�L����/�{�[�C�b�V������.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);

	LoadTexture("Res/�L����/���C�h_�����G.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex);
	LoadTexture("Res/�L����/���C�h_����.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchMaidRobotTex);
	
	LoadTexture("Res/�T���Q�[��/��.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemKeyTex);

	LoadTexture("Res/UI/�e�L�X�g�{�b�N�X.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex);
	LoadTexture("Res/UI/�A�C�e�����j���[.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/UI/�A�C�e���{�b�N�X.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);
	LoadTexture("Res/�Ƌ�/�ϗt�A��B.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchFlowerpot);
	LoadTexture("Res/�Ƌ�/�R�[�g�|��.png", TEXTURE_SEARCH, SearchCategoryTextureList::Searchhanger);
	//boyish.clear = true;
	InitBoyish();
	InitArea();
	InitSearchPlayer();
	InitMaidRobot();
	
	InitTextBox();
	InitMenu();
	InitTimeCounter();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearchScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}

	HitSearchObject();

	HitEyeSearchObject();

	UpDataPlayerPos();

	UpDateMenu();

	if (searchplayer.pos_x <= 70.0f && searchplayer.pos_y >= 390.0f && searchplayer.pos_y <= 500.0f)
	{
		areadata.searcharea1 = false;
		areadata.searcharea2 = true;

		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (searchplayer.pos_x >= 1770.0f && searchplayer.pos_y >= 370.0f && searchplayer.pos_y <= 500.0f)
	{
		areadata.searcharea1 = false;
		areadata.searchcriminalarea = true;

		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (searchplayer.pos_x >= 870.0f && searchplayer.pos_x <= 900.0f && searchplayer.pos_y >= 950.0f && boyish.clear == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (time.end == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishSearchScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH);

	if (areadata.searcharea2 == true)
	{
		return SceneId::Search2Scene;
	}
	else if (areadata.searchcriminalarea == true)
	{
		return SceneId::CriminalRoomScene;
	}
	else if (boyish.clear == true)
	{
		return SceneId::GameClearScene;
	}
	else if (time.end == true)
	{
		return SceneId::GameOverScene;
	}
}