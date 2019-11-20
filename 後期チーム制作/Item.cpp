#include"Item.h"
#include "Graphics.h"
#include "Texture.h"

void DrawRobotNeck()
{
	DrawTexture(700.0f, 400.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex));
}

