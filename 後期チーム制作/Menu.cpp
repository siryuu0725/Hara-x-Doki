#include "Menu.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Text.h"
#include "Item.h"
#include "Bg.h"
#include "JK.h"

#define MENU_POS_X 0
#define MENU_POS_Y 680

MenuData menu;
extern TextBoxData textbox;

void InitMenu()
{
	menu.pos_x = MENU_POS_X;
	menu.pos_y = MENU_POS_Y;
	menu.onenterkey = false;
}

void DrawMenu()
{
	if (menu.onenterkey == true)
	{
		DrawTexture(menu.pos_x, menu.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex));
	}

	if (menu.onenterkey == true)
	{
		DrawTexture(menu.pos_x, menu.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex));

		if (getitem.itemrobot == true && searchgameobject.completerobot != true)
		{
			DrawTexture(60.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemRobotPartTex));
		}
		if (getitem.itemlight == true)
		{
			DrawTexture(320.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemRightTex));
		}
		if (getitem.itemkey == true)
		{
			DrawTexture(580.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemKeyTex));
		}
		if (getitem.boyishdoorkey == true && getitem.tunderedoorkey == true && getitem.yuruhuwadoorkey == true)
		{
			DrawTexture(580.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemKeyTex));
		}
		if (getitem.itemenergy == true)
		{
			DrawTexture(840.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemEnergyTex));
		}
	}
}

void UpDateMenu()
{
	// ENTERキーを押したらメニュー画面描画
	if (GetKeyDown(RETURN_KEY) == true && menu.onenterkey == false)
	{
		menu.onenterkey = true;
	}

	// ENTERキーをもう一度押したらメニュー画面を消す
	else if (GetKeyDown(RETURN_KEY) == true && menu.onenterkey == true)
	{
		menu.onenterkey = false;
	}
}


void Reset()
{
	areadata.cangearea = false;
	boyish.clear = false;
	boyish.heart = 0;
}