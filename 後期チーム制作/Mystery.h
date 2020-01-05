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

	float problemtextpos_x;
	float problemtextpos_y;


	bool choicetext;
	bool decisiontext;
	bool correctanswer;

}MysteryText;

extern MysteryText mysterytext;

void InitMysteryText();

void DrawMysteryBg();



void UpDataChoiceText();


#endif
