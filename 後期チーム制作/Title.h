#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_
//#include "Scene.h"

#define START_X 700 // 始めるのX座標
#define START_X_SIZE 600 // 始めるのX座標のサイズ
#define START_Y 700 // 始めるのY座標
#define START_Y_SIZE 100 // 始めるのY座標のサイズ
#define END_X 700 // 終わるのX座標
#define END_X_SIZE 600 // 終わるのX座標のサイズ
#define END_Y 900 // 終わるのY座標
#define END_Y_SIZE 100 // 終わるのY座標のサイズ


/**
* @brief タイトルシーンの更新関数@n
* タイトルシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::TitleSceneが返る)
*/
SceneId UpdateTitleScene();

/**
* @brief タイトルシーンの描画関数@n
* タイトルシーンのオブジェクトを描画する関数
*/
void DrawTitleScene();

#endif

