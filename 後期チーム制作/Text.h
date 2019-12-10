#ifndef TEXT_H_
#define TEXT_H_

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
};

extern TextBoxData textbox;

extern Time time;

void InitTextBox();

void DrawTextBox();

void InitTimeCounter();

void DrawTime();


void DrawTxt();
#endif


