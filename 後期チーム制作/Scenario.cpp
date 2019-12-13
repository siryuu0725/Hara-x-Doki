#include "Scenario.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "Text.h"

extern ScenarioData scenario;

void InitScenarioScene();

void MainScenarioScene();

SceneId FinishScenarioScene();

SceneId UpdateScenarioScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitScenarioScene();
		break;
	case SceneStep::MainStep:
		MainScenarioScene();
		break;
	case SceneStep::EndStep:
		return FinishScenarioScene();
		break;
	}

	return SceneId::ScenarioScene;
}

void DrawScenarioScene()
{
	DrawScenario();
}

void InitScenarioScene()
{
	InitScenario();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainScenarioScene()
{
	if (scenario.scenario == false && GetKeyDown(SPACE_KEY) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishScenarioScene()
{
	ReleaseCategoryTexture(TEXTURE_SCENARIO);

	return SceneId::MovieScene;
}