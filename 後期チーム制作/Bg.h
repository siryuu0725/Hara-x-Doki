#ifndef BG_
#define BG_

typedef struct
{
	float Tu, Tv;     //���[�r�[�w�i��Tu,Tv
	float movespeed;  //���[�r�[�w�i�̈ړ��X�s�[�h
	int stopcount;    //�w�i�̋󂫉Ƃ�������Ƃ��̎~�߂Ă��鎞��
}MovieBgData;

typedef struct
{
	bool searcharea1;     //�啔���ɂ���Ƃ�true
	bool searcharea2;     //�L���ɂ���Ƃ�true
	bool searchgamearea;  //���q���������ɂ���Ƃ�true
	bool cangearea;       //�L���Ƒ啔�����ړ�����Ƃ�
	bool cangearea2;      //�L���Ə��q�����������ړ�����Ƃ�

}SearchAreaData;

extern SearchAreaData areadata;
	
void InitBg();

void InitArea();

void DrawBg();

void DrawSearchBg();

void DrawTalkBg();

void UpDateBg();

#endif