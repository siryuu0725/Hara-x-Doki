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
	//画面左端
	if (HitPlayerObject(0.0f, 0.0f, 155.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面左下
	else if (HitPlayerObject(155.0f, 990.0f, 715.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面右下
	else if (HitPlayerObject(960.0f, 990.0f, 770.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面右端
	else if (HitPlayerObject(1730.0f, 550.0f, 185.0f, 525.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面右端
	else if (HitPlayerObject(1730.0f, 0.0f, 185.0f, 470.0f) == true)
	{
		searchplayer.hit = true;
	}
	//大テーブル
	else if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true)
	{
		if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}
		searchplayer.hit = true;	
	}
	//椅子１
	else if (HitPlayerObject(635.0f, 530.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(635.0f, 530.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//椅子2
	else if (HitPlayerObject(830.0f, 780.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(830.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//椅子3
	else if (HitPlayerObject(1005.0f, 780.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(1005.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//椅子4
	else if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true)
	{
		if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;

	}
	//植木鉢
	else if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true)
	{
		if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;

	}
	//時計
	else if (HitPlayerObject(225.0f, 120.0f ,70.0f, 185.0f) == true)
	{
		if (HitPlayerObject(225.0f, 120.0f, 70.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;
	}
	//ソファー
	else if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true)
	{
		if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}

		searchplayer.hit = true;	
	}
	//電話
	else if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true)
	{
		searchplayer.hit = true;

		if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true && GetKeyDown(SPACE_KEY) == true)
		{
			searchplayer.eyehit = true;
		}
	}
	//照明
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
	//画面左端
	if (HitPlayerObject(0.0f, 0.0f, 460.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面左下
	else if (HitPlayerObject(460.0f, 1020.0f, 440.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面右下
	else if (HitPlayerObject(975.0f, 1020.0f, 470.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面右端
	else if (HitPlayerObject(1445.0f, 0.0f, 475.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ロボット
	else if (HitPlayerObject(searchrobot.pos_x + 20.0f, searchrobot.pos_y + 64.0f, searchrobot.width-30.0f, searchrobot.height-42.0f) == true)
	{
		searchplayer.hit = true;
	}
	//首
	else if (HitPlayerObject(700.0f, 500.0f, 64.0f, 64.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ベッド
	else if (HitPlayerObject(480.0f, 755.0f, 265.0f, 146.0f) == true)
	{
		searchplayer.hit = true;
	}
	//小テーブル
	else if (HitPlayerObject(480.0f, 910.0f, 50.0f, 65.0f) == true)
	{
		searchplayer.hit = true;
	}
	//大テーブル
	else if (HitPlayerObject(1045.0f, 510.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子１
	else if (HitPlayerObject(990.0f, 610.0f, 40.0f, 40.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子2
	else if (HitPlayerObject(1120.0f, 775.0f, 40.0f, 40.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子3
	else if (HitPlayerObject(1240.0f, 775.0f, 40.0f, 40.0f) == true)
	{
		searchplayer.hit = true;
	}
	//植木鉢と照明
	else if (HitPlayerObject(1175.0f, 95.0f, 270.0f, 190.0f) == true)
	{
		searchplayer.hit = true;
	}
	//箪笥と本棚
	else if (HitPlayerObject(460.0f, 35.0f, 450.0f, 255.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ぬいぐるみ
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
	//椅子１
	else if (HitPlayerObject(635.0f, 530.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子2
	else if(HitPlayerObject(830.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子3
	else if (HitPlayerObject(1005.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子4
	else if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//植木鉢
	else if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//時計
	else if (HitPlayerObject(225.0f, 120.0f, 70.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//ソファー
	else if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//電話
	else if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//照明
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
	//ロボット
	if (HitPlayerEyeObject(searchrobot.pos_x + 20.0f, searchrobot.pos_y + 64.0f, searchrobot.width - 30.0f, searchrobot.height - 42.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//首
	else if (HitPlayerEyeObject(700.0f, 500.0f, 64.0f, 64.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		neck.get = true;
	}
	//ベッド
	else if (HitPlayerEyeObject(480.0f, 755.0f, 265.0f, 146.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
		tochobject.bed = true;
	}
	//小テーブル
	else if(HitPlayerEyeObject(480.0f, 910.0f, 50.0f, 65.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.desk = true;
	}
	//大テーブル
	else if (HitPlayerEyeObject(1045.0f, 510.0f, 315.0f, 250.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子１
	else if (HitPlayerEyeObject(990.0f, 610.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//椅子2
	else if (HitPlayerEyeObject(1120.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//椅子3
	else if (HitPlayerEyeObject(1240.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//植木鉢と照明
	else if (HitPlayerEyeObject(1175.0f, 95.0f, 270.0f, 190.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//箪笥と本棚
	else if (HitPlayerEyeObject(460.0f, 35.0f, 450.0f, 255.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		
		tochobject.bookshelf = true;
	}
	//ぬいぐるみ
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


