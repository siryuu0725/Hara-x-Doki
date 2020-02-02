#ifndef MENU_
#define MENU_

typedef struct
{
	float pos_x, pos_y; // メニューのX座標とY座標
	bool onenterkey;    // ENTERキーを押したフラグ
}MenuData;              // メニュー構造体

extern MenuData menu;

void InitMenu();

void DrawMenu();

void UpDateMenu();

void Reset();
#endif