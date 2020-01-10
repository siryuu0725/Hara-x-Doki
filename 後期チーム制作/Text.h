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

typedef struct
{
	int displaytimecounter;
}DisplayTimeData;


struct TextData
{
	char text[256];
	char* oneline;
	char* twoline;
	char* threeline;
	bool nexttext;
};

typedef struct 
{
	float pos_x;
	float pos_y;

	int Choicepos;
	bool decision;
}ChoiceTextureData;

extern TextBoxData textbox;

extern Time time;

extern DisplayTimeData displaytimedata;

extern TextData textdata;

extern ChoiceTextureData choicetexturedata;

void LoadUI();

void InitTextBox();

void DrawTextBox();

void DrawTalkObject(bool* touchobject, bool* tolkobject, char* text);

void InitTimeCounter();

void DrawTime();

void InitScenario();

void DrawScenario();

//void InitLoadFile(char* file);

void InitLoadFile2();

void LoadText();

void DrawTalkText();

void UpDataText();

void InitChoiceTexture();

void DrawChoiceTexture();
#endif


