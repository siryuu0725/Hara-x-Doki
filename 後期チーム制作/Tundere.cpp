#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Tundere.h"

// 犯人部屋シーンの初期化
void InitTundereRoomScene();
// 犯人部屋シーンのメイン
void MainTundereRoomScene();
// 犯人部屋シーンの終了
SceneId FinishTundereRoomScene();

SceneId UpdateTundereRoomScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitTundereRoomScene();
		break;
	case SceneStep::MainStep:
		MainTundereRoomScene();
		break;
	case SceneStep::EndStep:
		return FinishTundereRoomScene();
		break;
	}

	return SceneId::TundereRoomScene;
}

void DrawTundereRoomScene()
{
}

void InitTundereRoomScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

void MainTundereRoomScene()
{

	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishTundereRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_TUNDERE_ROOM);

	return SceneId::TitleScene;
}