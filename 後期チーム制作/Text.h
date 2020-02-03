#ifndef TEXT_H_
#define TEXT_H_

#define TEXTBOX_POS_X 0
#define TEXTBOX_POS_Y 680

typedef struct
{
	float pos_x;
	float pos_y;
	bool onspacekey; //�v���C���[���~�߂邽�߂̃t���O
}TextBoxData;

typedef struct
{
	bool scenario;
}ScenarioData;

struct Time
{
	char timefont[20];      //����
	int timecounter;		//1�b������
	int onesecondscounter;	//1�̒P��
	int tensecondscounter;	//10�̒P��
	int oneminutecounter;	//1���̒P��
	int tenminutecounter;	//10���̒P��
	bool start;             
	bool end;				
};

typedef struct
{
	bool displaynext;        //�eJK�����ړ����t���O
	bool display_cleartext;	 //�N���A��ʎ��X�`���`��t���O
}DisplayData;


struct TextData
{
	char robot_text[1000];   //�e�L�X�g�ۑ��p
	char jk_text[5000];		 //�e�L�X�g�ۑ��p
	char* robot_oneline;	 //1�s��
	char* robot_twoline;	 //2�s��
	char* robot_threeline;	 //3�s��
							 
	char* jk_oneline;		 //1�s��
	char* jk_twoline;		 //2�s��
	char* jk_threeline;		 //3�s��
							 
	char* jk_lossoneline;	 //1�s��(�폜�p)
	char* jk_losstwoline;	 //2�s��(�폜�p)
	char* jk_lossthreeline;	 //3�s��(�폜�p)
							 
	bool robot_nexttext;	 //�ŏ��̃e�L�X�g�\���㑱����ǂݍ��ނ��߂̃t���O
	bool jk_nexttext;		 //�ŏ��̃e�L�X�g�\���㑱����ǂݍ��ނ��߂̃t���O
};

typedef struct 
{
	float pos_x;
	float pos_y;

	int Choicepos;      //�u�͂��v���u�������v���̍��W
	bool decision_1;    //�u�͂��v�̂Ƃ�
	bool decision_2;    //�u�������v�̂Ƃ�

	int display;        //�I����tex���W�������p
	bool door_touch;	//�h�A�ɃA�N�V���������Ƃ�

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


