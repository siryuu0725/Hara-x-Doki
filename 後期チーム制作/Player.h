#ifndef PLAYER_
#define PLAYER_

typedef struct
{
	float pos_x, pos_y;
	float Tu, Tv;
	float movespeed;
	int animetioncount;//�A�j���[�V�����̓����X�s�[�h
	int nextmoviecount;//�w�i���������̃J�E���g
	bool moveanimesion;//�w�i�������I������Ƃ��ɃA�j���[�V�����𓮂����p
	bool Bg_pos;//�w�i�𓮂����|�W�V�����ɗ��������p
}MoviePlayerDate;

typedef struct
{
	float pos_x, pos_y;
	float movespeed;
	float animetion_tu, animetion_tv;
	//float animetionmovespeed;
	int animetioncount;
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

void InitBackPlayer();

void DrawMoviePlayer();

void DrawSearchPlayer();

void DrawBackPlayer();

void UpDateMoviePlayer();

void SearchPlayerControl();

void Search2PlayerControl();

void UpDateBackPlayer(BackPlayerData*backplayer);
#endif
