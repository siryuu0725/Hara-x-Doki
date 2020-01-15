#include "Robot.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"
#include "Hit.h"
#include "Item.h"
#include "Text.h"
#include "Talk.h"

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

#pragma region ロボット初期化
void InitMaidRobot()
{
	maidrobot.pos_x = 920.0f;
	maidrobot.pos_y = 700.0f;
	maidrobot.height = 128.0f;
	maidrobot.width = 64.0f;
	maidrobot.talk = false;
	maidrobot.description = false;
	maidrobot.talktype = 0;
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
#pragma endregion

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

#pragma region ロボット描画
void DrawMaidRobot()
{
	DrawTexture(maidrobot.pos_x, maidrobot.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchMaidRobotTex));
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
	DrawUVTexture(searchplayer.pos_x, searchplayer.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex), 64.0f, 128.0f, searchplayer.animetion_tu, searchplayer.animetion_tv);
	DrawTexture(puzzlegamerobot.pos_x, puzzlegamerobot.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex));
}

void DrawMysteryGameRobot()
{
	DrawTexture(mysterygamerobot.pos_x, mysterygamerobot.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRobotTex));
}
#pragma endregion

#pragma region 会話関数
void DrawTalkMaid()
{
	if (largeroomobject.maid == true && maidrobot.talk == false)
	{
		maidrobot.talk = true;
		textbox.onspacekey = true;
		maidrobot.talktype++;
	}
	else if (textdata.threeline == NULL && maidrobot.talk == true)
	{
		maidrobot.talk = false;
		textbox.onspacekey = false;

		//会話が終わると同時に時間制限スタート
		time.start = true;
		
		//ドアを開けるためのカギをもらう
		if (getitem.breakdoorkey == false)
		{
			getitem.boyishdoorkey = true;
			getitem.tunderedoorkey = true;
			getitem.yuruhuwadoorkey = true;
		}
	}
	if (maidrobot.talk == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawTalkText();

		//DrawChoiceTexture();
	}
}

void DrawTalkSearchGameRobot()
{
	if (searchgameobject.robot == true && searchgamerobot.talk == false)
	{
		searchgamerobot.talk = true;
		textbox.onspacekey = true;
		
	}
	else if (GetKeyDown(SPACE_KEY) == true && searchgamerobot.talk == true)
	{
		searchgamerobot.talk = false;
		textbox.onspacekey = false;
	}
	if (searchgamerobot.talk == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobotTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
	}
}

void DrawTalkPuzzleGameRobot()
{
	if (yuruhuwaobject.robot == true && puzzlegamerobot.talk == false)
	{
		puzzlegamerobot.talk = true;
		textbox.onspacekey = true;
	}
	else if (GetKeyDown(SPACE_KEY) == true && puzzlegamerobot.talk == true)
	{
		puzzlegamerobot.talk = false;
		textbox.onspacekey = false;
	}
	if (puzzlegamerobot.talk == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkRobotTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
	}
}

void DrawTalkMysteryGameRobot()
{
	if (tundereobject.robot == true && mysterygamerobot.talk == false)
	{
		mysterygamerobot.talk = true;
		textbox.onspacekey = true;

	}
	else if (GetKeyDown(SPACE_KEY) == true && mysterygamerobot.talk == true)
	{
		mysterygamerobot.talk = false;
		textbox.onspacekey = false;
	}
	if (mysterygamerobot.talk == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTalkRobotTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		
	}
}

void UpDateTalkMaid()
{
	if (GetKeyDown(SPACE_KEY) == true)
	{
		
		LoadText();
		textdata.nexttext = true;
	}
}
#pragma endregion