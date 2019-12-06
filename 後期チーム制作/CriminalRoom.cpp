#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "CriminalRoom.h"
#include "Item.h"
#include "Player.h"
#include "Bg.h"
#include "Text.h"
#include "Menu.h"

// 犯人部屋シーンの初期化
void InitCriminalRoomScene();
// 犯人部屋シーンのメイン
void MainCriminalRoomScene();
// 犯人部屋シーンの終了
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

	LoadTexture("Res/主人公統合ファイル.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/テキストボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextBoxTex);
	LoadTexture("Res/テキスト名前.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextnameTex);
	LoadTexture("Res/アイテムメニュー.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/アイテムボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);

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