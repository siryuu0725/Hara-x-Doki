#ifndef PLAYER_
#define PLAYER_

#define MOVIE_PLAYER_SPEED 2.65
#define PLAYER_WIDTH 64.0f
#define PLAYER_HEIGHT 128.0f


typedef struct
{
	float pos_x, pos_y;
	float Tu, Tv;
	float movespeed;      //�L�����̓����X�s�[�h
	int animetioncount;   //�A�j���[�V�����̓����X�s�[�h
	int nextmoviecount;   //�w�i���������̃J�E���g
	bool moveanimesion;   //�w�i�������I������Ƃ��ɃA�j���[�V�����𓮂����p
	bool Bg_pos;          //�w�i�𓮂����|�W�V�����ɗ��������p
}MoviePlayerDate;

typedef struct
{
	float pos_x, pos_y;
	float oldpos_x, oldpos_y;           //�v���C���[�̂����蔻�莞�p�̑O�̈ʒu
	float eyepos_x, eyepos_y;           //�v���C���[�̎��o�̈ʒu
	float movespeed;                    //�L�����̓����X�s�[�h
	float animetion_tu, animetion_tv;   //�L�����̃A�j���[�V�������W
	int animetioncount;                 //�A�j���[�V�����X�s�[�h
	bool hit;                           //�v���C���[�ƃI�u�W�F�N�g�̂����蔻��t���O
	bool eyehit;                        //�v���C���[�̎��o�ƃI�u�W�F�N�g�̂����蔻��t���O
	
}SearchPlayerData;

typedef struct
{
	float pos_x, pos_y;
}BackPlayerData;

extern MoviePlayerDate movieplayer;

extern SearchPlayerData searchplayer;

extern BackPlayerData backplayer;

#pragma region �v���C���[�̏�����
void InitMoviePlayer();

void InitLargeRoomPlayer();

void InitCorridorPlayer();

void InitGameRoomPlayer();

void InitCriminalPlayer();

void InitBackPlayer();
#pragma endregion

#pragma region �v���C���[�̕`��
void DrawMoviePlayer();

void DrawSearchPlayerAndRobot();

void DrawBackPlayer();
#pragma endregion

#pragma region �v���C���[�̋���
void UpDateMoviePlayer();

void SearchPlayerControl(float upmax, float downmax, float leftmax, float rightmax);

void UpDataPlayerPos();
#pragma endregion

#endif
