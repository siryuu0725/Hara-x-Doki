#define DIRECTINPUT_VERSION 0x0800
#define MOUSE_ON_VALUE (0x80)		// オン状態の値
#include "Input.h"
#include <Windows.h>
#include <dinput.h>
#include "Window.h"

// キー情報構造体
struct INPUTSTATE
{
	DWORD now;
	DWORD trg;
	DWORD ntrg;
};

// DIRECTINPUT8のポインタ
static LPDIRECTINPUT8 g_pInputInterface;

static LPDIRECTINPUTDEVICE8 g_KeyDevice;    // DIRECTINPUTDEVICE8のキーポインタ
static LPDIRECTINPUTDEVICE8 g_MouseDevice;  // DIRECTINPUTDEVICE8のマウスポインタ

// キー情報
static INPUTSTATE g_InputState;

//マウス情報
static DIMOUSESTATE g_PrevMouseState;			//!< マウスの１フレーム前の入力情報
static DIMOUSESTATE g_CurrentMouseState;		//!< マウスの現在の入力情報
static Vec2 g_MousePos;
static Vec2 g_MouseMoveVec;

void UpdateMouse();

#pragma region DirectInput初期化
bool InitDirectInput(HINSTANCE instance_handle, HWND window_handle)
{
	// IDirectInput8インターフェイスの取得
	HRESULT hr = DirectInput8Create(instance_handle,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&g_pInputInterface,
		NULL);
	if (FAILED(hr))
	{
		return false;
	}

	// IDirectInputDevice8インターフェイスの取得
	hr = g_pInputInterface->CreateDevice(GUID_SysKeyboard, &g_KeyDevice, NULL);
	if (FAILED(hr))
	{
		return false;
	}
	hr = g_pInputInterface->CreateDevice(GUID_SysMouse, &g_MouseDevice, NULL);
	if (FAILED(hr))
	{
		return false;
	}


	// デバイスのフォーマットの設定
	hr = g_KeyDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		return false;
	}
	hr = g_MouseDevice->SetDataFormat(&c_dfDIMouse);
	if (FAILED(hr))
	{
		return false;
	}


	// 協調モードの設定
	hr = g_KeyDevice->SetCooperativeLevel(window_handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		return false;
	}
	hr = g_MouseDevice->SetCooperativeLevel(window_handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		return false;
	}

	// デバイスの設定
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;	// 相対値モードで設定（絶対値はDIPROPAXISMODE_ABS）

	if (FAILED(g_KeyDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		// デバイスの設定に失敗
		return false;
	}
	if (FAILED(g_MouseDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		// デバイスの設定に失敗
		return false;
	}

	//デバイスの取得開始
	g_KeyDevice->Acquire();
	g_MouseDevice->Acquire();

	return true;
}
#pragma endregion

#pragma region DirectInput解放
void ReleaseDirectInput()
{
	g_KeyDevice->Unacquire();
	g_KeyDevice->Release();
	g_MouseDevice->Unacquire();
	g_MouseDevice->Release();
	g_pInputInterface->Release();
}
#pragma endregion

#pragma region キーUpdate
void KeyUpDate()
{
	// キー情報取格納用
	BYTE KeyState[256];
	HRESULT hr;

	// キーボードデバイスのゲッター
	hr = g_KeyDevice->GetDeviceState(sizeof(BYTE) * 256, KeyState);
	if (SUCCEEDED(hr))
	{
		// 1フレーム前のキー情報の確保
		DWORD old = g_InputState.now;

		g_InputState.now = 0;

		// 上キー
		if (KeyState[DIK_UP] & 0x80)
		{
			g_InputState.now |= UP_KEY;
		}

		// 下キー
		if (KeyState[DIK_DOWN] & 0x80)
		{
			g_InputState.now |= DOWN_KEY;
		}

		// 左キー
		if (KeyState[DIK_LEFT] & 0x80)
		{
			g_InputState.now |= LEFT_KEY;
		}

		//右キー
		if (KeyState[DIK_RIGHT] & 0x80)
		{
			g_InputState.now |= RIGHT_KEY;
		}

		//Enterキー
		if (KeyState[DIK_RETURN] & 0x80)
		{
			g_InputState.now |= RETURN_KEY;
		}

		// スペースキー
		if (KeyState[DIK_SPACE] & 0x80)
		{
			g_InputState.now |= SPACE_KEY;
		}

		g_InputState.trg = (g_InputState.now & (~old));	// トリガー情報取得
		g_InputState.ntrg = (~g_InputState.now) & old;	// 逆トリガー情報取得

	}
	else if (hr == DIERR_INPUTLOST) {
		g_KeyDevice->Acquire();
	}
}
#pragma endregion

//押している間
bool GetKey(DWORD key_code)
{
	return g_InputState.now & key_code;
}

//押した瞬間
bool GetKeyDown(DWORD key_code)
{
	return g_InputState.trg & key_code;
}

//離した瞬間
bool GetKeyUp(DWORD key_code)
{
	return g_InputState.ntrg & key_code;
}


void UpdateInput()
{
	UpdateMouse();

	g_PrevMouseState = g_CurrentMouseState;
	// マウスの状態を取得します
	HRESULT	hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	if (FAILED(hr))
	{
		g_MouseDevice->Acquire();
		hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	}
}

//押している間
bool OnMouseDown(MouseButton button_type)
{
	if (!(g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE) &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}

//押した瞬間
bool OnMousePush(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}


//離した瞬間
bool OnMouseUp(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		!(g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE))
	{
		return true;
	}

	return false;
}

#pragma region マウスの座標所得
void UpdateMouse()
{
	Vec2 prev = g_MousePos;
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(FindWindowA("後期チーム制作", nullptr), &p);

	g_MousePos.X = (float)p.x;
	g_MousePos.Y = (float)p.y;

	g_MouseMoveVec.X = g_MousePos.X - prev.X;
	g_MouseMoveVec.Y = g_MousePos.Y - prev.Y;
}
#pragma endregion

Vec2 GetMousePos()
{
	return g_MousePos;
}
