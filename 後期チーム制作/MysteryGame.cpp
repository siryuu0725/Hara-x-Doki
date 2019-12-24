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
	DrawMysteryChoiceText();
}

void InitMysteryGameScene()
{
	
	LoadTexture("Res/�䂩���Q�[��/�䂩��.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgMax);
	LoadTexture("Res/�䂩���Q�[��/�I�𕶎�.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextMax);
	LoadTexture("Res/�䂩���Q�[��/���.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextMax);

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