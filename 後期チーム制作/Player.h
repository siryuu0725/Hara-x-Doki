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
	float oldpos_x, oldpos_y;
	float movespeed;                    //�L�����̓����X�s�[�h
	float animetion_tu, animetion_tv;   //�L�����̃A�j���[�V�������W
	int animetioncount;                 //�A�j���[�V�����X�s�[�h
	bool hit;
}SearchPlayerData;

typedef struct
{
	float pos_x, pos_y;
}BackPlayerData;

extern MoviePlayerDate movieplayer;

extern SearchPlayerData searchplayer;

extern BackPlayerData backplayer;

void InitMoviePlayer();

void InitSearchPlayer();

void InitSearch2Player();

void InitSearchGamePlayer();

void InitBackPlayer();

void DrawMoviePlayer();

void DrawSearchPlayer();

void DrawBackPlayer();

void UpDateMoviePlayer();

void SearchPlayerControl(float upmax, float downmax, float leftmax, float rightmax);

void UpDataPlayerPos();

#endif
