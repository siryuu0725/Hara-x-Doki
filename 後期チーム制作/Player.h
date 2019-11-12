#ifndef PLAYER_
#define PLAYER_

typedef struct
{
	float pos_x, pos_y;
	float Tu, Tv;
	float movespeed;
	bool moveflg;
	bool Bgflg;
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
