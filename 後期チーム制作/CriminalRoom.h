#ifndef CRIMINAL_ROOM_SCENE_H_
#define CRIMINAL_ROOM_SCENE_H_
#include "Scene.h"

/**
* @brief ゲームオーバーシーンの更新関数@n
* ゲームオーバーシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::GameOverSceneが返る)
*/
SceneId UpdateCriminalRoomScene();

/**
* @brief ゲームオーバーシーンの描画関数@n
* ゲームオーバーシーンのオブジェクトを描画するための関数
*/
void DrawCriminalRoomScene();

#endif