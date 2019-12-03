#ifndef TEXT_H_
#define TEXT_H_

typedef struct
{
	float pos_x;
	float pos_y;
	bool onspacekey;
}TextBoxData;

extern TextBoxData textbox;

void InitTextBox();

void DrawTextBox();

#endif


