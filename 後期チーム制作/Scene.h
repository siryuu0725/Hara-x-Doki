#ifndef SCENE_H_
#define SCENE_H_

enum SceneId
{
	TitleScene,	     	//!< タイトルシーン
	ScenarioScene,      //!< シナリオシーン
	HelpScene,			//!< ヘルプ(遊戯説明画面)シーン
	MovieScene,			//!< ゲーム本編シーン
	SearchScene,		//!< 探索シーン
	CorridorScene,		//!<
	CriminalRoomScene,
	TundereRoomScene,
	YuruhuwaRoomScene,
	SearchGameScene,    //!<
	PuzzleGameScene,    //!< パズルゲームシーン
	MysteryGameScene,
	TalkScene,          //!< 会話シーン
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
