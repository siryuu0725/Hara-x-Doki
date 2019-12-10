#include "Text.h"
#include "Graphics.h"
#include "Texture.h"
#include "Robot.h"
#include "Player.h"
#include "Input.h"
#include "Item.h"
#include "Menu.h"
#include <stdio.h>
#include<stdlib.h>



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
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
	}
}

void InitTimeCounter()
{
	if (time.start == false)
	{
		time.timecounter = 0;
		time.onesecondscounter = 0;
		time.tensecondscounter = 0;
		time.oneminutecounter = 5;
		time.tenminutecounter = 0;
	}
	
}


void DrawTime()
{
	if (time.start == true)
	{
		time.timecounter++;
		if (time.timecounter == 60)
		{
			time.onesecondscounter--;
			time.timecounter = 0;
		}
		if (time.onesecondscounter == -1)
		{
			time.onesecondscounter = 9;
			time.tensecondscounter--;
		}
		if (time.tensecondscounter == -1)
		{
			time.tensecondscounter = 5;
			time.oneminutecounter--;
		}
		if (time.oneminutecounter == -1)
		{
			time.oneminutecounter = 0;
		}

		sprintf(time.timefont, "残り時間 %d:%d%d", time.oneminutecounter, time.tensecondscounter, time.onesecondscounter);

		DrawFont(1500, 0, time.timefont, FontSize::Regular, FontColor::Red);
	}
	
}

void DrawTxt()
{
	FILE* fp;
	char mozi[256];

	fopen_s(&fp,"Res/test.txt", "r");

	if (fp != NULL)
	{
		while (fgets(mozi, 256, fp) != NULL)
		{
			
			if (mozi[256] != '\n')
			{
				DrawFont(100.0f, 500.0f, mozi, FontSize::Regular, FontColor::Red);
			}
		}
		fclose(fp);
	}
}
