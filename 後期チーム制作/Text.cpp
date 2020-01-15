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
#include "Talk.h"


TextBoxData textbox;
Time time;
DisplayData displaydata;
ScenarioData scenario;
TextData textdata;
ChoiceTextureData choicetexturedata;

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

	displaydata.name_uicounter = 0;
	displaydata.displaynext = false;
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
