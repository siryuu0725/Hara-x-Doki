#include "Player.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include <math.h>
#include "Robot.h"
#include "Menu.h"
#include "Bg.h"
#include "Text.h"

#define BACKPLAYERSIZE 150
#define ROBOTSIZE 150
#define INTERVAL 0.01


MoviePlayerDate movieplayer;
SearchPlayerData searchplayer;
BackPlayerData backplayer;
extern TextBoxData textbox;


void InitMoviePlayer()
{
	movieplayer.pos_x = 900.0f;
	movieplayer.pos_y = 1300.0f;
	movieplayer.Tu = 0.0f;
	movieplayer.Tv = 0.5f;
	movieplayer.movespeed = MOVIE_PLAYER_SPEED;
	movieplayer.moveanimesion = false;
	movieplayer.Bg_pos = false;
	movieplayer.animetioncount = 0;
	movieplayer.nextmoviecount = 0;
}

void InitSearchPlayer()
{
	//プレイヤーが廊下から大部屋に戻った時
	if (areadata.cangearea == true)
	{
		searchplayer.pos_x = 90.0f;
		searchplayer.pos_y = 430.0f;
		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.75f;
	}
	else
	{
		searchplayer.pos_x = 880.0f;
		searchplayer.pos_y = 950.0f;

		searchplayer.eyepos_x = searchplayer.pos_x;
		searchplayer.eyepos_y = searchplayer.pos_y + 34.0f;

		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.5f;
		searchplayer.hit = false;
		searchplayer.eyehit = false;

	}

}

void InitSearch2Player()
{
	//プレイヤーがボーイッシュ部屋から廊下に戻った時
	if (areadata.cangearea2 == 1)
	{
		searchplayer.pos_x = 1465.0f;
		searchplayer.pos_y = 455.0f;
		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.0f;
	}
	//プレイヤーがツンデレ部屋から廊下に戻った時
	else if (areadata.cangearea2 == 2)
	{
		searchplayer.pos_x = 855.0f;
		searchplayer.pos_y = 455.0f;
		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.0f;
	}
	//プレイヤーがゆるふわ部屋から廊下に戻った時
	else if (areadata.cangearea2 == 3)
	{
		searchplayer.pos_x = 265.0f;
		searchplayer.pos_y = 455.0f;
		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.0f;
	}
	else
	{
		searchplayer.pos_x = 1830.0f;
		searchplayer.pos_y = 645.0f;
		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.25f;
	}
	
}

void InitGameRoomPlayer()
{
	searchplayer.pos_x = 900.0f;
	searchplayer.pos_y = 950.0f;
	searchplayer.animetion_tu = 0.0f;
	searchplayer.animetion_tv = 0.5f;
	
}

void InitCriminalPlayer()
{
	searchplayer.pos_x = 335.0f;
	searchplayer.pos_y = 700.0f;
	searchplayer.animetion_tu = 0.0f;
	searchplayer.animetion_tv = 0.5f;

}

void InitBackPlayer()
{
	searchplayer.pos_x = 960.0f;
	searchplayer.pos_y = 800.0f;
}

void DrawMoviePlayer()
{
	DrawUVTexture(movieplayer.pos_x, movieplayer.pos_y, GetTexture(TEXTURE_MOVIE, MovieCategoryTextureList::MoviePlayerTex), 64.0f, 128.0f, movieplayer.Tu, movieplayer.Tv);
}

void DrawSearchPlayer()
{
	DrawUVTexture(searchplayer.pos_x, searchplayer.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex), 64.0f, 128.0f, searchplayer.animetion_tu, searchplayer.animetion_tv);
}

void DrawBackPlayer()
{
	DrawUVTexture(searchplayer.pos_x, searchplayer.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex), 64.0f, 128.0f, searchplayer.animetion_tu, searchplayer.animetion_tv);
}

void UpDateMoviePlayer()
{
	//アニメーション
	if (movieplayer.moveanimesion == false)
	{
		movieplayer.animetioncount++;
		movieplayer.pos_y -= MOVIE_PLAYER_SPEED;
		if (movieplayer.animetioncount >= 10)
		{
			movieplayer.Tu += 0.25f;
			movieplayer.animetioncount = 0;
		}
		
	}
	//特定の位置に進むと背景が動く
	if (movieplayer.pos_y <= 540.0f)
	{
		movieplayer.moveanimesion = true;
		movieplayer.nextmoviecount++;
		if (movieplayer.nextmoviecount == 60)
		{
			movieplayer.Bg_pos = true;
			movieplayer.movespeed = 4.8f;
			movieplayer.nextmoviecount = 0;
		}
	}
}

void SearchPlayerControl(float upmax, float downmax, float leftmax, float rightmax)
{
	searchplayer.movespeed = 10.0f;
	searchplayer.oldpos_x = searchplayer.pos_x;
	searchplayer.oldpos_y = searchplayer.pos_y;


	if (GetKey(UP_KEY) == true)
	{
		searchplayer.animetion_tv = 0.5f;

		searchplayer.eyepos_x = searchplayer.pos_x;
		searchplayer.eyepos_y = searchplayer.pos_y + 10.0f;

		if (searchplayer.pos_y >= upmax)
		{
			searchplayer.animetioncount++;

			searchplayer.pos_y -= searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}


	else if (GetKey(DOWN_KEY) == true)
	{
		searchplayer.animetion_tv = 0.0f;	

		searchplayer.eyepos_x = searchplayer.pos_x;
		searchplayer.eyepos_y = searchplayer.pos_y + PLAYER_HEIGHT + 64.0f;

		if (searchplayer.pos_y + 128.0f <= downmax)
		{
			searchplayer.animetioncount++;

			
			searchplayer.pos_y += searchplayer.movespeed;

			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}

	else if (GetKey(LEFT_KEY) == true)
	{

		searchplayer.animetion_tv = 0.25f;

		searchplayer.eyepos_x = searchplayer.pos_x - 64.0f;
		searchplayer.eyepos_y = searchplayer.pos_y + 16.0f;

		if (searchplayer.pos_x >= leftmax)
		{
			searchplayer.animetioncount++;

			
			searchplayer.pos_x -= searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}
	else if (GetKey(RIGHT_KEY) == true)
	{
		searchplayer.animetion_tv = 0.75f;

		searchplayer.eyepos_x = searchplayer.pos_x + 64.0f;
		searchplayer.eyepos_y = searchplayer.pos_y + 16.0f;

		if (searchplayer.pos_x + 64.0f <= rightmax)
		{
			searchplayer.animetioncount++;

			searchplayer.pos_x += searchplayer.movespeed;
			
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}
	else 
		searchplayer.animetion_tu = 0.0f;

}

//あたり判定時の描画位置更新
void UpDataPlayerPos()
{
	if (searchplayer.hit == true)
	{
		searchplayer.pos_x = searchplayer.oldpos_x;
		searchplayer.pos_y = searchplayer.oldpos_y;
	}
	
}








