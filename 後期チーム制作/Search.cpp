#include "Search.h"
#include "Scene.h"
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"
#include "Bg.h"

extern SearchPlayerData serachplayer;


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
	DrawSearchPlayer();
}

void InitSearchScene()
{
	LoadTexture("Res/SearchBg.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex);
	LoadTexture("Res/SearchBg2.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchBg2Tex);
	LoadTexture("Res/Player.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);

	InitSearchPlayer();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearchScene()
{
	//SearchPlayerControl(&serachplayer);

	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishSearchScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH);

	return SceneId::TalkScene;

}