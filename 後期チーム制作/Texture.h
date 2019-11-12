#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Graphics.h"
#include "Scene.h"

//それぞれのテクスチャのカテゴリー
#define TEXTURE_TITLE (SceneId::TitleScene)			
#define TEXTURE_MOVIE (SceneId::MovieScene)	
#define TEXTURE_TALK (SceneId::TalkScene)
#define TEXTURE_PUZZLE (SceneId::PuzzleGameScene)
#define TEXTURE_HELP (SceneId::HelpScene)				
#define TEXTURE_GAME_OVER (SceneId::GameOverScene)	
#define TEXTURE_GAME_CLEAR (SceneId::GameClearScene)	
#define MAX_TEXTURE_ (SceneId::SceneIdMax)	//!< カテゴリー最大



enum TitleCategoryTextureList
{
	TitleBgTex,				//!< 背景
	TitleStart,             //!< 始める
	TitleEnd,               //!< 終わる
	TitleTextureMax			//!< リスト最大数
};

enum MovieCategoryTextureList
{
	MovieBgTex,				//!< 背景
	MoviePlayer,            //プレイヤー
	MovieTextureMax,	    //!< リスト最大数
};

enum TalkCategoryTextureList
{
	TalkBg,
	TalkPlayer,
	TalkRobot,
	TalkSurprised,
	TalkTextureMax,
};
enum PuzzleGameCategoryTextureList
{
	PuzzleGameBg,				//!< 背景
	PuzzleKey,                  //鍵　　　
	Puzzle1,					//正方形
	Puzzle2,					//横長
	Puzzle3,					//縦長
	PuzzleGameTextureMax,		//リスト最大数
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