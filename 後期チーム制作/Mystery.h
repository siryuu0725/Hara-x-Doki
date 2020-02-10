#ifndef MYSTERY_H
#define MYSTERY_H

typedef struct
{
	int text[5][11];
	int textcount;

    //あいうえお表
	float textpos_x;
	float textpos_y;
	float textwidth;
	float textheight;

    //あいうえお表背景
	float textboxpos_x;
	float textboxpos_y;
	float textboxwidth;
	float textboxheight;

    //問題文
	float problemtextpos_x;
	float problemtextpos_y;

	float problemanswer_x;
	float problemanswer_y;

    //1文字目
	float one_text_tu;
	float one_text_tv;

	int one_text;
    //2文字目
	float two_text_tu;
	float two_text_tv;

	int two_text;
    //3文字目
	float three_text_tu;
	float three_text_tv;

	int three_text;
    //4文字目
	float four_text_tu;
	float four_text_tv;

	int four_text;

    //5文字目
	float five_text_tu;
	float five_text_tv;

	int five_text;


	//次の文字に移行
	int nexttext;

	//選択
	bool choicetext;
	

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

	bool correct_answer;

	bool decisiontext;
	bool answer;

	int counter;

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

void DrawMysteryAnswerBg();

void UpDataChoiceText();

void UpDataChoiceText();

void UpdataDecision();

void UpdataDelete();


#endif
