#include "Robot.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"

#define ROBOTSIZE 150
#define SURPRISEDSIZE 50

RobotData robot;
SurprisedData surprised;

void InitRobot()
{
	robot.pos_x = 960.0f;
	robot.pos_y = 200.0f;
}

void InitSuprised()
{
	surprised.pos_x = robot.pos_x + SURPRISEDSIZE;
	surprised.pos_y = robot.pos_y - SURPRISEDSIZE;
}

void DrawRobot()
{
	DrawTexture(robot.pos_x, robot.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkRobot));
}

void DrawSuprised()
{
	if (backplayer.pos_x >= robot.pos_x - ROBOTSIZE && backplayer.pos_x <= robot.pos_x + ROBOTSIZE && backplayer.pos_y >= robot.pos_y - ROBOTSIZE && backplayer.pos_y <= robot.pos_y + ROBOTSIZE)
	{
		DrawTexture(surprised.pos_x, surprised.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkSurprised));
	}
}
