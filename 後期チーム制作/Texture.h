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
#define TEXTURE_CRIMINAL_ROOM (SceneId::CriminalRoomScene)
#define TEXTURE_TUNDERE_ROOM (SceneId::TundereRoomScene)
#define TEXTURE_YURUHUWA_ROOM (SceneId::YuruhuwaRoomScene)
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
	TitleStartChoiceTex,          //!< �n�߂��I��ł�Ƃ�
	TitleEndChoiceTex,            //!< �I����I��ł�Ƃ�
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
	Searchhanger,
	SearchFlowerpot,
	SearchRobotTex,          //!< ���{�b�g
	SearchMaidRobotTex,          //!<���C�h
	SearchTalkMaidTex,          //!< ���{�b�g
	SearchTextBoxTex,        //!< �e�L�X�g�{�b�N�X
	SearchTextnameTex,       //!< 
	SearchTextureMax,	        //!< ���X�g�ő吔
};

enum Search2CategoryTextureList
{
	Search2BgTex,				//!< �w�i
	Search2Door,
	Search2Vase,
	Search2TextureMax,	        //!< ���X�g�ő吔
};

enum CriminalRoomCategoryTextureList
{
	CriminalRoomBgTex,				//!< �w�i
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
	CriminalRoomTextureMax,	        //!< ���X�g�ő吔

};

enum TundereRoomCategoryTextureList
{
	TundereRoomBgTex,				//!< �w�i
	TundereRobotTex,          //!< ���{�b�g
	TundereTalkRobotTex,          //!< ���{�b�g(������)
	TundereWindow,
	TundereFlowerpot,
	TundereCloset,
	TundereSofa,
	TundereCarpet,
	TundereRight,
	TundereDesk,
	TundereBed,
	TundereDoll,
	TundereRoomTextureMax,	        //!< ���X�g�ő吔
};

enum YuruhuwaRoomCategoryTextureList
{
	YuruhuwaRoomBgTex,				//!< �w�i
	YuruhuwaRobotTex,          //!< ���{�b�g
	YuruhuwaTalkRobotTex,          //!< ���{�b�g(������)
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
	YuruhuwaRoomTextureMax,	        //!< ���X�g�ő吔
};
enum SearchGameCategoryTextureList
{
	SearchGameBgTex,             //!< �w�i
	SearchGamePlayerTex,         //!< �v���C���[
	SearchGameTalkRobotTex,      //!< ���{�b�g

	SearchGameRobotTex,          //!< ���{�b�g(������)
	SearchGameCompleteRobotTex,  //!< ���{�b�g(����)
	SearchGameBoyishTex,            //�v���C���[

	SearchGameRobotNeckTex,      //!< ���{�b�g�̎�
	SearchGameSurprisedTex,      //!< �r�b�N���}�[�N
	
	
	SearchGameItemBoxTex,        //!< �A�C�e���{�b�N�X
	SearchGameItemMenuTex,       //!< 
	SearchGameItemKeyTex,        //!< ��
	SearchGameItemEnergyTex,     //!< �d�r
	SearchGameItemRobotPartTex,  //!< �p�[�c

	SearchGameTextureMax,        //!< ���X�g�ő吔
};

enum TalkCategoryTextureList
{
	TalkBgTex,            //!< �w�i
	TalkPlayerTex,	      //!< �v���C���[
	TalkRobotTex,	      //!< ���{�b�g
	TalkSurprisedTex,     //!< �r�b�N���}�[�N
	MenuTex,		      //!< 
	TalkTextureMax,	      //!< ���X�g�ő吔
};
enum PuzzleGameCategoryTextureList
{
	PuzzleGameBgTex,			   //!< �w�i
	PuzzleKeyTex,                  //���@�@�@
	PuzzleSquareTex,			   //�����`
	PuzzleLandscapeTex,			   //����
	PuzzlePortraitTex,			   //�c��
	PuzzleGameTextureMax,		   //���X�g�ő吔
};

enum GameClearCategoryTextureList
{
	GameClearBgTex,			//!< �w�i
	GameClearTextureMax,	//!< ���X�g�ő吔
};

enum GameOverCategoryTextureList
{
	GameOverBgTex,			//!< �w�i
	GameOverLogoTex,			//!< �w�i

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