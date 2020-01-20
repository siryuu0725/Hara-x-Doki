#include "JK.h"
#include "Graphics.h"
#include "Texture.h"
#include "Bg.h"
#include "Robot.h"
#include "Item.h"
#include "Input.h"
#include "Text.h"
#include "Player.h"
#include "Talk.h"


Boyish boyish;
Yuruhuwa yuruhuwa;

void InitBoyish()
{
	if (areadata.searchgamearea == true)
	{
		boyish.pos_x = 1040.0f;
		boyish.pos_y = 180.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talktype = 0;
		boyish.talk = false;

		boyish.clear = false;
		boyish.heart = 0;
	}
	if (areadata.corridor == true /*&& boyish.clear == true*/)
	{
		boyish.pos_x = 1560.0f;
		boyish.pos_y = 450.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
	if (areadata.largeroom == true /*&& boyish.clear == true*/)
	{
		boyish.pos_x = 540.0f;
		boyish.pos_y = 170.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
}

void InitYuruhuwa()
{
	if (areadata.searchyuruhuwaarea == true)
	{
		yuruhuwa.pos_x = 1200.0f;
		yuruhuwa.pos_y = 240.0f;

		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;

		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;

		yuruhuwa.talk = false;
	}
	if (areadata.corridor == true && yuruhuwa.clear == true)
	{
		yuruhuwa.pos_x = 335.0f;
		yuruhuwa.pos_y = 450.0f;

		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
	if (areadata.largeroom == true && yuruhuwa.clear == true)
	{
		yuruhuwa.pos_x = 550.0f;
		yuruhuwa.pos_y = 50.0f;
		
		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
}


void DrawBoyish()
{
	if (areadata.searchgamearea == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.corridor == true && boyish.clear == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.largeroom == true && boyish.clear == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	
}

void DrawYuruhuwa()
{
	if (areadata.searchyuruhuwaarea == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.corridor == true && yuruhuwa.clear == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.largeroom == true && yuruhuwa.clear == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
		//DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}

}


void DrawTalkBoyish()
{
	if ((searchgameobject.boyish == true || corridorobject.boyish == true || largeroomobject.boyish == true) && boyish.talk == false)
	{
		if (searchplayer.animetion_tv == 0.25f)
		{
			boyish.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{

			boyish.tu = 0.33f;
		}
		
		boyish.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && boyish.talk == true)
	{
		boyish.tu = 0.0f;
		boyish.talk = false;
		textbox.onspacekey = false;
		
		textdata.jk_nexttext = false;

		InitJKLoadFile();

		if (boyish.heart <= 2)
		{
			getitem.yuruhuwadoorkey = true;
			getitem.tunderedoorkey = true;
		}
		
		
	}
	if (boyish.talk == true)
	{
		
		if (strstr(textdata.jk_oneline, "たすけて") || strstr(textdata.jk_oneline, "な、ナツナ") || strstr(textdata.jk_oneline, "パーツ？")
			|| strstr(textdata.jk_oneline, "とにかく！") || strstr(textdata.jk_oneline, "助けてってば") || strstr(textdata.jk_oneline, "た、助かった")
			|| strstr(textdata.jk_oneline, "ところで") || strstr(textdata.jk_oneline, "アキラさん") || strstr(textdata.jk_oneline, "そうなんすね")
			|| strstr(textdata.jk_oneline, "本当っすか！？") || strstr(textdata.jk_oneline, " 私さ、") || strstr(textdata.jk_oneline, "そ、そんなこと")
			|| strstr(textdata.jk_twoline, "やったー！") || strstr(textdata.jk_oneline, "それは、そうだけどさ") || strstr(textdata.jk_oneline, "ほかの部屋も")
			|| strstr(textdata.jk_oneline, "ちょっと待ってください！") || strstr(textdata.jk_oneline, "これさっきの") || strstr(textdata.jk_oneline, "電気もあって"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex));

			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "ナツナ", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.jk_oneline, "落ち着いて、") || strstr(textdata.jk_oneline, "もう大丈夫だ")
			|| strstr(textdata.jk_oneline, "無理やり") || strstr(textdata.jk_oneline, "君のこと") || strstr(textdata.jk_oneline, "あぁ。")
			|| strstr(textdata.jk_oneline, "これでナツナ"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		}
		DrawJKTalkText();
		if (strstr(textdata.jk_oneline, "無理やり") || strstr(textdata.jk_oneline, "君のこと") || strstr(textdata.jk_oneline, "あぁ"))
		{
			DrawChoiceTexture();
		}
		
		
		
	}
}

void DrawTalkYuruhuwa()
{
	if (yuruhuwaobject.yuruhuwa == true && yuruhuwa.talk == false)
	{
		if (searchplayer.animetion_tv == 0.25f)
		{
			yuruhuwa.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{
			
			yuruhuwa.tu = 0.33f;
		}
		yuruhuwa.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && yuruhuwa.talk == true)
	{
		yuruhuwa.tu = 0.0f;
		yuruhuwa.talk = false;
		textbox.onspacekey = false;

		textdata.jk_nexttext = false;

		InitJKLoadFile();
	}
	if (yuruhuwa.talk == true)
	{
		DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex));
		//DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex));
		//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		if (strstr(textdata.jk_oneline, "あ、")|| strstr(textdata.jk_oneline, "お友達") || strstr(textdata.jk_oneline, "ハルカ") || strstr(textdata.jk_oneline, "あ、"))
		{
			DrawTexture(350.0f, 0.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "ハルカ", FontSize::Regular, FontColor::Yellow);
		}
		if (strstr(textdata.jk_oneline, "おぉ、") || strstr(textdata.jk_oneline, "これは"))
		{
			DrawTexture(800.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot_NoNeckTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "執事", FontSize::Regular, FontColor::Yellow);
		}
		if (strstr(textdata.jk_oneline, "どうやら") || strstr(textdata.jk_oneline, "俺は") || strstr(textdata.jk_oneline, "・・・"))
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
		}
		

		DrawJKTalkText();
	}
}


void UpDataBoyishTalk()
{
	if (searchgameobject.boyish == true || corridorobject.boyish == true || largeroomobject.boyish == true)
	{
		if (searchgameobject.completerobot == true && boyish.talktype == 1)
		{
			InitJKLoadFile();
		}
		if ((boyish.talk == true && choicetexturedata.Choicepos == 1))
		{
			choicetexturedata.decision_1 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;
		}
		else if ((boyish.talk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;

		}

		JKLoadText();
		
		textdata.jk_nexttext = true;
	}
}

void UpDataYuruhuwaTalk()
{
	if (GetKeyDown(SPACE_KEY) == true && yuruhuwaobject.yuruhuwa == true)
	{
		JKLoadText();
		textdata.jk_nexttext = true;

	}
}


void DrawTalkClearBoyish()
{
	if (areadata.cleararea == true && boyish.clear == true && boyish.heart == 3 && boyish.talk == false)
	{
		boyish.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && boyish.talk == true)
	{
		boyish.talk = false;
		textbox.onspacekey = false;
		boyish.end = true;
		
	}
	if (boyish.talk == true)
	{
		if (displaydata.display_cleartext == true)
		{
			if (strstr(textdata.jk_oneline, "アキラさん") || strstr(textdata.jk_oneline, "あの時") || strstr(textdata.jk_oneline, "それだけ")
				|| strstr(textdata.jk_oneline, "ありがとう"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex));

				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "ナツナ", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.jk_oneline, "もう卒業") || strstr(textdata.jk_oneline, "――"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextnameTex));
				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
			}
			
		}
		
		DrawJKTalkText();
	}
}

void UpDataClearText()
{

	if (GetKeyDown(SPACE_KEY) == true)
	{

		if (strstr(textdata.jk_oneline, "夏。"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		JKLoadText();

	}
}