#include "Menu.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"

#define MENU_POS_X 660 // メニューのX座標
#define MENU_POS_Y 240 // メニューのY座標
#define MENU_RETURN_GAME_VERTEX_UPPER_LEFT 100 // メニューのゲームに戻るの左上左下頂点とタイトルに戻るの左上頂点
#define MENU_RETURN_GAME_VERTEX_UPPER_RIGHT 500 // メニューのゲームに戻るの右上頂点
#define MENU_RETURN_GAME_VERTEX_BOTTOM_RIGHT 200 // メニューのゲームに戻るの右下頂点
#define MENU_RETURN_TITLE_VERTEX_UPPER_RIGHT 500 // メニューのタイトルに戻るの右上頂点
#define MENU_RETURN_TITLE_VERTEX_BOTTOM_LEFT 400 // メニューのタイトルに戻るの左下頂点
#define MENU_RETURN_TITLE_VERTEX_BOTTOM_RIGHT 500 // メニューのタイトルに戻るの右下頂点

MenuData menu;

void InitMenu()
{
	menu.pos_x = MENU_POS_X;
	menu.pos_y = MENU_POS_Y;
	menu.onenterkey = false;
}

void DrawMenu()
{
	if (menu.onenterkey == true)
	{
		DrawTexture(menu.pos_x, menu.pos_y, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::MenuTex));
	}
}

void UpDateMenu()
{
	// ENTERキーを押したらフラグを1にする
	if (GetKey(RETURN_KEY) == true)
	{
		menu.onenterkey = true;
	}

	// マウスとゲームに戻るの当たり判定
	if (GetMousePos().X >= menu.pos_x + MENU_RETURN_GAME_VERTEX_UPPER_LEFT && GetMousePos().X <= menu.pos_x + MENU_RETURN_GAME_VERTEX_UPPER_RIGHT &&
		GetMousePos().Y >= menu.pos_y + MENU_RETURN_GAME_VERTEX_UPPER_LEFT && GetMousePos().Y <= menu.pos_y + MENU_RETURN_GAME_VERTEX_BOTTOM_RIGHT &&
		OnMouseDown(Left) == true)
	{
		menu.onenterkey = false;
	}

	// マウスとタイトルに戻るの当たり判定
	if (GetMousePos().X >= menu.pos_x + MENU_RETURN_GAME_VERTEX_UPPER_LEFT && GetMousePos().X <= menu.pos_x + MENU_RETURN_TITLE_VERTEX_UPPER_RIGHT &&
		GetMousePos().Y >= menu.pos_y + MENU_RETURN_TITLE_VERTEX_BOTTOM_LEFT && GetMousePos().Y <= menu.pos_y + MENU_RETURN_TITLE_VERTEX_BOTTOM_RIGHT &&
		OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}
