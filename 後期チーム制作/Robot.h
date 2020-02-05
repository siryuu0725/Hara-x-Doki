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
	bool talk;             //��b���t���O
						   
	int talktype;		   //��b���
	bool description;	   //�u�͂��v��I�񂾎�

}MaidRobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;             //��b���t���O
	int talktype;          //��b��� 
	
}SearchGameRobotData;


typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;              //��b���t���O
	int talktype;			//��b��� 
	bool play;


}PuzzleGameRobotData;

typedef struct
{
	float pos_x, pos_y;
	float width, height;
	bool talk;
	int talktype;			//��b��� 
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

#pragma region ���{�b�g������
void InitMaidRobot();

void InitSearchGameRobot();

void InitPuzzleGameRobot();

void InitMysteryGameRobot();
#pragma endregion

void InitSuprised();


#pragma region ���{�b�g�`��
void DrawMaidRobot();

void DrawSearchGameRobot();

void DrawPuzzleGameRobot();

void DrawMysteryGameRobot();
#pragma endregion



#pragma region ��b�`��
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
