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

	LoadTexture("Res/謎かけゲーム/謎文1.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex_1);
	LoadTexture("Res/謎かけゲーム/謎文2.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex_2);

	LoadTexture("Res/謎かけゲーム/答え枠.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblem_Answer_1);
	LoadTexture("Res/謎かけゲーム/答え枠2.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblem_Answer_2);

	LoadTexture("Res/謎かけゲーム/決定.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDecisionButtonTex);
	LoadTexture("Res/謎かけゲーム/消す.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDeleteButtonTex);

	InitMysteryText();
	InitButton();
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