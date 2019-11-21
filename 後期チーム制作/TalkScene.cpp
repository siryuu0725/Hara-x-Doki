#include "Graphics.h"
#include "Input.h"
#include "Texture.h"
#include "TalkScene.h"
#include "Player.h"
#include "Bg.h"
#include "Robot.h"
#include "Menu.h"

#define ROBOTSIZE 150 // ロボットのサイズ

extern BackPlayerData backplayer;
extern RobotData robot;
extern MenuData menu;

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
	DrawMenu();
}

void InitTalkScene()
{
	LoadTexture("Res/犯人部屋.png", TEXTURE_TALK, TalkCategoryTextureList::TalkBgTex);
	LoadTexture("Res/Robot.png", TEXTURE_TALK, TalkCategoryTextureList::TalkRobotTex);
	LoadTexture("Res/ラフキャラ.jpg", TEXTURE_SEARCH, SearchCategoryTextureList::SearchPlayerTex);
	LoadTexture("Res/Surprised.png", TEXTURE_TALK, TalkCategoryTextureList::TalkSurprisedTex);
	LoadTexture("Res/Menu.png", TEXTURE_TALK, TalkCategoryTextureList::MenuTex);

	InitRobot();
	InitBackPlayer();
	InitSuprised();
	InitMenu();

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTalkScene()
{
	UpDateMenu();
	//SearchPlayerControl();

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

	if (menu.onenterkey == true)
	{
		menu.onenterkey = false;
		return SceneId::TitleScene;
	}

	else
	{
		return SceneId::PuzzleGameScene;
	}
}
