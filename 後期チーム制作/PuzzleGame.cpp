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
	LoadTexture("Res/配置.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleGameBgTex);
	LoadTexture("Res/Key.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleKeyTex);
	LoadTexture("Res/cabe変更.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleSquareTex);
	LoadTexture("Res/cabe2変更.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleLandscapeTex);
	LoadTexture("Res/cabe3変更.png", TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzlePortraitTex);

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