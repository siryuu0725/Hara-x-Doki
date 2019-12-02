#include "PuzzleGame.h"
#include "Puzzle.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"

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
	

}

void InitPuzzleGameScene()
{
	InitPuzzle();
	LoadTexture("Res/�z�u.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleGameBgTex);
	LoadTexture("Res/�s�[�X���C��.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleKeyTex);
	LoadTexture("Res/cabe�ύX.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleSquareTex);
	LoadTexture("Res/�s�[�X��.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleLandscapeTex);
	LoadTexture("Res/�s�[�X�c.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzlePortraitTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainPuzzleGameScene()
{
	UpDatePuzzle();
	
	if (nextcene.Clea == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishPuzzleGameScene()
{
	ReleaseCategoryTexture(TEXTURE_PUZZLE);

	return SceneId::GameClearScene;

}