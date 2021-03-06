#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Graphics.h"
#include "Scene.h"

//それぞれのテクスチャのカテゴリー
#define TEXTURE_TITLE (SceneId::TitleScene)                  //!<タイトルシーン
#define TEXTURE_SCENARIO (SceneId::ScenarioScene)            //!<シナリオシーン
#define TEXTURE_MOVIE (SceneId::MovieScene)	                 //!<ムービーシーン
#define TEXTURE_SEARCH (SceneId::LargeRoomScene)             //!<探索(大部屋)シーン
#define TEXTURE_SEARCH2 (SceneId::CorridorScene)             //!<探索(廊下)シーン
#define TEXTURE_CRIMINAL_ROOM (SceneId::CriminalRoomScene)   //!<犯人部屋シーン
#define TEXTURE_TUNDERE_ROOM (SceneId::TundereRoomScene)     //!<ツンデレ部屋シーン
#define TEXTURE_YURUHUWA_ROOM (SceneId::YuruhuwaRoomScene)   //!<ゆるふわ部屋シーン
#define TEXTURE_SEARCH_GAME (SceneId::SearchGameScene)       //!<探索ゲーム(ボーイッシュ部屋)シーン
#define TEXTURE_PUZZLE (SceneId::PuzzleGameScene)            //!パズルゲーム<シーン
#define TEXTURE_MYSTERY (SceneId::MysteryGameScene)          //!パズルゲーム<シーン
#define TEXTURE_GAME_OVER (SceneId::GameOverScene)	         //!<ゲームオーバーシーン
#define TEXTURE_GAME_CLEAR (SceneId::GameClearScene)	     //!<ゲームクリアシーン
#define MAX_TEXTURE_ (SceneId::SceneIdMax)	                 //!< カテゴリー最大



enum TitleCategoryTextureList
{
	TitleBgTex,				//!< 背景
	TitleStartTex,          //!< 始める
	TitleEndTex,            //!< 終わる
	TitleListTex,           //!< スチルリスト
	TitleStartChoiceTex,    //!< 始めるを選んでるとき
	TitleEndChoiceTex,      //!< 終わるを選んでるとき
	TitleListChoiceTex,     //!< スチルリストを選んでるとき

	TitleTextureMax			//!< リスト最大数
};

enum ScenarioCategoryTextureList
{
	ScenarioBgTex,          //!< 背景

	ScenarioTextureMax      //!< リスト最大数
};
enum MovieCategoryTextureList
{
	MovieBgTex,				//!< 背景
	MoviePlayerTex,         //!< プレイヤー

	MovieTextureMax,	    //!< リスト最大数
};

enum LargeRoomCategoryTextureList
{
	LargeRoomBgTex,				//!< 背景1
	SearchPlayerTex,            //!< プレイヤー
	LargeRoomhanger,            //!< 服掛け
	LargeRoomFlowerpot,         //!< 植木鉢
	LargeRoomMaidRobotTex,      //!< メイド
	LargeRoomTalkMaidTex,       //!< メイド立ち絵
	SearchTextBoxTex,           //!< テキストボックス
	SearchTextnameTex,          //!< 名前テキストボックス 
	ChoiceTex,                  //!< 会話選択テキスト

	SearchTextureMax,	        //!<  リスト最大数
};

enum CorridorCategoryTextureList
{
	Search2BgTex,				//!< 背景
	Search2Door,                //!< ドア
	Search2Vase,                //!< 花瓶
	Search2TextureMax,	        //!< リスト最大数
};

enum CriminalRoomCategoryTextureList
{
	CriminalRoomBgTex,			 //!< 背景
	CriminalRedCarpet,           //!< 赤色カーペット
	CriminalBuleCarpet,		     //!< 青色カーペット
	CriminalGreenCarpet,	     //!< 緑色カーペット
	CriminalDesk,			     //!< 机
	CriminalRight,			     //!< 照明
	CriminalCloset,			     //!< 箪笥
	CriminalClock,			     //!< 時計
	CriminalBed,			     //!< ベッド
	CriminalBookshelf,		     //!< 本棚
	CriminalBook,			     //!< 本(落ちている)
	CriminalBook2,			     //!< 本2(落ちている)
	CriminalRobotAllParts,	     //!< ロボットのパーツがつられている
	CriminalRobotPartsArm,	     //!< ロボットの腕
	CriminalRobotPartsLeg,	     //!< ロボットの脚
	CriminalRobotPartsHead,	     //!< ロボットの頭
	CriminalRobotDesign,	     //!< ロボットの設計図
	CriminalWorkbench,		     //!< 作業台
	CriminalPC,				     //!< PC
	CriminalCabinet,		     //!< キャビネット

	CriminalRoomTextureMax,	     //!< リスト最大数

};

