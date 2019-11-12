#ifndef DIRECT_INPUT_H_
#define DIRECT_INPUT_H_

#include <Windows.h>
#include <dinput.h>

#pragma comment (lib,"dinput8.lib")
#pragma comment (lib,"dxguid.lib")


// �L�[�R�[�h
#define CLEAR_KEY	0x0000		// �N���A�p
#define UP_KEY		0x0001		// ��L�[
#define DOWN_KEY	0x0002		// ���L�[
#define LEFT_KEY	0x0004		// ���L�[
#define RIGHT_KEY	0x0008		// �E�L�[
#define RETURN_KEY	0x0010	// ���^�[���L�[
#define SPACE_KEY   0x0020  // �X�y�[�X�L�[

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
	* @param[in] x ����
	* @param[in] y �c��
	*/
	Vec2(float x, float y)
	{
		X = x;
		Y = y;
	}

	/**
	* @brief Constructor
	* @param[in] Vec2 �R�s�[�pVec2�f�[�^
	*/
	Vec2(const Vec2& size)
	{
		this->X = size.X;
		this->Y = size.Y;
	}

	float X;	//!< X�l
	float Y;	//!< Y�l
};

enum MouseButton
{
	Left,		//!< ��
	Right,		//!< �E
	Center,		//!< �^��
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
