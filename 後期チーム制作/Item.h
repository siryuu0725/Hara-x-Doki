#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	bool maid;         //���{
	bool light;         //���C�g
	bool desk;          //��
	bool chair;         //�֎q
	bool flowerpot;     //�A�ؔ�
	bool sofa;          //
	bool clock;			//
	bool phone;			//
	bool hanger;		//

	bool desktalk;
	bool chairtalk;
	bool lighttalk;
	bool flowerpottalk;
	bool sofatalk;
	bool clocktalk;
	bool phonetalk;
	bool hangertalk;
	
}LargeRoomTouchObject;

typedef struct
{
	bool boyishdoor;
	bool tunderedoor;
	bool yuruhuwadoor;


	bool boyish;
	bool tundere;
	bool yuruhuwa;

	bool doortalk;
}CorridorTouchObject;

typedef struct
{
	bool boyish;
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
	bool cabinet;

	bool robottalk;         //���{
	bool robotnecktalk;     //���{�̓�

	bool cabinettalk;
	bool lighttalk;        
	bool desktalk;         
	bool chairtalk;        
	bool dolltalk;
	bool bedtalk;
	bool flowerpottalk;
	bool closettalk;
	bool bookshelftalk;
	
}SearchGameTouchObject;

typedef struct
{
	bool robot;         //���{
	bool yuruhuwa;

	bool light;         //���C�g
	bool desk;          //��
	bool chair;         //�֎q
	bool sofa;
	bool cabinet;
	bool bed;           //�x�b�h
	bool closet;        //�N���[�[�b�g

	bool lighttalk;         
	bool desktalk;
	bool chairtalk;
	
	bool cabinettalk;
	bool bedtalk;
	bool sofatalk;
	bool closettalk;

}YuruhuwaTouchObject;

typedef struct
{
	bool tundere;
	bool robot;         //���{
	bool sofa;
	bool light;         //���C�g
	bool desk;          //��
	bool chair;         //�֎q
	bool doll;          //�l�`
	bool bed;           //�x�b�h
	bool flowerpot;     //�A�ؔ�
	bool closet;        //�N���[�[�b�g

	bool lighttalk;
	bool desktalk;
	bool chairtalk;
	bool dolltalk;
	bool bedtalk;
	bool flowerpottalk;
	bool closettalk;
	bool sofatalk;
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

extern LargeRoomTouchObject largeroomobject;

extern CorridorTouchObject corridorobject;

extern SearchGameTouchObject searchgameobject;

extern YuruhuwaTouchObject yuruhuwaobject;

extern TundereTouchObject tundereobject;

extern GetItem getitem;

void InitLargeRoomObject();

void InitSearchGameObject();

void InitTundereRoomObject();

void InitYuruhuwaRoomObject();

void LoadSearchGameItem();

void DrawRobotNeck();


/*
   ���ꂼ��̕����̉Ƌ�Tex
*/
void LoadCorridorFurnitureTex();

void LoadTundereFurnitureTex();

void LoadYuruhuwaFurnitureTex();

void LoadCriminalFurnitureTex();


/*
�@�@�T���p�[�g�ł̃I�u�W�F�N�g�Ƃ̂����蔻��
�@�@��`�Ƌ�`�̂����蔻��
*/
void HitLargeRoomObject();

void HitCorridorObject();

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
void HitEyeLargeRoomObject();


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


void SearchObject();

void DrawDoorTalk();
#endif

