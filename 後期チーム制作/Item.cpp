#include"Item.h"
#include "Graphics.h"
#include "Texture.h"
#include "Hit.h"
#include "Player.h"
#include "Robot.h"
#include "Input.h"

TouchObject tochobject;
RobotNeck neck;

void InitObject()
{
	tochobject.energy = false;
	tochobject.desk = false;
	tochobject.chair = false;
	tochobject.doll = false;
	tochobject.bed = false;
	tochobject.light = false;
	tochobject.flowerpot = false;
	tochobject.closet = false;
	tochobject.bookshelf = false;
}

void DrawRobotNeck()
{
	if (neck.get != true)
	{
		DrawTexture(700.0f, 500.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex));

	}
}

void HitSearchObject()
{
	//��ʍ��[
	if (HitPlayerObject(0.0f, 0.0f, 155.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʍ���
	else if (HitPlayerObject(155.0f, 990.0f, 715.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE��
	else if (HitPlayerObject(960.0f, 990.0f, 770.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1730.0f, 550.0f, 185.0f, 525.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1730.0f, 0.0f, 185.0f, 470.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��e�[�u��
	else if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true)
	{
		if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}
		searchplayer.hit = true;	
	}
	//�֎q�P
	else if (HitPlayerObject(635.0f, 530.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(635.0f, 530.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//�֎q2
	else if (HitPlayerObject(830.0f, 780.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(830.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//�֎q3
	else if (HitPlayerObject(1005.0f, 780.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(1005.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//�֎q4
	else if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;

	}
	//�A�ؔ�
	else if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true)
	{
		if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;

	}
	//���v
	else if (HitPlayerObject(225.0f, 120.0f ,70.0f, 185.0f) == true)
	{
		if (HitPlayerObject(225.0f, 120.0f, 70.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//�\�t�@�[
	else if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true)
	{
		if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;	
	}
	//�d�b
	else if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true)
	{
		searchplayer.hit = true;

		if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}
	}
	//�Ɩ�
	else if (HitPlayerObject(1600.0f, 155.0f, 75.0f, 185.0f) == true)
	{
		searchplayer.hit = true;

		if (HitPlayerObject(1600.0f, 155.0f, 75.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}
	}
	else
	{
		searchplayer.hit = false;
		searchplayer.eyehit = false;
	}
}

void HitSearchGameObject()
{
	//��ʍ��[
	if (HitPlayerObject(0.0f, 0.0f, 460.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʍ���
	else if (HitPlayerObject(460.0f, 1020.0f, 440.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE��
	else if (HitPlayerObject(975.0f, 1020.0f, 470.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1445.0f, 0.0f, 475.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���{�b�g
	else if (HitPlayerObject(searchrobot.pos_x + 20.0f, searchrobot.pos_y + 64.0f, searchrobot.width-30.0f, searchrobot.height-42.0f) == true)
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

void HitEyeSearchObject()
{
	if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q�P
	else if (HitPlayerObject(635.0f, 530.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q2
	else if(HitPlayerObject(830.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q3
	else if (HitPlayerObject(1005.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q4
	else if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�A�ؔ�
	else if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//���v
	else if (HitPlayerObject(225.0f, 120.0f, 70.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�\�t�@�[
	else if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�d�b
	else if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�Ɩ�
	else if (HitPlayerObject(1600.0f, 155.0f, 75.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	else
	{
		searchplayer.eyehit = false;
	}
}

void HitEyeSearchGameObject()
{
	//���{�b�g
	if (HitPlayerEyeObject(searchrobot.pos_x + 20.0f, searchrobot.pos_y + 64.0f, searchrobot.width - 30.0f, searchrobot.height - 42.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//��
	else if (HitPlayerEyeObject(700.0f, 500.0f, 64.0f, 64.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		neck.get = true;
	}
	//�x�b�h
	else if (HitPlayerEyeObject(480.0f, 755.0f, 265.0f, 146.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
		tochobject.bed = true;
	}
	//���e�[�u��
	else if(HitPlayerEyeObject(480.0f, 910.0f, 50.0f, 65.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.desk = true;
	}
	//��e�[�u��
	else if (HitPlayerEyeObject(1045.0f, 510.0f, 315.0f, 250.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q�P
	else if (HitPlayerEyeObject(990.0f, 610.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//�֎q2
	else if (HitPlayerEyeObject(1120.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//�֎q3
	else if (HitPlayerEyeObject(1240.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//�A�ؔ��ƏƖ�
	else if (HitPlayerEyeObject(1175.0f, 95.0f, 270.0f, 190.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//�\�y�Ɩ{�I
	else if (HitPlayerEyeObject(460.0f, 35.0f, 450.0f, 255.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		
		tochobject.bookshelf = true;
	}
	//�ʂ������
	else if (HitPlayerEyeObject(522.0f, 625.0f, 45.0f, 75.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.doll = true;
	}
	else
	{
		tochobject.energy = false;
		tochobject.desk = false;
		tochobject.chair = false;
		tochobject.doll = false;
		tochobject.bed = false;
		tochobject.light = false;
		tochobject.flowerpot = false;
		tochobject.closet = false;
		tochobject.bookshelf = false;
		searchplayer.hit = false;
	}
}


void UpDataSearchGame()
{
	if (tochobject.light == true)
	{

	}
	if (tochobject.bed == true)
	{

	}
	else if (tochobject.bed == true && tochobject.light == true)
	{

	}
	if (tochobject.closet == true)
	{

	}
	else if (tochobject.bed == true && tochobject.light == true && tochobject.closet == true)
	{

	}
}


