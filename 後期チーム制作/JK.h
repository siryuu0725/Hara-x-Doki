#ifndef JK_H
#define JK_H

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool talk;
	int talktype;
	bool clear;

	int heart;
	bool end;
}Boyish;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool talk;
	bool clear;
	int heart;
}Yuruhuwa;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool talk;
	bool clear;
	int heart;
}Tundere;

extern Boyish boyish;

extern Yuruhuwa yuruhuwa;

extern Tundere tundere;

void InitBoyish();

void InitYuruhuwa();

void DrawBoyish();

void DrawYuruhuwa();

void DrawTalkYuruhuwa();

void DrawTalkBoyish();

void UpDataBoyishTalk();

void UpDataYuruhuwaTalk();

void DrawTalkClearBoyish();

void UpDataClearText();

#endif

