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
	SearchTextureMax,	        //!< リスト最大数
};

enum Search2CategoryTextureList
{
	Search2BgTex,				//!< 背景
	Search2TextureMax,	        //!< リスト最大数
};

enum CriminalRoomCategoryTextureList
{
	CriminalRoomBgTex,				//!< 背景
	CriminalRoomTextureMax,	        //!< リスト最大数
};

enum TundereRoomCategoryTextureList
{
	TundereRoomBgTex,				//!< 背景
	TundereRoomTextureMax,	        //!< リスト最大数
};

enum YuruhuwaRoomCategoryTextureList
{
	YuruhuwaRoomBgTex,				//!< 背景
	YuruhuwaRoomTextureMax,	        //!< リスト最大数
};
enum SearchGameCategoryTextureList
{
	SearchGameBgTex,             //!< 背景
	SearchGamePlayerTex,         //!< プレイヤー
	SearchGameRobotTex,          //!< ロボット
	SearchGameRobotNeckTex,      //!< ロボットの首
	SearchGameSurprisedTex,      //!< ビックリマーク
	SearchGameTextBoxTex,        //!< テキストボックス
	SearchGameTextnameTex,       //!< 
	SearchGameItemBoxTex,        //!< アイテムボックス
	SearchGameItemMenuTex,       //!< 
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