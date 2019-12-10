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
	DrawMysteryGameRobot();
	DrawSearchPlayer();
	
	//�v���C���[�̉��s�����o�����ߕ`��ʒu�ύX
	DrawTexture(450.0f, 610.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight));
	DrawTextBox();
	DrawMenu();
	DrawTime();
}

void InitTundereRoomScene()
{
	LoadTundereFurnitureTex();

	LoadTexture("Res/��l�������t�@�C��.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/���ю���.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRobotTex);
	LoadTexture("Res/�e�L�X�g�{�b�N�X.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextBoxTex);
	LoadTexture("Res/�e�L�X�g���O.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextnameTex);
	LoadTexture("Res/�A�C�e�����j���[.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/�A�C�e���{�b�N�X.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);


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
		areadata.searcharea2 = true;
		areadata.cangearea2 = 2;
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishTundereRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_TUNDERE_ROOM);

	if (areadata.cangearea2 == 2)
	{
		return SceneId::Search2Scene;
	}
	
}