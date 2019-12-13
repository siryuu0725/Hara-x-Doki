#include "Graphics.h"
#include "Texture.h"

static LPDIRECT3D9 g_Interface;
static LPDIRECT3DDEVICE9 g_Device;
static LPD3DXFONT g_FontList[FontSize::FontSizeMax];


//DirectXの初期化
bool  InitDirectGraphics(HWND window_handle)
{

	D3DPRESENT_PARAMETERS present_param;

	g_Interface = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_Interface == NULL)
	{
		return false;
	}

	ZeroMemory(&present_param, sizeof(D3DPRESENT_PARAMETERS));

	present_param.BackBufferCount = 1;
	present_param.BackBufferFormat = D3DFMT_UNKNOWN;
	present_param.Windowed = true;
	present_param.SwapEffect = D3DSWAPEFFECT_DISCARD;

	if (FAILED(g_Interface->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		window_handle,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
		&present_param,
		&g_Device)))
	{
		return false;
	}

	D3DVIEWPORT9 view_port;

	view_port.X = 0;
	view_port.Y = 0;
	view_port.Width = present_param.BackBufferWidth;
	view_port.Height = present_param.BackBufferHeight;
	view_port.MinZ = 0.0f;
	view_port.MaxZ = 1.0f;

	if (FAILED(g_Device->SetViewport(&view_port)))
	{
		return false;
	}
	return true;
}



void ReleaseDirectGraphics()
{
	for (int i = 0; i < FontSize::FontSizeMax; i++)
	{
		g_FontList[i]->Release();
	}
	g_Device->Release();
	g_Interface->Release();
}


bool DrawStart()
{
	g_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0);

	//テクスチャ透過
	g_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	if (D3D_OK == g_Device->BeginScene())
	{
		return true;
	}
	return false;
}

void DrawEnd()
{
	g_Device->EndScene();
	g_Device->Present(NULL, NULL, NULL, NULL);
}


bool CreateTexture(const char* file_name, TEXTURE_DATE* texture_data)
{
	D3DXIMAGE_INFO info;

	// 2の累乗じゃないケースを想定して元のサイズを取得してD3DXCreateTextureFromFileExで使う
	D3DXGetImageInfoFromFileA(file_name, &info);

	if (FAILED(D3DXCreateTextureFromFileExA(g_Device,
		file_name,
		info.Width,
		info.Height,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0x0000ff00,
		nullptr,
		nullptr,
		&texture_data->Texture)))
	{
		return false;
	}
	else
	{
		// テクスチャサイズの取得
		D3DSURFACE_DESC desc;

		if (FAILED(texture_data->Texture->GetLevelDesc(0, &desc)))
		{
			texture_data->Texture->Release();
			return false;
		}
		texture_data->Width = desc.Width;
		texture_data->Height = desc.Height;
	}

	return true;
}

//背景用
void DrawBgTexture(TEXTURE_DATE* texture)
{

	CUSTOM_VERTEX bg[4] =
	{
		// 左上頂点
		{ 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },//右から2番目と1番目が座標
		// 右上頂点
		{ texture->Width, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f },
		// 右下頂点
		{ texture->Width, texture->Height, 0.0f, 1.0f, 1.0f, 1.0f },
		// 左下頂点
		{ 0.0f, texture->Height, 0.0f, 1.0f, 0.0f, 1.0f },
	};

	g_Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);

	g_Device->SetTexture(0, texture->Texture);

	g_Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, bg, sizeof(CUSTOM_VERTEX));
}

//自キャラ敵キャラ用
void DrawTexture(float x, float y, TEXTURE_DATE* texture)
{
	CUSTOM_VERTEX obj[4] =
	{
		{ x, y, 0.0f, 1.0f, 0.0f, 0.0f },
		{ x + texture->Width, y, 0.0f, 1.0f, 1.0f, 0.0f },
		{ x + texture->Width, y + texture->Height, 0.0f, 1.0f, 1.0f, 1.0f },
		{ x, y + texture->Height, 0.0f, 1.0f, 0.0f, 1.0f },
	};

	// 頂点構造の指定
	g_Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);

	g_Device->SetTexture(0, texture->Texture);

	g_Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, obj, sizeof(CUSTOM_VERTEX));

}

//アニメーション用
void DrawUVTexture(float x, float y, TEXTURE_DATE* texture, float sprite_width, float sprite_height, float tu, float tv)
{
	float Ttu = sprite_width / texture->Width;
	float Ttv = sprite_height / texture->Height;

	CUSTOM_VERTEX effect[4] =
	{
		{ x, y, 0.0f, 1.0f, tu, tv },
		{ x + sprite_width, y, 0.0f, 1.0f, tu + Ttu , tv },
		{ x + sprite_width, y + sprite_height, 0.0f, 1.0f, tu + Ttu, tv + Ttv},
		{ x, y + sprite_height, 0.0f, 1.0f, tu, tv + Ttv },
	};

	// 頂点構造の指定
	g_Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);

	g_Device->SetTexture(0, texture->Texture);

	g_Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, effect, sizeof(CUSTOM_VERTEX));

}

//文字描画
void DrawFont(float pos_x, float pos_y, const char* text, FontSize font_type, FontColor color)
{
	RECT rect =
	{
		(long)pos_x,
		(long)pos_y,
		(long)pos_x + 10000,
		(long)pos_y + 10000,
	};

	int r, g, b;
	r = g = b = 255;

	if (color == FontColor::Black)
	{
		r = g = b = 0;
	}
	else if (color == FontColor::Red)
	{
		r = 255;
		g = b = 0;
	}
	else if (color == FontColor::Yellow)
	{
		r = 255;
		g = 225;
		b = 0;
	}
	else if (color == FontColor::Pink)
	{
		r = 255;
		g = 0;
		b = 255;
	}
	else if (color == FontColor::White)
	{
		r = 255;
		g = 255;
		b = 255;
	}
	else if (color == FontColor::Aqua)
	{
		r = 0;
		g = 255;
		b = 255;
	}

	g_FontList[font_type]->DrawTextA(
		NULL,
		text,
		-1,
		&rect,
		DT_LEFT,
		D3DCOLOR_XRGB(r, g, b)
	);
}


bool CreateFontDevice()
{
	int size_list[] =
	{
		SMALL_FONT_SIZE,
		REGULAR_FONT_SIZE,
		LARGE_FONT_SIZE
	};

	for (int i = 0; i < FontSize::FontSizeMax; i++)
	{
		if (FAILED(D3DXCreateFont(g_Device,
			size_list[i],
			size_list[i] / 2,
			FW_REGULAR,
			NULL,
			FALSE,
			DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_SCRIPT,
			TEXT("ＭＳ　Ｐゴシック"),
			&g_FontList[i])))
		{
			return false;
		}
	}

	return true;
}