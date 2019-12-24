#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Graphics.h"
#include "Scene.h"

//���ꂼ��̃e�N�X�`���̃J�e�S���[
#define TEXTURE_TITLE (SceneId::TitleScene)                  //!<�^�C�g���V�[��
#define TEXTURE_SCENARIO (SceneId::ScenarioScene)            //!<�V�i���I�V�[��
#define TEXTURE_MOVIE (SceneId::MovieScene)	                 //!<���[�r�[�V�[��
#define TEXTURE_SEARCH (SceneId::LargeRoomScene)                //!<�T��(�啔��)�V�[��
#define TEXTURE_SEARCH2 (SceneId::CorridorScene)              //!<�T��(�L��)�V�[��
#define TEXTURE_CRIMINAL_ROOM (SceneId::CriminalRoomScene)   //!<�Ɛl�����V�[��
#define TEXTURE_TUNDERE_ROOM (SceneId::TundereRoomScene)     //!<�c���f�������V�[��
#define TEXTURE_YURUHUWA_ROOM (SceneId::YuruhuwaRoomScene)   //!<���ӂ핔���V�[��
#define TEXTURE_SEARCH_GAME (SceneId::SearchGameScene)       //!<�T���Q�[��(�{�[�C�b�V������)�V�[��
#define TEXTURE_PUZZLE (SceneId::PuzzleGameScene)            //!�p�Y���Q�[��<�V�[��
#define TEXTURE_MYSTERY (SceneId::MysteryGameScene)            //!�p�Y���Q�[��<�V�[��
#define TEXTURE_TALK (SceneId::TalkScene)                    //!<
#define TEXTURE_HELP (SceneId::HelpScene)				     //!<
#define TEXTURE_GAME_OVER (SceneId::GameOverScene)	         //!<�Q�[���I�[�o�[�V�[��
#define TEXTURE_GAME_CLEAR (SceneId::GameClearScene)	     //!<�Q�[���N���A�V�[��
#define MAX_TEXTURE_ (SceneId::SceneIdMax)	                 //!< �J�e�S���[�ő�



enum TitleCategoryTextureList
{
	TitleBgTex,				//!< �w�i
	TitleStartTex,          //!< �n�߂�
	TitleEndTex,            //!< �I���
	TitleListTex,           //!< �X�`�����X�g
	TitleStartChoiceTex,    //!< �n�߂��I��ł�Ƃ�
	TitleEndChoiceTex,      //!< �I����I��ł�Ƃ�
	TitleListChoiceTex,     //!< �X�`�����X�g��I��ł�Ƃ�

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
	SearchPlayerTex,            //!< �v���C���[
	Searchhanger,               //!< ���|��
	SearchFlowerpot,            //!< �A�ؔ�
	SearchMaidRobotTex,         //!< ���C�h
	SearchTalkMaidTex,          //!< ���C�h�����G
	SearchTextBoxTex,           //!< �e�L�X�g�{�b�N�X
	SearchTextnameTex,          //!< ���O�e�L�X�g�{�b�N�X 
	SearchTextureMax,	        //!<  ���X�g�ő吔
};

enum Search2CategoryTextureList
{
	Search2BgTex,				//!< �w�i
	Search2Door,                //!< �h�A
	Search2Vase,                //!< �ԕr
	Search2TextureMax,	        //!< ���X�g�ő吔
};

enum CriminalRoomCategoryTextureList
{
	CriminalRoomBgTex,			 //!< �w�i
	CriminalRedCarpet,           //!< �ԐF�J�[�y�b�g
	CriminalBuleCarpet,		     //!< �F�J�[�y�b�g
	CriminalGreenCarpet,	     //!< �ΐF�J�[�y�b�g
	CriminalDesk,			     //!< ��
	CriminalRight,			     //!< �Ɩ�
	CriminalCloset,			     //!< �\�y
	CriminalClock,			     //!< ���v
	CriminalBed,			     //!< �x�b�h
	CriminalBookshelf,		     //!< �{�I
	CriminalBook,			     //!< �{(�����Ă���)
	CriminalBook2,			     //!< �{2(�����Ă���)
	CriminalRobotAllParts,	     //!< ���{�b�g�̃p�[�c�����Ă���
	CriminalRobotPartsArm,	     //!< ���{�b�g�̘r
	CriminalRobotPartsLeg,	     //!< ���{�b�g�̋r
	CriminalRobotPartsHead,	     //!< ���{�b�g�̓�
	CriminalRobotDesign,	     //!< ���{�b�g�̐݌v�}
	CriminalWorkbench,		     //!< ��Ƒ�
	CriminalPC,				     //!< PC
	CriminalCabinet,		     //!< �L���r�l�b�g
	CriminalRoomTextureMax,	     //!< ���X�g�ő吔

};

enum TundereRoomCategoryTextureList
{
	TundereRoomBgTex,		  //!< �w�i
	TundereRobotTex,          //!< ���{�b�g
	TundereTalkRobotTex,      //!< ���{�b�g(������)
	TundereWindow,            //!< ��
	TundereFlowerpot,         //!< �ԕr
	TundereCloset,	          //!< �\�y
	TundereSofa,	          //!< �\�t�@
	TundereCarpet,	          //!< �J�[�y�b�g
	TundereRight,	          //!< �Ɩ�
	TundereDesk,	          //!< ��
	TundereBed,		          //!< �x�b�h
	TundereDoll,	          //!< �l�`
	TundereRoomTextureMax,	  //!< ���X�g�ő吔
};

enum YuruhuwaRoomCategoryTextureList
{
	YuruhuwaRoomBgTex,		  //!< �w�i
	YuruhuwaRobotTex,         //!< ���{�b�g
	YuruhuwaTalkRobotTex,     //!< ���{�b�g(������)
	YuruhuwaTalkTex,		  //!< �w�i
	                          
	YuruhuwaWindow,			  //!< ��
	YuruhuwaClock,			  //!< ���v
	YuruhuwaCloset,			  //!< �\�y
	YuruhuwaSofa,			  //!< �\�t�@
	YuruhuwaCarpet,			  //!< �J�[�y�b�g
	YuruhuwaRight,			  //!< �Ɩ�
	YuruhuwaDesk,			  //!< ��
	YuruhuwaBed,			  //!< �x�b�h
	YuruhuwaDoll,			  //!< �l�`
	YuruhuwaCabinet,		  //!< �L���r�l�b�g
	YuruhuwaRoomTextureMax,	  //!< ���X�g�ő吔
};
enum SearchGameCategoryTextureList
{
	SearchGameBgTex,             //!< �w�i
	SearchGamePlayerTex,         //!< �v���C���[
	SearchGameTalkRobotTex,      //!< ���{�b�g�����G

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


enum PuzzleGameCategoryTextureList
{
	PuzzleGameBgTex,			   //!< �w�i
	PuzzleKeyTex,                  //���@�@�@
	PuzzleSquareTex,			   //�����`
	PuzzleLandscapeTex,			   //����
	PuzzlePortraitTex,			   //�c��
	PuzzleGameTextureMax,		   //���X�g�ő吔
};

enum MysteryGameCategoryTextureList
{
	MysteryGameBgMax,		   //!< �w�i
	MysteryGameChoiceTextMax,		   //!< �w�i
	MysteryGameProblemTextMax,		   //!< �w�i

	MysteryGameTextureMax,		   //���X�g�ő吔
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