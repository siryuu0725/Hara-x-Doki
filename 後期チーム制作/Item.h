#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	float pos_x, pos_y;
	bool get;
}RobotNeck;

extern RobotNeck neck;

void DrawRobotNeck();


#endif

