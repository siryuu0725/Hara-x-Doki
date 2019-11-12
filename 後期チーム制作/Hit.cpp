#include "Hit.h"
#include "Puzzle.h"
#include <math.h>

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
