#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "GameOverr.h"
#include "Text.h"

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
	DrawTexture(200.0f, 200.0f, GetTexture(TEXTURE_GAME_OVER, GameOverCategoryTextureList::GameOverLogoTex));
}

void InitGameOverScene()
{
	LoadTexture("Res/UI/�Q�[���I�[�o�[.png", TEXTURE_GAME_OVER, GameOverCategoryTextureList::GameOverLogoTex);
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

