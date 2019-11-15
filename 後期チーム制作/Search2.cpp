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
	DrawSearch2Bg();
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
	SearchPlayerControl();

	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishSearch2Scene()
{
	ReleaseCategoryTexture(TEXTURE_SEARCH);

	return SceneId::TalkScene;

}