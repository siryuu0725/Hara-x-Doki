#ifndef GRAHPICS
#define GRAHPICS

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

#include <Windows.h>

#define SMALL_FONT_SIZE (16)	//!< �t�H���g�T�C�Y(��)
#define REGULAR_FONT_SIZE (50)	//!< �t�H���g�T�C�Y(��)
#define LARGE_FONT_SIZE (70)	//!< �t�H���g�T�C�Y(��)

struct TEXTURE_DATA
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
	Pink,
	Aqua,
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

bool CreateTexture(const char* file_name, TEXTURE_DATA* texture_data);

//�w�i�p
void DrawBgTexture(TEXTURE_DATA*);

//���W�w��p
void DrawTexture(float x, float y, TEXTURE_DATA* texture_data);

//�A�j���[�V�����p
void DrawUVTexture(float x, float y, TEXTURE_DATA* texture, float sprite_width, float sprite_height, float tu, float tv);

void ReleaseTexture(TEXTURE_DATA*);

void DrawFont(float pos_x, float pos_y, const char* text, FontSize font_type, FontColor color);

bool CreateFontDevice();

#endif
