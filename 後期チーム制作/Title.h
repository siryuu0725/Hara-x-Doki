#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_
//#include "Scene.h"

#define START_X 700 // �n�߂��X���W
#define START_X_SIZE 600 // �n�߂��X���W�̃T�C�Y
#define START_Y 700 // �n�߂��Y���W
#define START_Y_SIZE 100 // �n�߂��Y���W�̃T�C�Y
#define END_X 700 // �I����X���W
#define END_X_SIZE 600 // �I����X���W�̃T�C�Y
#define END_Y 900 // �I����Y���W
#define END_Y_SIZE 100 // �I����Y���W�̃T�C�Y


/**
* @brief �^�C�g���V�[���̍X�V�֐�@n
* �^�C�g���V�[���̎d�l�����s�����
* @return �J�ڐ�V�[��ID(��{��SceneId::TitleScene���Ԃ�)
*/
SceneId UpdateTitleScene();

/**
* @brief �^�C�g���V�[���̕`��֐�@n
* �^�C�g���V�[���̃I�u�W�F�N�g��`�悷��֐�
*/
void DrawTitleScene();

#endif

