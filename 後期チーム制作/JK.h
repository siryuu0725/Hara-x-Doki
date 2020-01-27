#ifndef JK_H
#define JK_H

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;

	bool unlock;        //足枷を外すフラグ
	bool areachange;    //部屋移動フラグ

	bool talk;          //会話時フラグ
	int talktype;       //会話種類
	bool clear;	        //クリア時フラグ
				        
	int heart;	        //好感度
	bool end;	        //大部屋から救出したとき
}Boyish;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;


	bool unlock;       //足枷を外すフラグ
	bool areachange;   //部屋移動フラグ

	int talktype;	   //会話時フラグ
	bool talk;		   //会話種類
	bool clear;		   //クリア時フラグ

	int heart;         //好感度
	bool end;		   //大部屋から救出したとき
}Yuruhuwa;

typedef struct
{
	float pos_x, pos_y;
	float tu, tv;
	float width;
	float height;
	                      
	bool unlock;         //足枷を外すフラグ
	bool areachange;     //部屋移動フラグ

	bool talk;		     //会話時フラグ
	int talktype;        //会話種類
			             
	bool clear;          //クリア時フラグ
	int heart;			 //好感度
	bool end;            //大部屋から救出したとき

}Tundere;				
						 
extern Boyish boyish;

extern Yuruhuwa yuruhuwa;

extern Tundere tundere;

void LoadCharacter();

//JK初期化
void InitBoyish();
void InitYuruhuwa();


//JK描画
void DrawBoyish();
void DrawYuruhuwa();


//JK会話描画
void DrawTalkYuruhuwa();
void DrawTalkBoyish();

void DrawTalkClearBoyish();   //クリア時
void DrawTalkClearYuruhuwa(); //クリア時

//次の会話へ移行
void UpDataBoyishTalk();
void UpDataYuruhuwaTalk();

void UpDataClearText();

#endif

