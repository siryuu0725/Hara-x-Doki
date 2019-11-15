#include "Player.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include <math.h>
#include "Robot.h"
#include "Menu.h"

#define BACKPLAYERSIZE 150
#define ROBOTSIZE 150
#define INTERVAL 0.01

MoviePlayerDate movieplayer;
SearchPlayerData searchplayer;
BackPlayerData backplayer;
extern MenuData menu;

void InitMoviePlayer()
{
	movieplayer.pos_x = 900.0f;
	movieplayer.pos_y = 1300.0f;
	movieplayer.Tu = 0.0f;
	movieplayer.Tv = 0.5f;
	movieplayer.movespeed = 2.8f;
	movieplayer.moveanimesion = false;
	movieplayer.Bg_pos = false;
	movieplayer.animetioncount = 0;
	movieplayer.nextmoviecount = 0;
}

void InitSearchPlayer()
{
	searchplayer.pos_x = 820.0f;
	searchplayer.pos_y = 890.0f;
	searchplayer.animetion_tu = 0.0f;
	searchplayer.animetion_tv = 0.5f;
	//searchplayer.movespeed = 0.25f;
}

void InitSearch2Player()
{
	searchplayer.pos_x = 1760.0f;
	searchplayer.pos_y = 440.0f;
	searchplayer.animetion_tu = 0.0f;
	searchplayer.animetion_tv = 0.25f;
	//searchplayer.movespeed = 0.25f;

}

void InitBackPlayer()
{
	backplayer.pos_x = 960.0f;
	backplayer.pos_y = 800.0f;
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
	DrawTexture(backplayer.pos_x, backplayer.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkPlayerTex));
}

void UpDateMoviePlayer()
{
	if (movieplayer.moveanimesion == false)//アニメーション
	{
		movieplayer.animetioncount++;
		movieplayer.pos_y -= 2.0f;
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
			movieplayer.nextmoviecount = 0;
		}
	}
}

void SearchPlayerControl()
{

	searchplayer.movespeed = 5.0f;
	float vec_x = 0.0f;
	float vec_y = 0.0f;
	float length = 0.0f;

	if (GetKey(UP_KEY) == true)
	{
		if (searchplayer.pos_y >= 0.0f)
		{
			searchplayer.animetion_tv = 0.5f;

			searchplayer.animetioncount++;

			vec_y = -searchplayer.movespeed;
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

		searchplayer.animetioncount++;

		if (searchplayer.pos_y + 175.0f <= 1080.0f)
		{
			vec_y = searchplayer.movespeed;
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

		searchplayer.animetioncount++;

		if (searchplayer.pos_x >= 0.0f)
		{
			vec_x = -searchplayer.movespeed;
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

		searchplayer.animetioncount++;

		if (searchplayer.pos_x + 175.0f <= 1980.0f)
		{
			vec_x = searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}

	if (vec_x != 0.0f || vec_y != 0.0f)
	{
		length = sqrt(vec_x * vec_x + vec_y * vec_y);

		float normal_x = vec_x / length;
		float normal_y = vec_y / length;

		normal_x *= searchplayer.movespeed;
		normal_y *= searchplayer.movespeed;

		searchplayer.pos_x += normal_x;
		searchplayer.pos_y += normal_y;
	}
}

void Search2PlayerControl()
{

	searchplayer.movespeed = 5.0f;
	float vec_x = 0.0f;
	float vec_y = 0.0f;
	float length = 0.0f;

	if (GetKey(UP_KEY) == true)
	{
		if (searchplayer.pos_y >= 0.0f)
		{
			searchplayer.animetion_tv = 0.25f;

			searchplayer.animetioncount++;

			vec_y = -searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}

	if (GetKey(DOWN_KEY) == true)
	{
		searchplayer.animetion_tv = 0.0f;

		searchplayer.animetioncount++;

		if (searchplayer.pos_y + 175.0f <= 1080.0f)
		{
			vec_y = searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}

	if (GetKey(LEFT_KEY) == true)
	{

		searchplayer.animetion_tv = 0.5f;

		searchplayer.animetioncount++;

		if (searchplayer.pos_x >= 0.0f)
		{
			vec_x = -searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}
	if (GetKey(RIGHT_KEY) == true)
	{
		searchplayer.animetion_tv = 0.75f;

		searchplayer.animetioncount++;

		if (searchplayer.pos_x + 175.0f <= 1980.0f)
		{
			vec_x = searchplayer.movespeed;
			if (searchplayer.animetioncount >= 10)
			{
				searchplayer.animetion_tu += 0.25f;
				searchplayer.animetioncount = 0;
			}
		}
	}

	if (vec_x != 0.0f || vec_y != 0.0f)
	{
		length = sqrt(vec_x * vec_x + vec_y * vec_y);

		float normal_x = vec_x / length;
		float normal_y = vec_y / length;

		normal_x *= searchplayer.movespeed;
		normal_y *= searchplayer.movespeed;

		searchplayer.pos_x += normal_x;
		searchplayer.pos_y += normal_y;
	}
}


void UpDateBackPlayer(BackPlayerData *backplayer)
{
	
	float speed = 10.0f;
	float vec_x = 0.0f;
	float vec_y = 0.0f;	
	float length = 0.0f;

	if (menu.onenterkey == true)
	{
		speed = 0.0f;
	}

	if (GetKey(UP_KEY) == true)
	{
		if (backplayer->pos_y + BACKPLAYERSIZE >= 200.0f)
		{
			vec_y = -speed;
		}
	}

	if (GetKey(DOWN_KEY) == true)
	{
		if (backplayer->pos_y + BACKPLAYERSIZE + 100 <= 1080.0f)
		{
			vec_y = speed;
		}
	}
	if (GetKey(LEFT_KEY) == true)
	{
		if (backplayer->pos_x + BACKPLAYERSIZE >= 200.0f)
		{
			vec_x = -speed;
		}
	}
	if (GetKey(RIGHT_KEY) == true)
	{
		if (backplayer->pos_x + BACKPLAYERSIZE + 100 <= 1980.0f)
		{
			vec_x = speed;
		}
	}

	if (vec_x != 0.0f || vec_y != 0.0f)
	{
		length = sqrt(vec_x * vec_x + vec_y * vec_y);

		float normal_x = vec_x / length;
		float normal_y = vec_y / length;

		normal_x *= speed;
		normal_y *= speed;

		backplayer->pos_x += normal_x;
		backplayer->pos_y += normal_y;
	}
}

