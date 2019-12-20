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
	LoadTexture("Res/タイトル.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleBgTex);
	LoadTexture("Res/UI/はじめる.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex);
	LoadTexture("Res/UI/おわる.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex);
	LoadTexture("Res/UI/スチル.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleListTex);

	LoadTexture("Res/UI/はじめる02.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleStartChoiceTex);
	LoadTexture("Res/UI/おわる02.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleEndChoiceTex);
	LoadTexture("Res/UI/スチル02.png", TEXTURE_TITLE, TitleCategoryTextureList::TitleListChoiceTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{

	if (HitChoise(START_X, START_Y, START_X_SIZE, START_Y_SIZE) == true
		&& OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

	if (HitChoise(END_X, END_Y, END_X_SIZE, END_Y_SIZE) == true
		&& OnMouseDown(Left) == true)
	{
		PostQuitMessage(0);
	}
}

SceneId FinishTitleScene()
{
	ReleaseCategoryTexture(TEXTURE_TITLE);

	//return SceneId::MovieScene;
	
	//return SceneId::SearchGameScene;

	return SceneId::ScenarioScene;
}