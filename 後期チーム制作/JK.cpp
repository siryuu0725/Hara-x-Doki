#include "JK.h"
#include "Graphics.h"
#include "Texture.h"
#include "Bg.h"


Boyish boyish;
Yuruhuwa yuruhuwa;

void InitBoyish()
{
	if (areadata.searchgamearea == true)
	{
		boyish.pos_x = 1040.0f;
		boyish.pos_y = 180.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
	if (areadata.searcharea2 == true && boyish.clear == true)
	{
		boyish.pos_x = 1560.0f;
		boyish.pos_y = 450.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
	if (areadata.searcharea1 == true && boyish.clear == true)
	{
		boyish.pos_x = 540.0f;
		boyish.pos_y = 170.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
}

void InitYuruhuwa()
{
	if (areadata.searchyuruhuwaarea == true)
	{
		yuruhuwa.pos_x = 1040.0f;
		yuruhuwa.pos_y = 250.0f;

		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;

		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;

		yuruhuwa.talk = false;
	}
	if (areadata.searcharea2 == true && yuruhuwa.clear == true)
	{
		yuruhuwa.pos_x = 335.0f;
		yuruhuwa.pos_y = 450.0f;

		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
	if (areadata.searcharea1 == true && yuruhuwa.clear == true)
	{
		yuruhuwa.pos_x = 540.0f;
		yuruhuwa.pos_y = 170.0f;
		
		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
}

void DrawBoyish()
{
	if (areadata.searchgamearea == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.searcharea2 == true && boyish.clear == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.searcharea1 == true && boyish.clear == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	
}

void DrawYuruhuwa()
{
	if (areadata.searchyuruhuwaarea == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.searcharea2 == true && yuruhuwa.clear == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.searcharea1 == true && yuruhuwa.clear == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}

}

void ClearSearchGame()
{
	if (boyish.talk == true && boyish.clear == true)
	{

	}
}