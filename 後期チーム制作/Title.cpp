#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Title.h"
#include "Window.h"
#include "Hit.h"
#include "Bg.h"


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
	DrawTitleBg();
}


void InitTitleScene()
{
	LoadTexture("Res/TitleBg.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleBgTex);
	LoadTexture("Res/UI/�͂��߂�.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex);
	LoadTexture("Res/UI/�����.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex);
	LoadTexture("Res/UI/�͂��߂�02.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleStartChoiceTex);
	LoadTexture("Res/UI/�����02.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleEndChoiceTex);
	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{

	if (HitChoiseTitle(START_X, START_Y, START_X_SIZE, START_Y_SIZE) == true
		&& OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

	if (HitChoiseTitle(END_X, END_Y, END_X_SIZE, END_Y_SIZE) == true
		&& OnMouseDown(Left) == true)
	{
		PostQuitMessage(0);
	}

	//// �n�߂�ƃ}�E�X�̓����蔻��
	//if (GetMousePos().X >= START_X && GetMousePos().X <= START_X + START_X_SIZE &&
	//	GetMousePos().Y >= START_Y && GetMousePos().Y <= START_Y + START_Y_SIZE &&
	//	OnMouseDown(Left) == true)
	//{
	//	ChangeSceneStep(SceneStep::EndStep);
	//}

	//// �I���ƃ}�E�X�̓����蔻��
	//if (GetMousePos().X >= END_X && GetMousePos().X <= END_X + END_X_SIZE &&
	//	GetMousePos().Y >= END_Y && GetMousePos().Y <= END_Y + END_Y_SIZE &&
	//	OnMouseDown(Left) == true)
	//{
	//	PostQuitMessage(0);
	//}
}

SceneId FinishTitleScene()
{
	ReleaseCategoryTexture(TEXTURE_TITLE);

	return SceneId::MovieScene;
	
	//return SceneId::SearchGameScene;
}