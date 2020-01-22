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
#include "Puzzle.h"


Boyish boyish;
Yuruhuwa yuruhuwa;

//キャラテクスチャ読み込み
void LoadCharacter()
{
	LoadTexture("Res/キャラ/主人公統合ファイル.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchPlayerTex);

	LoadTexture("Res/キャラ/メイド_立ち絵.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomTalkMaidTex);
	LoadTexture("Res/キャラ/メイド_ちび.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomMaidRobotTex);

	LoadTexture("Res/キャラ/ボーイッシュちび.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);
	LoadTexture("Res/キャラ/ボーイッシュ立ち絵.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex);

	LoadTexture("Res/キャラ/ちびロボパーツ.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex);
	LoadTexture("Res/キャラ/ちび執事(カオナシ).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);
	LoadTexture("Res/キャラ/ちび執事.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameCompleteRobotTex);
	LoadTexture("Res/キャラ/ちび執事.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex);
	LoadTexture("Res/キャラ/立ち絵執事かおなし.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot_NoNeckTex);
	LoadTexture("Res/キャラ/立ち絵執事.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot);
}

#pragma region Jk初期化
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

		boyish.talk = false;

		if (boyish.clear == false)
		{
			boyish.talktype = 0;
			boyish.clear = false;
			boyish.heart = 0;
		}
	}
	if (areadata.corridor == true && boyish.unlock == true)
	{
		boyish.pos_x = 1560.0f;
		boyish.pos_y = 450.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
	if (areadata.largeroom == true && boyish.unlock == true)
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

		if (yuruhuwa.clear == false)
		{
			yuruhuwa.talktype = 0;
			
			yuruhuwa.clear = false;
			yuruhuwa.heart = 0;
		}
		
	}
	if (areadata.corridor == true && yuruhuwa.unlock == true)
	{
		yuruhuwa.pos_x = 350.0f;
		yuruhuwa.pos_y = 450.0f;

		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
	if (areadata.largeroom == true && yuruhuwa.unlock == true)
	{
		yuruhuwa.pos_x = 1395.0f;
		yuruhuwa.pos_y = 250.0f;
		
		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
}

#pragma endregion

#pragma region Jk描画
void DrawBoyish()
{
	if (areadata.searchgamearea == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.corridor == true && boyish.unlock == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.largeroom == true && boyish.unlock == true)
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
	if (areadata.corridor == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.largeroom == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
		
	}

}

#pragma endregion

#pragma region Jk会話
void DrawTalkBoyish()
{
	if ((searchgameobject.boyish == true || corridorobject.boyish == true || largeroomobject.boyish == true) && boyish.talk == false)
	{
		if (boyish.clear == true)
		{
			boyish.unlock = true;
		}

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
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "ナツナ", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.jk_oneline, "落ち着いて、") || strstr(textdata.jk_oneline, "もう大丈夫だ")
			|| strstr(textdata.jk_oneline, "無理やり") || strstr(textdata.jk_oneline, "君のこと") || strstr(textdata.jk_oneline, "あぁ。")
			|| strstr(textdata.jk_oneline, "これでナツナ"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
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
	if ((yuruhuwaobject.yuruhuwa == true || corridorobject.yuruhuwa == true || largeroomobject.yuruhuwa == true) && yuruhuwa.talk == false)
	{
		if (yuruhuwa.clear == true)
		{
			yuruhuwa.unlock = true;
		}

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
		choicetexturedata.decision_2 = false;
		textdata.jk_nexttext = false;

		if (puzzle.goal_key == true)
		{
			yuruhuwa.talktype = 2;

		}
 		InitJKLoadFile();

	}
	if (yuruhuwa.talk == true)
	{

		if (strstr(textdata.jk_oneline, "あ、こんにちは") || strstr(textdata.jk_oneline, "お友達さん") || strstr(textdata.jk_oneline, "ハルカです")
			|| strstr(textdata.jk_oneline, "シツジさん") || strstr(textdata.jk_oneline, "わぁ") || strstr(textdata.jk_oneline, "ありがとうございます")
			|| strstr(textdata.jk_oneline, "お友達なら") || strstr(textdata.jk_oneline, "あら？") || strstr(textdata.jk_oneline, "私がおっとり") 
			|| strstr(textdata.jk_oneline, "ふふ、") || strstr(textdata.jk_oneline, "うぅ、")|| strstr(textdata.jk_oneline, "それじゃあ")
			|| strstr(textdata.jk_oneline, "わかりました")|| strstr(textdata.jk_oneline, "たしかに") || strstr(textdata.jk_oneline, "それでは") 
			|| strstr(textdata.jk_oneline, "アキラさんは")|| strstr(textdata.jk_oneline, "はい。") || strstr(textdata.jk_oneline, "それにしても") 
			|| strstr(textdata.jk_oneline, "私はここで") || strstr(textdata.jk_oneline, "他の部屋"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "ハルカ", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.jk_oneline, "俺はアキラ") || strstr(textdata.jk_oneline, "・・・・・")
			|| strstr(textdata.jk_oneline, "あぁ。") || strstr(textdata.jk_oneline, "お友達じゃない") || strstr(textdata.jk_oneline, "大丈夫")
			|| strstr(textdata.jk_oneline, "何か") || strstr(textdata.jk_oneline, "もう足") || strstr(textdata.jk_oneline, "何か"))
		{
			
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.jk_oneline, "おぉ、") || strstr(textdata.jk_oneline, "これは"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "執事", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		}
		DrawJKTalkText();
		if (strstr(textdata.jk_oneline, "大丈夫") || strstr(textdata.jk_oneline, "何か") || strstr(textdata.jk_oneline, "もう足"))
		{
			DrawChoiceTexture();
		}
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
	if (yuruhuwaobject.yuruhuwa == true || corridorobject.yuruhuwa == true || largeroomobject.yuruhuwa == true)
	{
		if (puzzle.goal_key == true && yuruhuwa.talktype == 1)
		{
			InitJKLoadFile();
		}
		if ((yuruhuwa.talk == true && choicetexturedata.Choicepos == 1))
		{
			choicetexturedata.decision_1 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;
		}
		else if ((yuruhuwa.talk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;

		}

  		JKLoadText();

		textdata.jk_nexttext = true;
	}
}


void DrawTalkClearBoyish()
{
	if (areadata.cleararea == true && boyish.clear == true && boyish.talk == false)
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
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "ナツナ", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.jk_oneline, "もう卒業") || strstr(textdata.jk_oneline, "――"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
			}
			
		}
		
		DrawJKTalkText();
	}
}

void DrawTalkClearYuruhuwa()
{
	if (areadata.cleararea == true && yuruhuwa.clear == true && yuruhuwa.talk == false)
	{
		yuruhuwa.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && yuruhuwa.talk == true)
	{
		yuruhuwa.talk = false;
		textbox.onspacekey = false;
		yuruhuwa.end = true;

	}
	if (yuruhuwa.talk == true)
	{
		if (displaydata.display_cleartext == true)
		{
			if (strstr(textdata.jk_oneline, "わぁ！") || strstr(textdata.jk_oneline, "ふふふ") || strstr(textdata.jk_oneline, "またアキラ"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "ハルカ", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.jk_oneline, "結婚指輪"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
			}

		}

		DrawJKTalkText();
	}
}


#pragma endregion
void UpDataClearText()
{

	if (GetKeyDown(SPACE_KEY) == true && boyish.clear == true)
	{
		
		if (strstr(textdata.jk_oneline, "夏。"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		JKLoadText();

	}
	else if (GetKeyDown(SPACE_KEY) == true && yuruhuwa.clear == true)
	{

		if (strstr(textdata.jk_oneline, "春。"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		JKLoadText();

	}
}