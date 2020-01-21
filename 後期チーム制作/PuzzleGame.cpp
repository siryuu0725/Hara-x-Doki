#include "PuzzleGame.h"
#include "Puzzle.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "JK.h"
#include "Text.h"

void InitPuzzleGameScene();

void MainPuzzleGameScene();


SceneId FinishPuzzleGameScene();


SceneId UpdatePuzzleGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitPuzzleGameScene();
		break;
	case SceneStep::MainStep:
		MainPuzzleGameScene();
		break;
	case SceneStep::EndStep:
		return FinishPuzzleGameScene();
		break;
	}

	return SceneId::PuzzleGameScene;
}

void DrawPuzzleGameScene()
{
	DrawBgPuzzle();
	DrawPuzzle();
	
	DrawTime();
}

void InitPuzzleGameScene()
{
	InitPuzzle();
	LoadTexture("Res/�p�Y���Q�[��/�p�Y���w�i.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleGameBgTex);
	LoadTexture("Res/�p�Y���Q�[��/�s�[�X���C��.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleKeyTex);
	LoadTexture("Res/�p�Y���Q�[��/�s�[�X�����`.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleSquareTex);
	LoadTexture("Res/�p�Y���Q�[��/�s�[�X��.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleLandscapeTex);
	LoadTexture("Res/�p�Y���Q�[��/�s�[�X�c.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzlePortraitTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainPuzzleGameScene()
{
	UpDatePuzzle();
	
	if (nextcene.Clea == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (OnMouseDown(Right) == true)
	{

		yuruhuwa.clear = true;
		puzzle.goal_key = true;
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishPuzzleGameScene()
{
	ReleaseCategoryTexture(TEXTURE_PUZZLE);

	return SceneId::YuruhuwaRoomScene;

}