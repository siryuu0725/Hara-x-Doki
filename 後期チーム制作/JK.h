#ifndef JK_H
#define JK_H

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool unlock;
	bool areachange;

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
	bool unlock;

	bool areachange;

	int talktype;
	bool talk;
	bool clear;
	int heart;

	bool end;
}Yuruhuwa;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool areachange;

	int talktype;

	bool talk;
	bool clear;
	int heart;
}Tundere;

extern Boyish boyish;

extern Yuruhuwa yuruhuwa;

extern Tundere tundere;

void LoadCharacter();

void InitBoyish();


void InitYuruhuwa();

void DrawBoyish();

void DrawYuruhuwa();

void DrawTalkYuruhuwa();

void DrawTalkBoyish();

void UpDataBoyishTalk();

void UpDataYuruhuwaTalk();

void DrawTalkClearBoyish();

void DrawTalkClearYuruhuwa();

void UpDataClearText();

#endif

