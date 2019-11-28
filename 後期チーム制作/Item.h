#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	float pos_x, pos_y;
	bool get;            //�A�C�e������ɓ��ꂽ���ǂ���
}RobotNeck;

typedef struct
{
	bool energy;
	bool desk;
	bool chair;
	bool doll;
	bool bed;
	bool light;
	bool flowerpot;
	bool closet;
	bool bookshelf;

}TouchObject;

extern RobotNeck neck;



void DrawRobotNeck();

void HitSearchObject();

void HitSearchGameObject();

void HitEyeSearchObject();

void HitEyeSearchGameObject();


#endif

