#include"Item.h"
#include "Graphics.h"
#include "Texture.h"
#include "Hit.h"
#include "Player.h"
#include "Robot.h"

void DrawRobotNeck()
{
	DrawTexture(700.0f, 500.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex));
}

void HitSearchObject()
{
	//��e�[�u��
	if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q�P
	else if (HitPlayerObject(635.0f, 530.0f, 58.0f, 58.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q2
	else if (HitPlayerObject(830.0f, 780.0f, 58.0f, 58.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q3
	else if (HitPlayerObject(1005.0f, 780.0f, 58.0f, 58.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q4
	else if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�A�ؔ�
	else if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���v
	else if (HitPlayerObject(225.0f, 120.0f ,70.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�t�@�[
	else if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�d�b
	else if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�Ɩ�
	else if (HitPlayerObject(1600.0f, 155.0f, 75.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	else
	{
		searchplayer.hit = false;
	}
}

void HitSearchGameObject()
{
	//���{�b�g
	if (HitPlayerObject(searchrobot.pos_x + 20.0f, searchrobot.pos_y + 64.0f, searchrobot.width-30.0f, searchrobot.height-42.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��
	else if (HitPlayerObject(700.0f, 500.0f, 64.0f, 64.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�x�b�h
	else if (HitPlayerObject(480.0f, 755.0f, 265.0f, 146.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���e�[�u��
	else if (HitPlayerObject(480.0f, 910.0f, 50.0f, 65.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��e�[�u��
	else if (HitPlayerObject(1045.0f, 510.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q�P
	else if (HitPlayerObject(990.0f, 610.0f, 40.0f, 40.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q2
	else if (HitPlayerObject(1120.0f, 775.0f, 40.0f, 40.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q3
	else if (HitPlayerObject(1240.0f, 775.0f, 40.0f, 40.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�A�ؔ��ƏƖ�
	else if (HitPlayerObject(1175.0f, 95.0f, 270.0f, 190.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�y�Ɩ{�I
	else if (HitPlayerObject(460.0f, 35.0f, 450.0f, 255.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�ʂ������
	else if (HitPlayerObject(522.0f, 625.0f, 45.0f, 75.0f) == true)
	{
		searchplayer.hit = true;
	}
	else
	{
		searchplayer.hit= false;
	}
}



