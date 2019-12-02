#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Yuruhuwa.h"

// 犯人部屋シーンの初期化
void InitYuruhuwaRoomScene();
// 犯人部屋シーンのメイン
void MainYuruhuwaRoomScene();
// 犯人部屋シーンの終了
SceneId FinishYuruhuwaRoomScene();

SceneId UpdateYuruhuwaRoomScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitYuruhuwaRoomScene();
		break;
	case SceneStep::MainStep:
		MainYuruhuwaRoomScene();
		break;
	case SceneStep::EndStep:
		return FinishYuruhuwaRoomScene();
		break;
	}

	return SceneId::YuruhuwaRoomScene;
}

void DrawYuruhuwaRoomScene()
{
}

void InitYuruhuwaRoomScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

void MainYuruhuwaRoomScene()
{

	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishYuruhuwaRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_YURUHUWA_ROOM);

	return SceneId::TitleScene;
}