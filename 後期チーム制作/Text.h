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
	char timefont[20];      //文字
	int timecounter;		//1秒数える
	int onesecondscounter;	//1の単位
	int tensecondscounter;	//10の単位
	int oneminutecounter;	//1分の単位
	int tenminutecounter;	//10分の単位
	bool start;             
	bool end;				
};

typedef struct
{
	bool displaynext;        //各JK部屋移動時フラグ
	bool display_cleartext;	 //クリア画面時スチル描画フラグ
}DisplayData;


struct TextData
{
	char robot_text[1000];   //テキスト保存用
	char boyish_text[5000];		 //テキスト保存用
	char tundere_text[5000];		 //テキスト保存用
	char yuruhuwa_text[5000];		 //テキスト保存用

	char* robot_oneline;	 //1行目
	char* robot_twoline;	 //2行目
	char* robot_threeline;	 //3行目
							 
	char* boyish_oneline;		 //1行目
	char* boyish_twoline;		 //2行目
	char* boyish_threeline;		 //3行目
							 
	char* boyiah_lossoneline;	 //1行目(削除用)
	char* boyiah_losstwoline;	 //2行目(削除用)
	char* boyiah_lossthreeline;	 //3行目(削除用)

	char* tundere_oneline;		 //1行目
	char* tundere_twoline;		 //2行目
	char* tundere_threeline;	 //3行目
	
	char* tundere_lossoneline;	 //1行目(削除用)
	char* tundere_losstwoline;	 //2行目(削除用)
	char* tundere_lossthreeline; //3行目(削除用)

	char* yuruhuwa_oneline;		 //1行目
	char* yuruhuwa_twoline;		 //2行目
	char* yuruhuwa_threeline;	 //3行目

	char* yuruhuwa_lossoneline;	 //1行目(削除用)
	char* yuruhuwa_losstwoline;	 //2行目(削除用)
	char* yuruhuwa_lossthreeline;//3行目(削除用)
							 
	bool robot_nexttext;	 //最初のテキスト表示後続きを読み込むためのフラグ
	bool jk_nexttext;		 //最初のテキスト表示後続きを読み込むためのフラグ
};

typedef struct 
{
	float pos_x;
	float pos_y;

	int Choicepos;      //「はい」か「いいえ」かの座標
	bool decision_1;    //「はい」のとき
	bool decision_2;    //「いいえ」のとき

	int display;        //選択肢tex座標初期化用
	bool door_touch;	//ドアにアクションしたとき

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


