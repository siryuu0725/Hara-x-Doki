#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	float pos_x, pos_y;
	bool get;            //�A�C�e������ɓ��ꂽ���ǂ���
}RobotNeck;

extern RobotNeck neck;

void DrawRobotNeck();

void HitSearchObject();

void HitSearchGameObject();



#endif

