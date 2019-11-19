#include "Scenario.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"

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
	DrawFont(900, 540, "スペースでムービーに移動", FontSize::Small, FontColor::White);
}

void InitScenarioScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

void MainScenarioScene()
{
	if (GetKeyDown(SPACE_KEY) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishScenarioScene()
{
	ReleaseCategoryTexture(TEXTURE_SCENARIO);

	return SceneId::MovieScene;
}