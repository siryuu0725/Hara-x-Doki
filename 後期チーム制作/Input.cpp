#define DIRECTINPUT_VERSION 0x0800
#define MOUSE_ON_VALUE (0x80)		// �I����Ԃ̒l
#include "Input.h"
#include <Windows.h>
#include <dinput.h>
#include "Window.h"

// �L�[���\����
struct INPUTSTATE
{
	DWORD now;
	DWORD trg;
	DWORD ntrg;
};

// DIRECTINPUT8�̃|�C���^
static LPDIRECTINPUT8 g_pInputInterface;

static LPDIRECTINPUTDEVICE8 g_KeyDevice;    // DIRECTINPUTDEVICE8�̃L�[�|�C���^
static LPDIRECTINPUTDEVICE8 g_MouseDevice;  // DIRECTINPUTDEVICE8�̃}�E�X�|�C���^

// �L�[���
static INPUTSTATE g_InputState;

//�}�E�X���
static DIMOUSESTATE g_PrevMouseState;			//!< �}�E�X�̂P�t���[���O�̓��͏��
static DIMOUSESTATE g_CurrentMouseState;		//!< �}�E�X�̌��݂̓��͏��
static Vec2 g_MousePos;
static Vec2 g_MouseMoveVec;

void UpdateMouse();

#pragma region DirectInput������
bool InitDirectInput(HINSTANCE instance_handle, HWND window_handle)
{
	// IDirectInput8�C���^�[�t�F�C�X�̎擾
	HRESULT hr = DirectInput8Create(instance_handle,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&g_pInputInterface,
		NULL);
	if (FAILED(hr))
	{
		return false;
	}

	// IDirectInputDevice8�C���^�[�t�F�C�X�̎擾
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


	// �f�o�C�X�̃t�H�[�}�b�g�̐ݒ�
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


	// �������[�h�̐ݒ�
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

	// �f�o�C�X�̐ݒ�
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;	// ���Βl���[�h�Őݒ�i��Βl��DIPROPAXISMODE_ABS�j

	if (FAILED(g_KeyDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		// �f�o�C�X�̐ݒ�Ɏ��s
		return false;
	}
	if (FAILED(g_MouseDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		// �f�o�C�X�̐ݒ�Ɏ��s
		return false;
	}

	//�f�o�C�X�̎擾�J�n
	g_KeyDevice->Acquire();
	g_MouseDevice->Acquire();

	return true;
}
#pragma endregion

#pragma region DirectInput���
void ReleaseDirectInput()
{
	g_KeyDevice->Unacquire();
	g_KeyDevice->Release();
	g_MouseDevice->Unacquire();
	g_MouseDevice->Release();
	g_pInputInterface->Release();
}
#pragma endregion

#pragma region �L�[Update
void KeyUpDate()
{
	// �L�[����i�[�p
	BYTE KeyState[256];
	HRESULT hr;

	// �L�[�{�[�h�f�o�C�X�̃Q�b�^�[
	hr = g_KeyDevice->GetDeviceState(sizeof(BYTE) * 256, KeyState);
	if (SUCCEEDED(hr))
	{
		// 1�t���[���O�̃L�[���̊m��
		DWORD old = g_InputState.now;

		g_InputState.now = 0;

		// ��L�[
		if (KeyState[DIK_UP] & 0x80)
		{
			g_InputState.now |= UP_KEY;
		}

		// ���L�[
		if (KeyState[DIK_DOWN] & 0x80)
		{
			g_InputState.now |= DOWN_KEY;
		}

		// ���L�[
		if (KeyState[DIK_LEFT] & 0x80)
		{
			g_InputState.now |= LEFT_KEY;
		}

		//�E�L�[
		if (KeyState[DIK_RIGHT] & 0x80)
		{
			g_InputState.now |= RIGHT_KEY;
		}

		//Enter�L�[
		if (KeyState[DIK_RETURN] & 0x80)
		{
			g_InputState.now |= RETURN_KEY;
		}

		// �X�y�[�X�L�[
		if (KeyState[DIK_SPACE] & 0x80)
		{
			g_InputState.now |= SPACE_KEY;
		}

		g_InputState.trg = (g_InputState.now & (~old));	// �g���K�[���擾
		g_InputState.ntrg = (~g_InputState.now) & old;	// �t�g���K�[���擾

	}
	else if (hr == DIERR_INPUTLOST) {
		g_KeyDevice->Acquire();
	}
}
#pragma endregion

//�����Ă����
bool GetKey(DWORD key_code)
{
	return g_InputState.now & key_code;
}

//�������u��
bool GetKeyDown(DWORD key_code)
{
	return g_InputState.trg & key_code;
}

//�������u��
bool GetKeyUp(DWORD key_code)
{
	return g_InputState.ntrg & key_code;
}


void UpdateInput()
{
	UpdateMouse();

	g_PrevMouseState = g_CurrentMouseState;
	// �}�E�X�̏�Ԃ��擾���܂�
	HRESULT	hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	if (FAILED(hr))
	{
		g_MouseDevice->Acquire();
		hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	}
}

//�����Ă����
bool OnMouseDown(MouseButton button_type)
{
	if (!(g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE) &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}

//�������u��
bool OnMousePush(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}


//�������u��
bool OnMouseUp(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		!(g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE))
	{
		return true;
	}

	return false;
}

#pragma region �}�E�X�̍��W����
void UpdateMouse()
{
	Vec2 prev = g_MousePos;
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(FindWindowA("����`�[������", nullptr), &p);

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
