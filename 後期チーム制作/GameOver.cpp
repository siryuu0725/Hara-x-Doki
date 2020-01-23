#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "GameOverr.h"
#include "Text.h"

// ゲームオーバーシーンの初期化
void InitGameOverScene();
// ゲームオーバーシーンのメイン
void MainGameOverScene();
// ゲームオーバーシーンの終了
SceneId FinishGameOverScene();

SceneId UpdateGameOverScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameOverScene();
		break;
	case SceneStep::MainStep:
		MainGameOverScene();
		break;
	case SceneStep::EndStep:
		return FinishGameOverScene();
		break;
	}

	return SceneId::GameOverScene;
}

void DrawGameOverScene()
{
	DrawTexture(200.0f, 200.0f, GetTexture(TEXTURE_GAME_OVER, GameOverCategoryTextureList::GameOverLogoTex));
}

void InitGameOverScene()
{
	LoadTexture("Res/UI/ゲームオーバー.png", TEXTURE_GAME_OVER, GameOverCategoryTextureList::GameOverLogoTex);
	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameOverScene()
{
	if (GetKeyDown(SPACE_KEY) == true)
	{
		time.end = false;
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishGameOverScene()
{
	ReleaseCategoryTexture(TEXTURE_GAME_OVER);

	return SceneId::TitleScene;
}

