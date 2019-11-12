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

#pragma region �����`������
	puzzle.square_width = 180.0f;
	puzzle.square_height = 180.0f;

	puzzle.pos_x[0] = 0.0f, puzzle.pos_y[0] = 360.0f;
	puzzle.pos_x[1] = 0.0f, puzzle.pos_y[1] = 900.0f;
	puzzle.pos_x[2] = 360.0f, puzzle.pos_y[2] = 900.0f;
	puzzle.pos_x[3] = 540.0f, puzzle.pos_y[3] = 360.0f;
	puzzle.pos_x[4] = 540.0f, puzzle.pos_y[4] = 720.0f;
	puzzle.pos_x[5] = 1080.0f, puzzle.pos_y[5] = 900.0f;
	puzzle.pos_x[6] = 1260.0f, puzzle.pos_y[6] = 180.0f;
	puzzle.pos_x[7] = 1260.0f, puzzle.pos_y[7] = 360.0f;
	puzzle.pos_x[8] = 1260.0f, puzzle.pos_y[8] = 900.0f;
#pragma endregion	

#pragma region �����ƌ�������
	puzzle.Landscape_width = 360.0f;
	puzzle.Landscape_height = 180.0f;
	puzzle.goal_key = false;

	puzzle.pos_x[9] = 0.0f, puzzle.pos_y[9] = 180.0f;
	puzzle.pos_x[10] = 0.0f, puzzle.pos_y[10] = 0.0f;
	puzzle.pos_x[11] = 180.0f, puzzle.pos_y[11] = 720.0f;
	puzzle.pos_x[12] = 360.0f, puzzle.pos_y[12] = 540.0f;
	puzzle.pos_x[13] = 540.0f, puzzle.pos_y[13] = 0.0f;
	puzzle.pos_x[14] = 540.0f, puzzle.pos_y[14] = 180.0f;
	puzzle.pos_x[15] = 720.0f, puzzle.pos_y[15] = 360.0f;
	puzzle.pos_x[16] = 720.0f, puzzle.pos_y[16] = 900.0f;
	puzzle.pos_x[17] = 1080.0f, puzzle.pos_y[17] = 0.0f;
	puzzle.pos_x[18] = 1080.0f, puzzle.pos_y[18] = 540.0f;
	puzzle.pos_x[19] = 1260.0f, puzzle.pos_y[19] = 720.0f;
#pragma endregion	

#pragma region �c��������
	puzzle.Portrait_width = 180.0f;
	puzzle.Portrait_height = 360.0f;

	puzzle.pos_x[20] = 0.0f, puzzle.pos_y[20] = 540.0f;
	puzzle.pos_x[21] = 180.0f, puzzle.pos_y[21] = 360.0f;
	puzzle.pos_x[22] = 360.0f, puzzle.pos_y[22] = 0.0f;
	puzzle.pos_x[23] = 720.0f, puzzle.pos_y[23] = 540.0f;
	puzzle.pos_x[24] = 900.0f, puzzle.pos_y[24] = 0.0f;
	puzzle.pos_x[25] = 900.0f, puzzle.pos_y[25] = 540.0f;
	puzzle.pos_x[26] = 1080.0f, puzzle.pos_y[26] = 180.0f;
	puzzle.pos_x[27] = 1440.0f, puzzle.pos_y[27] = 360.0f;
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
		DrawTexture(puzzle.pos_x[i], puzzle.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::Puzzle1));
	}
	for (int i = 10; i < 20; i++)
	{
		DrawTexture(puzzle.pos_x[i], puzzle.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::Puzzle2));
	}
	DrawTexture(puzzle.pos_x[9], puzzle.pos_y[9], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::PuzzleKey));
	for (int i = 20; i < 28; i++)
	{
		DrawTexture(puzzle.pos_x[i], puzzle.pos_y[i], GetTexture(TEXTURE_PUZZLE, PuzzleGameCategoryTextureList::Puzzle3));
	}
}


void UpDatePuzzle()
{
#pragma region �����`�̑���
	for (int i = 0; i < 9; i++)
	{
		//��
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

		//��
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
		//��
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
			else if (puzzle.pos_x[i] < 0.0f)
			{
				puzzle.pos_x[i] += 180.0f;
			}
		}

		//�E
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
			else if (puzzle.pos_x[i] + puzzle.square_width > 1740.0f)
			{
				puzzle.pos_x[i] -= 180.0f;
			}
		}
	}
#pragma endregion 


#pragma region �����̑���
	for (int i = 9; i < 20; i++)
	{
		//��
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
		//��
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
		//��
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
			else if (puzzle.pos_x[i] < 0.0f)
			{
				puzzle.pos_x[i] += 180.0f;
			}
		}
		//�E
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
			else if (puzzle.pos_x[i] + puzzle.Landscape_width > 1740.0f)
			{
				puzzle.pos_x[i] -= 180.0f;
			}

			if (puzzle.pos_x[9] == 1260.0f && puzzle.pos_y[9] == 360.0f && GetMousePos().X >= puzzle.pos_x[9] + 320.0f && GetMousePos().X <= puzzle.pos_x[9] + 360.0f
				&& GetMousePos().Y >= puzzle.pos_y[9] + 40.0f && GetMousePos().Y <= puzzle.pos_y[9] + 140.0f
				&& OnMouseDown(Left) == true)
			{
				puzzle.goal_key = true;
			}
		}

	}
#pragma endregion 


#pragma region �c���̑���
	for (int i = 20; i < 28; i++)
	{
		//��
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

		//��
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

		//��
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
			else if (puzzle.pos_x[i] < 0.0f)
			{
				puzzle.pos_x[i] += 180.0f;
			}
		}
		//�E
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
			else if (puzzle.pos_x[i] + puzzle.Portrait_width > 1740.0f)
			{
				puzzle.pos_x[i] -= 180.0f;
			}
		}
	}
#pragma endregion 

	//�����S�[��������
	if (puzzle.goal_key == true)
	{
		puzzle.pos_x[9] += 10.0f;
		if (puzzle.pos_x[9] > 1920.0f)
		{
			nextcene.Clea = true;
		}
	}

}