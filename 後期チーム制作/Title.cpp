#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Title.h"
#include "Window.h"
#include "Hit.h"
#include "Bg.h"


// タイトルシーンの初期化
void InitTitleScene();
// タイトルシーンのメイン処理
void MainTitleScene();
// タイトルシーンの終了
SceneId FinishTitleScene();

SceneId UpdateTitleScene()
{
	switch (GetCurrentSceneStep())//Current:今の
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
	LoadTexture("Res/UI/はじめる.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex);
	LoadTexture("Res/UI/おわる.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex);
	LoadTexture("Res/UI/はじめる02.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleStartChoiceTex);
	LoadTexture("Res/UI/おわる02.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleEndChoiceTex);
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

	//// 始めるとマウスの当たり判定
	//if (GetMousePos().X >= START_X && GetMousePos().X <= START_X + START_X_SIZE &&
	//	GetMousePos().Y >= START_Y && GetMousePos().Y <= START_Y + START_Y_SIZE &&
	//	OnMouseDown(Left) == true)
	//{
	//	ChangeSceneStep(SceneStep::EndStep);
	//}

	//// 終わるとマウスの当たり判定
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