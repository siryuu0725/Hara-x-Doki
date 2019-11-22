#ifndef PLAYER_
#define PLAYER_

#define MOVIE_PLAYER_SPEED 2.65

typedef struct
{
	float pos_x, pos_y;
	float Tu, Tv;
	float movespeed;      //キャラの動くスピード
	int animetioncount;   //アニメーションの動くスピード
	int nextmoviecount;   //背景が動く時のカウント
	bool moveanimesion;   //背景が動き終わったときにアニメーションを動かす用
	bool Bg_pos;          //背景を動かすポジションに立った時用
}MoviePlayerDate;

typedef struct
{
	float pos_x, pos_y;
	float movespeed;                    //キャラの動くスピード
	float animetion_tu, animetion_tv;   //キャラのアニメーション座標
	//float animetionmovespeed;
	int animetioncount;                 //アニメーションスピード
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


#endif
