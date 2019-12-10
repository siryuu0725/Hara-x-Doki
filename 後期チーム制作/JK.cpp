#include "JK.h"
#include "Graphics.h"
#include "Texture.h"


Boyish boyish;

void InitBoyish()
{
	boyish.pos_x = 1040.0f;
	boyish.pos_y = 180.0f;

	boyish.tu = 0.0f;
	boyish.tv = 0.0f;

	boyish.width = 64.0f;
	boyish.height = 128.0f;

	boyish.talk = false;

}

void DrawBoyish()
{
	DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::BoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
}