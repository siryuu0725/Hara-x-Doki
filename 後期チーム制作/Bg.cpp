#include "Bg.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"


MovieBgDate bgdate;

int f;
void InitBg()
{
	bgdate.Tu = 0.3f;
	bgdate.Tv = 0.4f;
	bgdate.moveflg = false;
	bgdate.movespeed = 0.001f;
	f = 0;
}

void DrawBg()
{
	DrawUVTexture(0.0f, 0.0f, GetTexture(TEXTURE_MOVIE, MovieCategoryTextureList::MovieBgTex), 1920, 1378, bgdate.Tu, bgdate.Tv);
}

void DrawTalkBg()
{
	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkBg));
}

void DrawSearchBg()
{
	DrawBgTexture(GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex));
}

//背景移動
void UpDateBg()
{
	if (movieplayer.Bg_pos == true)//プレイヤーが特定の位置に来た時
	{

		if (bgdate.Tv <= 0.0f)//プレイヤーは動かず背景だけ移動
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
			f++;
			if (f == 120)
			{
				bgdate.movespeed = -0.001f;
				movieplayer.movespeed = -2.8f;
			}

		}
		bgdate.Tv -= bgdate.movespeed;
		movieplayer.pos_y += movieplayer.movespeed;

		if (bgdate.Tv >= 0.4)//元の画面に戻った時
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
			movieplayer.move_animesion = false;
		}
	}
	
}
