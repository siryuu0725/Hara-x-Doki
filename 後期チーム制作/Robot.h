#ifndef ROBOT_H_
#define ROBOT_H_

typedef struct
{
	float pos_x, pos_y;
}RobotData;

typedef struct
{
	float pos_x, pos_y;
}SurprisedData;

extern RobotData robot;

extern SurprisedData surprised;

void InitRobot();

void InitSuprised();

void DrawRobot();

void DrawSuprised();
#endif
