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
	LoadTexture("Res/‘å•”‰®.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex);
	LoadTexture("Res/ƒ‰ƒtƒLƒƒƒ‰.jpg", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);

	InitArea();
	InitSearchPlayer();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearchScene()
{
	SearchPlayerControl(155.0f, 1080.0f, 155.0f, 1730.0f);

	if (searchplayer.pos_x <= 170.0f && searchplayer.pos_y >= 150.0f && searchplayer.pos_y <= 370.0f && searchplayer.pos_y >= 314.0f)
	{
		areadata.searcharea1 = false;
		areadata.searcharea2 = true;

		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishSearchScene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH);

	return SceneId::Search2Scene;

}