#ifndef HIT_
#define HIT_
#include "Puzzle.h"

bool HitChoiseTitle(float x, float y, float width, float height);


#pragma region 探索パート
/*
     部屋(エリア)移動を行うときの移動判定
	当たっていればtrue
	 矩形と点であたり判定をとっている
	 引数
	 　　(左辺,右辺,上辺,底辺)
*/
bool HitNextArea(float left_x, float right_x, float up_y, float down_y);


/*
	プレイヤーとオブジェクトのあたり判定
	当たっていればtrue
	矩形と矩形であたり判定をとっている
	引数
	 　　(オブジェクトのx座標,オブジェクトのy座標,オブジェクトの横サイズ,オブジェクトの縦サイズ)
*/
bool HitPlayerObject(float obj_x, float obj_y, float obj_width, float obj_height);


/*
	プレイヤーの視界とオブジェクトのあたり判定
	当たっていればtrue
	矩形と矩形であたり判定をとっている
	引数
	 　　(オブジェクトのx座標,オブジェクトのy座標,オブジェクトの横サイズ,オブジェクトの縦サイズ)
*/
bool HitPlayerEyeObject(float obj_x, float obj_y, float obj_width, float obj_height);


#pragma endregion

#pragma region パズルゲーム
/*
    それぞれのキューブを矩形と矩形であたり判定をとっている
	当たっていればtrue
	引数
	　　(それぞれのブロックの始まりの要素番号,
	  　 それぞれのブロックの最後の要素番号,
		 動かすキューブの種類,
		 動かすキューブの横幅,
		 動かすキューブの縦幅,
		 判定をとるキューブの横幅,
		 判定をとる動かすキューブの縦幅,
*/
bool HitCabe(int d, int d2, int idx_, PuzzleCabe* puzzle1, float width, float height, float Compare_width, float Compare_height);
#pragma endregion

#endif