#ifndef TEXT_H_
#define TEXT_H_

#define TEXTBOX_POS_X 0
#define TEXTBOX_POS_Y 680

typedef struct
{
	float pos_x;
	float pos_y;
	bool onspacekey;
}TextBoxData;

struct Time
{
	char timefont[20];
	int timecounter;
	int onesecondscounter;
	int tensecondscounter;
	int oneminutecounter;
	int tenminutecounter;
	bool start;
	bool end;
};

extern TextBoxData textbox;

extern Time time;

void InitTextBox();

void DrawTextBox();

void InitTimeCounter();

void DrawTime();


void DrawTxt();
#endif


