#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Title.h"
#include "Window.h"

#define START_X 710 // �n�߂��X���W
#define START_X_SIZE 600 // �n�߂��X���W�̃T�C�Y
#define START_Y 700 // �n�߂��Y���W
#define START_Y_SIZE 150 // �n�߂��Y���W�̃T�C�Y
#define END_X 710 // �I����X���W
#define END_X_SIZE 600 // �I����X���W�̃T�C�Y
#define END_Y 900 // �I����Y���W
#define END_Y_SIZE 150 // �I����Y���W�̃T�C�Y

// �^�C�g���V�[���̏�����
void InitTitleScene();
// �^�C�g���V�[���̃��C������
void MainTitleScene();
// �^�C�g���V�[���̏I��
SceneId FinishTitleScene();

SceneId UpdateTitleScene()
{
	switch (GetCurrentSceneStep())//Current:����
	{
	case SceneStep::InitStep:
		InitTitleScene();
		break;
	case SceneStep::MainStep:
		MainTitleScene();
		break;
	case SceneStep::EndStep:
		return FinishTitleScene();
		break;
	}

	return SceneId::TitleScene;
}

void DrawTitleScene()
{
	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleBgTex));
	DrawTexture(START_X, START_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex));
	DrawTexture(END_X, END_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex));
}

void InitTitleScene()
{
	LoadTexture("Res/TitleBg.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleBgTex);
	LoadTexture("Res/Start.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex);
	LoadTexture("Res/End.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex);
	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	// �n�߂�ƃ}�E�X�̓����蔻��
	if (GetMousePos().X >= START_X && GetMousePos().X <= START_X + START_X_SIZE &&
		GetMousePos().Y >= START_Y && GetMousePos().Y <= START_Y + START_Y_SIZE &&
		OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

	// �I���ƃ}�E�X�̓����蔻��
	if (GetMousePos().X >= END_X && GetMousePos().X <= END_X + END_X_SIZE &&
		GetMousePos().Y >= END_Y && GetMousePos().Y <= END_Y + END_Y_SIZE &&
		OnMouseDown(Left) == true)
	{
		PostQuitMessage(0);
	}
}

SceneId FinishTitleScene()
{
	ReleaseCategoryTexture(TEXTURE_TITLE);

	//return SceneId::MovieScene;
	//return SceneId::MovieScene;
	return SceneId::ScenarioScene;
}