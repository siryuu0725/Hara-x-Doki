#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "CriminalRoom.h"
#include "Item.h"
#include "Player.h"
#include "Bg.h"
#include "Text.h"
#include "Menu.h"

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
	DrawSearchBg();

	DrawSearchPlayer();
	DrawTextBox();
	DrawMenu();
}

void InitCriminalRoomScene()
{
	LoadCriminalFurnitureTex();

	LoadTexture("Res/��l�������t�@�C��.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/UI/�e�L�X�g�{�b�N�X.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex);
	LoadTexture("Res/UI/�e�L�X�g���O.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex);
	LoadTexture("Res/UI/�A�C�e�����j���[.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/UI/�A�C�e���{�b�N�X.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);


	InitCriminalPlayer();
	InitTextBox();
	InitMenu();
	ChangeSceneStep(SceneStep::MainStep);
}

void MainCriminalRoomScene()
{
	if (textbox.onspacekey == false && menu.onenterkey == false)
	{
		SearchPlayerControl(175.0f, 1080.0f, 0.0f, 1920.0f);
	}

	HitCriminalRoomObject();

	UpDataPlayerPos();

	HitEyeCriminalRoomObject();
	if (OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishCriminalRoomScene()
{
	ReleaseCategoryTexture(TEXTURE_CRIMINAL_ROOM);

	return SceneId::TitleScene;
}