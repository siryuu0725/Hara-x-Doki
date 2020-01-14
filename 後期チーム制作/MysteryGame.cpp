#include "MysteryGame.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "JK.h"
#include "Text.h"
#include "Mystery.h"

void InitMysteryGameScene();

void MainMysteryGameScene();


SceneId FinishMysteryGameScene();


SceneId UpdateMysteryGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitMysteryGameScene();
		break;
	case SceneStep::MainStep:
		MainMysteryGameScene();
		break;
	case SceneStep::EndStep:
		return FinishMysteryGameScene();
		break;
	}

	return SceneId::MysteryGameScene;
}

void DrawMysteryGameScene()
{
	DrawMysteryBg();
	
}

void InitMysteryGameScene()
{
	LoadTexture("Res/謎かけゲーム/なぞなぞ背景.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgTex);
	LoadTexture("Res/謎かけゲーム/あいうえお.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex);
	LoadTexture("Res/謎かけゲーム/あいうえお枠.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextBoxTex);
	LoadTexture("Res/謎かけゲーム/選択中.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextTex);
	LoadTexture("Res/謎かけゲーム/問題.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex);
	LoadTexture("Res/謎かけゲーム/決定.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDecisionButtonTex);

	InitMysteryText();
	InitDecisionButton();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainMysteryGameScene()
{
	UpDataChoiceText();

	if (OnMouseDown(Right) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishMysteryGameScene()
{
	ReleaseCategoryTexture(TEXTURE_PUZZLE);

	return SceneId::TundereRoomScene;

}