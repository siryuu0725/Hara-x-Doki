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
	bool talk;             //会話時フラグ
						   
	int talktype;		   //会話種類
	bool description;	   //「はい」を選んだ時

}MaidRobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;             //会話時フラグ
	int talktype;          //会話種類 
	
}SearchGameRobotData;


typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;              //会話時フラグ
	int talktype;			//会話種類 
	bool play;


}PuzzleGameRobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;
	int talktype;			//会話種類 
	bool play;


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


#pragma region ロボット描画
void DrawMaidRobot();

void DrawSearchGameRobot();

void DrawPuzzleGameRobot();

void DrawMysteryGameRobot();
#pragma endregion



#pragma region 会話描画
void DrawTalkMaid();

void DrawTalkSearchGameRobot();

void DrawTalkPuzzleGameRobot();

void DrawTalkMysteryGameRobot();
#pragma endregion

void UpDateTalkMaid();

void UpDateTalkSearchGameRobot();

void UpDateTalkPuzzleGameRobot();

void UpDateTalkMysteryGameRobot();


#endif
