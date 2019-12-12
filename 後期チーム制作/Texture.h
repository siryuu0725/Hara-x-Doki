#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Graphics.h"
#include "Scene.h"

//それぞれのテクスチャのカテゴリー
#define TEXTURE_TITLE (SceneId::TitleScene)
#define TEXTURE_SCENARIO (SceneId::ScenarioScene)
#define TEXTURE_MOVIE (SceneId::MovieScene)	
#define TEXTURE_SEARCH (SceneId::SearchScene)
#define TEXTURE_SEARCH2 (SceneId::Search2Scene)
#define TEXTURE_CRIMINAL_ROOM (SceneId::CriminalRoomScene)
#define TEXTURE_TUNDERE_ROOM (SceneId::TundereRoomScene)
#define TEXTURE_YURUHUWA_ROOM (SceneId::YuruhuwaRoomScene)
#define TEXTURE_SEARCH_GAME (SceneId::SearchGameScene)
#define TEXTURE_TALK (SceneId::TalkScene)
#define TEXTURE_PUZZLE (SceneId::PuzzleGameScene)
#define TEXTURE_HELP (SceneId::HelpScene)				
#define TEXTURE_GAME_OVER (SceneId::GameOverScene)	
#define TEXTURE_GAME_CLEAR (SceneId::GameClearScene)	
#define MAX_TEXTURE_ (SceneId::SceneIdMax)	//!< カテゴリー最大



enum TitleCategoryTextureList
{
	TitleBgTex,				//!< 背景
	TitleStartTex,          //!< 始める
	TitleEndTex,            //!< 終わる
	TitleStartChoiceTex,          //!< 始めるを選んでるとき
	TitleEndChoiceTex,            //!< 終わるを選んでるとき
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

enum SearchCategoryTextureList
{
	SearchBgTex,				//!< 背景1
	SearchPlayerTex,            //プレイヤー
	Searchhanger,
	SearchFlowerpot,
	SearchRobotTex,          //!< ロボット
	SearchMaidRobotTex,          //!<メイド
	SearchTalkMaidTex,          //!< ロボット
	SearchTextBoxTex,        //!< テキストボックス
	SearchTextnameTex,       //!< 
	SearchTextureMax,	        //!< リスト最大数
};

enum Search2CategoryTextureList
{
	Search2BgTex,				//!< 背景
	Search2Door,
	Search2Vase,
	Search2TextureMax,	        //!< リスト最大数
};

enum CriminalRoomCategoryTextureList
{
	CriminalRoomBgTex,				//!< 背景
	CriminalRedCarpet,
	CriminalBuleCarpet,
	CriminalGreenCarpet,
	CriminalDesk,
	CriminalRight,
	CriminalCloset,
	CriminalClock,
	CriminalBed,
	CriminalBookshelf,
	CriminalBook,
	CriminalBook2,
	CriminalRobotAllParts,
	CriminalRobotPartsArm,
	CriminalRobotPartsLeg,
	CriminalRobotPartsHead,
	CriminalRobotDesign,
	CriminalWorkbench,
	CriminalPC,
	CriminalCabinet,
	CriminalRoomTextureMax,	        //!< リスト最大数

};

enum TundereRoomCategoryTextureList
{
	TundereRoomBgTex,				//!< 背景
	TundereRobotTex,          //!< ロボット
	TundereTalkRobotTex,          //!< ロボット(未完成)
	TundereWindow,
	TundereFlowerpot,
	TundereCloset,
	TundereSofa,
	TundereCarpet,
	TundereRight,
	TundereDesk,
	TundereBed,
	TundereDoll,
	TundereRoomTextureMax,	        //!< リスト最大数
};

enum YuruhuwaRoomCategoryTextureList
{
	YuruhuwaRoomBgTex,				//!< 背景
	YuruhuwaRobotTex,          //!< ロボット
	YuruhuwaTalkRobotTex,          //!< ロボット(未完成)
	YuruhuwaWindow,
	YuruhuwaClock,
	YuruhuwaCloset,
	YuruhuwaSofa,
	YuruhuwaCarpet,
	YuruhuwaRight,
	YuruhuwaDesk,
	YuruhuwaBed,
	YuruhuwaDoll,
	YuruhuwaCabinet,
	YuruhuwaRoomTextureMax,	        //!< リスト最大数
};
enum SearchGameCategoryTextureList
{
	SearchGameBgTex,             //!< 背景
	SearchGamePlayerTex,         //!< プレイヤー
	SearchGameTalkRobotTex,      //!< ロボット

	SearchGameRobotTex,          //!< ロボット(未完成)
	SearchGameCompleteRobotTex,  //!< ロボット(完成)
	SearchGameBoyishTex,            //プレイヤー

	SearchGameRobotNeckTex,      //!< ロボットの首
	SearchGameSurprisedTex,      //!< ビックリマーク
	
	
	SearchGameItemBoxTex,        //!< アイテムボックス
	SearchGameItemMenuTex,       //!< 
	SearchGameItemKeyTex,        //!< 鍵
	SearchGameItemEnergyTex,     //!< 電池
	SearchGameItemRobotPartTex,  //!< パーツ

	SearchGameTextureMax,        //!< リスト最大数
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
enum PuzzleGameCategoryTextureList
{
	PuzzleGameBgTex,			   //!< 背景
	PuzzleKeyTex,                  //鍵　　　
	PuzzleSquareTex,			   //正方形
	PuzzleLandscapeTex,			   //横長
	PuzzlePortraitTex,			   //縦長
	PuzzleGameTextureMax,		   //リスト最大数
};

enum GameClearCategoryTextureList
{
	GameClearBgTex,			//!< 背景
	GameClearTextureMax,	//!< リスト最大数
};

enum GameOverCategoryTextureList
{
	GameOverBgTex,			//!< 背景
	GameOverLogoTex,			//!< 背景

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

TEXTURE_DATE* GetTexture(int category_id, int texture_id);

#endif