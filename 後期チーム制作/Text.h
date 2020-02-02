#ifndef TEXT_H_
#define TEXT_H_

#define TEXTBOX_POS_X 0
#define TEXTBOX_POS_Y 680

typedef struct
{
	float pos_x;
	float pos_y;
	bool onspacekey; //プレイヤーを止めるためのフラグ
}TextBoxData;

typedef struct
{
	bool scenario;
}ScenarioData;

struct Time
{
	char timefont[20];      //<!文字
	int timecounter;		//<!1秒数える
	int onesecondscounter;	//<!1の単位
	int tensecondscounter;	//<!10の単位
	int oneminutecounter;	//<!1分の単位
	int tenminutecounter;	//<!10分の単位
	bool start;             
	bool end;				
};

typedef struct
{
	int name_uicounter;
	bool displaynext;
	bool display_cleartext;
}DisplayData;


struct TextData
{
	char robot_text[1000];
	char jk_text[5000];
	char* robot_oneline;
	char* robot_twoline;
	char* robot_threeline;

	char* jk_oneline;
	char* jk_twoline;
	char* jk_threeline;

	char* jk_lossoneline;
	char* jk_losstwoline;
	char* jk_lossthreeline;

	bool robot_nexttext;
	bool jk_nexttext;
};

typedef struct 
{
	float pos_x;
	float pos_y;

	int Choicepos;
	bool decision_1;
	bool decision_2;

	int display;
	bool door_touch;

}ChoiceTextureData;

extern TextBoxData textbox;

extern Time time;

extern DisplayData displaydata;

extern TextData textdata;

extern ChoiceTextureData choicetexturedata;

void LoadUI();

void InitTextBox();



void InitTimeCounter();

void DrawTime();

void InitScenario();

void DrawScenario();




void UpDataDescriptionText();

void InitChoiceTexture();

void DrawChoiceTexture();

#endif


