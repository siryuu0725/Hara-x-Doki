#ifndef BG_
#define BG_

typedef struct
{
	float Tu, Tv;
	float moveflg;
	float movespeed;

}MovieBgDate;
	
void InitBg();

void DrawBg();

void DrawSearchBg();

void DrawSearch2Bg();

void DrawTalkBg();

void UpDateBg();

#endif