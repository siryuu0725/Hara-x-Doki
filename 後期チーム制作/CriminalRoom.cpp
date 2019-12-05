#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "CriminalRoom.h"

// �Ɛl�����V�[���̏�����
void InitCriminalRoomScene();
// �Ɛl�����V�[���̃��C��
void MainCriminalRoomScene();
// �Ɛl�����V�[���̏I��
SceneId FinishCriminalRoomScene();

SceneId UpdateCriminalRoomScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitCriminalRoomScene();
		break;
	case SceneStep::MainStep:
		MainCriminalRoomScene();
		break;
	case SceneStep::EndStep:
		return FinishCriminalRoomScene();
		break;
	}

	return SceneId::CriminalRoomScene;
}

void DrawCriminalRoomScene()
{

}

void InitCriminalRoomScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

void MainCriminalRoomScene()
{

	ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishCriminalRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_CRIMINAL_ROOM);

	return SceneId::TitleScene;
}