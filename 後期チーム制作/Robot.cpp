#include "Robot.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"
#include "Hit.h"

#define ROBOTSIZE 150
#define SURPRISEDSIZE 50

RobotData robot;
SurprisedData surprised;
SearchRobotData searchrobot;

void InitRobot()
{
	robot.pos_x = 860.0f;
	robot.pos_y = 200.0f;
}

void InitSearchRobot()
{
	searchrobot.pos_x = 800.0f;
	searchrobot.pos_y = 400.0f;
	searchrobot.height = 128.0f;
	searchrobot.width = 64.0f;
	searchrobot.hit = false;
}

void InitSuprised()
{
	surprised.pos_x = robot.pos_x + SURPRISEDSIZE;
	surprised.pos_y = robot.pos_y - SURPRISEDSIZE;
}

void DrawRobot()
{
	DrawTexture(robot.pos_x, robot.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkRobotTex));
}

void DrawSuprised()
{
	if (backplayer.pos_x >= robot.pos_x - ROBOTSIZE && backplayer.pos_x <= robot.pos_x + ROBOTSIZE && backplayer.pos_y >= robot.pos_y - ROBOTSIZE && backplayer.pos_y <= robot.pos_y + ROBOTSIZE)
	{
		DrawTexture(surprised.pos_x, surprised.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex));
	}
}

void DrawSearchRobot()
{
	DrawTexture(searchrobot.pos_x, searchrobot.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex));
}

void HitSearchPlayerRobot()
{
	if(HitPlayerObject(searchrobot.pos_x, searchrobot.pos_y, searchrobot.width, searchrobot.height) == true)
	{
		searchrobot.hit = true;
	}
	else
	{
		searchrobot.hit = false;
	}
	
}
