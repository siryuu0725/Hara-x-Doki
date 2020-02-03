#ifndef ITEM_H
#define ITEM_H

//大部屋用構造体
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

//廊下用構造体
typedef struct
{
	bool boyishdoor;      //ボーイッシュ扉  
	bool tunderedoor;	  //ツンデレ扉  
	bool yuruhuwadoor;	  //ゆるふわ扉  

	bool boyish;          //ボーイッシュ扉
	bool tundere;		  //ツンデレ扉  
	bool yuruhuwa;		  //ゆるふわ扉  

	//アクション時フラグ
	bool doortalk;
}CorridorTouchObject;

//ボーイッシュ部屋用構造体
typedef struct
{
	bool boyish;            //ボーイッシュ
	bool robot;             //ロボ
	bool robotneck;         //ロボの頭
	bool completerobot;     //ロボ完成形
						    
	bool light;             //ライト
	bool desk;              //机
	bool chair;             //椅子
	bool doll;              //人形
	bool bed;               //ベッド
	bool flowerpot;         //植木鉢
	bool closet;            //クローゼット
	bool bookshelf;         //本棚
	bool cabinet;

	//アクション時フラグ
	bool robottalk;         
	bool robotnecktalk;     

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


//ゆるふわ部屋用構造体
typedef struct
{
	bool robot;         //ロボ
	bool yuruhuwa;      //ゆるふわ		

	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool sofa;          //ソファ 
	bool cabinet;		//キャビネット
	bool bed;           //ベッド
	bool closet;        //クローゼット

	//アクション時フラグ
	bool lighttalk;         
	bool desktalk;
	bool chairtalk;
	
	bool cabinettalk;
	bool bedtalk;
	bool sofatalk;
	bool closettalk;

}YuruhuwaTouchObject;


//ツンデレ部屋用構造体
typedef struct
{
	bool tundere;       //ツンデレ
	bool robot;         //ロボ
	bool sofa;
	bool light;         //ライト
	bool desk;          //机
	bool chair;         //椅子
	bool doll;          //人形
	bool bed;           //ベッド
	bool flowerpot;     //植木鉢
	bool closet;        //クローゼット

	//アクション時フラグ
	bool lighttalk;
	bool desktalk;
	bool chairtalk;
	bool dolltalk;
	bool bedtalk;
	bool flowerpottalk;
	bool closettalk;
	bool sofatalk;
}TundereTouchObject;

//アイテム用構造体
typedef struct
{
	bool itemrobot;   //ロボの首
	bool itemkey;     //鍵
	bool itemenergy;  //電池
	bool itemlight;   //ライト

	//アクション時フラグ
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

//部屋初期化
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

