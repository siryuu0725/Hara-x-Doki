#include "Puzzle.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "Hit.h"

NextCeneFlg next_flg;

Puzzle_1 puzzle1;
Puzzle_2 puzzle2;
Puzzle_3 puzzle3;


void InitPuzzle()
{
	next_flg.CleaFlg = false;

#pragma region 正方形初期化
	puzzle1.width = 180.0f;
	puzzle1.height = 180.0f;

	puzzle1.pos_x[0] = 0.0f, puzzle1.pos_y[0] = 360.0f;
	puzzle1.pos_x[1] = 0.0f, puzzle1.pos_y[1] = 900.0f;
	puzzle1.pos_x[2] = 360.0f, puzzle1.pos_y[2] = 900.0f;
	puzzle1.pos_x[3] = 540.0f, puzzle1.pos_y[3] = 360.0f;
	puzzle1.pos_x[4] = 540.0f, puzzle1.pos_y[4] = 720.0f;
	puzzle1.pos_x[5] = 1080.0f, puzzle1.pos_y[5] = 900.0f;
	puzzle1.pos_x[6] = 1260.0f, puzzle1.pos_y[6] = 180.0f;
	puzzle1.pos_x[7] = 1260.0f, puzzle1.pos_y[7] = 360.0f;
	puzzle1.pos_x[8] = 1260.0f, puzzle1.pos_y[8] = 900.0f;
#pragma endregion	

#pragma region 横長と鍵初期化
	puzzle2.width = 360.0f;
	puzzle2.height = 180.0f;
	puzzle2.key_flg = false;

	puzzle2.pos_x[0] = 0.0f, puzzle2.pos_y[0] = 180.0f;
	puzzle2.pos_x[1] = 0.0f, puzzle2.pos_y[1] = 0.0f;
	puzzle2.pos_x[2] = 180.0f, puzzle2.pos_y[2] = 720.0f;
	puzzle2.pos_x[3] = 360.0f, puzzle2.pos_y[3] = 540.0f;
	puzzle2.pos_x[4] = 540.0f, puzzle2.pos_y[4] = 0.0f;
	puzzle2.pos_x[5] = 540.0f, puzzle2.pos_y[5] = 180.0f;
	puzzle2.pos_x[6] = 720.0f, puzzle2.pos_y[6] = 360.0f;
	puzzle2.pos_x[7] = 720.0f, puzzle2.pos_y[7] = 900.0f;
	puzzle2.pos_x[8] = 1080.0f, puzzle2.pos_y[8] = 0.0f;
	puzzle2.pos_x[9] = 1080.0f, puzzle2.pos_y[9] = 540.0f;
	puzzle2.pos_x[10] = 1260.0f, puzzle2.pos_y[10] = 720.0f;
#pragma endregion	

#pragma region 縦長初期化
	puzzle3.width = 180.0f;
	puzzle3.height = 360.0f;

	puzzle3.pos_x[0] = 0.0f, puzzle3.pos_y[0] = 540.0f;
	puzzle3.pos_x[1] = 180.0f, puzzle3.pos_y[1] = 360.0f;
	puzzle3.pos_x[2] = 360.0f, puzzle3.pos_y[2] = 0.0f;
	puzzle3.pos_x[3] = 720.0f, puzzle3.pos_y[3] = 540.0f;
	puzzle3.pos_x[4] = 900.0f, puzzle3.pos_y[4] = 0.0f;
	puzzle3.pos_x[5] = 900.0f, puzzle3.pos_y[5] = 540.0f;
	puzzle3.pos_x[6] = 1080.0f, puzzle3.pos_y[6] = 180.0f;
	puzzle3.pos_x[7] = 1440.0f, puzzle3.pos_y[7] = 360.0f;
#pragma endregion	

}

void DrawBgPuzzle()
{
	DrawBgTexture(GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleGameBg));

}


void DrawPuzzle()
{
	for (int i = 0; i < 9; i++)
	{
		DrawTexture(puzzle1.pos_x[i], puzzle1.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::Puzzle1));
	}
	for (int i = 1; i < 11; i++)
	{
		DrawTexture(puzzle2.pos_x[i], puzzle2.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::Puzzle2));
	}
	DrawTexture(puzzle2.pos_x[0], puzzle2.pos_y[0], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleKey));
	for (int i = 0; i < 8; i++)
	{
		DrawTexture(puzzle3.pos_x[i], puzzle3.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::Puzzle3));
	}
}


