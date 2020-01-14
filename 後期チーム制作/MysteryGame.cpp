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
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/Ç»ÇºÇ»Çºîwåi.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgTex);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/Ç†Ç¢Ç§Ç¶Ç®.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/Ç†Ç¢Ç§Ç¶Ç®òg.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextBoxTex);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/ëIëíÜ.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextTex);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/ñ‚ëË.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/åàíË.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDecisionButtonTex);

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