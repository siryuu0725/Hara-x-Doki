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
	bool searcharea1;       //大部屋にいるときtrue
	bool searcharea2;       //廊下にいるときtrue
	bool searchcriminalarea;//犯人部屋にいるときtrue
	bool searchgamearea;    //ボーイッシュ部屋にいるときtrue
	bool searchtunderearea; //ツンデレ部屋にいるときtrue
	bool searchyuruhuwaarea;//ゆるふわ部屋にいるときtrue
	bool cangearea;         //廊下と大部屋を移動するとき
	int cangearea2;        //廊下と女子高生部屋を移動するとき

}SearchAreaData;

extern SearchAreaData areadata;
	
void InitMovieBg();

//エリア移動フラグの初期化
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