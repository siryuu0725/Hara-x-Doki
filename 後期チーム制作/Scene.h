#ifndef SCENE_H_
#define SCENE_H_

enum SceneId
{
	TitleScene,	     	//!< �^�C�g���V�[��
	ScenarioScene,      //!< �V�i���I�V�[��
	HelpScene,			//!< �w���v(�V�Y�������)�V�[��
	MovieScene,			//!< �Q�[���{�҃V�[��
	SearchScene,		//!< �T���V�[��
	CorridorScene,		//!<
	CriminalRoomScene,
	TundereRoomScene,
	YuruhuwaRoomScene,
	SearchGameScene,    //!<
	PuzzleGameScene,    //!< �p�Y���Q�[���V�[��
	MysteryGameScene,
	TalkScene,          //!< ��b�V�[��
	GameClearScene,		//!< �Q�[���N���A�V�[��
	GameOverScene,		//!< �Q�[���I�[�o�[�V�[��
	SceneIdMax			//!< �V�[��ID�ő�
};

enum SceneStep
{
	InitStep,			//!< ������
	MainStep,			//!< ���C��
	EndStep,			//!< �I��
};

SceneId GetCurrentSceneId();

SceneStep GetCurrentSceneStep();

void ChangeSceneStep(SceneStep next_step);

void UpdateScene();

void DrawScene();

#endif
