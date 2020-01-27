#ifndef JK_H
#define JK_H

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool unlock;        //���g���O���t���O
	bool areachange;    //�����ړ��t���O

	bool talk;          //��b���t���O
	int talktype;       //��b���
	bool clear;	        //�N���A���t���O
				        
	int heart;	        //�D���x
	bool end;	        //�啔������~�o�����Ƃ�
}Boyish;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;


	bool unlock;       //���g���O���t���O
	bool areachange;   //�����ړ��t���O

	int talktype;	   //��b���t���O
	bool talk;		   //��b���
	bool clear;		   //�N���A���t���O

	int heart;         //�D���x
	bool end;		   //�啔������~�o�����Ƃ�
}Yuruhuwa;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;
	                      
	bool unlock;         //���g���O���t���O
	bool areachange;     //�����ړ��t���O

	bool talk;		     //��b���t���O
	int talktype;        //��b���
			             
	bool clear;          //�N���A���t���O
	int heart;			 //�D���x
	bool end;            //�啔������~�o�����Ƃ�

}Tundere;				
						 
extern Boyish boyish;

extern Yuruhuwa yuruhuwa;

extern Tundere tundere;

void LoadCharacter();

//JK������
void InitBoyish();
void InitYuruhuwa();


//JK�`��
void DrawBoyish();
void DrawYuruhuwa();


//JK��b�`��
void DrawTalkYuruhuwa();
void DrawTalkBoyish();

void DrawTalkClearBoyish();   //�N���A��
void DrawTalkClearYuruhuwa(); //�N���A��

//���̉�b�ֈڍs
void UpDataBoyishTalk();
void UpDataYuruhuwaTalk();

void UpDataClearText();

#endif

