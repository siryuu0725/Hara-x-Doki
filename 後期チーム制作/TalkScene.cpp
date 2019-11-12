#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "TalkScene.h"
#include "Player.h"
#include "Bg.h"
#include "Robot.h"

#define ROBOTSIZE 150 // ロボットのサイズ

extern BackPlayerData backplayer;
extern RobotData robot;

void InitTalkScene();

void MainTalkScene();

SceneId FinishTalkScene();

SceneId UpdateTalkScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitTalkScene();
		break;
	case SceneStep::MainStep:
		MainTalkScene();
		break;
	case SceneStep::EndStep:
		return FinishTalkScene();
		break;
	}

	return SceneId::TalkScene;
}

void DrawTalkScene()
{
	DrawTalkBg();
	DrawRobot();
	DrawBackPlayer();
	DrawSuprised();
}

void InitTalkScene()
{
	LoadTexture("Res/room.png", TEXTURE_TALK, TalkCategoryTextureList::TalkBgTex);
	LoadTexture("Res/Robot.png", TEXTURE_TALK, TalkCategoryTextureList::TalkRobotTex);
	LoadTexture("Res/backplayer.png", TEXTURE_TALK, TalkCategoryTextureList::TalkPlayerTex);
	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);

	InitRobot();
	InitBackPlayer();
	InitSuprised();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTalkScene()
{
	UpDateBackPlayer(&backplayer);

	if (backplayer.pos_x >= robot.pos_x - ROBOTSIZE && backplayer.pos_x <= robot.pos_x + ROBOTSIZE &&
		backplayer.pos_y >= robot.pos_y - ROBOTSIZE && backplayer.pos_y <= robot.pos_y + ROBOTSIZE)
	{
		if (GetKeyDown(SPACE_KEY) == true)
		{
			ChangeSceneStep(SceneStep::EndStep);
		}
	}	
}

SceneId FinishTalkScene()
{
	ReleaseCategoryTexture(TEXTURE_TALK);

	return SceneId::PuzzleGameScene;
}
