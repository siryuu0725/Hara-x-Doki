#ifndef HIT_
#define HIT_
#include "Puzzle.h"

bool HitChoiseTitle(float x, float y, float width, float height);


#pragma region �T���p�[�g
/*
     ����(�G���A)�ړ����s���Ƃ��̈ړ�����
	�������Ă����true
	 ��`�Ɠ_�ł����蔻����Ƃ��Ă���
	 ����
	 �@�@(����,�E��,���,���)
*/
bool HitNextArea(float left_x, float right_x, float up_y, float down_y);


/*
	�v���C���[�ƃI�u�W�F�N�g�̂����蔻��
	�������Ă����true
	��`�Ƌ�`�ł����蔻����Ƃ��Ă���
	����
	 �@�@(�I�u�W�F�N�g��x���W,�I�u�W�F�N�g��y���W,�I�u�W�F�N�g�̉��T�C�Y,�I�u�W�F�N�g�̏c�T�C�Y)
*/
bool HitPlayerObject(float obj_x, float obj_y, float obj_width, float obj_height);


/*
	�v���C���[�̎��E�ƃI�u�W�F�N�g�̂����蔻��
	�������Ă����true
	��`�Ƌ�`�ł����蔻����Ƃ��Ă���
	����
	 �@�@(�I�u�W�F�N�g��x���W,�I�u�W�F�N�g��y���W,�I�u�W�F�N�g�̉��T�C�Y,�I�u�W�F�N�g�̏c�T�C�Y)
*/
bool HitPlayerEyeObject(float obj_x, float obj_y, float obj_width, float obj_height);


#pragma endregion

#pragma region �p�Y���Q�[��
/*
    ���ꂼ��̃L���[�u����`�Ƌ�`�ł����蔻����Ƃ��Ă���
	�������Ă����true
	����
	�@�@(���ꂼ��̃u���b�N�̎n�܂�̗v�f�ԍ�,
	  �@ ���ꂼ��̃u���b�N�̍Ō�̗v�f�ԍ�,
		 �������L���[�u�̎��,
		 �������L���[�u�̉���,
		 �������L���[�u�̏c��,
		 ������Ƃ�L���[�u�̉���,
		 ������Ƃ铮�����L���[�u�̏c��,
*/
bool HitCabe(int d, int d2, int idx_, PuzzleCabe* puzzle1, float width, float height, float Compare_width, float Compare_height);
#pragma endregion

#endif