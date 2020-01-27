#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	bool maid;          //メイドロボ
	bool boyish;        //ボーイッシュ
	bool tundere;       //ツンデレ
	bool yuruhuwa;      //ゆるふわ

	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool flowerpot;     //植木鉢
	bool sofa;          //ソファ
	bool clock;			//時計
	bool phone;			//電話
	bool hanger;		//コート掛け

	//アクション時フラグ
	bool desktalk;      
	bool chairtalk;
	bool lighttalk;
	bool flowerpottalk;
	bool sofatalk;
	bool clocktalk;
	bool phonetalk;
	bool hangertalk;
	
}LargeRoomTouchObject;

typedef struct
{
	bool boyishdoor;
	bool tunderedoor;
	bool yuruhuwadoor;


	bool boyish;
	bool tundere;
	bool yuruhuwa;

	bool doortalk;
}CorridorTouchObject;

typedef struct
{
	bool boyish;
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
	bool cabinet;

	bool robottalk;         //ロボ
	bool robotnecktalk;     //ロボの頭

	bool cabinettalk;
	bool lighttalk;        
	bool desktalk;         
	bool chairtalk;        
	bool dolltalk;
	bool bedtalk;
	bool flowerpottalk;
	bool closettalk;
	bool bookshelftalk;
	
}SearchGameTouchObject;

typedef struct
{
	bool robot;         //ロボ
	bool yuruhuwa;

	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool sofa;
	bool cabinet;
	bool bed;           //ベッド
	bool closet;        //クローゼット

	bool lighttalk;         
	bool desktalk;
	bool chairtalk;
	
	bool cabinettalk;
	bool bedtalk;
	bool sofatalk;
	bool closettalk;

}YuruhuwaTouchObject;

typedef struct
{
	bool tundere;
	bool robot;         //ロボ
	bool sofa;
	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool doll;          //人形
	bool bed;           //ベッド
	bool flowerpot;     //植木鉢
	bool closet;        //クローゼット

	bool lighttalk;
	bool desktalk;
	bool chairtalk;
	bool dolltalk;
	bool bedtalk;
	bool flowerpottalk;
	bool closettalk;
	bool sofatalk;
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

extern LargeRoomTouchObject largeroomobject;

extern CorridorTouchObject corridorobject;

extern SearchGameTouchObject searchgameobject;

extern YuruhuwaTouchObject yuruhuwaobject;

extern TundereTouchObject tundereobject;

extern GetItem getitem;

void InitLargeRoomObject();

void InitSearchGameObject();

void InitTundereRoomObject();

void InitYuruhuwaRoomObject();

void LoadSearchGameItem();

void DrawRobotNeck();


/*
   それぞれの部屋の家具Tex
*/
void LoadCorridorFurnitureTex();

void LoadTundereFurnitureTex();

void LoadYuruhuwaFurnitureTex();

void LoadCriminalFurnitureTex();


/*
　　探索パートでのオブジェクトとのあたり判定
　　矩形と矩形のあたり判定
*/
void HitLargeRoomObject();

void HitCorridorObject();

void HitSearchGameObject();

void HitTundereRoomObject();

void HitYuruhuwaRoomObject();

void HitCriminalRoomObject();





/*
　　探索ゲームでのプレイヤーとがアクションを起こすときの
  　オブジェクトとの視覚のあたり判定
　　矩形と矩形のあたり判定
*/

void HitEyeLargeRoomObject();

void HitEyeCorridorObject();

void HitEyeSearchGameObject();

void HitEyeTundereRoomObject();

void HitEyeYuruhuwaRoomObject();

void HitEyeCriminalRoomObject();


//探索ゲーム進行フラグ
void UpDataSearchGame();

//オブジェクトアクション時関数
void SearchObject();

//扉アクション時関数
void DrawDoorTalk();
#endif