void UpDatePuzzle()
{
#pragma region 正方形の操作
	for (int i = 0; i < 9; i++)
	{
		//上
		if (GetMousePos().X >= puzzle1.pos_x[i] + 40.0f && GetMousePos().X <= puzzle1.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle1.pos_y[i] && GetMousePos().Y <= puzzle1.pos_y[i] + 40.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle1.pos_y[i] -= 180.0f;

			if (HitCabe1_1(i, &puzzle1) == true)
			{
				puzzle1.pos_y[i] += 180.0f;

			}
			else if (HitCabe1_2(i, &puzzle1, &puzzle2) == true)
			{
				puzzle1.pos_y[i] += 180.0f;
			}
			else if (HitCabe1_3(i, &puzzle1, &puzzle3) == true)
			{
				puzzle1.pos_y[i] += 180.0f;
			}
			else if (puzzle1.pos_y[i] < 0.0f)
			{
				puzzle1.pos_y[i] += 180.0f;
			}
		}

		//下
		if (GetMousePos().X >= puzzle1.pos_x[i] + 40.0f && GetMousePos().X <= puzzle1.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle1.pos_y[i] + 140.0f && GetMousePos().Y <= puzzle1.pos_y[i] + 180.0f
			&& OnMouseDown(Left) == true)
		{

			puzzle1.pos_y[i] += 180.0f;

			if (HitCabe1_1(i, &puzzle1) == true)
			{
				puzzle1.pos_y[i] -= 180.0f;

			}
			else if (HitCabe1_2(i, &puzzle1, &puzzle2) == true)
			{
				puzzle1.pos_y[i] -= 180.0f;

			}
			else if (HitCabe1_3(i, &puzzle1, &puzzle3) == true)
			{
				puzzle1.pos_y[i] -= 180.0f;
			}
			else if (puzzle1.pos_y[i] + puzzle1.height > 1080.0f)
			{
				puzzle1.pos_y[i] -= 180.0f;
			}
		}
		//左
		if (GetMousePos().X >= puzzle1.pos_x[i] && GetMousePos().X <= puzzle1.pos_x[i] + 40.0f
			&& GetMousePos().Y >= puzzle1.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle1.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle1.pos_x[i] -= 180.0f;

			if (HitCabe1_1(i, &puzzle1) == true)
			{
				puzzle1.pos_x[i] += 180.0f;

			}
			else if (HitCabe1_2(i, &puzzle1, &puzzle2) == true)
			{
				puzzle1.pos_x[i] += 180.0f;

			}
			else if (HitCabe1_3(i, &puzzle1, &puzzle3) == true)
			{
				puzzle1.pos_x[i] += 180.0f;
			}
			else if (puzzle1.pos_x[i] < 0.0f)
			{
				puzzle1.pos_x[i] += 180.0f;
			}
		}
	
		//右
		if (GetMousePos().X >= puzzle1.pos_x[i] + 140.0f && GetMousePos().X <= puzzle1.pos_x[i] + 180.0f
			&& GetMousePos().Y >= puzzle1.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle1.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle1.pos_x[i] += 180.0f;

			if (HitCabe1_1(i, &puzzle1) == true)
			{
				puzzle1.pos_x[i] -= 180.0f;
			
			}
			else if (HitCabe1_2(i, &puzzle1, &puzzle2) == true)
			{
				puzzle1.pos_x[i] -= 180.0f;
				
			}
			else if (HitCabe1_3(i, &puzzle1, &puzzle3) == true)
			{
				puzzle1.pos_x[i] -= 180.0f;
			}
			else if (puzzle1.pos_x[i] + puzzle1.width > 1740.0f)
			{
				puzzle1.pos_x[i] -= 180.0f;
			}
		}
	}
#pragma endregion 


#pragma region 横長の操作
	for (int i = 0; i < 11; i++)
	{
		//上
		if (GetMousePos().X >= puzzle2.pos_x[i] + 40.0f && GetMousePos().X <= puzzle2.pos_x[i] + 320.0f
			&& GetMousePos().Y >= puzzle2.pos_y[i] && GetMousePos().Y <= puzzle2.pos_y[i] + 40.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle2.pos_y[i] -= 180.0f;

			if (HitCabe2_2(i, &puzzle2) == true)
			{
				
				puzzle2.pos_y[i] += 180.0f;

			} 
			else if (HitCabe2_1(i, &puzzle2, &puzzle1) == true)
			{
				puzzle2.pos_y[i] += 180.0f;

			}
			else if (HitCabe2_3(i, &puzzle2, &puzzle3) == true)
			{
				puzzle2.pos_y[i] += 180.0f;
			}
			else if (puzzle2.pos_y[i] < 0.0f)
			{
				puzzle2.pos_y[i] += 180.0f;
			}
		}
		//下
		if (GetMousePos().X >= puzzle2.pos_x[i] + 40.0f && GetMousePos().X <= puzzle2.pos_x[i] + 320.0f
			&& GetMousePos().Y >= puzzle2.pos_y[i] + 140.0f && GetMousePos().Y <= puzzle2.pos_y[i] + 180.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle2.pos_y[i] += 180.0f;

			if (HitCabe2_2(i, &puzzle2) == true)
			{

				puzzle2.pos_y[i] -= 180.0f;

			}
			else if (HitCabe2_1(i, &puzzle2, &puzzle1) == true)
			{
				puzzle2.pos_y[i] -= 180.0f;

			}
			else if (HitCabe2_3(i, &puzzle2, &puzzle3) == true)
			{
				puzzle2.pos_y[i] -= 180.0f;
			}
			else if (puzzle2.pos_y[i] + puzzle2.height > 1080.0f)
			{
				puzzle2.pos_y[i] -= 180.0f;
			}
		}
		//左
		if (GetMousePos().X >= puzzle2.pos_x[i] && GetMousePos().X <= puzzle2.pos_x[i] + 40.0f
			&& GetMousePos().Y >= puzzle2.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle2.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle2.pos_x[i] -= 180.0f;

			if (HitCabe2_2(i, &puzzle2) == true)
			{

				puzzle2.pos_x[i] += 180.0f;

			}
			else if (HitCabe2_1(i, &puzzle2, &puzzle1) == true)
			{
				puzzle2.pos_x[i] += 180.0f;

			}
			else if (HitCabe2_3(i, &puzzle2, &puzzle3) == true)
			{
				puzzle2.pos_x[i] += 180.0f;
			}
			else if (puzzle2.pos_x[i] < 0.0f)
			{
				puzzle2.pos_x[i] += 180.0f;
			}
		}
		//右
		if (GetMousePos().X >= puzzle2.pos_x[i] + 320.0f && GetMousePos().X <= puzzle2.pos_x[i] + 360.0f
			&& GetMousePos().Y >= puzzle2.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle2.pos_y[i] + 140.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle2.pos_x[i] += 180.0f;

			if (HitCabe2_2(i, &puzzle2) == true)
			{

				puzzle2.pos_x[i] -= 180.0f;

			}
			else if (HitCabe2_1(i, &puzzle2, &puzzle1) == true)
			{
				puzzle2.pos_x[i] -= 180.0f;

			}
			else if (HitCabe2_3(i, &puzzle2, &puzzle3) == true)
			{
				puzzle2.pos_x[i] -= 180.0f;
			}
			else if (puzzle2.pos_x[i] + puzzle2.width > 1740.0f)
			{
				puzzle2.pos_x[i] -= 180.0f;
			}

			if (puzzle2.pos_x[0] == 1260.0f && puzzle2.pos_y[0] == 360.0f && GetMousePos().X >= puzzle2.pos_x[0] + 320.0f && GetMousePos().X <= puzzle2.pos_x[0] + 360.0f
				&& GetMousePos().Y >= puzzle2.pos_y[0] + 40.0f && GetMousePos().Y <= puzzle2.pos_y[0] + 140.0f
				&& OnMouseDown(Left) == true)
			{
				puzzle2.key_flg = true;
			}
		}

	}
#pragma endregion 


#pragma region 縦長の操作
	for (int i = 0; i < 8; i++)
	{
		//上
		if (GetMousePos().X >= puzzle3.pos_x[i] + 40.0f && GetMousePos().X <= puzzle3.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle3.pos_y[i] && GetMousePos().Y <= puzzle3.pos_y[i] + 40.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle3.pos_y[i] -= 180.0f;

			if (HitCabe3_3(i, &puzzle3) == true)
			{
				puzzle3.pos_y[i] += 180.0f;

			}
			else if (HitCabe3_1(i, &puzzle3, &puzzle1) == true)
			{
				puzzle3.pos_y[i] += 180.0f;

			}
			else if (HitCabe3_2(i, &puzzle3, &puzzle2) == true)
			{
				puzzle3.pos_y[i] += 180.0f;
			}
			else if (puzzle3.pos_x[i] < 0.0f)
			{
				puzzle3.pos_x[i] += 180.0f;
			}
			else if (puzzle3.pos_y[i] < 0.0f)
			{
				puzzle3.pos_y[i] += 180.0f;
			}
		}

		//下
		if (GetMousePos().X >= puzzle3.pos_x[i] + 40.0f && GetMousePos().X <= puzzle3.pos_x[i] + 140.0f
			&& GetMousePos().Y >= puzzle3.pos_y[i] + 320.0f && GetMousePos().Y <= puzzle3.pos_y[i] + 360.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle3.pos_y[i] += 180.0f;

			if (HitCabe3_3(i, &puzzle3) == true)
			{

				puzzle3.pos_y[i] -= 180.0f;

			}
			else if (HitCabe3_1(i, &puzzle3, &puzzle1) == true)
			{
				puzzle3.pos_y[i] -= 180.0f;

			}
			else if (HitCabe3_2(i, &puzzle3, &puzzle2) == true)
			{
				puzzle3.pos_y[i] -= 180.0f;
			}
			else if (puzzle3.pos_y[i] + puzzle3.height > 1080.0f)
			{
				puzzle3.pos_y[i] -= 180.0f;
			}
		}
		//左
		if (GetMousePos().X >= puzzle3.pos_x[i] && GetMousePos().X <= puzzle3.pos_x[i] + 40.0f
			&& GetMousePos().Y >= puzzle3.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle3.pos_y[i] + 320.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle3.pos_x[i] -= 180.0f;

			if (HitCabe3_3(i, &puzzle3) == true)
			{

				puzzle3.pos_x[i] += 180.0f;

			}
			else if (HitCabe3_1(i, &puzzle3, &puzzle1) == true)
			{
				puzzle3.pos_x[i] += 180.0f;

			}
			else if (HitCabe3_2(i, &puzzle3, &puzzle2) == true)
			{
				puzzle3.pos_x[i] += 180.0f;
			}
			else if (puzzle3.pos_x[i] < 0.0f)
			{
				puzzle3.pos_x[i] += 180.0f;
			}
		}
		//右
		if (GetMousePos().X >= puzzle3.pos_x[i] + 140.0f && GetMousePos().X <= puzzle3.pos_x[i] + 180.0f
			&& GetMousePos().Y >= puzzle3.pos_y[i] + 40.0f && GetMousePos().Y <= puzzle3.pos_y[i] + 320.0f
			&& OnMouseDown(Left) == true)
		{
			puzzle3.pos_x[i] += 180.0f;

			if (HitCabe3_3(i, &puzzle3) == true)
			{

				puzzle3.pos_x[i] -= 180.0f;

			}
			else if (HitCabe3_1(i, &puzzle3, &puzzle1) == true)
			{
				puzzle3.pos_x[i] -= 180.0f;

			}
			else if (HitCabe3_2(i, &puzzle3, &puzzle2) == true)
			{
				puzzle3.pos_x[i] -= 180.0f;
			}
			else if (puzzle3.pos_x[i] + puzzle3.width > 1740.0f)
			{
				puzzle3.pos_x[i] -= 180.0f;
			}
		}
	}
#pragma endregion 

	//鍵がゴールした時
	if (puzzle2.key_flg == true)
	{
		puzzle2.pos_x[0] += 10.0f;
		if (puzzle2.pos_x[0] > 1920.0f)
		{
			next_flg.CleaFlg = true;

		}
	}
	
}