enum TundereRoomCategoryTextureList
{
	TundereRoomBgTex,		  //!< 背景
	TundereRobotTex,          //!< ロボット
	TundereTalkRobotTex,      //!< ロボット(未完成)
	TundereTalkTex,		      //!< ツンデレ
	TundereTex,		          //!< ツンデレ会話
	TundereWindow,            //!< 窓
	TundereFlowerpot,         //!< 花瓶
	TundereCloset,	          //!< 箪笥
	TundereSofa,	          //!< ソファ
	TundereCarpet,	          //!< カーペット
	TundereRight,	          //!< 照明
	TundereDesk,	          //!< 机
	TundereBed,		          //!< ベッド
	TundereDoll,	          //!< 人形

	TundereRoomTextureMax,	  //!< リスト最大数
};

enum YuruhuwaRoomCategoryTextureList
{
	YuruhuwaRoomBgTex,		  //!< 背景
	YuruhuwaRobotTex,         //!< ロボット
	YuruhuwaTalkRobotTex,     //!< ロボット(未完成)
	YuruhuwaTalkTex,		  //!< ゆるふわ
	YuruhuwaTex,		      //!< ゆるふわ会話
	                          
	YuruhuwaFetters,	      //!< 足枷
	YuruhuwaWindow,			  //!< 窓
	YuruhuwaClock,			  //!< 時計
	YuruhuwaCloset,			  //!< 箪笥
	YuruhuwaSofa,			  //!< ソファ
	YuruhuwaCarpet,			  //!< カーペット
	YuruhuwaRight,			  //!< 照明
	YuruhuwaDesk,			  //!< 机
	YuruhuwaBed,			  //!< ベッド
	YuruhuwaDoll,			  //!< 人形
	YuruhuwaCabinet,		  //!< キャビネット

	YuruhuwaRoomTextureMax,	  //!< リスト最大数
};
enum SearchGameCategoryTextureList
{
	SearchGameBgTex,                 //!< 背景
	SearchGamePlayerTex,             //!< プレイヤー
	SearchGameTalkRobot_NoNeckTex,   //!< ロボット(首無し)立ち絵
	SearchGameTalkRobot,             //!< ロボット立ち絵

	SearchGameRobotTex,              //!< ロボット(未完成)
	SearchGameCompleteRobotTex,      //!< ロボット(完成)
	SearchGameBoyishTex,             //!<ボーイッシュ
	SearchGameTalkBoyishTex,         //!<ボーイッシュ立ち絵

	SearchGameRobotNeckTex,          //!< ロボットの首
	SearchGameFetters,               //!< アイテムボックス
	
	
	SearchGameItemBoxTex,            //!< アイテムボックス
	SearchGameItemMenuTex,           //!< 
	SearchGameItemKeyTex,            //!< 鍵
	SearchGameItemRightTex,		     //!< ライト
	SearchGameItemEnergyTex,         //!< 電池
	SearchGameItemRobotPartTex,      //!< パーツ
								     
	SearchGameTextureMax,            //!< リスト最大数
};


enum PuzzleGameCategoryTextureList
{
	PuzzleGameBgTex,			   //!< 背景
	PuzzleKeyTex,                  //鍵　　　
	PuzzleSquareTex,			   //正方形
	PuzzleLandscapeTex,			   //横長
	PuzzlePortraitTex,			   //縦長

	PuzzleGameTextureMax,		   //リスト最大数
};

enum MysteryGameCategoryTextureList
{
	MysteryGameBgTex,		       //!< 背景
	MysteryGameTextTex,
	MysteryGameTextBoxTex,		   //!< あいうえお表箱

	MysteryGameChoiceTextTex,	   //!< 選択中
	MysteryGameProblemTextTex_1,   //!< 問題文
	MysteryGameProblemTextTex_2,   //!< 問題文

	MysteryGameProblem_Answer_1,   //!<答え枠1
	MysteryGameProblem_Answer_2,   //!<答え枠2

	MysteryGameCorrect_Answer,     //!<正解
	MysteryGameIncorrect_Answer,   //!<不正解
	

	MysteryGameDecisionButtonTex,  //!< 決定ボタン
	MysteryGameDeleteButtonTex,    //!< 削除ボタン

	MysteryGameTextureMax,		   //リスト最大数
};

enum TalkCategoryTextureList
{
	TalkBgTex,            //!< 背景
	TalkPlayerTex,	      //!< プレイヤー
	TalkRobotTex,	      //!< ロボット
	TalkSurprisedTex,     //!< ビックリマーク
	MenuTex,		      //!< 
	TalkTextureMax,	      //!< リスト最大数
};
enum GameClearCategoryTextureList
{
	BoyishClearBgTex,		//!< 背景
	TundereClearBgTex,		//!< 背景
	YuruhuwaClearBgTex,		//!< 背景
	GameClearTextureMax,	//!< リスト最大数
};

enum GameOverCategoryTextureList
{
	GameOverBgTex,			//!< 背景
	GameOverLogoTex,	    //!< 背景

	GameOverTextureMax,		//!< リスト最大数
};

enum HelpCategoryTextureList
{
	HelpBgTex,				//!< 背景
	HelpTextureMax,			//!< リスト最大数
};


void InitTexture();

void ReleaseCategoryTexture(int category_id);

void AllReleaseTexture();

bool LoadTexture(const char* file_name, int category_id, int texture_id);

TEXTURE_DATA* GetTexture(int category_id, int texture_id);

#endif