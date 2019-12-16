#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	bool maid;         //ロボ
	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool flowerpot;     //植木鉢

}SearchTouchObject;

typedef struct
{
	bool robot;         //ロボ
	bool robotneck;     //ロボの頭
	bool completerobot; //ロボ完成形
	bool light;         //ライト


	bool desk;          //机
	bool chair;         //椅子
	bool doll;          //人形
	bool bed;           //ベッド
	bool flowerpot;     //植木鉢
	bool closet;        //クローゼット
	bool bookshelf;     //本棚

}SearchGameTouchObject;

typedef struct
{
	bool robot;         //ロボ
	bool yuruhuwa;

	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool doll;          //人形
	bool bed;           //ベッド
	bool flowerpot;     //植木鉢
	bool closet;        //クローゼット
	bool bookshelf;     //本棚

}YuruhuwaTouchObject;

typedef struct
{
	bool robot;         //ロボ

	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool doll;          //人形
	bool bed;           //ベッド
	bool flowerpot;     //植木鉢
	bool closet;        //クローゼット
	bool bookshelf;     //本棚

}TundereTouchObject;


typedef struct
{
	bool itemrobot;   //ロボの首
	bool itemkey;     //鍵
	bool itemenergy;  //電池
	bool itemlight;   //ライト
	bool boyishdoorkey;
	bool yuruhuwadoorkey;
	bool tunderedoorkey;
	bool breakdoorkey;

}GetItem;

extern SearchTouchObject searchobject;

extern SearchGameTouchObject searchgameobject;

extern YuruhuwaTouchObject yuruhuwaobject;

extern TundereTouchObject tundereobject;

extern GetItem getitem;



void InitSearchGameObject();

void InitTundereRoomObject();

void InitYuruhuwaRoomObject();

void LoadSearchGameItem();

void DrawRobotNeck();


/*
   それぞれの部屋の家具Tex
*/
void LoadSearch2FurnitureTex();

void LoadTundereFurnitureTex();

void LoadYuruhuwaFurnitureTex();

void LoadCriminalFurnitureTex();


/*
　　探索パートでのオブジェクトとのあたり判定
　　矩形と矩形のあたり判定
*/
void HitSearchObject();

void HitSearch2Object();

void HitTundereRoomObject();

void HitYuruhuwaRoomObject();

void HitCriminalRoomObject();

/*
　　探索ゲームでのオブジェクトとのあたり判定
　　矩形と矩形のあたり判定
*/
void HitSearchGameObject();


/*
　　探索パートでのプレイヤーとがアクションを起こすときの
  　オブジェクトとの視覚のあたり判定
　　矩形と矩形のあたり判定
*/
void HitEyeSearchObject();


/*
　　探索ゲームでのプレイヤーとがアクションを起こすときの
  　オブジェクトとの視覚のあたり判定
　　矩形と矩形のあたり判定
*/
void HitEyeSearchGameObject();

void HitEyeTundereRoomObject();

void HitEyeYuruhuwaRoomObject();

void HitEyeCriminalRoomObject();


void UpDataSearchGame();

#endif

