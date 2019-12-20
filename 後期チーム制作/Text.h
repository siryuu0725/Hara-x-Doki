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

typedef struct
{
	bool scenario;
}ScenarioData;

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

struct TextData
{
	char text[256];
	char* oneline;
	char* twoline;
	char* threeline;
	bool nexttext;
};

extern TextBoxData textbox;

extern Time time;

extern TextData textdata;

void LoadUI();

void InitTextBox();

void DrawTextBox();

void InitTimeCounter();

void DrawTime();

void InitScenario();

void DrawScenario();

void InitLoadFile();

void LoadText();

void DrawTalkText();
#endif


