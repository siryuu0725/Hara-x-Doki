#ifndef BG_
#define BG_

typedef struct
{
	float Tu, Tv;
	float movespeed;
	int stopcount;
}MovieBgData;

typedef struct
{
	bool searcharea1;
	bool searcharea2;
	bool searchgamearea;
	bool cangearea;
	bool cangearea2;

}SearchAreaData;

extern SearchAreaData areadata;
	
void InitBg();

void InitArea();

void DrawBg();

void DrawSearchBg();

void DrawTalkBg();

void UpDateBg();

#endif