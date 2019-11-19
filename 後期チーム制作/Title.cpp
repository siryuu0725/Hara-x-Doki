#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Title.h"
#include "Window.h"

#define START_X 710 // 始めるのX座標
#define START_X_SIZE 600 // 始めるのX座標のサイズ
#define START_Y 700 // 始めるのY座標
#define START_Y_SIZE 150 // 始めるのY座標のサイズ
#define END_X 710 // 終わるのX座標
#define END_X_SIZE 600 // 終わるのX座標のサイズ
#define END_Y 900 // 終わるのY座標
#define END_Y_SIZE 150 // 終わるのY座標のサイズ

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
	// 始めるとマウスの当たり判定
	if (GetMousePos().X >= START_X && GetMousePos().X <= START_X + START_X_SIZE &&
		GetMousePos().Y >= START_Y && GetMousePos().Y <= START_Y + START_Y_SIZE &&
		OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

	// 終わるとマウスの当たり判定
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