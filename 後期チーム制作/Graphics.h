#ifndef GRAHPICS
#define GRAHPICS

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

#include <Windows.h>

#define SMALL_FONT_SIZE (16)	//!< フォントサイズ(小)
#define REGULAR_FONT_SIZE (60)	//!< フォントサイズ(中)
#define LARGE_FONT_SIZE (80)	//!< フォントサイズ(大)

struct TEXTURE_DATE
{
	LPDIRECT3DTEXTURE9 Texture;
	float Width;
	float Height;
};


enum FontColor
{
	Black,
	White,
	Red,
	Yellow,
};

enum FontSize
{
	Small,
	Regular,
	Large,
	FontSizeMax,
};


struct CUSTOM_VERTEX
{
	float x;
	float y;
	float z;
	float rhw;
	float tu;
	float tv;
};

bool InitDirectGraphics(HWND window_handle);

void ReleaseDirectGraphics();

bool DrawStart();

void DrawEnd();

bool CreateTexture(const char* file_name, TEXTURE_DATE* texture_data);

void DrawBgTexture(TEXTURE_DATE*);

void DrawTexture(float x, float y, TEXTURE_DATE* texture_data);

void DrawUVTexture(float x, float y, TEXTURE_DATE* texture, float sprite_width, float sprite_height, float tu, float tv);

void ReleaseTexture(TEXTURE_DATE*);

void DrawFont(float pos_x, float pos_y, const char* text, FontSize font_type, FontColor color);

bool CreateFontDevice();

#endif
