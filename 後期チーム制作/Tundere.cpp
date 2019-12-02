#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Tundere.h"

// �Ɛl�����V�[���̏�����
void InitTundereRoomScene();
// �Ɛl�����V�[���̃��C��
void MainTundereRoomScene();
// �Ɛl�����V�[���̏I��
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