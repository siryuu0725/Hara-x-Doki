#include "Window.h"

LRESULT CALLBACK WindowProc(HWND window_handle, UINT message_id, WPARAM wparam, LPARAM lparam)
{
	switch (message_id)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:   
		if (wparam == VK_ESCAPE)
		{
			PostMessage(window_handle, WM_CLOSE, NULL, NULL);
		}
	default:
		return DefWindowProc(window_handle, message_id, wparam, lparam);
		break;
	}
	return 0;
}

HWND MakeWindow(HINSTANCE instance, int width, int height)
{
	HWND hWnd;
	WNDCLASSEX window_class = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		WindowProc,
		0,
		0,
		instance,
		LoadIcon(NULL,MAKEINTRESOURCE(IDI_APPLICATION)),
		LoadCursor(NULL,IDC_ARROW),
		NULL,
		NULL,
		TEXT("チーム制作"),
		NULL
	};

	if (RegisterClassEx(&window_class) == 0)
	{
		return 0;
	}

	hWnd = CreateWindow(
		TEXT("チーム制作"),
		TEXT("チーム制作"),
		WS_VISIBLE | WS_POPUP, //フルスクリーンかどうか
		CW_USEDEFAULT,
		0,
		width,
		height,
		NULL,
		NULL,
		instance,
		NULL);

	if (hWnd == NULL)
	{
		return 0;
	}

	RECT window_rect;
	RECT client_rect;

	GetWindowRect(hWnd, &window_rect);
	GetClientRect(hWnd, &client_rect);

	int frame_size_x = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
	int frame_size_y = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

	SetWindowPos(hWnd, NULL, CW_USEDEFAULT, CW_USEDEFAULT, frame_size_x + width, frame_size_y + height, SWP_NOMOVE);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	return hWnd;
}