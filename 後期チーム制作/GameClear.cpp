#include "Graphics.h"
#include "Texture.h"
#include "GameClear.h"
#include "Input.h"
#include "Talk.h"
#include "JK.h"
#include "Bg.h"
#include "Text.h"
#include "Menu.h"

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
	GameClearBg();

	DrawTalkClearBoyish();

	DrawTalkClearYuruhuwa();

}

void InitGameClearScene()
{
	//areadata.largeroom = false;
	//areadata.cleararea = true;
	//boyish.clear = true;

	LoadTexture("Res/�X�`�� ����.png", TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::BoyishClearBgTex);
	LoadTexture("Res/�X�`�����ӂ�.png", TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::YuruhuwaClearBgTex);

	LoadUI();

	InitTextBox();

	InitJKLoadFile();

	JKLoadText();
	
	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameClearScene()
{
	
	UpDataClearText();

	

	if (boyish.end == true || yuruhuwa.end == true)
	{
		boyish.end = false;
		yuruhuwa.end = false;
		Reset();
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishGameClearScene()
{
	ReleaseCategoryTexture(TEXTURE_GAME_CLEAR);

	return SceneId::TitleScene;
}

