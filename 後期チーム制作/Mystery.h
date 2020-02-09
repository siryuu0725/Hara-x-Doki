#ifndef MYSTERY_H
#define MYSTERY_H

typedef struct
{
	int text[5][11];
	int textcount;

    //�����������\
	float textpos_x;
	float textpos_y;
	float textwidth;
	float textheight;

    //�����������\�w�i
	float textboxpos_x;
	float textboxpos_y;
	float textboxwidth;
	float textboxheight;

    //��蕶
	float problemtextpos_x;
	float problemtextpos_y;

	float problemanswer_x;
	float problemanswer_y;

    //1������
	float one_text_tu;
	float one_text_tv;
    //2������
	float two_text_tu;
	float two_text_tv;
    //3������
	float three_text_tu;
	float three_text_tv;
    //4������
	float four_text_tu;
	float four_text_tv;
    //5������
	float five_text_tu;
	float five_text_tv;

	//���̕����Ɉڍs
	int nexttext;

	//�I��
	bool choicetext;
	bool decisiontext;
	bool correctanswer;

	bool oneproblem;
	bool twoproblem;



}MysteryText;

typedef struct
{
	float decisionpos_x;
	float decisionpos_y;
	float decisionwidth;
	float decisionheight;

	float deletepos_x;
	float deletepos_y;
	float deletewidth;
	float deleteheight;

	bool push;
}Button;

typedef struct
{
	float pos_x;
	float pos_y;
	float width;
	float height;

	bool correct;

}ProblemData;

extern MysteryText mysterytext;

extern Button button;

extern ProblemData problemdata;


void InitMysteryText();

void InitButton();

void DrawMysteryBg();

void UpDataChoiceText();

void UpDataChoiceText();


#endif
