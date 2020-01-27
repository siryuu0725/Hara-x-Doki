#ifndef BG_
#define BG_

//�^�C�g���p
typedef struct
{
	bool choicestart;
	bool choiceend;
	bool choicelist;

}TitleBgData;

//���[�r�[�p
typedef struct
{
	float Tu, Tv;     //���[�r�[�w�i��Tu,Tv
	float movespeed;  //���[�r�[�w�i�̈ړ��X�s�[�h
	int stopcount;    //�w�i�̋󂫉Ƃ�������Ƃ��̎~�߂Ă��鎞��

	bool endmovie;

}MovieBgData;

//�����ړ����̃t���O
typedef struct
{
	bool largeroom;       //�啔���ɂ���Ƃ�true
	bool corridor;       //�L���ɂ���Ƃ�true
	bool searchcriminalarea;//�Ɛl�����ɂ���Ƃ�true
	bool searchgamearea;    //�{�[�C�b�V�������ɂ���Ƃ�true
	bool searchtunderearea; //�c���f�������ɂ���Ƃ�true
	bool searchyuruhuwaarea;//���ӂ핔���ɂ���Ƃ�true
	bool cleararea;

	bool cangearea;         //�L���Ƒ啔�����ړ�����Ƃ�
	int cangearea2;        //�L���Ə��q�����������ړ�����Ƃ�

}SearchAreaData;

extern MovieBgData moviebgdate;

extern SearchAreaData areadata;

extern TitleBgData titlebg;
	
void InitMovieBg();

//�G���A�ړ��t���O�̏�����
void InitArea();

void DrawTitleBg();

void DrawMovieBg();

//�w�i�܂Ƃ�
void DrawSearchBg();


//�L��
void DrawCorridorBg();

//�c���f������
void DrawTundereBg();

//���ӂ�
void DrawYuruhuwaBg();


//�Ɛl����
void DrawCriminalBg();

void DrawTalkBg();

void UpDateBg();

void GameClearBg();

#endif