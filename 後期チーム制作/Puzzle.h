#ifndef PUZZLE_
#define PUZZLE_

typedef struct
{
	bool Clea;
}NextCene;

typedef struct
{
	float pos_x[28];
	float pos_y[28];
	//正方形
	float square_width;
	float square_height;
	//横長
	float Landscape_width;
	float Landscape_height;
	//縦長
	float Portrait_width;
	float Portrait_height;

	bool goal_key;//キーブロック
	float move_speed;

}PuzzleCabe;

extern NextCene nextcene;
extern PuzzleCabe puzzle;


void InitPuzzle();

void DrawBgPuzzle();


void DrawPuzzle();

void UpDatePuzzle();


#endif