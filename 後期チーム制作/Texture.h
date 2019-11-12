#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Graphics.h"
#include "Scene.h"

//���ꂼ��̃e�N�X�`���̃J�e�S���[
#define TEXTURE_TITLE (SceneId::TitleScene)			
#define TEXTURE_MOVIE (SceneId::MovieScene)	
#define TEXTURE_TALK (SceneId::TalkScene)
#define TEXTURE_PUZZLE (SceneId::PuzzleGameScene)
#define TEXTURE_HELP (SceneId::HelpScene)				
#define TEXTURE_GAME_OVER (SceneId::GameOverScene)	
#define TEXTURE_GAME_CLEAR (SceneId::GameClearScene)	
#define MAX_TEXTURE_ (SceneId::SceneIdMax)	//!< �J�e�S���[�ő�



enum TitleCategoryTextureList
{
	TitleBgTex,				//!< �w�i
	TitleStart,             //!< �n�߂�
	TitleEnd,               //!< �I���
	TitleTextureMax			//!< ���X�g�ő吔
};

enum MovieCategoryTextureList
{
	MovieBgTex,				//!< �w�i
	MoviePlayer,            //�v���C���[
	MovieTextureMax,	    //!< ���X�g�ő吔
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
	PuzzleGameBg,				//!< �w�i
	PuzzleKey,                  //���@�@�@
	Puzzle1,					//�����`
	Puzzle2,					//����
	Puzzle3,					//�c��
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