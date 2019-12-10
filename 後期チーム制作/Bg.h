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
	bool searcharea1;       //�啔���ɂ���Ƃ�true
	bool searcharea2;       //�L���ɂ���Ƃ�true
	bool searchcriminalarea;//�Ɛl�����ɂ���Ƃ�true
	bool searchgamearea;    //�{�[�C�b�V�������ɂ���Ƃ�true
	bool searchtunderearea; //�c���f�������ɂ���Ƃ�true
	bool searchyuruhuwaarea;//���ӂ핔���ɂ���Ƃ�true
	bool cangearea;         //�L���Ƒ啔�����ړ�����Ƃ�
	int cangearea2;        //�L���Ə��q�����������ړ�����Ƃ�

}SearchAreaData;

extern SearchAreaData areadata;
	
void InitMovieBg();

//�G���A�ړ��t���O�̏�����
void InitArea();

void DrawMovieBg();

void DrawSearch2Bg();

void DrawTundereBg();

void DrawYuruhuwaBg();

void DrawSearchBg();

void DrawCriminalBg();

void DrawTalkBg();

void UpDateBg();

#endif