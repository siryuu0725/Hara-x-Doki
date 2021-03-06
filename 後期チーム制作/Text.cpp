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

//UIファイル読み込み
void LoadUI()
{
	LoadTexture("Res/UI/テキスト名前.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex);
	LoadTexture("Res/UI/テキストボックス.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex);
	LoadTexture("Res/UI/アイテムメニュー.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemMenuTex);
	LoadTexture("Res/UI/アイテムボックス.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemBoxTex);
	LoadTexture("Res/UI/矢印.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::ChoiceTex);
}

//テキストボックス初期化
void InitTextBox()
{
	textbox.pos_x = TEXTBOX_POS_X;
	textbox.pos_y = TEXTBOX_POS_Y;
	textbox.onspacekey = false;

	
	displaydata.displaynext = false;
}

//タイマー初期化
void InitTimeCounter()
{
	if (time.start == false)
	{
		time.timecounter = 0;         
		time.onesecondscounter = 0;   
		time.tensecondscounter = 0;	  
		time.oneminutecounter = 10;	  
		time.tenminutecounter = 0;	  
		time.end = false;
	}
	
}

//タイマー描画
void DrawTime()
{
	if (time.start == true)
	{
		if (textbox.onspacekey == false)
		{
			time.timecounter++;
		}
		if (time.timecounter == 60)
		{
			time.onesecondscounter--;
			time.timecounter = 0;
		}
		if (time.onesecondscounter == -1)
		{
			time.onesecondscounter = 9;//タイマー設定
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

//選択時tex初期化
void InitChoiceTexture()
{
	choicetexturedata.pos_x = 230.0f;
	choicetexturedata.pos_y = 760.0f;
	choicetexturedata.Choicepos = 0;
	choicetexturedata.display = 0;
	choicetexturedata.decision_1 = false;
	choicetexturedata.decision_2 = false;

}

//選択時tex描画
void DrawChoiceTexture()
{
	
	choicetexturedata.display++;

	if (choicetexturedata.display == 1)
	{
		choicetexturedata.Choicepos = 1;
		choicetexturedata.display = 2;
	}
	
	if (GetKeyDown(UP_KEY) == true)
	{
		choicetexturedata.Choicepos = 1;
	}
	else if (GetKeyDown(DOWN_KEY) == true)
	{
		choicetexturedata.Choicepos = 2;
	}
	
	if (choicetexturedata.Choicepos == 1)
	{
		DrawTexture(choicetexturedata.pos_x, choicetexturedata.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::ChoiceTex));
	}
	else if (choicetexturedata.Choicepos == 2)
	{
		DrawTexture(choicetexturedata.pos_x, choicetexturedata.pos_y + 100.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::ChoiceTex));
	}
}
