#ifndef MAID_H
#define MAID_H

typedef struct
{
	bool talk;

}MaidData;

extern MaidData maid;

void InitMaid();

void DrawTalkMaid();



#endif // !MAID_H
