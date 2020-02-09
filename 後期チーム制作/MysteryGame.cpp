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

	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/ì‰ï∂1.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex_1);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/ì‰ï∂2.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex_2);

	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/ìöÇ¶òg.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblem_Answer_1);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/ìöÇ¶òg2.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblem_Answer_2);

	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/åàíË.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDecisionButtonTex);
	LoadTexture("Res/ì‰Ç©ÇØÉQÅ[ÉÄ/è¡Ç∑.png", TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDeleteButtonTex);

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