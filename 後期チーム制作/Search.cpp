#include "Search.h"
#include "Scene.h"
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"
#include "Bg.h"

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
	
}

void InitSearchScene()
{
	
	ChangeSceneStep(SceneStep::MainStep);
}

void MainSearchScene()
{

	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishSearchScene()
{
	ReleaseCategoryTexture(TEXTURE_MOVIE);

	return SceneId::TalkScene;

}