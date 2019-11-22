#include "Search.h"
#include "Search2.h"
#include "Scene.h"
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"
#include "Bg.h"

void InitSearch2Scene();

void MainSearch2Scene();



SceneId FinishSearch2Scene();


SceneId UpdateSearch2Scene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitSearch2Scene();
		break;
	case SceneStep::MainStep:
		MainSearch2Scene();
		break;
	case SceneStep::EndStep:
		return FinishSearch2Scene();
		break;
	}

	return SceneId::Search2Scene;
}

void DrawSearch2Scene()
{
	DrawSearchBg();
	DrawSearchPlayer();
}

void InitSearch2Scene()
{
	LoadTexture("Res/˜L‰º.png", TEXTURE_SEARCH2, Search2CategoryTextureList::Search2BgTex);
	LoadTexture("Res/ƒ‰ƒtƒLƒƒƒ‰.jpg", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);

	InitSearch2Player();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearch2Scene()
{
	SearchPlayerControl(450.0f, 840.0f, 0.0f, 1920.0f);

	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (searchplayer.pos_x + 64.0f >= 1900.0f && searchplayer.pos_y <= 650.0f && searchplayer.pos_y >= 630.0f)
	{
		areadata.searcharea2 = false;
		areadata.searcharea1 = true;
		areadata.cangearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}
	//ƒLƒƒƒ‰‚Ì•+20’ö”»’è‚ð‘å‚«‚­‚µ‚Ä‚¢‚é
	if (searchplayer.pos_x >= 1430.0f && searchplayer.pos_x + 64.0f <= 1550.0f && searchplayer.pos_y <= 460.0f
		&& GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searcharea2 = false;
		areadata.searchgamearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (searchplayer.pos_x >= 820.0f && searchplayer.pos_x + 64.0f <= 945.0f && searchplayer.pos_y <= 450.0f
		&& GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searcharea2 = false;
		areadata.searchgamearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (searchplayer.pos_x >= 225.0f && searchplayer.pos_x + 64.0f <= 350.0f && searchplayer.pos_y <= 450.0f
		&& GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searcharea2 = false;
		areadata.searchgamearea = true;
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishSearch2Scene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH2);

	if (areadata.searcharea1 == true)
	{
		return SceneId::SearchScene;
	}
	else if (areadata.searchgamearea == true)
	{
		return SceneId::SearchGameScene;
	}
		

}