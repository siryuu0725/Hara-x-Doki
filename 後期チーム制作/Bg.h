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

void DrawTalkBg();

void UpDateBg();

#endif