#include "Robot.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"
#include "Hit.h"
#include "Item.h"
#include "Text.h"
#include "Talk.h"
#include "Bg.h"
#include "JK.h"

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
	
	if (areadata.cangearea == true && maidrobot.talktype != 0)
	{
		maidrobot.talktype = 1;
	}
	else
	{
		maidrobot.talktype = 0;
	}
}

void InitSearchGameRobot()
{
	searchgamerobot.pos_x = 800.0f;
	searchgamerobot.pos_y = 400.0f;
	searchgamerobot.height = 128.0f;
	searchgamerobot.width = 64.0f;
	searchgamerobot.talk = false;
	if (puzzle.goal_key == false)
	{
		searchgamerobot.talktype = 0;
	}
}

void InitPuzzleGameRobot()
{
	puzzlegamerobot.pos_x = 910.0f;
	puzzlegamerobot.pos_y = 530.0f;
	puzzlegamerobot.height = 128.0f;
	puzzlegamerobot.width = 64.0f;
	puzzlegamerobot.talk = false;
	if (puzzle.goal_key == false)
	{
		puzzlegamerobot.talktype = 0;

	}
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
	DrawTexture(maidrobot.pos_x, maidrobot.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomMaidRobotTex));
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
	DrawUVTexture(searchplayer.pos_x, searchplayer.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchPlayerTex), 64.0f, 128.0f, searchplayer.animetion_tu, searchplayer.animetion_tv);
	DrawTexture(puzzlegamerobot.pos_x, puzzlegamerobot.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex));
}

void DrawMysteryGameRobot()
{
	DrawTexture(mysterygamerobot.pos_x, mysterygamerobot.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRobotTex));
}
#pragma endregion

#pragma region 会話関数

//メイド会話描画
void DrawTalkMaid()
{
	if (largeroomobject.maid == true && maidrobot.talk == false)
	{
		maidrobot.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.robot_threeline == NULL && maidrobot.talk == true)
	{
		maidrobot.talk = false;
		textbox.onspacekey = false;
		maidrobot.talktype++;
		
		InitRobotLoadFile();

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
		DrawTexture(500.0f, 0.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
		if (strstr(textdata.robot_oneline, "‥‥") || strstr(textdata.robot_oneline, "不気味"))
		{
			DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawFont(100, 610, "メイドロボ", FontSize::Regular, FontColor::Yellow);
		}
		DrawRobotTalkText();
	}
}

//探索ゲームロボット会話描画
void DrawTalkSearchGameRobot()
{
	if (searchgameobject.robot == true && searchgamerobot.talk == false)
	{
		searchgamerobot.talk = true;
		textbox.onspacekey = true;
		
	}
	else if (textdata.robot_threeline == NULL && searchgamerobot.talk == true)
	{
		searchgamerobot.talk = false;
		textbox.onspacekey = false;
		textdata.robot_nexttext = false;
		InitRobotLoadFile();

	}
	if (searchgamerobot.talk == true)
	{
		if (searchgameobject.completerobot == true)
		{
			
			if (strstr(textdata.robot_oneline, "再起動します。") || strstr(textdata.robot_oneline, "少女を移動させる")|| strstr(textdata.robot_oneline, "まさか"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				DrawTexture(400.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "執事ロボ", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.robot_oneline, "これで"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
			}
			else
			{
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			}
			
		}
		else
		{
			if (strstr(textdata.robot_oneline, "あ、それ"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				DrawTexture(600.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "ナツナ", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.robot_oneline, "やってみよう"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
			}
			else
			{
				DrawTexture(400.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot_NoNeckTex));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));

			}
		}
		DrawRobotTalkText();
	}
}

//パズルゲームロボット会話描画
void DrawTalkPuzzleGameRobot()
{
	if (yuruhuwaobject.robot == true && puzzlegamerobot.talk == false)
	{
		puzzlegamerobot.talk = true;
		textbox.onspacekey = true;

	}
	else if (textdata.robot_threeline == NULL && puzzlegamerobot.talk == true)
	{
		puzzlegamerobot.talk = false;
		textbox.onspacekey = false;
		textdata.robot_nexttext = false;

		if (puzzle.goal_key == true)
		{
			yuruhuwa.clear = true;

		}

		InitRobotLoadFile();

	}
	if (puzzlegamerobot.talk == true)
	{
		if (puzzle.goal_key == true)
		{
			if (strstr(textdata.robot_oneline, "これで"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "主人公", FontSize::Regular, FontColor::Yellow);
			}
			else
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				DrawTexture(400.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "執事ロボ", FontSize::Regular, FontColor::Yellow);
			}
		}
		else
		{
			if (strstr(textdata.robot_oneline, "さぁご友人") || strstr(textdata.robot_oneline, "やりますね") || strstr(textdata.robot_oneline, "この問題"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				DrawTexture(400.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot));
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "執事ロボ", FontSize::Regular, FontColor::Yellow);
			}
			else
			{
				DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			}
			if (strstr(textdata.robot_oneline, "はい"))
			{
				DrawChoiceTexture();
			}

		}
		
		DrawRobotTalkText();
	}
}

//謎解きゲームロボット会話描画
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
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		
	}
}



void UpDateTalkMaid()
{
	if (GetKeyDown(SPACE_KEY) == true && largeroomobject.maid == true)
	{
		
		RobotLoadText();
		
		textdata.robot_nexttext = true;
		if (maidrobot.talktype == 6)
		{
			maidrobot.talktype = 1;
		}
	}
}

void UpDateTalkSearchGameRobot()
{
	if (searchgameobject.robot == true)
	{
		if (getitem.itemenergy == true)
		{
			InitRobotLoadFile();
		}
		RobotLoadText();
		
		textdata.robot_nexttext = true;
		if (searchgamerobot.talktype == 3)
		{
			searchgamerobot.talktype = 1;
		}
	}
}

void UpDateTalkPuzzleGameRobot()
{
	if (yuruhuwaobject.robot == true)
	{
		/*if (puzzle.goal_key == true)
		{
			InitRobotLoadFile();
		}*/

		if ((puzzlegamerobot.talk == true && choicetexturedata.Choicepos == 1))
		{
			puzzlegamerobot.play = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;
		}
		else if ((puzzlegamerobot.talk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;

		}

		RobotLoadText();

		textdata.robot_nexttext = true;
	}
}
#pragma endregion