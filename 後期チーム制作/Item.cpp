#include"Item.h"
#include "Graphics.h"
#include "Texture.h"
#include "Hit.h"
void DrawRobotNeck()
{
	DrawTexture(700.0f, 500.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex));
}

//void HitObject()
//{
//	if (HitPlayerObject() == true)
//	{
//		searchrobot.hit = true;
//	}
//	else
//	{
//		searchrobot.hit = false;
//	}
//}



