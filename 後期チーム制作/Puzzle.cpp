#include "Puzzle.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "Hit.h"

NextCene nextcene;

PuzzleCabe puzzle;

void InitPuzzle()
{
	nextcene.Clea = false;

	puzzle.move_speed = 180.0f;

#pragma region 正方形初期化
	puzzle.square_width = 180.0f;
	puzzle.square_height = 180.0f;

	puzzle.pos_x[0] = 150.0f, puzzle.pos_y[0] = 360.0f;
	puzzle.pos_x[1] = 150.0f, puzzle.pos_y[1] = 900.0f;
	puzzle.pos_x[2] = 510.0f, puzzle.pos_y[2] = 900.0f;
	puzzle.pos_x[3] = 690.0f, puzzle.pos_y[3] = 360.0f;
	puzzle.pos_x[4] = 690.0f, puzzle.pos_y[4] = 720.0f;
	puzzle.pos_x[5] = 1230.0f, puzzle.pos_y[5] = 900.0f;
	puzzle.pos_x[6] = 1410.0f, puzzle.pos_y[6] = 180.0f;
	puzzle.pos_x[7] = 1410.0f, puzzle.pos_y[7] = 360.0f;
	puzzle.pos_x[8] = 1410.0f, puzzle.pos_y[8] = 900.0f;
#pragma endregion	

#pragma region 横長と鍵初期化
	puzzle.Landscape_width = 360.0f;
	puzzle.Landscape_height = 180.0f;
	puzzle.goal_key = false;

	puzzle.pos_x[9] = 150.0f, puzzle.pos_y[9] = 180.0f;
	puzzle.pos_x[10] = 150.0f, puzzle.pos_y[10] = 0.0f;
	puzzle.pos_x[11] = 330.0f, puzzle.pos_y[11] = 720.0f;
	puzzle.pos_x[12] = 510.0f, puzzle.pos_y[12] = 540.0f;
	puzzle.pos_x[13] = 690.0f, puzzle.pos_y[13] = 0.0f;
	puzzle.pos_x[14] = 690.0f, puzzle.pos_y[14] = 180.0f;
	puzzle.pos_x[15] = 870.0f, puzzle.pos_y[15] = 360.0f;
	puzzle.pos_x[16] = 870.0f, puzzle.pos_y[16] = 900.0f;
	puzzle.pos_x[17] = 1230.0f, puzzle.pos_y[17] = 0.0f;
	puzzle.pos_x[18] = 1230.0f, puzzle.pos_y[18] = 540.0f;
	puzzle.pos_x[19] = 1410.0f, puzzle.pos_y[19] = 720.0f;
#pragma endregion	

#pragma region 縦長初期化
	puzzle.Portrait_width = 180.0f;
	puzzle.Portrait_height = 360.0f;

	puzzle.pos_x[20] = 150.0f, puzzle.pos_y[20] = 540.0f;
	puzzle.pos_x[21] = 330.0f, puzzle.pos_y[21] = 360.0f;
	puzzle.pos_x[22] = 510.0f, puzzle.pos_y[22] = 0.0f;
	puzzle.pos_x[23] = 870.0f, puzzle.pos_y[23] = 540.0f;
	puzzle.pos_x[24] = 1050.0f, puzzle.pos_y[24] = 0.0f;
	puzzle.pos_x[25] = 1050.0f, puzzle.pos_y[25] = 540.0f;
	puzzle.pos_x[26] = 1230.0f, puzzle.pos_y[26] = 180.0f;
	puzzle.pos_x[27] = 1590.0f, puzzle.pos_y[27] = 360.0f;
#pragma endregion	

}

void DrawBgPuzzle()
{
	DrawBgTexture(GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleGameBgTex));

}


void DrawPuzzle()
{
	for (int i = 0; i < 9; i++)
	{
		DrawTexture(puzzle.pos_x[i], puzzle.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleSquareTex));
	}
	for (int i = 10; i < 20; i++)
	{
		DrawTexture(puzzle.pos_x[i], puzzle.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleLandscapeTex));
	}
	DrawTexture(puzzle.pos_x[9], puzzle.pos_y[9], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleKeyTex));
	for (int i = 20; i < 28; i++)
	{
		DrawTexture(puzzle.pos_x[i], puzzle.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzlePortraitTex));
	}
}


