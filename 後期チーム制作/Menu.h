#ifndef MENU_
#define MENU_

typedef struct
{
	float pos_x, pos_y; // ���j���[��X���W��Y���W
	bool onenterkey;    // ENTER�L�[���������t���O
}MenuData;              // ���j���[�\����

extern MenuData menu;

void InitMenu();

void DrawMenu();

void UpDateMenu();

void Reset();
#endif