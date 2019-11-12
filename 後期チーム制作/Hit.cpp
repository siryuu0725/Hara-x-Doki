#include "Hit.h"
#include "Puzzle.h"
#include <math.h>

#pragma region ê≥ï˚å`Ç∆ÇªÇÃëºÇÃîªíË
bool HitCabe1_1(int idx_, Puzzle_1* puzzle1)
{

	for (int i = 0; i < 9; i++)
	{

		if (i == idx_)
		{
			continue;
		}

		if ((puzzle1->pos_x[idx_] < puzzle1->pos_x[i] + puzzle1->width)
			&& (puzzle1->pos_x[idx_] + puzzle1->width > puzzle1->pos_x[i])
			&& (puzzle1->pos_y[idx_] < puzzle1->pos_y[i] + puzzle1->height)
			&& (puzzle1->pos_y[idx_] + puzzle1->height > puzzle1->pos_y[i]))
		{
			return true;
		}

	}
}

bool HitCabe1_2(int idx_,Puzzle_1* puzzle1, Puzzle_2* puzzle2)
{
	
	for (int i = 0; i < 11; i++)
	{
		if ((puzzle1->pos_x[idx_] < puzzle2->pos_x[i] + puzzle2->width)
			&& (puzzle1->pos_x[idx_] + puzzle1->width > puzzle2->pos_x[i])
			&& (puzzle1->pos_y[idx_] < puzzle2->pos_y[i] + puzzle2->height)
			&& (puzzle1->pos_y[idx_] + puzzle1->height > puzzle2->pos_y[i]))
		{
			return true;
		}
		
	}
}

bool HitCabe1_3(int idx_,Puzzle_1* puzzle1, Puzzle_3* puzzle3)
{

	for (int i = 0; i < 8; i++)
	{
		if ((puzzle1->pos_x[idx_] < puzzle3->pos_x[i] + puzzle3->width)
			&& (puzzle1->pos_x[idx_] + puzzle1->width > puzzle3->pos_x[i])
			&& (puzzle1->pos_y[idx_] < puzzle3->pos_y[i] + puzzle3->height)
			&& (puzzle1->pos_y[idx_] + puzzle1->height > puzzle3->pos_y[i]))
		{
			return true;
		}

	}
}
#pragma endregion

#pragma region â°í∑Ç∆ÇªÇÃëºÇÃîªíË
bool HitCabe2_2(int idx_, Puzzle_2* puzzle2)
{

	for (int i = 0; i < 11; i++)
	{

		if (i == idx_)
		{
			continue;
		}

		if ((puzzle2->pos_x[idx_] < puzzle2->pos_x[i] + puzzle2->width)
			&& (puzzle2->pos_x[idx_] + puzzle2->width > puzzle2->pos_x[i])
			&& (puzzle2->pos_y[idx_] < puzzle2->pos_y[i] + puzzle2->height)
			&& (puzzle2->pos_y[idx_] + puzzle2->height > puzzle2->pos_y[i]))
		{
			return true;
		}

	}
}

bool HitCabe2_1(int idx_,Puzzle_2* puzzle2, Puzzle_1* puzzle1)
{

	for (int i = 0; i < 9; i++)
	{
		if ((puzzle2->pos_x[idx_] < puzzle1->pos_x[i] + puzzle1->width)
			&& (puzzle2->pos_x[idx_] + puzzle2->width > puzzle1->pos_x[i])
			&& (puzzle2->pos_y[idx_] < puzzle1->pos_y[i] + puzzle1->height)
			&& (puzzle2->pos_y[idx_] + puzzle2->height > puzzle1->pos_y[i]))
		{
			return true;
		}

	}
}

bool HitCabe2_3(int idx_, Puzzle_2* puzzle2, Puzzle_3* puzzle3)
{

	for (int i = 0; i < 8; i++)
	{
		if ((puzzle2->pos_x[idx_] < puzzle3->pos_x[i] + puzzle3->width)
			&& (puzzle2->pos_x[idx_] + puzzle2->width > puzzle3->pos_x[i])
			&& (puzzle2->pos_y[idx_] < puzzle3->pos_y[i] + puzzle3->height)
			&& (puzzle2->pos_y[idx_] + puzzle2->height > puzzle3->pos_y[i]))
		{
			return true;
		}

	}
}
#pragma endregion

#pragma region ècí∑Ç∆ÇªÇÃëºÇÃîªíË
bool HitCabe3_3(int idx_,Puzzle_3* puzzle3)
{

	for (int i = 0; i < 8; i++)
	{

		if (i == idx_)
		{
			continue;
		}

		if ((puzzle3->pos_x[idx_] < puzzle3->pos_x[i] + puzzle3->width)
			&& (puzzle3->pos_x[idx_] + puzzle3->width > puzzle3->pos_x[i])
			&& (puzzle3->pos_y[idx_] < puzzle3->pos_y[i] + puzzle3->height)
			&& (puzzle3->pos_y[idx_] + puzzle3->height > puzzle3->pos_y[i]))
		{
			return true;
		}

	}
}

bool HitCabe3_1(int idx_, Puzzle_3* puzzle3, Puzzle_1* puzzle1)
{

	for (int i = 0; i < 9; i++)
	{
		if ((puzzle3->pos_x[idx_] < puzzle1->pos_x[i] + puzzle1->width)
			&& (puzzle3->pos_x[idx_] + puzzle3->width > puzzle1->pos_x[i])
			&& (puzzle3->pos_y[idx_] < puzzle1->pos_y[i] + puzzle1->height)
			&& (puzzle3->pos_y[idx_] + puzzle3->height > puzzle1->pos_y[i]))
		{
			return true;
		}

	}
}

bool HitCabe3_2(int idx_, Puzzle_3* puzzle3, Puzzle_2* puzzle2)
{

	for (int i = 0; i < 11; i++)
	{
		if ((puzzle3->pos_x[idx_] < puzzle2->pos_x[i] + puzzle2->width)
			&& (puzzle3->pos_x[idx_] + puzzle3->width > puzzle2->pos_x[i])
			&& (puzzle3->pos_y[idx_] < puzzle2->pos_y[i] + puzzle2->height)
			&& (puzzle3->pos_y[idx_] + puzzle3->height > puzzle2->pos_y[i]))
		{
			return true;
		}
	}
}
#pragma endregion
