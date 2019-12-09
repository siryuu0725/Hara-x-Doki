#include "Text.h"
#include "Graphics.h"
#include "Texture.h"
#include "Robot.h"
#include "Player.h"
#include "Input.h"
#include "Item.h"
#include "Menu.h"
#include <stdio.h>

#define TEXTBOX_POS_X 0
#define TEXTBOX_POS_Y 680

TextBoxData textbox;
Time time;
extern SearchGameRobotData searchgamerobot;
extern SearchPlayerData searchplayer;
void InitTextBox()
{
	textbox.pos_x = TEXTBOX_POS_X;
	textbox.pos_y = TEXTBOX_POS_Y;
	textbox.onspacekey = false;
}

void DrawTextBox()
{
	// プレイヤーとロボットが当たってスペースを押したらテキストボックス描画
	if (searchgameobject.robot == true && textbox.onspacekey == false)
	{
		textbox.onspacekey = true;
	}
	else if (GetKeyDown(SPACE_KEY) == true && textbox.onspacekey == true)
	{
		textbox.onspacekey = false;
	}
	if (textbox.onspacekey == true)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTextBoxTex));
	}

	if (menu.onenterkey == true)
	{
		DrawTexture(menu.pos_x, menu.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex));

		if (getitem.itemrobot == true)
		{
			DrawTexture(60.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemRobotPartTex));
		}
		if (getitem.itemlight == true)
		{
			//DrawTexture(320.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemRobotPartTex);
		}
		if (getitem.itemkey == true)
		{
			DrawTexture(580.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemKeyTex));
		}
		if (getitem.itemenergy == true)
		{
			DrawTexture(840.0f, 790.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemEnergyTex));
		}

		
	}
}

void InitTimeCounter()
{
	time.timecounter = 0;
	time.onesecondscounter = 0;
	time.tensecondscounter = 0;
	time.oneminutecounter = 5;
	time.tenminutecounter = 0;
}


void DrawTime()
{
	time.timecounter++;
	if (time.timecounter == 60)
	{
		time.onesecondscounter--;
		time.timecounter = 0;
	}
	if (time.onesecondscounter == 0)
	{
		time.onesecondscounter = 10;
		time.tensecondscounter--;
	}
	if (time.tensecondscounter == 0)
	{
		time.tensecondscounter = 10;
		time.oneminutecounter--;
	}
	if (time.oneminutecounter == 0)
	{
		time.oneminutecounter = 0;
	}

	sprintf(time.timefont, "残り時間 %d:%d%d", time.oneminutecounter, time.tensecondscounter, time.onesecondscounter);

	DrawFont(1500, 0, time.timefont, FontSize::Regular, FontColor::Red);
}
