#include "Player.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include <math.h>
#include "Robot.h"
#include "Menu.h"
#include "Bg.h"

#define BACKPLAYERSIZE 150
#define ROBOTSIZE 150
#define INTERVAL 0.01


MoviePlayerDate movieplayer;
SearchPlayerData searchplayer;
BackPlayerData backplayer;


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
	if (areadata.cangearea == true)
	{
		searchplayer.pos_x = 180.0f;
		searchplayer.pos_y = 340.0f;
		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.75f;
	}
	else
	{
		searchplayer.pos_x = 820.0f;
		searchplayer.pos_y = 890.0f;
		searchplayer.animetion_tu = 0.0f;
		searchplayer.animetion_tv = 0.5f;
	}

}

void InitSearch2Player()
{
	if (areadata.cangearea2 == true)
	{
		searchplayer.pos_x = 1465.0f;
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

void InitSearchGamePlayer()
{
	searchplayer.pos_x = 860.0f;
	searchplayer.pos_y = 935.0f;
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
	if (movieplayer.moveanimesion == false)//アニメーション
	{
		movieplayer.animetioncount++;
		movieplayer.pos_y -= MOVIE_PLAYER_SPEED;
		if (movieplayer.animetioncount >= 10)
		{
			movieplayer.Tu += 0.25f;
			movieplayer.animetioncount = 0;
		}
		
	}
	if (movieplayer.pos_y <= 540.0f)//特定の位置に進むと背景が動く
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
	searchplayer.movespeed = 5.0f;
	
	float vec_x = 0.0f;
	float vec_y = 0.0f;
	float length = 0.0f;

	if (GetKey(UP_KEY) == true)
	{
		searchplayer.animetion_tv = 0.5f;
		searchplayer.oldpos_y = searchplayer.pos_y;

		if (searchplayer.pos_y >= upmax)
		{
			searchplayer.animetioncount++;

			searchplayer.pos_y -= searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
			if (searchrobot.hit == true)
			{
				searchplayer.pos_y = searchplayer.oldpos_y;
			}
		}
	}


	else if (GetKey(DOWN_KEY) == true)
	{
		searchplayer.animetion_tv = 0.0f;

		if (searchplayer.pos_y + 128.0f <= downmax)
		{
			searchplayer.animetioncount++;

			searchplayer.oldpos_y = searchplayer.pos_y;
			searchplayer.pos_y += searchplayer.movespeed;

			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
			if (searchrobot.hit == true)
			{
				searchplayer.pos_y = searchplayer.oldpos_y;
			}
		}
	}

	else if (GetKey(LEFT_KEY) == true)
	{

		searchplayer.animetion_tv = 0.25f;

		if (searchplayer.pos_x >= leftmax)
		{
			searchplayer.animetioncount++;

			searchplayer.oldpos_x = searchplayer.pos_x;
			searchplayer.pos_x -= searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
			if (searchrobot.hit == true)
			{
				searchplayer.pos_x = searchplayer.oldpos_x;
			}
		}
	}
	else if (GetKey(RIGHT_KEY) == true)
	{
		searchplayer.animetion_tv = 0.75f;

		if (searchplayer.pos_x + 64.0f <= rightmax)
		{
			searchplayer.animetioncount++;

			searchplayer.oldpos_x = searchplayer.pos_x;
			searchplayer.pos_x += searchplayer.movespeed;
			
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
			if (searchrobot.hit == true)
			{
				searchplayer.pos_x = searchplayer.oldpos_x;
			}
		}
	}
	else 
		searchplayer.animetion_tu = 0.0f;

	/*if (vec_x != 0.0f || vec_y != 0.0f)
	{
		length = sqrt(vec_x * vec_x + vec_y * vec_y);

		float normal_x = vec_x / length;
		float normal_y = vec_y / length;

		normal_x *= searchplayer.movespeed;
		normal_y *= searchplayer.movespeed;

		searchplayer.pos_x += normal_x;
		searchplayer.pos_y += normal_y;
	}*/
}








