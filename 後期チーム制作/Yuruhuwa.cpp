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
	DrawSearchPlayer();
	DrawTexture(1330.0f, 780.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight));
	DrawTextBox();
	DrawMenu();
}

void InitYuruhuwaRoomScene()
{
	LoadYuruhuwaFurnitureTex();


	LoadTexture("Res/��l�������t�@�C��.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/�e�L�X�g�{�b�N�X.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextBoxTex);
	LoadTexture("Res/�e�L�X�g���O.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextnameTex);
	LoadTexture("Res/�A�C�e�����j���[.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/�A�C�e���{�b�N�X.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);

	InitSearchGamePlayer();
	InitTextBox();
	InitMenu();
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


	if (HitNextArea(900.0f, 990.0f, 940.0f, 1020.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		areadata.searchyuruhuwaarea = false;
		areadata.searcharea2 = true;
		areadata.cangearea2 = 3;
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

SceneId FinishYuruhuwaRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_YURUHUWA_ROOM);

	if (areadata.cangearea2 == 3)
	{
		return SceneId::Search2Scene;
	}
}