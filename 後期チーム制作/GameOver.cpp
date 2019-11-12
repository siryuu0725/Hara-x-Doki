#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "GameOverr.h"

// �Q�[���I�[�o�[�V�[���̏�����
void InitGameOverScene();
// �Q�[���I�[�o�[�V�[���̃��C��
void MainGameOverScene();
// �Q�[���I�[�o�[�V�[���̏I��
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

