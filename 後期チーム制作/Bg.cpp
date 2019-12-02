#include "Bg.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"

#define MOVIETEX_TU 0.0f
#define MOVITEXE_TV 0.45f
#define MOVIE_SPEED 0.001f
#define MOVIE_STOP_TIME 120

MovieBgData bgdate;
SearchAreaData areadata;
extern MoviePlayerDate movieplayer;

void InitBg()
{
	bgdate.Tu = MOVIETEX_TU;
	bgdate.Tv = MOVITEXE_TV;
	bgdate.movespeed = 0.002f;
	bgdate.stopcount = 0;
}

void InitArea()
{
	areadata.searcharea1 = true;
	areadata.searcharea2 = false;
	areadata.searchcriminalarea = false;
	areadata.searchgamearea = false;
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
	if (areadata.searcharea1 == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex));
	}
	else if (areadata.searcharea2 == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH2, Search2CategoryTextureList::Search2BgTex));
	}
	else if (areadata.searchgamearea == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex));
	}
	else if (areadata.searchcriminalarea == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRoomBgTex));
	}
}


//ムービー用背景移動
void UpDateBg()
{
	//プレイヤーが特定の位置に来た時
	if (movieplayer.Bg_pos == true)
	{
		//プレイヤーは動かず背景だけ移動
		bgdate.Tv -= bgdate.movespeed;
		movieplayer.pos_y += movieplayer.movespeed;


		if (bgdate.Tv <= 0.01f)
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
			bgdate.stopcount++;

			if (bgdate.stopcount == MOVIE_STOP_TIME)
			{
				bgdate.movespeed = -0.002f;
				movieplayer.movespeed -= 4.7;
			}

		}
		

		if (bgdate.Tv >= 0.5)//元の画面に戻った時
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
		
			movieplayer.moveanimesion = false;
		}
	}
	
}
