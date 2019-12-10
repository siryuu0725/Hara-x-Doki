#ifndef JK_H
#define JK_H

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool talk;
}Boyish;


extern Boyish boyish;


void InitBoyish();

void DrawBoyish();

#endif

