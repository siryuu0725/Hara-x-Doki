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


//背景と家具が別のため関数化
void LoadTundereFurnitureTex()
{
	LoadTexture("Res/部屋(空).png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRoomBgTex);
	LoadTexture("Res/カーペット02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCarpet);
	LoadTexture("Res/窓.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereWindow);
	LoadTexture("Res/ソファ.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereSofa);
	LoadTexture("Res/観葉植物.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereFlowerpot);
	LoadTexture("Res/箪笥02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCloset);
	LoadTexture("Res/ライト.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight);
	LoadTexture("Res/ベッド04.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereBed);
	LoadTexture("Res/テーブル03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDesk);
	LoadTexture("Res/ぬいぐるみ03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDoll);
}
void LoadYuruhuwaFurnitureTex()
{
	LoadTexture("Res/部屋(空).png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRoomBgTex);
	LoadTexture("Res/カーペット03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCarpet);
	LoadTexture("Res/窓.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaWindow);
	LoadTexture("Res/ソファ02.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaSofa);
	LoadTexture("Res/箪笥03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCloset);
	LoadTexture("Res/ライト.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight);
	LoadTexture("Res/ベッド.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaBed);
	LoadTexture("Res/テーブル03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDesk);
	LoadTexture("Res/ぬいぐるみ03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDoll);
	LoadTexture("Res/時計.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaClock);
	LoadTexture("Res/キャビネット.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCabinet);
}

void LoadCriminalFurnitureTex()
{
	LoadTexture("Res/犯人部屋.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRoomBgTex);
	LoadTexture("Res/カーペット.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRedCarpet);
	LoadTexture("Res/カーペット02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBuleCarpet);
	LoadTexture("Res/カーペット03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalGreenCarpet);
	LoadTexture("Res/キャビネット.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCabinet);
	LoadTexture("Res/箪笥02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCloset);
	LoadTexture("Res/ライト.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRight);
	LoadTexture("Res/ベッド04.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBed);
	LoadTexture("Res/テーブル03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalDesk);
	LoadTexture("Res/時計.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalClock);
	LoadTexture("Res/本棚03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBookshelf);
	LoadTexture("Res/本04.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook);
	LoadTexture("Res/本02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook2);
}


#pragma region プレイヤーとオブジェクトのあたり判定
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
	else if (HitPlayerObject(1730.0f, 0.0f, 185.0f, 450.0f) == true)
	{
		searchplayer.hit = true;
	}
	//メイド
	else if (HitPlayerObject(maidrobot.pos_x, maidrobot.pos_y, 64.0f, 128.0f) == true)
	{
		searchplayer.hit = true;
	}
	//大テーブル
	else if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true)
	{
		searchplayer.hit = true;	
	}
	//椅子１
	else if (HitPlayerObject(635.0f, 530.0f, 50.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子2
	else if (HitPlayerObject(830.0f, 780.0f, 50.0f, 30.0f) == true)
	{
	    searchplayer.hit = true;
	}
	//椅子3
	else if (HitPlayerObject(1005.0f, 780.0f, 50.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子4
	else if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true)
	{
		searchplayer.hit = true;
	}
	//植木鉢
	else if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true)
	{
		searchplayer.hit = true;
	}
	//時計
	else if (HitPlayerObject(225.0f, 120.0f ,70.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ソファー
	else if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true)
	{
		searchplayer.hit = true;	
	}
	//電話
	else if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true)
	{
		searchplayer.hit = true;
	}
	//照明
	else if (HitPlayerObject(1600.0f, 155.0f, 75.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
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
	else if (HitPlayerObject(searchgamerobot.pos_x + 20.0f, searchgamerobot.pos_y + 64.0f, searchgamerobot.width - 30.0f, searchgamerobot.height - 62.0f) == true)
	{
		searchplayer.hit = true;
	}
	//首
	else if (HitPlayerObject(700.0f, 500.0f, 64.0f, 64.0f) == true && neck.get == false)
	{
		searchplayer.hit = true;
	}
	//ベッド
	else if (HitPlayerObject(480.0f, 755.0f, 255.0f, 146.0f) == true)
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
	else if (HitPlayerObject(995.0f, 610.0f, 40.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子2
	else if (HitPlayerObject(1130.0f, 775.0f, 15.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子3
	else if (HitPlayerObject(1250.0f, 775.0f, 15.0f, 30.0f) == true)
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
	else if (HitPlayerObject(525.0f, 625.0f, 35.0f, 75.0f) == true)
	{
		searchplayer.hit = true;
	}
	else
	{
		searchplayer.hit= false;
	}
}

void HitTundereRoomObject()
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
	else if (HitPlayerObject(mysterygamerobot.pos_x + 20.0f, mysterygamerobot.pos_y + 64.0f, mysterygamerobot.width - 30.0f, mysterygamerobot.height - 62.0f) == true)
	{
		searchplayer.hit = true;
	}
	
	//ベッド
	else if (HitPlayerObject(465.0f, 865.0f, 265.0f, 146.0f) == true)
	{
		searchplayer.hit = true;
	}
	//大テーブル
	else if (HitPlayerObject(1050.0f, 665.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子１
	else if (HitPlayerObject(1130.0f, 930.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子2
	else if (HitPlayerObject(1250.0f, 930.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子3
	else if (HitPlayerObject(1380.0f, 770.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//植木鉢
	else if (HitPlayerObject(460.0f, 255.0f, 165.0f, 70.0f) == true)
	{
		searchplayer.hit = true;
	}
	//照明
	else if (HitPlayerObject(460.0f, 800.0f, 85.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ソファ
	else if (HitPlayerObject(695.0f, 170.0f, 245.0f, 110.0f) == true)
	{
		searchplayer.hit = true;
	}
	//箪笥
	else if (HitPlayerObject(1305.0f, 80.0f, 120.0f, 225.0f) == true)
	{
		searchplayer.hit = true;
	}
	else
	{
		searchplayer.hit = false;
	}
}

void HitYuruhuwaRoomObject()
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
	else if (HitPlayerObject(puzzlegamerobot.pos_x + 20.0f, puzzlegamerobot.pos_y + 64.0f, puzzlegamerobot.width - 30.0f, puzzlegamerobot.height - 62.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ベッド
	else if (HitPlayerObject(475.0f, 745.0f, 145.0f, 255.0f) == true)
	{
		searchplayer.hit = true;
	}
	//小テーブル
	else if (HitPlayerObject(1390.0f, 460.0f, 50.0f, 65.0f) == true)
	{
		searchplayer.hit = true;
	}
	//大テーブル
	else if (HitPlayerObject(460.0f, 260.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子１
	else if (HitPlayerObject(550.0f, 525.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子2
	else if (HitPlayerObject(670.0f, 525.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子3
	else if (HitPlayerObject(790.0f, 360.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ソファ
	else if (HitPlayerObject(1040.0f, 185.0f, 245.0f, 130.0f) == true)
	{
		searchplayer.hit = true;
	}
	//箪笥
	else if (HitPlayerObject(870.0f, 70.0f, 125.0f, 245.0f) == true)
	{
		searchplayer.hit = true;
	}
	//時計
	else if (HitPlayerObject(1330.0f, 120.0f, 75.0f, 180.0f) == true)
	{
		searchplayer.hit = true;
	}
	//キャビネット
	else if (HitPlayerObject(1390.0f, 460.0f, 50.0f, 55.0f) == true)
	{
		searchplayer.hit = true;
	}
	//照明
	else if (HitPlayerObject(1350.0f, 950.0f, 75.0f, 50.0f) == true)
	{
		searchplayer.hit = true;
	}
	
	else
	{
		searchplayer.hit = false;
	}
}
#pragma endregion 

#pragma region プレイヤーの視界とオブジェクトのあたり判定
void HitEyeSearchObject()
{
	//メイド
	if (HitPlayerEyeObject(maidrobot.pos_x, maidrobot.pos_y, 64.0f, 128.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//大テーブル
	else if (HitPlayerEyeObject(720.0f, 380.0f, 460.0f, 360.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子１
	else if (HitPlayerEyeObject(635.0f, 530.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子2
	else if(HitPlayerEyeObject(830.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子3
	else if (HitPlayerEyeObject(1005.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子4
	else if (HitPlayerEyeObject(1602.0f, 890.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//植木鉢
	else if (HitPlayerEyeObject(155.0f, 885.0f, 100.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//時計
	else if (HitPlayerEyeObject(225.0f, 120.0f, 70.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//ソファー
	else if (HitPlayerEyeObject(705.0f, 140.0f, 515.0f, 135.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//電話
	else if (HitPlayerEyeObject(1395.0f, 185.0f, 65.0f, 100.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//照明
	else if (HitPlayerEyeObject(1600.0f, 155.0f, 75.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
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
	if (HitPlayerEyeObject(searchgamerobot.pos_x + 20.0f, searchgamerobot.pos_y + 64.0f, searchgamerobot.width - 30.0f, searchgamerobot.height - 42.0f) == true
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
	else if (HitPlayerEyeObject(1175.0f, 185.0f, 175.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//照明
	else if (HitPlayerEyeObject(1340.0f, 95.0f, 100.0f, 190.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//箪笥
	else if (HitPlayerEyeObject(460.0f, 35.0f, 125.0f, 255.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//本棚
	else if (HitPlayerEyeObject(630.0f, 30.0f, 290.0f, 260.0f) == true && GetKeyDown(SPACE_KEY) == true)
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

void HitEyeTundereRoomObject()
{
	//ロボット
	if (HitPlayerEyeObject(mysterygamerobot.pos_x + 20.0f, mysterygamerobot.pos_y + 64.0f, mysterygamerobot.width - 30.0f, mysterygamerobot.height - 62.0f) == true
	    &&GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//ベッド
	else if (HitPlayerEyeObject(465.0f, 865.0f, 265.0f, 146.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//大テーブル
	else if (HitPlayerEyeObject(1050.0f, 665.0f, 315.0f, 250.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子１
	else if (HitPlayerEyeObject(1130.0f, 930.0f, 30.0f, 30.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子2
	else if (HitPlayerEyeObject(1250.0f, 930.0f, 30.0f, 30.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子3
	else if (HitPlayerEyeObject(1380.0f, 770.0f, 30.0f, 30.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//植木鉢
	else if (HitPlayerEyeObject(460.0f, 255.0f, 165.0f, 70.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//照明
	else if (HitPlayerEyeObject(460.0f, 800.0f, 85.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//ソファ
	else if (HitPlayerEyeObject(695.0f, 170.0f, 245.0f, 110.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//箪笥
	else if (HitPlayerEyeObject(1305.0f, 80.0f, 120.0f, 225.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	else
	{
		searchplayer.eyehit = false;
	}
}

void HitEyeYuruhuwaRoomObject()
{
	//ロボット
	if (HitPlayerEyeObject(puzzlegamerobot.pos_x + 20.0f, puzzlegamerobot.pos_y + 64.0f, puzzlegamerobot.width - 30.0f, puzzlegamerobot.height - 62.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//ベッド
	else if (HitPlayerEyeObject(475.0f, 745.0f, 145.0f, 255.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//小テーブル
	else if (HitPlayerEyeObject(1390.0f, 460.0f, 50.0f, 65.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//大テーブル
	else if (HitPlayerEyeObject(460.0f, 260.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子１
	else if (HitPlayerEyeObject(540.0f, 525.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子2
	else if (HitPlayerEyeObject(660.0f, 525.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子3
	else if (HitPlayerEyeObject(790.0f, 360.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//ソファ
	else if (HitPlayerEyeObject(1040.0f, 185.0f, 245.0f, 130.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//箪笥
	else if (HitPlayerEyeObject(870.0f, 70.0f, 125.0f, 245.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//時計
	else if (HitPlayerEyeObject(1330.0f, 120.0f, 75.0f, 180.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//キャビネット
	else if (HitPlayerEyeObject(1390.0f, 460.0f, 50.0f, 55.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//照明
	else if (HitPlayerEyeObject(1350.0f, 950.0f, 75.0f, 50.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	else
	{
		searchplayer.eyehit = false;
	}
}

#pragma endregion 

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


