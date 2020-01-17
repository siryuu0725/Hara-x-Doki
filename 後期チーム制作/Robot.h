#ifndef ROBOT_H_
#define ROBOT_H_

typedef struct
{
	float pos_x, pos_y;
}RobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;

	int talktype;
	bool description;

}MaidRobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;
	int talktype;
	
}SearchGameRobotData;


typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;

}PuzzleGameRobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;

}MysteryGameRobotData;

typedef struct
{
	float pos_x, pos_y;
}SurprisedData;

extern RobotData robot;

extern MaidRobotData maidrobot;

extern SearchGameRobotData searchgamerobot;

extern PuzzleGameRobotData puzzlegamerobot;

extern MysteryGameRobotData mysterygamerobot;

extern SurprisedData surprised;

void InitRobot();

#pragma region ロボット初期化
void InitMaidRobot();

void InitSearchGameRobot();

void InitPuzzleGameRobot();

void InitMysteryGameRobot();
#pragma endregion

void InitSuprised();

void DrawRobot();

#pragma region ロボット描画
void DrawMaidRobot();

void DrawSearchGameRobot();

void DrawPuzzleGameRobot();

void DrawMysteryGameRobot();
#pragma endregion


void DrawSuprised();

#pragma region 会話描画
void DrawTalkMaid();

void DrawTalkSearchGameRobot();

void DrawTalkPuzzleGameRobot();

void DrawTalkMysteryGameRobot();
#pragma endregion

void UpDateTalkMaid();

void UpDateTalkSearchGameRobot();

#endif
