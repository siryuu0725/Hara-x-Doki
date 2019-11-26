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
	DrawSearchRobot();
	DrawSearchPlayer();

	DrawMenu();
}

void InitSearchGameScene()
{
	LoadTexture("Res/個室（女子部屋）.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex);
	LoadTexture("Res/ラフキャラ.jpg", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/ちびロボパーツ.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex);
	LoadTexture("Res/ちび執事(カオナシ).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);

	InitSearchGamePlayer();
	InitSearchRobot();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearchGameScene()
{

	SearchPlayerControl(175.0f, 1080.0f, 460.0f, 1445.0f);

	HitSearchPlayerRobot();
	
	UpDataPlayerPos();

	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	else if (HitNextArea(850.0f, 945.0f, 940.0f, 1080.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchgamearea = false;
		areadata.searcharea2 = true;
		areadata.cangearea2 = true;
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishSearchGameScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH_GAME);

	if (areadata.searcharea2 == true)
	{
		return SceneId::Search2Scene;
	}
	/*else
	{
		return SceneId::TalkScene;
	}*/
	

}