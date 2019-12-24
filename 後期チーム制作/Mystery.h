#ifndef MYSTERY_H
#define MYSTERY_H

typedef struct
{
	int text[5][12];
	int textcount;

	float textpos_x;
	float textpos_y;
	float textwidth;
	float textheight;

	float textboxpos_x;
	float textboxpos_y;
	float textboxwidth;
	float textboxheight;

	bool choicetext;
	bool decisiontext;
}MysteryText;

extern MysteryText mysterytext;

void InitMysteryText();

void DrawMysteryBg();

void DrawMysteryChoiceText();


void UpDataChoiceText();


#endif
