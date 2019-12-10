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

}MaidRobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;
	
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

void InitMaidRobot();

void InitSearchGameRobot();

void InitPuzzleGameRobot();

void InitMysteryGameRobot();

void InitSuprised();

void DrawRobot();

void DrawMaidRobot();

void DrawSearchGameRobot();

void DrawPuzzleGameRobot();

void DrawMysteryGameRobot();

void DrawSuprised();

void DrawTalkMaid();

#endif
