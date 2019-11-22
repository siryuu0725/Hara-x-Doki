#ifndef BG_
#define BG_

typedef struct
{
	float Tu, Tv;     //ムービー背景のTu,Tv
	float movespeed;  //ムービー背景の移動スピード
	int stopcount;    //背景の空き家を見せるときの止めている時間
}MovieBgData;

typedef struct
{
	bool searcharea1;     //大部屋にいるときtrue
	bool searcharea2;     //廊下にいるときtrue
	bool searchgamearea;  //女子高生部屋にいるときtrue
	bool cangearea;       //廊下と大部屋を移動するとき
	bool cangearea2;      //廊下と女子高生部屋を移動するとき

}SearchAreaData;

extern SearchAreaData areadata;
	
void InitBg();

void InitArea();

void DrawBg();

void DrawSearchBg();

void DrawTalkBg();

void UpDateBg();

#endif