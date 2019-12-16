#include "Text.h"
#include "Graphics.h"
#include "Texture.h"
#include "Robot.h"
#include "Player.h"
#include "Input.h"
#include "Item.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


TextBoxData textbox;
Time time;
ScenarioData scenario;

void InitTextBox()
{
	textbox.pos_x = TEXTBOX_POS_X;
	textbox.pos_y = TEXTBOX_POS_Y;
	textbox.onspacekey = false;
}

void DrawTextBox()
{
	// �v���C���[�ƃ��{�b�g���������ăX�y�[�X����������e�L�X�g�{�b�N�X�`��
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
		time.oneminutecounter = 9;
		time.tenminutecounter = 0;
		time.end = false;
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
			time.end = true;
		}

		sprintf(time.timefont, "%d:%d%d", time.oneminutecounter, time.tensecondscounter, time.onesecondscounter);

		DrawFont(1780, 0, time.timefont, FontSize::Regular, FontColor::Red);
	}
	
}

void DrawTxt()
{
	FILE* fp;
	char text[256];
	char *oneline;
	char* twoline;
	char *threeline;

	fopen_s(&fp,"Res/test.txt", "r");

	if (fp != NULL)
	{
		while (fgets(text, 256, fp) != NULL)
		{
			
			oneline = strtok(text, ",");
			twoline = strtok(NULL, ",");
			threeline = strtok(NULL, ",");
			
			DrawFont(100.0f, 300.0f, oneline, FontSize::Regular, FontColor::Red);
			DrawFont(100.0f, 400.0f, twoline, FontSize::Regular, FontColor::Red);
			DrawFont(100.0f, 500.0f, threeline, FontSize::Regular, FontColor::Red);
			if (OnMouseDown(Left) == true)
			{

			}
		}
		
		fclose(fp);
	}
}

void InitScenario()
{
	scenario.scenario = true;
}

void DrawScenario()
{
	if (scenario.scenario == true)
	{
		DrawFont(250, 440, "���t�ł���@�@�@�́A�@�@�@�@��", FontSize::Large, FontColor::White);
		DrawFont(600, 440, "��l��", FontSize::Large, FontColor::Aqua);
		DrawFont(950, 440, "���q����", FontSize::Large, FontColor::Pink);
		DrawFont(250, 640, "�s���s���ɂȂ��Ă���\�𕷂����B", FontSize::Large, FontColor::White);
	}

	if (scenario.scenario == true && GetKeyDown(SPACE_KEY) == true)
	{
		scenario.scenario = false;
	}

	if (scenario.scenario == false)
	{
		DrawFont(250, 340, "���`���̋����@�@�@�͌��������Ă���Œ��ɁA", FontSize::Large, FontColor::White);
		DrawFont(670, 340, "��l��", FontSize::Large, FontColor::Aqua);
		DrawFont(530, 540, "���A�ꋎ��������������ڌ��B", FontSize::Large, FontColor::White);
		DrawFont(250, 540, "���q����", FontSize::Large, FontColor::Pink);
		DrawFont(250, 740, "�^����˂��~�߂�ׂ��A���ǂ��������̂������B ", FontSize::Large, FontColor::White);
	}
}
