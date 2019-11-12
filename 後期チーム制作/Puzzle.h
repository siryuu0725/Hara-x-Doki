#ifndef PUZZLE_
#define PUZZLE_

typedef struct
{
	bool CleaFlg;
}NextCeneFlg;

typedef struct
{
	float pos_x[9];
	float pos_y[9];
	float width;
	float height;

}Puzzle_1;


typedef struct
{
	float pos_x[11];
	float pos_y[11];
	float width;
	float height;
	bool key_flg;
	
}Puzzle_2;



typedef struct
{
	float pos_x[8];
	float pos_y[8];
	float width;
	float height;

}Puzzle_3;

extern NextCeneFlg next_flg;
extern Puzzle_1 puzzle1;
extern Puzzle_2 puzzle2;
extern Puzzle_3 puzzle3;


void InitPuzzle();

void DrawBgPuzzle();


void DrawPuzzle();

void UpDatePuzzle();


#endif