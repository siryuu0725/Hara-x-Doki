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

Tundere tundere;
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

	LoadTexture("Res/キャラ/ツンデレ立ち絵.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTalkTex);
	LoadTexture("Res/キャラ/ツンデレちび.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex);

	LoadTexture("Res/キャラ/ゆるふわ立ち絵.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex);
	LoadTexture("Res/キャラ/ゆるふわちび.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex);

	LoadTexture("Res/キャラ/ちびロボパーツ.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex);
	LoadTexture("Res/キャラ/ちび執事(カオナシ).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);
	LoadTexture("Res/キャラ/ちび執事.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameCompleteRobotTex);
	LoadTexture("Res/キャラ/ちび執事.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex);
	LoadTexture("Res/キャラ/ちび執事.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRobotTex);
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

void InitTundere()
{
	if (areadata.searchtunderearea == true)
	{
		tundere.pos_x = 1200.0f;
		tundere.pos_y = 240.0f;
		tundere.tu = 0.0f;
		tundere.tv = 0.0f;
		tundere.width = 64.0f;
		tundere.height = 128.0f;
		tundere.talk = false;

		if (tundere.clear == false)
		{
			tundere.talktype = 0;

			tundere.clear = false;
			tundere.heart = 0;
		}

	}
	if (areadata.corridor == true && tundere.unlock == true)
	{
		tundere.pos_x = 965.0f;
		tundere.pos_y = 450.0f;
		tundere.tu = 0.0f;
		tundere.tv = 0.0f;
		tundere.width = 64.0f;
		tundere.height = 128.0f;
		tundere.talk = false;
	}
	if (areadata.largeroom == true && tundere.unlock == true)
	{
		tundere.pos_x = 740.0f;
		tundere.pos_y = 690.0f;
		tundere.tu = 0.0f;
		tundere.tv = 0.0f;
		tundere.width = 64.0f;
		tundere.height = 128.0f;
		tundere.talk = false;
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
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.corridor == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.largeroom == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
		
	}

}

void DrawTundere()
{
	if (areadata.searchtunderearea == true)
	{
		DrawUVTexture(tundere.pos_x, tundere.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex), tundere.width, tundere.height, tundere.tu, tundere.tv);
	}
	if (areadata.corridor == true && tundere.unlock == true)
	{
		DrawUVTexture(tundere.pos_x, tundere.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex), tundere.width, tundere.height, tundere.tu, tundere.tv);
	}
	if (areadata.largeroom == true && tundere.unlock == true)
	{
		DrawUVTexture(tundere.pos_x, tundere.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex), tundere.width, tundere.height, tundere.tu, tundere.tv);
	}

}
#pragma endregion

#pragma region Jk会話
void DrawTalkBoyish()
{
	//各部屋でボーイッシュに話しかけたとき
	if ((searchgameobject.boyish == true || corridorobject.boyish == true || largeroomobject.boyish == true) && boyish.talk == false)
	{
		if (boyish.clear == true)
		{
			boyish.unlock = true;
		}
		//プレイヤーが向いている方向に向く
		if (searchplayer.animetion_tv == 0.25f)
		{
			boyish.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{

			boyish.tu = 0.33f;
		}

		boyish.talk = true;
		textbox.onspacekey = true; //プレイヤーを止めておくフラグ
	}
	//txtがNULLのとき
	else if (textdata.boyish_threeline == NULL && boyish.talk == true)
	{
		boyish.tu = 0.0f;
		boyish.talk = false;
		textbox.onspacekey = false;
		
		textdata.jk_nexttext = false;

		InitJKLoadFile();
		//好感度システム
		if (boyish.heart == 3)
		{
			getitem.tunderedoorkey = false;
			getitem.yuruhuwadoorkey = false;
		}
		else if (boyish.heart <= 2)
		{
			getitem.tunderedoorkey = true;
			getitem.yuruhuwadoorkey = true;
		}
	
	}
	if (boyish.talk == true)
	{
		//txtに指定した文字列があった場合
		if (strstr(textdata.boyish_oneline, "たすけて") || strstr(textdata.boyish_oneline, "な、ナツナ") || strstr(textdata.boyish_oneline, "パーツ？")
			|| strstr(textdata.boyish_oneline, "とにかく！") || strstr(textdata.boyish_oneline, "助けてってば") || strstr(textdata.boyish_oneline, "た、助かった")
			|| strstr(textdata.boyish_oneline, "ところで") || strstr(textdata.boyish_oneline, "アキラさん") || strstr(textdata.boyish_oneline, "そうなんすね")
			|| strstr(textdata.boyish_oneline, "本当っすか！？") || strstr(textdata.boyish_oneline, " 私さ、") || strstr(textdata.boyish_oneline, "そ、そんなこと")
			|| strstr(textdata.boyish_twoline, "やったー！") || strstr(textdata.boyish_oneline, "それは、そうだけどさ") || strstr(textdata.boyish_oneline, "ほかの部屋も")
			|| strstr(textdata.boyish_oneline, "ちょっと待ってください！") || strstr(textdata.boyish_oneline, "扉の鍵") || strstr(textdata.boyish_oneline, "電気もあって"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(600.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "ナツナ", FontSize::Regular, FontColor::Yellow);
		}
		//txtに指定した文字列があった場合
		else if (strstr(textdata.boyish_oneline, "落ち着いて、") || strstr(textdata.boyish_oneline, "もう大丈夫だ")
			|| strstr(textdata.boyish_oneline, "無理やり") || strstr(textdata.boyish_oneline, "君のこと") || strstr(textdata.boyish_oneline, "あぁ。")
			|| strstr(textdata.boyish_oneline, "これでナツナ"))
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
		if (strstr(textdata.boyish_oneline, "無理やり") || strstr(textdata.boyish_oneline, "君のこと") || strstr(textdata.boyish_oneline, "あぁ"))
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
	else if (textdata.yuruhuwa_threeline == NULL && yuruhuwa.talk == true)
	{
		yuruhuwa.tu = 0.0f;
		yuruhuwa.talk = false;
		textbox.onspacekey = false;
		choicetexturedata.decision_2 = false;
		textdata.jk_nexttext = false;

		if (yuruhuwa.clear == true)
		{
			yuruhuwa.talktype = 2;

		}
 		InitJKLoadFile();

		if (yuruhuwa.heart == 3)
		{
			getitem.tunderedoorkey = false;
			getitem.boyishdoorkey = false;
		}
		else if (yuruhuwa.heart <= 2)
		{
			getitem.tunderedoorkey = true;
			getitem.boyishdoorkey = true;
		}
	}
	if (yuruhuwa.talk == true)
	{

		if (strstr(textdata.yuruhuwa_oneline, "あ、こんにちは") || strstr(textdata.yuruhuwa_oneline, "お友達さん") || strstr(textdata.yuruhuwa_oneline, "ハルカです")
			|| strstr(textdata.yuruhuwa_oneline, "シツジさん") || strstr(textdata.yuruhuwa_oneline, "わぁ") || strstr(textdata.yuruhuwa_oneline, "ありがとうございます")
			|| strstr(textdata.yuruhuwa_oneline, "お友達なら") || strstr(textdata.yuruhuwa_oneline, "あら？") || strstr(textdata.yuruhuwa_oneline, "私がおっとり")
			|| strstr(textdata.yuruhuwa_oneline, "ふふ、") || strstr(textdata.yuruhuwa_oneline, "うぅ、")|| strstr(textdata.yuruhuwa_oneline, "それじゃあ")
			|| strstr(textdata.yuruhuwa_oneline, "わかりました")|| strstr(textdata.yuruhuwa_oneline, "たしかに") || strstr(textdata.yuruhuwa_oneline, "それでは")
			|| strstr(textdata.yuruhuwa_oneline, "アキラさんは")|| strstr(textdata.yuruhuwa_oneline, "はい。") || strstr(textdata.yuruhuwa_oneline, "それにしても")
			|| strstr(textdata.yuruhuwa_oneline, "私はここで") || strstr(textdata.yuruhuwa_oneline, "ちょっと待ってください！") || strstr(textdata.yuruhuwa_oneline, "鍵は"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(350.0f, -50.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "ハルカ", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.yuruhuwa_oneline, "俺はアキラ") || strstr(textdata.yuruhuwa_oneline, "・・・・・")
			|| strstr(textdata.yuruhuwa_oneline, "あぁ。") || strstr(textdata.yuruhuwa_oneline, "お友達じゃない") || strstr(textdata.yuruhuwa_oneline, "大丈夫")
			|| strstr(textdata.yuruhuwa_oneline, "何か") || strstr(textdata.yuruhuwa_oneline, "もう足") || strstr(textdata.yuruhuwa_oneline, "何か"))
		{
			
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.yuruhuwa_oneline, "おぉ、") || strstr(textdata.yuruhuwa_oneline, "これは"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(400.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "執事ロボ", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		}
		DrawJKTalkText();
		if (strstr(textdata.yuruhuwa_oneline, "大丈夫") || strstr(textdata.yuruhuwa_oneline, "何か") || strstr(textdata.yuruhuwa_oneline, "もう足"))
		{
			DrawChoiceTexture();
		}
	}
}

void DrawTalkTundere()
{
	if ((tundereobject.tundere == true || corridorobject.tundere == true || largeroomobject.tundere == true) && tundere.talk == false)
	{
		if (tundere.clear == true)
		{
			tundere.unlock = true;
		}

		if (searchplayer.animetion_tv == 0.25f)
		{
			tundere.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{

			tundere.tu = 0.33f;
		}

		tundere.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.tundere_threeline == NULL && tundere.talk == true)
	{
		tundere.tu = 0.0f;
		tundere.talk = false;
		textbox.onspacekey = false;
		choicetexturedata.decision_2 = false;
		textdata.jk_nexttext = false;

		
		InitJKLoadFile();

		if (tundere.heart == 3)
		{
			getitem.yuruhuwadoorkey = false;
			getitem.boyishdoorkey = false;
		}
		else if (tundere.heart <= 2)
		{
			getitem.yuruhuwadoorkey = true;
			getitem.boyishdoorkey = true;
		}
	}
	if (tundere.talk == true)
	{

		if (strstr(textdata.tundere_oneline, "ちょっと") || strstr(textdata.tundere_oneline, "信じられる") || strstr(textdata.tundere_oneline, "‥‥‥何よ")
			|| strstr(textdata.tundere_oneline, "それ！") || strstr(textdata.tundere_oneline, "別に‥") || strstr(textdata.tundere_oneline, "本当に")
			|| strstr(textdata.tundere_oneline, "な、なによ") || strstr(textdata.tundere_oneline, "逆に怪しい") || strstr(textdata.tundere_oneline, "それにし")
			|| strstr(textdata.tundere_oneline, "う、うるさ") || strstr(textdata.tundere_oneline, "なんであんた") || strstr(textdata.tundere_oneline, "ね、ねぇ、")
			|| strstr(textdata.tundere_oneline, "と、当然ね！") || strstr(textdata.tundere_oneline, "信用して") || strstr(textdata.tundere_oneline, "はぁー、")
			|| strstr(textdata.tundere_oneline, "って、") || strstr(textdata.tundere_oneline, "なんでこ") || strstr(textdata.tundere_oneline, "ちょっと待って！")
			|| strstr(textdata.tundere_oneline, "普通の家"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(350.0f, -50.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTalkTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "マシロ", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.tundere_oneline, "落ち着け！") || strstr(textdata.tundere_oneline, "そうだ")
			|| strstr(textdata.tundere_oneline, "大丈夫か？") || strstr(textdata.tundere_oneline, "それでも") || strstr(textdata.tundere_oneline, "君の方")
			|| strstr(textdata.tundere_oneline, "あぁ、"))
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
		if (strstr(textdata.tundere_oneline, "それでも") || strstr(textdata.tundere_oneline, "君の方が") || strstr(textdata.tundere_oneline, "あぁ、"))
		{
			DrawChoiceTexture();
		}
	}
}


//次の会話へ行く関数
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

		BoyishLoadText();
		
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

  		YuruhuwaLoadText();

		textdata.jk_nexttext = true;
	}
}

void UpDataTundereTalk()
{
	if (tundereobject.tundere == true || corridorobject.tundere == true || largeroomobject.tundere == true)
	{
		if (tundere.clear == false && tundere.talktype == 1)
		{
			InitJKLoadFile();
		}
		if ((tundere.talk == true && choicetexturedata.Choicepos == 1))
		{
			choicetexturedata.decision_1 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;
		}
		else if ((tundere.talk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;

		}

		TundereLoadText();

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
	else if (textdata.boyish_threeline == NULL && boyish.talk == true)
	{
		boyish.talk = false;
		textbox.onspacekey = false;
		boyish.end = true;
		
	}
	if (boyish.talk == true)
	{
		if (displaydata.display_cleartext == true)
		{
			if (strstr(textdata.boyish_oneline, "アキラさん") || strstr(textdata.boyish_oneline, "あの時") || strstr(textdata.boyish_oneline, "それだけ")
				|| strstr(textdata.boyish_oneline, "ありがとう"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "ナツナ", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.boyish_oneline, "もう卒業") || strstr(textdata.boyish_oneline, "――"))
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
	if (yuruhuwa.heart == 3)
	{
		if (areadata.cleararea == true && yuruhuwa.clear == true && yuruhuwa.talk == false)
		{
			yuruhuwa.talk = true;
			textbox.onspacekey = true;
		}
		else if (textdata.yuruhuwa_threeline == NULL && yuruhuwa.talk == true)
		{
			yuruhuwa.talk = false;
			textbox.onspacekey = false;
			yuruhuwa.end = true;

		}
		if (yuruhuwa.talk == true)
		{
			if (displaydata.display_cleartext == true)
			{
				if (strstr(textdata.yuruhuwa_oneline, "わぁ！") || strstr(textdata.yuruhuwa_oneline, "ふふふ") || strstr(textdata.yuruhuwa_oneline, "またアキラ"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

					//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
					DrawFont(100, 610, "ハルカ", FontSize::Regular, FontColor::Yellow);
				}
				else if (strstr(textdata.yuruhuwa_oneline, "結婚指輪"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
					//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
					DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
				}

			}

			DrawJKTalkText();
		}
	}
	
}

void DrawTalkClearTundere()
{
	if (tundere.heart == 3)
	{
		if (areadata.cleararea == true && tundere.clear == true && tundere.talk == false)
		{
			tundere.talk = true;
			textbox.onspacekey = true;
		}
		else if (textdata.tundere_threeline == NULL && tundere.talk == true)
		{
			tundere.talk = false;
			textbox.onspacekey = false;
			tundere.end = true;

		}
		if (tundere.talk == true)
		{
			if (displaydata.display_cleartext == true)
			{
				if (strstr(textdata.tundere_oneline, "な、なによ") || strstr(textdata.tundere_oneline, "はぁ！？") || strstr(textdata.tundere_oneline, "そもそも")
					|| strstr(textdata.tundere_oneline, "だから"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

					DrawFont(100, 610, "マシロ", FontSize::Regular, FontColor::Yellow);
				}
				else if (strstr(textdata.tundere_oneline, "君の好きな") || strstr(textdata.tundere_oneline, "今、なんて"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
					//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
					DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
				}

			}

			DrawJKTalkText();
		}
	}
}

#pragma endregion
void UpDataClearText()
{

	if (GetKeyDown(SPACE_KEY) == true && boyish.clear == true)
	{
		
		if (strstr(textdata.boyish_oneline, "夏。"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		BoyishLoadText();

	}
	else if (GetKeyDown(SPACE_KEY) == true && yuruhuwa.clear == true)
	{

		if (strstr(textdata.boyish_oneline, "春。"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		BoyishLoadText();

	}
	else if (GetKeyDown(SPACE_KEY) == true && tundere.clear == true)
	{

		if (strstr(textdata.boyish_oneline, "冬。"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		BoyishLoadText();

	}
}