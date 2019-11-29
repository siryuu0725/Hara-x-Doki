#include "Menu.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Text.h"

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
}

void UpDateMenu()
{
	// ENTER�L�[���������烁�j���[��ʕ`��
	if (GetKeyDown(RETURN_KEY) == true && menu.onenterkey == false)
	{
		menu.onenterkey = true;
	}

	// ENTER�L�[��������x�������烁�j���[��ʂ�����
	else if (GetKeyDown(RETURN_KEY) == true && menu.onenterkey == true)
	{
		menu.onenterkey = false;
	}
}
