#include "Menu.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"

#define MENU_POS_X 660 // ���j���[��X���W
#define MENU_POS_Y 240 // ���j���[��Y���W
#define MENU_RETURN_GAME_VERTEX_UPPER_LEFT 100 // ���j���[�̃Q�[���ɖ߂�̍��㍶�����_�ƃ^�C�g���ɖ߂�̍��㒸�_
#define MENU_RETURN_GAME_VERTEX_UPPER_RIGHT 500 // ���j���[�̃Q�[���ɖ߂�̉E�㒸�_
#define MENU_RETURN_GAME_VERTEX_BOTTOM_RIGHT 200 // ���j���[�̃Q�[���ɖ߂�̉E�����_
#define MENU_RETURN_TITLE_VERTEX_UPPER_RIGHT 500 // ���j���[�̃^�C�g���ɖ߂�̉E�㒸�_
#define MENU_RETURN_TITLE_VERTEX_BOTTOM_LEFT 400 // ���j���[�̃^�C�g���ɖ߂�̍������_
#define MENU_RETURN_TITLE_VERTEX_BOTTOM_RIGHT 500 // ���j���[�̃^�C�g���ɖ߂�̉E�����_

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
	// ENTER�L�[����������t���O��1�ɂ���
	if (GetKey(RETURN_KEY) == true)
	{
		menu.onenterkey = true;
	}

	// �}�E�X�ƃQ�[���ɖ߂�̓����蔻��
	if (GetMousePos().X >= menu.pos_x + MENU_RETURN_GAME_VERTEX_UPPER_LEFT && GetMousePos().X <= menu.pos_x + MENU_RETURN_GAME_VERTEX_UPPER_RIGHT &&
		GetMousePos().Y >= menu.pos_y + MENU_RETURN_GAME_VERTEX_UPPER_LEFT && GetMousePos().Y <= menu.pos_y + MENU_RETURN_GAME_VERTEX_BOTTOM_RIGHT &&
		OnMouseDown(Left) == true)
	{
		menu.onenterkey = false;
	}

	// �}�E�X�ƃ^�C�g���ɖ߂�̓����蔻��
	if (GetMousePos().X >= menu.pos_x + MENU_RETURN_GAME_VERTEX_UPPER_LEFT && GetMousePos().X <= menu.pos_x + MENU_RETURN_TITLE_VERTEX_UPPER_RIGHT &&
		GetMousePos().Y >= menu.pos_y + MENU_RETURN_TITLE_VERTEX_BOTTOM_LEFT && GetMousePos().Y <= menu.pos_y + MENU_RETURN_TITLE_VERTEX_BOTTOM_RIGHT &&
		OnMouseDown(Left) == true)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}
