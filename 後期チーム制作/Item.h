#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	float pos_x, pos_y;
	bool get;            //アイテムを手に入れたかどうか
}RobotNeck;

extern RobotNeck neck;

void DrawRobotNeck();


#endif

