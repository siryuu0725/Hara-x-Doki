#include "Robot.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"
#include "Hit.h"
#include "Item.h"
#include "Text.h"

#define ROBOTSIZE 150
#define SURPRISEDSIZE 50

RobotData robot;
SurprisedData surprised;
MaidRobotData maidrobot;

SearchGameRobotData searchgamerobot;
PuzzleGameRobotData puzzlegamerobot;
MysteryGameRobotData mysterygamerobot;

void InitRobot()
{
	robot.pos_x = 860.0f;
	robot.pos_y = 200.0f;
}

void InitMaidRobot()
{
	maidrobot.pos_x = 920.0f;
	maidrobot.pos_y = 700.0f;
	maidrobot.height = 128.0f;
	maidrobot.width = 64.0f;
	maidrobot.talk = false;
}

void InitSearchGameRobot()
{
	searchgamerobot.pos_x = 800.0f;
	searchgamerobot.pos_y = 400.0f;
	searchgamerobot.height = 128.0f;
	searchgamerobot.width = 64.0f;
	searchgamerobot.talk = false;
}

void InitPuzzleGameRobot()
{
	puzzlegamerobot.pos_x = 910.0f;
	puzzlegamerobot.pos_y = 530.0f;
	puzzlegamerobot.height = 128.0f;
	puzzlegamerobot.width = 64.0f;
	puzzlegamerobot.talk = false;

}

void InitMysteryGameRobot()
{
	mysterygamerobot.pos_x = 910.0f;
	mysterygamerobot.pos_y = 550.0f;
	mysterygamerobot.height = 128.0f;
	mysterygamerobot.width = 64.0f;
	mysterygamerobot.talk = false;

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

void DrawMaidRobot()
{
	DrawTexture(maidrobot.pos_x, maidrobot.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchMaidRobotTex));
}

void DrawSuprised()
{
	if (backplayer.pos_x >= robot.pos_x - ROBOTSIZE && backplayer.pos_x <= robot.pos_x + ROBOTSIZE && backplayer.pos_y >= robot.pos_y - ROBOTSIZE && backplayer.pos_y <= robot.pos_y + ROBOTSIZE)
	{
		DrawTexture(surprised.pos_x, surprised.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex));
	}
}

void DrawSearchGameRobot()
{
	if (searchgameobject.completerobot == true)
	{
		DrawTexture(searchgamerobot.pos_x, searchgamerobot.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameCompleteRobotTex));
	}
	else
	{
		DrawTexture(searchgamerobot.pos_x, searchgamerobot.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex));
	}
}

void DrawPuzzleGameRobot()
{
	DrawTexture(puzzlegamerobot.pos_x, puzzlegamerobot.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex));
}

void DrawMysteryGameRobot()
{
	DrawTexture(mysterygamerobot.pos_x, mysterygamerobot.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRobotTex));
}

void DrawTalkMaid()
{
	if (searchobject.maid == true && maidrobot.talk == false)
	{
		maidrobot.talk = true;

	}
	else if (GetKeyDown(SPACE_KEY) == true && maidrobot.talk == true)
	{
		maidrobot.talk = false;
		time.start = true;
		if (getitem.breakdoorkey == false)
		{
			getitem.doorkey = true;
		}
	}
	if (maidrobot.talk == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
	}
}

void DrawTalkSearchGameRobot()
{
	if (searchgameobject.robot = true && searchgamerobot.talk == false)
	{
		searchgamerobot.talk = true;

	}
	else if (GetKeyDown(SPACE_KEY) == true && searchgamerobot.talk == true)
	{
		searchgamerobot.talk = false;
	}
	if (searchgamerobot.talk == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobotTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
	}
}