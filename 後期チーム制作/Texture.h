#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Graphics.h"
#include "Scene.h"

//���ꂼ��̃e�N�X�`���̃J�e�S���[
#define TEXTURE_TITLE (SceneId::TitleScene)
#define TEXTURE_SCENARIO (SceneId::ScenarioScene)
#define TEXTURE_MOVIE (SceneId::MovieScene)	
#define TEXTURE_SEARCH (SceneId::SearchScene)
#define TEXTURE_SEARCH2 (SceneId::Search2Scene)
#define TEXTURE_SEARCH_GAME (SceneId::SearchGameScene)
#define TEXTURE_TALK (SceneId::TalkScene)
#define TEXTURE_PUZZLE (SceneId::PuzzleGameScene)
#define TEXTURE_HELP (SceneId::HelpScene)				
#define TEXTURE_GAME_OVER (SceneId::GameOverScene)	
#define TEXTURE_GAME_CLEAR (SceneId::GameClearScene)	
#define MAX_TEXTURE_ (SceneId::SceneIdMax)	//!< �J�e�S���[�ő�



enum TitleCategoryTextureList
{
	TitleBgTex,				//!< �w�i
	TitleStartTex,          //!< �n�߂�
	TitleEndTex,            //!< �I���
	TitleTextureMax			//!< ���X�g�ő吔
};

enum ScenarioCategoryTextureList
{
	ScenarioBgTex,          //!< �w�i
	ScenarioTextureMax      //!< ���X�g�ő吔
};
enum MovieCategoryTextureList
{
	MovieBgTex,				//!< �w�i
	MoviePlayerTex,         //!< �v���C���[
	MovieTextureMax,	    //!< ���X�g�ő吔
};

enum SearchCategoryTextureList
{
	SearchBgTex,				//!< �w�i1
	SearchPlayerTex,            //�v���C���[
	SearchTextureMax,	    //!< ���X�g�ő吔
};

enum Search2CategoryTextureList
{
	Search2BgTex,				//!< �w�i
	Search2TextureMax,	    //!< ���X�g�ő吔
};

enum SearchGameCategoryTextureList
{
	SearchGameBgTex,
	SearchGamePlayerTex,
	SearchGameRobotTex,
	SearchGameRobotNeckTex,
	SearchGameSurprisedTex,
	SearchGameTextBoxTex,
	SearchGameTextnameTex,
	SearchGameItemBoxTex,
	SearchGameItemMenuTex,
	SearchGameTextureMax,
};

enum TalkCategoryTextureList
{
	TalkBgTex,
	TalkPlayerTex,
	TalkRobotTex,
	TalkSurprisedTex,
	MenuTex,
	TalkTextureMax,
};
enum PuzzleGameCategoryTextureList
{
	PuzzleGameBgTex,				//!< �w�i
	PuzzleKeyTex,                  //���@�@�@
	PuzzleSquareTex,					//�����`
	PuzzleLandscapeTex,					//����
	PuzzlePortraitTex,					//�c��
	PuzzleGameTextureMax,		//���X�g�ő吔
};

enum GameClearCategoryTextureList
{
	GameClearBgTex,			//!< �w�i
	GameClearTextureMax,	//!< ���X�g�ő吔
};

enum GameOverCategoryTextureList
{
	GameOverBgTex,			//!< �w�i
	GameOverTextureMax,		//!< ���X�g�ő吔
};

enum HelpCategoryTextureList
{
	HelpBgTex,				//!< �w�i
	HelpTextureMax,			//!< ���X�g�ő吔
};


void InitTexture();

void ReleaseCategoryTexture(int category_id);

void AllReleaseTexture();

bool LoadTexture(const char* file_name, int category_id, int texture_id);

TEXTURE_DATE* GetTexture(int category_id, int texture_id);

#endif