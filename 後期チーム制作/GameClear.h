#ifndef GAME_CLAER_SCENE_H_
#define GAME_CLEAR_SCENE_H_
//#include "Scene.h"

/**
* @brief クリアシーンの更新関数@n
* ゲームクリアシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::GameClearSceneが返る)
*/
SceneId UpdateGameClearScene();

/**
* @brief クリアシーンの描画関数@n
* クリアシーンのオブジェクトを描画するための関数
*/
void DrawGameClearScene();

#endif
