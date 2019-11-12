#include "Scene.h"
#include "Graphics.h"
#include "Input.h"
#include "GameClear.h"
#include "GameOverr.h"
#include "Title.h"
#include "Movie.h"
#include "Search.h"
#include "PuzzleGame.h"
#include "TalkScene.h"

static SceneId g_CurrentSceneId = SceneId::TitleScene;		// 動作中シーンID
static SceneStep g_CurrentSceneStep = SceneStep::InitStep;	// 動作中シーンのステップ

SceneId GetCurrentSceneId()
{
	return g_CurrentSceneId;
}

SceneStep GetCurrentSceneStep()
{
	return g_CurrentSceneStep;
}

void ChangeSceneStep(SceneStep next_step)
{
	g_CurrentSceneStep = next_step;
}

void UpdateScene()
{
	UpdateInput();
	KeyUpDate();

	SceneId scene_id = g_CurrentSceneId;
	switch (g_CurrentSceneId)
	{
	case SceneId::TitleScene:
		scene_id = UpdateTitleScene();
		break;
	case SceneId::MovieScene:
		scene_id = UpdateMovieScene();
		break;
	case SceneId::SearchScene:
		scene_id = UpdateSearchScene();
		break;
	case SceneId::TalkScene:
		scene_id = UpdateTalkScene();
		break;
	case SceneId::PuzzleGameScene:
		scene_id = UpdatePuzzleGameScene();
		break;
	case SceneId::GameClearScene:
		scene_id = UpdateGameClearScene();
		break;
	case SceneId::GameOverScene:
		scene_id = UpdateGameOverScene();
		break;
	}

	DrawScene();

	if (scene_id != g_CurrentSceneId)
	{
		g_CurrentSceneId = scene_id;
		ChangeSceneStep(SceneStep::InitStep);
	}
}

void DrawScene()
{
	if (DrawStart() == false)
	{
		return;
	}
	if (g_CurrentSceneStep == SceneStep::MainStep)
	{
		switch (g_CurrentSceneId)
		{
		case SceneId::TitleScene:
			DrawTitleScene();
			break;
		case SceneId::MovieScene:
			DrawMovieScene();
			break;
		case SceneId::SearchScene:
			DrawSearchScene();
			break;
		case SceneId::TalkScene:
			DrawTalkScene();
			break;
		case SceneId::PuzzleGameScene:
			DrawPuzzleGameScene();
			break;
		case SceneId::GameClearScene:
			DrawGameClearScene();
			break;
		case SceneId::GameOverScene:
			DrawGameOverScene();
			break;
		}
	}

	DrawEnd();
}