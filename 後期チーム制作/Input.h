#ifndef DIRECT_INPUT_H_
#define DIRECT_INPUT_H_

#include <Windows.h>
#include <dinput.h>

#pragma comment (lib,"dinput8.lib")
#pragma comment (lib,"dxguid.lib")


// キーコード
#define CLEAR_KEY	0x0000		// クリア用
#define UP_KEY		0x0001		// 上キー
#define DOWN_KEY	0x0002		// 下キー
#define LEFT_KEY	0x0004		// 左キー
#define RIGHT_KEY	0x0008		// 右キー
#define RETURN_KEY	0x0010	// リターンキー
#define SPACE_KEY   0x0020  // スペースキー

struct Vec2
{
	/** Constructor */
	Vec2()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	/**
	* @brief Constructor
	* @param[in] x 横幅
	* @param[in] y 縦幅
	*/
	Vec2(float x, float y)
	{
		X = x;
		Y = y;
	}

	/**
	* @brief Constructor
	* @param[in] Vec2 コピー用Vec2データ
	*/
	Vec2(const Vec2& size)
	{
		this->X = size.X;
		this->Y = size.Y;
	}

	float X;	//!< X値
	float Y;	//!< Y値
};

enum MouseButton
{
	Left,		//!< 左
	Right,		//!< 右
	Center,		//!< 真ん中
};

bool InitDirectInput(HINSTANCE instance_handle, HWND window_handle);

void KeyUpDate();

bool GetKey(DWORD key_code);

bool GetKeyDown(DWORD key_code);

bool GetKeyUp(DWORD key_code);

void UpdateInput();


bool OnMouseDown(MouseButton button_type);


bool OnMousePush(MouseButton button_type);


bool OnMouseUp(MouseButton button_type);


Vec2 GetMousePos();

void ReleaseDirectInput();


#endif
