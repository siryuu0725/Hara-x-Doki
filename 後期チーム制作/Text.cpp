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


TextBoxData textbox;
Time time;
DisplayTimeData displaytimedata;
ScenarioData scenario;
TextData textdata;
ChoiceTextureData choicetexturedata;
FILE* fp;

void LoadUI()
{
	LoadTexture("Res/UI/テキスト名前.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex);
	LoadTexture("Res/UI/テキストボックス.png", TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex);
	LoadTexture("Res/UI/アイテムメニュー.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/UI/アイテムボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);
	LoadTexture("Res/UI/矢印.png", TEXTURE_SEARCH, SearchCategoryTextureList::ChoiceTex);
}

void InitTextBox()
{
	textbox.pos_x = TEXTBOX_POS_X;
	textbox.pos_y = TEXTBOX_POS_Y;
	textbox.onspacekey = false;
}

void DrawTextBox()
{
	//// プレイヤーとロボットが当たってスペースを押したらテキストボックス描画
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

//void InitLoadFile(char* file)
//{
//	textdata.nexttext = false;
//	if (areadata.searchgamearea == true)
//	{
//		fopen_s(&fp, file, "r");
//	}
//	fopen_s(&fp, file, "r");
//	fgets(textdata.text, 256, fp);	
//}

void InitLoadFile2()
{
	textdata.nexttext = false;
	fopen_s(&fp, "text.txt","r");
	fgets(textdata.text, 256, fp);
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

	if (textdata.text == strtok(NULL, "!"))
	{
		fp == NULL;
		fclose(fp);
	}
}

void DrawTalkText()
{
	DrawFont(100.0f, 300.0f, textdata.oneline, FontSize::Regular, FontColor::Red);
	DrawFont(100.0f, 400.0f, textdata.twoline, FontSize::Regular, FontColor::Red);
	DrawFont(100.0f, 500.0f, textdata.threeline, FontSize::Regular, FontColor::Red);
}

void UpDataText()
{
	if (GetKeyDown(SPACE_KEY) == true)
	{
		if ((maidrobot.description == true && choicetexturedata.Choicepos == 2))
		{
			maidrobot.description = false;
		}
		else
		{
			LoadText();
			textdata.nexttext = true;
		}
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
		DrawFont(250, 440, "教師である　　　は、　　　　が", FontSize::Large, FontColor::White);
		DrawFont(600, 440, "主人公", FontSize::Large, FontColor::Aqua);
		DrawFont(950, 440, "女子高生", FontSize::Large, FontColor::Pink);
		DrawFont(250, 640, "行方不明になっている噂を聞いた。", FontSize::Large, FontColor::White);
	}

	if (scenario.scenario == true && GetKeyDown(SPACE_KEY) == true)
	{
		scenario.scenario = false;
	}

	if (scenario.scenario == false)
	{
		DrawFont(250, 340, "正義感の強い　　　は見回りをしている最中に、", FontSize::Large, FontColor::White);
		DrawFont(670, 340, "主人公", FontSize::Large, FontColor::Aqua);
		DrawFont(530, 540, "が連れ去られる怪しい現場を目撃。", FontSize::Large, FontColor::White);
		DrawFont(250, 540, "女子高生", FontSize::Large, FontColor::Pink);
		DrawFont(250, 740, "真相を突き止めるべく、後を追いかけたのだった。 ", FontSize::Large, FontColor::White);
	}
}

void DrawDescription()
{
	bool descriptionflg;
	if (moviebgdate.endmovie == true)
	{
		for (int i=0; i <= 60; i++)
		{
			displaytimedata.displaytimecounter++;
		}
		if (displaytimedata.displaytimecounter==60)
		{
			maidrobot.description = true;
			textbox.onspacekey = true;
		}
		else if (maidrobot.description == false)
		{
			textbox.onspacekey = false;
		}
		if (maidrobot.description == true && descriptionflg == true)
		{
			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
			DrawTalkText();
			DrawChoiceTexture();
		}
	}

}

void InitChoiceTexture()
{
	choicetexturedata.pos_x = 300.0f;
	choicetexturedata.pos_y = 760.0f;
	choicetexturedata.Choicepos = 1;

	choicetexturedata.decision = false;

}

void DrawChoiceTexture()
{
	if (GetKeyDown(DOWN_KEY) == true && choicetexturedata.Choicepos < 3)
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
	else if (choicetexturedata.Choicepos == 3)
	{
		DrawTexture(choicetexturedata.pos_x, choicetexturedata.pos_y + 200.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::ChoiceTex));
	}
}
