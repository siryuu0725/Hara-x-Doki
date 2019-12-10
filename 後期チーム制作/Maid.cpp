#include "Maid.h"
#include "Graphics.h"
#include "Text.h"
#include "Texture.h"
#include "Item.h"
#include "Input.h"


MaidData maid;
void InitMaid()
{
	
	maid.talk = false;

}
void DrawTalkMaid()
{
	if (searchobject.maid == true)
	{
		
		
		DrawTexture(1300.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		
		
		if (getitem.breakdoorkey == false)
		{
			getitem.doorkey = true;
		}
	}
	else if (GetKeyDown(SPACE_KEY) == true && maid.talk == true)
	{
		maid.talk = false;
	}
}
