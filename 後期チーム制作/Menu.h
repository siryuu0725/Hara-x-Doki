#ifndef MENU_
#define MENU_

typedef struct
{
	float pos_x, pos_y; // ���j���[��X���W��Y���W
	bool onenterkey; // ENTER�L�[���������t���O
}MenuData; // ���j���[�\����

void InitMenu();

void DrawMenu();

void UpDateMenu();
#endif