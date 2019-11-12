#ifndef SCENE_H_
#define SCENE_H_

enum SceneId
{
	TitleScene,			//!< タイトルシーン
	HelpScene,			//!< ヘルプ(遊戯説明画面)シーン
	MovieScene,			//!< ゲーム本編シーン
	TalkScene,
	PuzzleGameScene,
	GameClearScene,		//!< ゲームクリアシーン
	GameOverScene,		//!< ゲームオーバーシーン
	SceneIdMax			//!< シーンID最大
};

enum SceneStep
{
	InitStep,			//!< 初期化
	MainStep,			//!< メイン
	EndStep,			//!< 終了
};

SceneId GetCurrentSceneId();

SceneStep GetCurrentSceneStep();

void ChangeSceneStep(SceneStep next_step);

void UpdateScene();

void DrawScene();

#endif
