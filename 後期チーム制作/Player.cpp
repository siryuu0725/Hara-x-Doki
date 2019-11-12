#include "Player.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include <math.h>
#include "Robot.h"

#define BACKPLAYERSIZE 150
#define ROBOTSIZE 150
#define INTERVAL 0.01

MoviePlayerDate movieplayer;
BackPlayerData backplayer;


void InitPlayer()
{
	movieplayer.pos_x = 900.0f;
	movieplayer.pos_y = 1300.0f;
	movieplayer.Tu = 0.0f;
	movieplayer.Tv = 0.25f;
	movieplayer.movespeed = 2.8f;
	movieplayer.move_animesion = false;
	movieplayer.Bg_pos = false;
	movieplayer.animetion_count = 0;
	movieplayer.nextmoviecount = 0;
}

void InitBackPlayer()
{
	backplayer.pos_x = 960.0f;
	backplayer.pos_y = 800.0f;
}

void DrawPlayer()
{
	DrawUVTexture(movieplayer.pos_x, movieplayer.pos_y, GetTexture(TEXTURE_MOVIE, MovieCategoryTextureList::MoviePlayer), 170.0f, 175.0f, movieplayer.Tu, movieplayer.Tv);
}

void DrawBackPlayer()
{
	DrawTexture(backplayer.pos_x, backplayer.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkPlayer));
}

void UpDatePlayer()
{
	if (movieplayer.move_animesion == false)//アニメーション
	{
		movieplayer.animetion_count++;
		movieplayer.pos_y -= 2.0f;
		if (movieplayer.animetion_count >= 10)
		{
			movieplayer.Tu += 0.25f;
			movieplayer.animetion_count = 0;
		}
		
	}
	if (movieplayer.pos_y <= 540.0f)//特定の位置に進むと背景が動く
	{
		movieplayer.move_animesion = true;
		movieplayer.nextmoviecount++;
		if (movieplayer.nextmoviecount == 60)
		{
			movieplayer.Bg_pos = true;
			movieplayer.nextmoviecount = 0;
		}
	}
}

void UpDateBackPlayer(BackPlayerData *backplayer)
{
	
	float speed = 10.0f;
	float vec_x = 0.0f;
	float vec_y = 0.0f;	
	float length = 0.0f;

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
