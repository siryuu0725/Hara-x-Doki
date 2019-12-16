#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	bool maid;         //���{
	bool light;         //���C�g
	bool desk;          //��
	bool chair;         //�֎q
	bool flowerpot;     //�A�ؔ�

}SearchTouchObject;

typedef struct
{
	bool robot;         //���{
	bool robotneck;     //���{�̓�
	bool completerobot; //���{�����`
	bool light;         //���C�g


	bool desk;          //��
	bool chair;         //�֎q
	bool doll;          //�l�`
	bool bed;           //�x�b�h
	bool flowerpot;     //�A�ؔ�
	bool closet;        //�N���[�[�b�g
	bool bookshelf;     //�{�I

}SearchGameTouchObject;

typedef struct
{
	bool robot;         //���{
	bool yuruhuwa;

	bool light;         //���C�g
	bool desk;          //��
	bool chair;         //�֎q
	bool doll;          //�l�`
	bool bed;           //�x�b�h
	bool flowerpot;     //�A�ؔ�
	bool closet;        //�N���[�[�b�g
	bool bookshelf;     //�{�I

}YuruhuwaTouchObject;

typedef struct
{
	bool robot;         //���{

	bool light;         //���C�g
	bool desk;          //��
	bool chair;         //�֎q
	bool doll;          //�l�`
	bool bed;           //�x�b�h
	bool flowerpot;     //�A�ؔ�
	bool closet;        //�N���[�[�b�g
	bool bookshelf;     //�{�I

}TundereTouchObject;


typedef struct
{
	bool itemrobot;   //���{�̎�
	bool itemkey;     //��
	bool itemenergy;  //�d�r
	bool itemlight;   //���C�g
	bool boyishdoorkey;
	bool yuruhuwadoorkey;
	bool tunderedoorkey;
	bool breakdoorkey;

}GetItem;

extern SearchTouchObject searchobject;

extern SearchGameTouchObject searchgameobject;

extern YuruhuwaTouchObject yuruhuwaobject;

extern TundereTouchObject tundereobject;

extern GetItem getitem;



void InitSearchGameObject();

void InitTundereRoomObject();

void InitYuruhuwaRoomObject();

void LoadSearchGameItem();

void DrawRobotNeck();


/*
   ���ꂼ��̕����̉Ƌ�Tex
*/
void LoadSearch2FurnitureTex();

void LoadTundereFurnitureTex();

void LoadYuruhuwaFurnitureTex();

void LoadCriminalFurnitureTex();


/*
�@�@�T���p�[�g�ł̃I�u�W�F�N�g�Ƃ̂����蔻��
�@�@��`�Ƌ�`�̂����蔻��
*/
void HitSearchObject();

void HitSearch2Object();

void HitTundereRoomObject();

void HitYuruhuwaRoomObject();

void HitCriminalRoomObject();

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

void HitEyeTundereRoomObject();

void HitEyeYuruhuwaRoomObject();

void HitEyeCriminalRoomObject();


void UpDataSearchGame();

#endif

