#ifndef JK_H
#define JK_H

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool talk;
	bool clear;
}Boyish;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool talk;
	bool clear;
}Yuruhuwa;

extern Boyish boyish;

extern Yuruhuwa yuruhuwa;

void InitBoyish();

void InitYuruhuwa();

void DrawBoyish();

void DrawYuruhuwa();

void DrawTalkYuruhuwa();
#endif

