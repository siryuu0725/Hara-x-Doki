#include "Bg.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"

#define MOVIETEX_TU 0.0f
#define MOVITEXE_TV 0.5f
#define MOVIE_SPEED 0.001f
#define MOVIE_STOP_TIME 120

MovieBgDate bgdate;

void InitBg()
{
	bgdate.Tu = MOVIETEX_TU;
	bgdate.Tv = MOVITEXE_TV;
	bgdate.movespeed = MOVIE_SPEED;
	bgdate.stopcount = 0;
}

void DrawBg()
{
	DrawUVTexture(0.0f, 0.0f, GetTexture(TEXTURE_MOVIE, MovieCategoryTextureList::MovieBgTex), 1920, 2500, bgdate.Tu, bgdate.Tv);
}

void DrawTalkBg()
{
	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkBgTex));
}

void DrawSearchBg()
{
	DrawBgTexture(GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex));
}


void DrawSearch2Bg()
{
	DrawBgTexture(GetTexture(TEXTURE_SEARCH2, Search2CategoryTextureList::Search2BgTex));

}

void DrawSearchGameBg()
{
	DrawBgTexture(GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex));
}

//背景移動
void UpDateBg()
{
	//プレイヤーが特定の位置に来た時
	if (movieplayer.Bg_pos == true)
	{
		//プレイヤーは動かず背景だけ移動
		if (bgdate.Tv <= 0.1f)
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
			bgdate.stopcount++;

			if (bgdate.stopcount == MOVIE_STOP_TIME)
			{
				bgdate.movespeed = -MOVIE_SPEED;
				movieplayer.movespeed = -MOVIE_PLAYER_SPEED;
			}

		}
		bgdate.Tv -= bgdate.movespeed;
		movieplayer.pos_y += movieplayer.movespeed;

		if (bgdate.Tv >= 0.5)//元の画面に戻った時
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
			movieplayer.moveanimesion = false;
		}
	}
	
}
