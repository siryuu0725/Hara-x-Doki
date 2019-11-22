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
	bool hit;
}SearchRobotData;

typedef struct
{
	float pos_x, pos_y;
}SurprisedData;

extern RobotData robot;

extern SearchRobotData searchrobot;

extern SurprisedData surprised;

void InitRobot();

void InitSearchRobot();

void InitSuprised();

void DrawRobot();

void DrawSearchRobot();

void HitSearchPlayerRobot();

void DrawSuprised();
#endif
