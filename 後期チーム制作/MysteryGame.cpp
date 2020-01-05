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
	
	LoadTexture("Res/謎かけゲーム/あいうえお.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgMax);
	LoadTexture("Res/謎かけゲーム/あいうえお枠.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextBoxMax);
	LoadTexture("Res/謎かけゲーム/選択中.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextMax);
	LoadTexture("Res/謎かけゲーム/問題.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextMax);

	InitMysteryText();
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