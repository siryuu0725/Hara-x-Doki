#ifndef BG_
#define BG_

typedef struct
{
	float Tu, Tv;
	float movespeed;
	int stopcount;
}MovieBgDate;
	
void InitBg();

void DrawBg();

void DrawSearchBg();

void DrawSearch2Bg();

void DrawSearchGameBg();

void DrawTalkBg();

void UpDateBg();

#endif