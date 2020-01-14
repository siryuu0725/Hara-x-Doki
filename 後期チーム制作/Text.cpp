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
#include "Bg.h"
#include "JK.h"


TextBoxData textbox;
Time time;
DisplayData displaydata;
ScenarioData scenario;
TextData textdata;
ChoiceTextureData choicetexturedata;

void LoadUI()
{
	LoadTexture("Res/UI/�e�L�X�g���O.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex);
	LoadTexture("Res/UI/�e�L�X�g�{�b�N�X.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex);
	LoadTexture("Res/UI/�A�C�e�����j���[.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/UI/�A�C�e���{�b�N�X.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);
	LoadTexture("Res/UI/���.png", TEXTURE_SEARCH, SearchCategoryTextureList::ChoiceTex);
}

void InitTextBox()
{
	textbox.pos_x = TEXTBOX_POS_X;
	textbox.pos_y = TEXTBOX_POS_Y;
	textbox.onspacekey = false;

	displaydata.choicescenecounter = 0;
	displaydata.name_uicounter = 0;
}

void DrawTextBox()
{
	//// �v���C���[�ƃ��{�b�g���������ăX�y�[�X����������e�L�X�g�{�b�N�X�`��
	//if (searchgameobject.robot == true && textbox.onspacekey == false)
	//{
	//	textbox.onspacekey = true;
	//}
	//else if (GetKeyDown(SPACE_KEY) == true && textbox.onspacekey == true)
	//{
	//	textbox.onspacekey = false;
	//}
	//if (textbox.onspacekey == true)
	//{
	//	DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
	//}
}

void DrawTalkObject(bool* touchobject, bool* tolkobject, char* text)
{
	if (*touchobject == true && *tolkobject == false)
	{
		*tolkobject = true;
		textbox.onspacekey = true;

	}
	else if (GetKeyDown(SPACE_KEY) == true && *tolkobject == true)
	{
		*tolkobject = false;
		
		textbox.onspacekey = false;

	}
	if (*tolkobject == true)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, text, FontSize::Regular, FontColor::White);
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

void InitLoadFile()
{
	textdata.nexttext = false;
	if (moviebgdate.endmovie == true)
	{
		FILE* DescriptionFp;

		fopen_s(&DescriptionFp, "Res/�e�L�X�g/�������.txt", "r");

		fgets(textdata.text, 1000, DescriptionFp);
		fclose(DescriptionFp);
	}
	else if (areadata.searchyuruhuwaarea == true)
	{
		FILE* fp;

		fopen_s(&fp, "Res/�e�L�X�g/���ӂ�V�X�e��.txt", "r");

		fgets(textdata.text, 1000, fp);
		fclose(fp);
	}

	
}

void LoadText()
{

	textdata.oneline = NULL;
	textdata.twoline = NULL;
	textdata.threeline = NULL;
	
	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	if (textdata.nexttext == true)
	{
		textdata.oneline = strtok(NULL,",");
	}
	else
	{
		textdata.oneline = strtok(textdata.text,",");
	}
	
	textdata.twoline = strtok(NULL,",");
	textdata.threeline = strtok(NULL,",");
}

void DrawTalkText()
{
	DrawFont(300.0f, 760.0f, textdata.oneline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 860.0f, textdata.twoline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 960.0f, textdata.threeline, FontSize::Regular, FontColor::White);
}

void UpDataDescriptionText()
{
	
	if (GetKeyDown(SPACE_KEY) == true)
	{
		if ((maidrobot.description == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision = true;
		}
		LoadText();
		textdata.nexttext = true;
		displaydata.choicescenecounter++;
	}
	if (moviebgdate.endmovie == true)
	{
		LoadText();
		moviebgdate.endmovie = false;
		textdata.nexttext = true;

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

void DrawDescription()
{
	
	if (maidrobot.description == false && moviebgdate.endmovie == true)
	{
		maidrobot.description = true;
		textbox.onspacekey = true;
	}
	else if (textdata.threeline == NULL && maidrobot.description == true && moviebgdate.endmovie == false || choicetexturedata.decision == true)
	{
		maidrobot.description = false;
		textbox.onspacekey = false;
	}
 	if (maidrobot.description == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawTalkText();
		if (displaydata.choicescenecounter == 1)
		{
			DrawChoiceTexture();
		}
	}
	
}

void InitChoiceTexture()
{
	choicetexturedata.pos_x = 230.0f;
	choicetexturedata.pos_y = 760.0f;
	choicetexturedata.Choicepos = 1;

	choicetexturedata.decision = false;

}

void DrawChoiceTexture()
{
	if (GetKeyDown(DOWN_KEY) == true && choicetexturedata.Choicepos < 2)
	{
		choicetexturedata.Choicepos++;
	}
	if (GetKeyDown(UP_KEY) == true && choicetexturedata.Choicepos > 1)
	{
		choicetexturedata.Choicepos--;
	}

	if (choicetexturedata.Choicepos == 1)
	{
		DrawTexture(choicetexturedata.pos_x, choicetexturedata.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::ChoiceTex));
	}
	else if (choicetexturedata.Choicepos == 2)
	{
		DrawTexture(choicetexturedata.pos_x, choicetexturedata.pos_y + 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::ChoiceTex));
	}
}
