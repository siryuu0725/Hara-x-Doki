#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "Player.h"
#include "Bg.h"
#include "Robot.h"
#include "Menu.h"
#include "Item.h"
#include "Hit.h"
#include "Text.h"
#include "Tundere.h"
#include "JK.h"


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
	DrawSearchBg();
	//DrawMysteryGameRobot();
	DrawSearchPlayerAndRobot();
	
	//�v���C���[�̉��s�����o�����ߕ`��ʒu�ύX
	DrawTexture(450.0f, 610.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight));
	DrawMenu();
	DrawTime();
	DrawTalkMysteryGameRobot();
	SearchObject();
}

void InitTundereRoomScene()
{
	LoadTundereFurnitureTex();
	LoadSearchGameItem();

	LoadCharacter();


	

	LoadUI();

	InitTundereRoomObject();
	InitGameRoomPlayer();
	InitMysteryGameRobot();
	InitTextBox();
	InitMenu();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainTundereRoomScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}
	HitTundereRoomObject();
	UpDataPlayerPos();
	UpDateMenu();
	HitEyeTundereRoomObject();
	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchtunderearea = false;
		areadata.corridor = true;
		areadata.cangearea2 = 2;
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishTundereRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_TUNDERE_ROOM);

	if (areadata.cangearea2 == 2)
	{
		return SceneId::CorridorScene;
	}
	
}