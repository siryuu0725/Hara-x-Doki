#ifndef PLAYER_
#define PLAYER_

typedef struct
{
	float pos_x, pos_y;
	float Tu, Tv;
	float movespeed;
	int animetion_count;//�A�j���[�V�����̓����X�s�[�h
	int nextmoviecount;//�w�i���������̃J�E���g
	bool move_animesion;//�w�i�������I������Ƃ��ɃA�j���[�V�����𓮂����p
	bool Bg_pos;//�w�i�𓮂����|�W�V�����ɗ��������p
}MoviePlayerDate;

typedef struct
{
	float pos_x, pos_y;
}BackPlayerData;

extern MoviePlayerDate movieplayer;

extern BackPlayerData backplayer;

void InitPlayer();

void InitBackPlayer();

void DrawPlayer();

void DrawBackPlayer();

void UpDatePlayer();

void UpDateBackPlayer(BackPlayerData*backplayer);
#endif
