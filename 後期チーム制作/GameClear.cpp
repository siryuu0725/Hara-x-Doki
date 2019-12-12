#include "Graphics.h"
#include "Texture.h"
#include "GameClear.h"
#include "Input.h"

// �Q�[���N���A�V�[���̏�����
void InitGameClearScene();
// �Q�[���N���A�V�[���̃��C������
void MainGameClearScene();
// �Q�[���N���A�V�[���̏I��
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

	LoadTexture("Res/�{�[�C�b�V�� �X�`��.JPG", TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::GameClearBgTex);
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

