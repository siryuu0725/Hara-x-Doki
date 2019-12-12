#include "Hit.h"
#include "Puzzle.h"
#include <math.h>
#include "Player.h"
#include "Input.h"


bool HitChoiseTitle(float x, float y, float width, float height)
{
	// 始めるとマウスの当たり判定
	if (GetMousePos().X >= x && GetMousePos().X <= x + width &&
		GetMousePos().Y >= y && GetMousePos().Y <= y + height)
	{
		return true;
	}
	return false;
}


bool HitNextArea(float left_x, float right_x, float up_y,float down_y)
{
	if (searchplayer.pos_x >= left_x && searchplayer.pos_x + 64.0f <= right_x && searchplayer.pos_y >= up_y && searchplayer.pos_y <= down_y)
	{
		return true;
	}
	return false;
	
}

bool HitPlayerObject(float obj_x,float obj_y, float obj_width, float obj_height)
{
	if ((searchplayer.pos_x < obj_x + obj_width)
		&& (searchplayer.pos_x + 64.0f > obj_x)
		&& (searchplayer.pos_y + 70.0f < obj_y + obj_height)
		&& (searchplayer.pos_y + 128.0f > obj_y))
	{
		return true;
	}
}

bool HitPlayerEyeObject(float obj_x, float obj_y, float obj_width, float obj_height)
{
	if ((searchplayer.eyepos_x < obj_x + obj_width)
		&& (searchplayer.eyepos_x + 64.0f > obj_x)
		&& (searchplayer.eyepos_y < obj_y + obj_height)
		&& (searchplayer.eyepos_y + 100.0f > obj_y))
	{
		return true;
	}
}

bool HitCabe(int d, int d2, int idx_, PuzzleCabe* puzzle1, float width, float height, float Compare_width, float Compare_height)
{

	for (int i = d; i < d2; i++)
	{
		if (i == idx_)
		{
			continue;
		}

		if ((puzzle1->pos_x[idx_] < puzzle1->pos_x[i] + Compare_width)
			&& (puzzle1->pos_x[idx_] + width > puzzle1->pos_x[i])
			&& (puzzle1->pos_y[idx_] < puzzle1->pos_y[i] + Compare_height)
			&& (puzzle1->pos_y[idx_] + height > puzzle1->pos_y[i]))
		{
			return true;
		}

	}
}
