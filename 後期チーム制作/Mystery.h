#ifndef MYSTERY_H
#define MYSTERY_H

typedef struct
{
	int text[5][11];
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

typedef struct
{
	float pos_x;
	float pos_y;
	float width;
	float height;
	bool push;
}DecisionButton;

typedef struct
{
	float pos_x;
	float pos_y;
	float width;
	float height;

	bool correct;

}ProblemData;

extern MysteryText mysterytext;

extern DecisionButton decisionbutton;

extern ProblemData problemdata;


void InitMysteryText();

void InitDecisionButton();

void DrawMysteryBg();



void UpDataChoiceText();


#endif