void UpDatePuzzle()
{
#pragma region 正方形の操作
	for (int i = 0; i < 9; i++)
	{
		//上
		if (GetMousePos().X >= puzzle.pos_x[i] + 40.0f && GetMousePos().X <= puzzle.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] && GetMousePos().Y <= puzzle.pos_y[i] + 40.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_y[i] -= 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.square_width, puzzle.square_height) == true)
			{
				puzzle.pos_y[i] += 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{
				puzzle.pos_y[i] += 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{
				puzzle.pos_y[i] += 180.0f;

			}
			else if (puzzle.pos_y[i] < 0.0f)
			{
				puzzle.pos_y[i] += 180.0f;
			}
		}

		//下
		if (GetMousePos().X >= puzzle.pos_x[i] + 40.0f && GetMousePos().X <= puzzle.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 140.0f && GetMousePos().Y <= puzzle.pos_y[i] + 180.0f
			&& OnMouseDown(Left) == true)
		{

			puzzle.pos_y[i] += 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.square_width, puzzle.square_height) == true)
			{
				puzzle.pos_y[i] -= 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{
				puzzle.pos_y[i] -= 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{
				puzzle.pos_y[i] -= 180.0f;

			}
			else if (puzzle.pos_y[i] + puzzle.square_height > 1080.0f)
			{
				puzzle.pos_y[i] -= 180.0f;
			}
		}
		//左
		if (GetMousePos().X >= puzzle.pos_x[i] && GetMousePos().X <= puzzle.pos_x[i] + 40.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_x[i] -= 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.square_width, puzzle.square_height) == true)
			{
				puzzle.pos_x[i] += 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{
				puzzle.pos_x[i] += 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{
				puzzle.pos_x[i] += 180.0f;

			}
			else if (puzzle.pos_x[i] < 150.0f)
			{
				puzzle.pos_x[i] += 180.0f;
			}
		}

		//右
		if (GetMousePos().X >= puzzle.pos_x[i] + 140.0f && GetMousePos().X <= puzzle.pos_x[i] + 180.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_x[i] += 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.square_width, puzzle.square_height) == true)
			{
				puzzle.pos_x[i] -= 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{
				puzzle.pos_x[i] -= 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.square_width, puzzle.square_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{
				puzzle.pos_x[i] -= 180.0f;

			}
			else if (puzzle.pos_x[i] + puzzle.square_width > 1770.0f)
			{
				puzzle.pos_x[i] -= 180.0f;
			}
		}
	}
#pragma endregion 


#pragma region 横長の操作
	for (int i = 9; i < 20; i++)
	{
		//上
		if (GetMousePos().X >= puzzle.pos_x[i] + 40.0f && GetMousePos().X <= puzzle.pos_x[i] + 320.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] && GetMousePos().Y <= puzzle.pos_y[i] + 40.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_y[i] -= 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.square_width, puzzle.square_height) == true)
			{

				puzzle.pos_y[i] += 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{

				puzzle.pos_y[i] += 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{

				puzzle.pos_y[i] += 180.0f;

			}
			else if (puzzle.pos_y[i] < 0.0f)
			{
				puzzle.pos_y[i] += 180.0f;
			}
		}
		//下
		if (GetMousePos().X >= puzzle.pos_x[i] + 40.0f && GetMousePos().X <= puzzle.pos_x[i] + 320.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 140.0f && GetMousePos().Y <= puzzle.pos_y[i] + 180.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_y[i] += 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.square_width, puzzle.square_height) == true)
			{
				puzzle.pos_y[i] -= 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{
				puzzle.pos_y[i] -= 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{

				puzzle.pos_y[i] -= 180.0f;

			}
			else if (puzzle.pos_y[i] + puzzle.Landscape_height > 1080.0f)
			{
				puzzle.pos_y[i] -= 180.0f;
			}
		}
		//左
		if (GetMousePos().X >= puzzle.pos_x[i] && GetMousePos().X <= puzzle.pos_x[i] + 40.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_x[i] -= 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.square_width, puzzle.square_height) == true)
			{

				puzzle.pos_x[i] += 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{

				puzzle.pos_x[i] += 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{

				puzzle.pos_x[i] += 180.0f;

			}
			else if (puzzle.pos_x[i] < 150.0f)
			{
				puzzle.pos_x[i] += 180.0f;
			}
		}
		//右
		if (GetMousePos().X >= puzzle.pos_x[i] + 320.0f && GetMousePos().X <= puzzle.pos_x[i] + 360.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_x[i] += 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.square_width, puzzle.square_height) == true)
			{

				puzzle.pos_x[i] -= 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{

				puzzle.pos_x[i] -= 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Landscape_width, puzzle.Landscape_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{

				puzzle.pos_x[i] -= 180.0f;

			}
			else if (puzzle.pos_x[i] + puzzle.Landscape_width > 1770.0f)
			{
				puzzle.pos_x[i] -= 180.0f;
			}

			if (puzzle.pos_x[9] == 1410.0f && puzzle.pos_y[9] == 360.0f && GetMousePos().X >= puzzle.pos_x[9] + 320.0f && GetMousePos().X <= puzzle.pos_x[9] + 360.0f
				&& GetMousePos().Y >= puzzle.pos_y[9] + 40.0f && GetMousePos().Y <= puzzle.pos_y[9] + 140.0f
				&& OnMouseDown(Left) == true)
			{
				puzzle.goal_key = true;
			}
		}

	}
