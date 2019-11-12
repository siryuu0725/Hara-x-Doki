#ifndef PLAYER_
#define PLAYER_

typedef struct
{
	float pos_x, pos_y;
	float Tu, Tv;
	float movespeed;
	int animetion_count;//アニメーションの動くスピード
	int nextmoviecount;//背景が動く時のカウント
	bool move_animesion;//背景が動き終わったときにアニメーションを動かす用
	bool Bg_pos;//背景を動かすポジションに立った時用
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
