#include "Window.h"
#include "Graphics.h"
#include "Input.h"
#include "Scene.h"
#include "Texture.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	HWND window_handle = MakeWindow(hInstance, 1920, 1080);


	InitDirectGraphics(window_handle);

	if (CreateFontDevice() == false)
	{
		return 0;
	}

	if (InitDirectInput(hInstance, window_handle) == false)
	{
		return 0;
	}

	InitTexture();

	while (true)
	{
		bool message_ret = false;
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else if (msg.message == WM_CLOSE)
			{
				break;
			}
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// シーンの更新
			UpdateScene();
		}
	}
	ReleaseDirectInput();

	ReleaseDirectGraphics();
}