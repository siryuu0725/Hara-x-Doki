#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	float pos_x, pos_y;
	bool get;            //アイテムを手に入れたかどうか
}RobotNeck;

typedef struct
{
	bool energy;    //ロボのエネルギー
	bool desk;      //机
	bool chair;     //椅子
	bool doll;      //人形
	bool bed;       //ベッド
	bool light;     //ライト
	bool flowerpot; //植木鉢
	bool closet;    //クローゼット
	bool bookshelf; //本棚

}TouchObject;

extern RobotNeck neck;



void DrawRobotNeck();

/*
　　探索パートでのオブジェクトとのあたり判定
　　矩形と矩形のあたり判定
*/
void HitSearchObject();

void HitTundereRoomObject();

void HitYuruhuwaRoomObject();

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


#endif

