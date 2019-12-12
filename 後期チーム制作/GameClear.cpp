#include "Graphics.h"
#include "Texture.h"
#include "GameClear.h"
#include "Input.h"

// ゲームクリアシーンの初期化
void InitGameClearScene();
// ゲームクリアシーンのメイン処理
void MainGameClearScene();
// ゲームクリアシーンの終了
SceneId FinishGameClearScene();

SceneId UpdateGameClearScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameClearScene();
		break;
	case SceneStep::MainStep:
		MainGameClearScene();
		break;
	case SceneStep::EndStep:
		return FinishGameClearScene();
		break;
	}

	return SceneId::GameClearScene;
}

void DrawGameClearScene()
{
	DrawBgTexture(GetTexture(TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::GameClearBgTex));
}

void InitGameClearScene()
{

	LoadTexture("Res/ボーイッシュ スチル.JPG", TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::GameClearBgTex);
	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameClearScene()
{
	
	if (GetKeyDown(SPACE_KEY) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishGameClearScene()
{
	ReleaseCategoryTexture(TEXTURE_GAME_CLEAR);

	return SceneId::TitleScene;
}