#pragma endregion 


#pragma region 縦長の操作
	for (int i = 20; i < 28; i++)
	{
		//上
		if (GetMousePos().X >= puzzle.pos_x[i] + 40.0f && GetMousePos().X <= puzzle.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] && GetMousePos().Y <= puzzle.pos_y[i] + 40.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_y[i] -= 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.square_width, puzzle.square_height) == true)
			{
				puzzle.pos_y[i] += 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{
				puzzle.pos_y[i] += 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{
				puzzle.pos_y[i] += 180.0f;

			}
			else if (puzzle.pos_x[i] < 0.0f)
			{
				puzzle.pos_x[i] += 180.0f;
			}
		}

		//下
		if (GetMousePos().X >= puzzle.pos_x[i] + 40.0f && GetMousePos().X <= puzzle.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 320.0f && GetMousePos().Y <= puzzle.pos_y[i] + 360.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_y[i] += 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.square_width, puzzle.square_height) == true)
			{

				puzzle.pos_y[i] -= 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{

				puzzle.pos_y[i] -= 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)

				puzzle.pos_y[i] -= 180.0f;

		}
		else if (puzzle.pos_y[i] + puzzle.Portrait_height > 1080.0f)
		{
			puzzle.pos_y[i] -= 180.0f;
		}

		//左
		if (GetMousePos().X >= puzzle.pos_x[i] && GetMousePos().X <= puzzle.pos_x[i] + 40.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle.pos_y[i] + 320.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_x[i] -= 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.square_width, puzzle.square_height) == true)
			{

				puzzle.pos_x[i] += 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{

				puzzle.pos_x[i] += 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{

				puzzle.pos_x[i] += 180.0f;

			}
			else if (puzzle.pos_x[i] < 150.0f)
			{
				puzzle.pos_x[i] += 180.0f;
			}
		}
		//右
		if (GetMousePos().X >= puzzle.pos_x[i] + 140.0f && GetMousePos().X <= puzzle.pos_x[i] + 180.0f
			&& GetMousePos().Y >= puzzle.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle.pos_y[i] + 320.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle.pos_x[i] += 180.0f;

			if (HitCabe(0, 9, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.square_width, puzzle.square_height) == true)
			{

				puzzle.pos_x[i] -= 180.0f;

			}
			else if (HitCabe(9, 20, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Landscape_width, puzzle.Landscape_height) == true)
			{

				puzzle.pos_x[i] -= 180.0f;

			}
			else if (HitCabe(20, 28, i, &puzzle, puzzle.Portrait_width, puzzle.Portrait_height, puzzle.Portrait_width, puzzle.Portrait_height) == true)
			{

				puzzle.pos_x[i] -= 180.0f;

			}
			else if (puzzle.pos_x[i] + puzzle.Portrait_width > 1770.0f)
			{
				puzzle.pos_x[i] -= 180.0f;
			}
		}
	}
#pragma endregion 

	//鍵がゴールした時
	if (puzzle.goal_key == true)
	{
		puzzle.pos_x[9] += 10.0f;
		if (puzzle.pos_x[9] > 1920.0f)
		{
			nextcene.Clea = true;
		}
	}

}