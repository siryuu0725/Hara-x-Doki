#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "GameOverr.h"

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
	//DrawTexture(0, 0, GetTexture(TEXTURE_GAME_OVER, GameOverCategoryTextureList::GameOverBgTex));
}

void InitGameOverScene()
{
	//LoadTexture("Res/GameOverBg.png", TEXTURE_GAME_OVER, GameOverCategoryTextureList::GameOverBgTex);
	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameOverScene()
{
	
		ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameOverScene()
{
	ReleaseCategoryTexture(TEXTURE_GAME_OVER);

	return SceneId::TitleScene;
}

