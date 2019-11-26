#ifndef ITEM_H
#define ITEM_H

typedef struct
{
	float pos_x, pos_y;
	bool get;            //ƒAƒCƒeƒ€‚ðŽè‚É“ü‚ê‚½‚©‚Ç‚¤‚©
}RobotNeck;

extern RobotNeck neck;

void DrawRobotNeck();

void HitSearchObject();

void HitSearchGameObject();



#endif

