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
#include "Yuruhuwa.h"
#include "JK.h"
#include "Talk.h"

// �Ɛl�����V�[���̏�����
void InitYuruhuwaRoomScene();
// �Ɛl�����V�[���̃��C��
void MainYuruhuwaRoomScene();
// �Ɛl�����V�[���̏I��
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
	DrawSearchBg();
	DrawYuruhuwa();

	DrawSearchPlayerAndRobot();
	//�v���C���[�̉��s�����o�����ߕ`��ʒu�ύX
	DrawTexture(1330.0f, 780.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight));
	
	DrawTalkYuruhuwa();
	DrawMenu();
	DrawTime();
	DrawTalkPuzzleGameRobot();
	SearchObject();
}

void InitYuruhuwaRoomScene()
{
	LoadYuruhuwaFurnitureTex();
	LoadSearchGameItem();

	LoadTexture("Res/�L����/��l�������t�@�C��.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/�L����/���ю���.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex);
	LoadTexture("Res/�L����/�����G����.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkRobotTex);
	LoadTexture("Res/�L����/�{�[�C�b�V������.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);
	LoadTexture("Res/�L����/���ӂ헧���G�P.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex);
	LoadTexture("Res/�L����/�����G����.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobotTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);

	LoadUI();
	
	InitLoadFile();

	InitYuruhuwaRoomObject();
	InitYuruhuwa();
	InitGameRoomPlayer();
	InitPuzzleGameRobot();
	InitTextBox();
	InitMenu();
	getitem.yuruhuwadoorkey = true;
	ChangeSceneStep(SceneStep::MainStep);
}

void MainYuruhuwaRoomScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}
	HitYuruhuwaRoomObject();

	UpDataPlayerPos();

	HitEyeYuruhuwaRoomObject();

	UpDateMenu();

	UpDataDescriptionText();

	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchyuruhuwaarea = false;
		areadata.corridor = true;
		areadata.cangearea2 = 3;
		ChangeSceneStep(SceneStep::EndStep);
	}
	if (yuruhuwaobject.robot == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishYuruhuwaRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_YURUHUWA_ROOM);

	if (yuruhuwaobject.robot == true)
	{
		return SceneId::PuzzleGameScene;
	}
	if (areadata.cangearea2 == 3)
	{
		return SceneId::CorridorScene;
	}
}