#ifndef BG_
#define BG_

//タイトル用
typedef struct
{
	bool choicestart;
	bool choiceend;
	bool choicelist;

}TitleBgData;

//ムービー用
typedef struct
{
	float Tu, Tv;     //ムービー背景のTu,Tv
	float movespeed;  //ムービー背景の移動スピード
	int stopcount;    //背景の空き家を見せるときの止めている時間

	bool endmovie;

}MovieBgData;

//部屋移動時のフラグ
typedef struct
{
	bool largeroom;       //大部屋にいるときtrue
	bool corridor;       //廊下にいるときtrue
	bool searchcriminalarea;//犯人部屋にいるときtrue
	bool searchgamearea;    //ボーイッシュ部屋にいるときtrue
	bool searchtunderearea; //ツンデレ部屋にいるときtrue
	bool searchyuruhuwaarea;//ゆるふわ部屋にいるときtrue
	bool cleararea;

	bool cangearea;         //廊下と大部屋を移動するとき
	int cangearea2;        //廊下と女子高生部屋を移動するとき

}SearchAreaData;

extern MovieBgData moviebgdate;

extern SearchAreaData areadata;

extern TitleBgData titlebg;
	
void InitMovieBg();

//エリア移動フラグの初期化
void InitArea();

void DrawTitleBg();

void DrawMovieBg();

//背景まとめ
void DrawSearchBg();


//廊下
void DrawCorridorBg();

//ツンデレ部屋
void DrawTundereBg();

//ゆるふわ
void DrawYuruhuwaBg();


//犯人部屋
void DrawCriminalBg();

void DrawTalkBg();

void UpDateBg();

void GameClearBg();

#endif