#include "Scene.h"
#include "Graphics.h"
#include "Input.h"
#include "GameClear.h"
#include "GameOverr.h"
#include "Title.h"
#include "Movie.h"
#include "Search.h"
#include "Search2.h"
#include "SearchGame.h"
#include "PuzzleGame.h"
#include "TalkScene.h"
#include "Scenario.h"
#include "CriminalRoom.h"
#include "Tundere.h"
#include "Yuruhuwa.h"


static SceneId g_CurrentSceneId = SceneId::SearchScene;		// 動作中シーンID
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
	case SceneId::ScenarioScene:
		scene_id = UpdateScenarioScene();
		break;
	case SceneId::MovieScene:
		scene_id = UpdateMovieScene();
		break;
	case SceneId::SearchScene:
		scene_id = UpdateSearchScene();
		break;
	case SceneId::Search2Scene:
		scene_id = UpdateSearch2Scene();
		break;
	case SceneId::TundereRoomScene:
		scene_id = UpdateTundereRoomScene();
		break;
	case SceneId::YuruhuwaRoomScene:
		scene_id = UpdateYuruhuwaRoomScene();
		break;
	case SceneId::SearchGameScene:
		scene_id = UpdateSearchGameScene();
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
		case SceneId::ScenarioScene:
			DrawScenarioScene();
			break;
		case SceneId::MovieScene:
			DrawMovieScene();
			break;
		case SceneId::SearchScene:
			DrawSearchScene();
			break;
		case SceneId::Search2Scene:
			DrawSearch2Scene();
			break;
		case SceneId::CriminalRoomScene:
			DrawCriminalRoomScene();
			break;	
		case SceneId::TundereRoomScene:
			DrawTundereRoomScene();
		    break;	
		case SceneId::YuruhuwaRoomScene:
			DrawYuruhuwaRoomScene();
		    break;	
		case SceneId::SearchGameScene:
			DrawSearchGameScene();
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