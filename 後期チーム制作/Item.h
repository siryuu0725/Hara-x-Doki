#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	float pos_x, pos_y;
	bool get;            //�A�C�e������ɓ��ꂽ���ǂ���
}RobotNeck;

typedef struct
{
	bool energy;    //���{�̃G�l���M�[
	bool desk;      //��
	bool chair;     //�֎q
	bool doll;      //�l�`
	bool bed;       //�x�b�h
	bool light;     //���C�g
	bool flowerpot; //�A�ؔ�
	bool closet;    //�N���[�[�b�g
	bool bookshelf; //�{�I

}TouchObject;

extern RobotNeck neck;



void DrawRobotNeck();

/*
�@�@�T���p�[�g�ł̃I�u�W�F�N�g�Ƃ̂����蔻��
�@�@��`�Ƌ�`�̂����蔻��
*/
void HitSearchObject();

void HitTundereRoomObject();

void HitYuruhuwaRoomObject();

/*
�@�@�T���Q�[���ł̃I�u�W�F�N�g�Ƃ̂����蔻��
�@�@��`�Ƌ�`�̂����蔻��
*/
void HitSearchGameObject();


/*
�@�@�T���p�[�g�ł̃v���C���[�Ƃ��A�N�V�������N�����Ƃ���
  �@�I�u�W�F�N�g�Ƃ̎��o�̂����蔻��
�@�@��`�Ƌ�`�̂����蔻��
*/
void HitEyeSearchObject();


/*
�@�@�T���Q�[���ł̃v���C���[�Ƃ��A�N�V�������N�����Ƃ���
  �@�I�u�W�F�N�g�Ƃ̎��o�̂����蔻��
�@�@��`�Ƌ�`�̂����蔻��
*/
void HitEyeSearchGameObject();


#endif

