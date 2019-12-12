#include"Item.h"
#include "Graphics.h"
#include "Texture.h"
#include "Hit.h"
#include "Player.h"
#include "Robot.h"
#include "Input.h"
#include "Text.h"
#include "JK.h"

SearchTouchObject searchobject;
SearchGameTouchObject searchgameobject;
YuruhuwaTouchObject yuruhuwaobject;
TundereTouchObject tundereobject;
GetItem getitem;

void InitSearchGameObject()
{
	searchgameobject.robot = false;
	searchgameobject.light = false;


	searchgameobject.desk = false;
	searchgameobject.chair = false;
	searchgameobject.doll = false;
	searchgameobject.bed = false;
	searchgameobject.flowerpot = false;
	searchgameobject.closet = false;
	searchgameobject.bookshelf = false;

	/*getitem.itemrobot = false;
	getitem.itemkey = false;
	getitem.itemenergy = false;
	getitem.itemlight = false;*/

	/*getitem.boyishdoorkey = false;
	getitem.tunderedoorkey = false;
	getitem.yuruhuwadoorkey = false;
	getitem.breakdoorkey = false;*/
}

void InitTundereRoomObject()
{
	tundereobject.robot = false;
}

void InitYuruhuwaRoomObject()
{
	yuruhuwaobject.robot = false;
}

void DrawRobotNeck()
{
	if (searchgameobject.robotneck == false && searchgameobject.completerobot != true)
	{
		DrawTexture(700.0f, 500.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex));
	}
}

void LoadSearchGameItem()
{
	LoadTexture("Res/探索ゲーム/鍵.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemKeyTex);
	LoadTexture("Res/探索ゲーム/電池.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemEnergyTex);
	LoadTexture("Res/探索ゲーム/ちびロボパーツ.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameItemRobotPartTex);
}


//背景と家具が別のため関数化
void LoadSearch2FurnitureTex()
{
	LoadTexture("Res/家具/ドア.png", TEXTURE_SEARCH2, Search2CategoryTextureList::Search2Door);
	LoadTexture("Res/家具/花瓶.png", TEXTURE_SEARCH2, Search2CategoryTextureList::Search2Vase);
}
void LoadTundereFurnitureTex()
{
	LoadTexture("Res/部屋(空).png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRoomBgTex);
	LoadTexture("Res/家具/カーペット02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCarpet);
	LoadTexture("Res/家具/窓.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereWindow);
	LoadTexture("Res/家具/ソファ.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereSofa);
	LoadTexture("Res/家具/観葉植物.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereFlowerpot);
	LoadTexture("Res/家具/箪笥02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCloset);
	LoadTexture("Res/家具/ライト.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight);
	LoadTexture("Res/家具/ベッド04.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereBed);
	LoadTexture("Res/家具/テーブル03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDesk);
	LoadTexture("Res/家具/ぬいぐるみ03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDoll);
}
void LoadYuruhuwaFurnitureTex()
{
	LoadTexture("Res/部屋(空).png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRoomBgTex);
	LoadTexture("Res/家具/カーペット03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCarpet);
	LoadTexture("Res/家具/窓.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaWindow);
	LoadTexture("Res/家具/ソファ02.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaSofa);
	LoadTexture("Res/家具/箪笥03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCloset);
	LoadTexture("Res/家具/ライト.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight);
	LoadTexture("Res/家具/ベッド.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaBed);
	LoadTexture("Res/家具/テーブル03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDesk);
	LoadTexture("Res/家具/ぬいぐるみ03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDoll);
	LoadTexture("Res/家具/時計.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaClock);
	LoadTexture("Res/家具/キャビネット.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCabinet);
}
void LoadCriminalFurnitureTex()
{
	LoadTexture("Res/犯人部屋.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRoomBgTex);
	LoadTexture("Res/家具/カーペット.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRedCarpet);
	LoadTexture("Res/家具/カーペット02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBuleCarpet);
	LoadTexture("Res/家具/カーペット03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalGreenCarpet);
	LoadTexture("Res/家具/キャビネット.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCabinet);
	LoadTexture("Res/家具/箪笥02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCloset);
	LoadTexture("Res/家具/ライト.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRight);
	LoadTexture("Res/家具/ベッド04.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBed);
	LoadTexture("Res/家具/テーブル03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalDesk);
	LoadTexture("Res/家具/時計.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalClock);
	LoadTexture("Res/家具/本棚03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBookshelf);
	LoadTexture("Res/家具/本04.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook);
	LoadTexture("Res/家具/本02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook2);
	LoadTexture("Res/家具/パーツ各種.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotAllParts);
	LoadTexture("Res/家具/腕.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotPartsArm);
	LoadTexture("Res/家具/脚.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotPartsLeg);
	LoadTexture("Res/家具/頭.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotPartsHead);
	LoadTexture("Res/家具/作業台.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalWorkbench);
	LoadTexture("Res/家具/パソコン.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalPC);
	LoadTexture("Res/家具/設計図.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotDesign);
	LoadTexture("Res/ちび執事(カオナシ).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);

}


#pragma region プレイヤーとオブジェクトのあたり判定
void HitSearchObject()
{
	//画面左端
	if (HitPlayerObject(0.0f, 0.0f, 155.0f, 490.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面左端
	else if (HitPlayerObject(0.0f, 580.0f, 155.0f, 500.0f) == true)
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
	else if (HitPlayerObject(1730.0f, 580.0f, 185.0f, 525.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面右端
	else if (HitPlayerObject(1730.0f, 0.0f, 185.0f, 450.0f) == true)
	{
		searchplayer.hit = true;
	}
	//メイド
	else if (HitPlayerObject(maidrobot.pos_x, maidrobot.pos_y, 64.0f, 110.0f) == true)
	{
		searchplayer.hit = true;
	}
	//大テーブル
	else if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true)
	{
		searchplayer.hit = true;	
	}
	//椅子１
	else if (HitPlayerObject(640.0f, 530.0f, 50.0f, 30.0f) == true)
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
	//コート掛け
	else if (HitPlayerObject(1010.0f, 935.0f, 65.0f, 50.0f) == true)
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

void HitSearch2Object()
{
	//花瓶
	if (HitPlayerObject(5.0f, 765.0f, 55.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	//花瓶2
	else if (HitPlayerObject(5.0f, 765.0f, 55.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	else if (HitPlayerObject(5.0f, 530.0f, 55.0f, 60.0f) == true && boyish.clear == true)
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
	//ボーイッシュ
	else if (HitPlayerObject(boyish.pos_x + 20.0f, boyish.pos_y + 64.0f, boyish.width - 30.0f, boyish.height - 62.0f) == true)
	{
		searchplayer.hit = true;
	}
	//首
	else if (HitPlayerObject(700.0f, 500.0f, 64.0f, 64.0f) == true && searchgameobject.robotneck == false)
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
	else if (HitPlayerObject(1180.0f, 95.0f, 270.0f, 160.0f) == true)
	{
		searchplayer.hit = true;
	}
	//箪笥と本棚
	else if (HitPlayerObject(460.0f, 35.0f, 450.0f, 240.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ぬいぐるみ
	else if (HitPlayerObject(525.0f, 625.0f, 35.0f, 70.0f) == true)
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

void HitCriminalRoomObject()
{
	//画面左端
	if (HitPlayerObject(0.0f, 0.0f, 325.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//画面右端
	else if (HitPlayerObject(1555.0f, 0.0f, 365.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ベッド
	else if (HitPlayerObject(335.0f, 865.0f, 265.0f, 145.0f) == true)
	{
		searchplayer.hit = true;
	}
	//大テーブル
	else if (HitPlayerObject(1160.0f, 745.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子１
	else if (HitPlayerObject(1240.0f, 1010.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子2
	else if (HitPlayerObject(1360.0f, 1010.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//椅子3
	else if (HitPlayerObject(1490.0f, 845.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//時計
	else if (HitPlayerObject(915.0f, 100.0f, 70.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	//照明
	else if (HitPlayerObject(345.0f, 1030.0f, 85.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	//キャビネット
	else if (HitPlayerObject(335.0f, 460.0f, 40.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	//箪笥
	else if (HitPlayerObject(1435.0f, 70.0f, 120.0f, 225.0f) == true)
	{
		searchplayer.hit = true;
	}
	//本棚
	else if (HitPlayerObject(335.0f, 75.0f, 270.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//本棚2
	else if (HitPlayerObject(615.0f, 75.0f, 270.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//作業台
	else if (HitPlayerObject(1000.0f, 220.0f, 410.0f, 175.0f) == true)
	{
		searchplayer.hit = true;
	}
	//ロボット
	else if (HitPlayerObject(925.0f, 280.0f, 40.0f, 70.0f) == true)
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
		searchobject.maid = true;
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
		searchobject.maid = false;
		searchplayer.eyehit = false;
	}
}

void HitEyeSearchGameObject()
{
	//ロボット
	if (HitPlayerEyeObject(searchgamerobot.pos_x + 20.0f, searchgamerobot.pos_y + 64.0f, searchgamerobot.width - 30.0f, searchgamerobot.height - 42.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.robot = true;
	}
	//ボーイッシュ
	else if (HitPlayerEyeObject(boyish.pos_x + 20.0f, boyish.pos_y + 64.0f, boyish.width - 30.0f, boyish.height - 62.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		boyish.talk = true;
	}
	//首
	else if (HitPlayerEyeObject(700.0f, 500.0f, 64.0f, 64.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.robotneck = true;
	}
	//ベッド
	else if (HitPlayerEyeObject(480.0f, 755.0f, 265.0f, 146.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		
		searchgameobject.bed = true;
	}
	//小テーブル
	else if(HitPlayerEyeObject(480.0f, 910.0f, 50.0f, 65.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.desk = true;
	}
	//大テーブル
	else if (HitPlayerEyeObject(1045.0f, 510.0f, 315.0f, 250.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子１
	else if (HitPlayerEyeObject(990.0f, 610.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.chair = true;
	}
	//椅子2
	else if (HitPlayerEyeObject(1120.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.chair = true;
	}
	//椅子3
	else if (HitPlayerEyeObject(1240.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.chair = true;
	}
	//植木鉢
	else if (HitPlayerEyeObject(1175.0f, 185.0f, 165.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.flowerpot = true;
	}
	//照明
	else if (HitPlayerEyeObject(1340.0f, 95.0f, 100.0f, 190.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.light = true;
	}
	//箪笥
	else if (HitPlayerEyeObject(460.0f, 35.0f, 125.0f, 255.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.closet = true;
	}
	//本棚
	else if (HitPlayerEyeObject(630.0f, 30.0f, 290.0f, 260.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		
		searchgameobject.bookshelf = true;
	}
	//ぬいぐるみ
	else if (HitPlayerEyeObject(522.0f, 625.0f, 45.0f, 75.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchgameobject.doll = true;
	}
	else
	{
		searchgameobject.robot = false;
		//searchgameobject.robotneck = false;
		
		searchgameobject.light = false;
		searchgameobject.closet = false;

		searchgameobject.desk = false;
		searchgameobject.chair = false;
		searchgameobject.doll = false;
		searchgameobject.bed = false;
		searchgameobject.flowerpot = false;
		searchgameobject.bookshelf = false;
		searchplayer.hit = false;
	}
}

void HitEyeTundereRoomObject()
{
	//ロボット
	if (HitPlayerEyeObject(mysterygamerobot.pos_x + 20.0f, mysterygamerobot.pos_y + 64.0f, mysterygamerobot.width - 30.0f, mysterygamerobot.height - 62.0f) == true
	    &&GetKeyDown(SPACE_KEY) == true)
	{
		tundereobject.robot = true;
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
		tundereobject.robot = false;
		searchplayer.eyehit = false;
	}
}

void HitEyeYuruhuwaRoomObject()
{
	//ロボット
	if (HitPlayerEyeObject(puzzlegamerobot.pos_x + 20.0f, puzzlegamerobot.pos_y + 64.0f, puzzlegamerobot.width - 30.0f, puzzlegamerobot.height - 62.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		yuruhuwaobject.robot = true;
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
		yuruhuwaobject.robot = false;
		searchplayer.eyehit = false;
	}
}

void HitEyeCriminalRoomObject()
{
	//ベッド
	if (HitPlayerEyeObject(335.0f, 865.0f, 265.0f, 145.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//大テーブル
	else if (HitPlayerEyeObject(1160.0f, 745.0f, 315.0f, 250.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子１
	else if (HitPlayerEyeObject(1240.0f, 1010.0f, 30.0f, 30.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子2
	else if (HitPlayerEyeObject(1360.0f, 1010.0f, 30.0f, 30.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//椅子3
	else if (HitPlayerEyeObject(1490.0f, 845.0f, 30.0f, 30.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//時計
	else if (HitPlayerEyeObject(915.0f, 100.0f, 70.0f, 185.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//照明
	else if (HitPlayerEyeObject(345.0f, 1030.0f, 85.0f, 185.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//キャビネット
	else if (HitPlayerEyeObject(335.0f, 460.0f, 55.0f, 60.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//箪笥
	else if (HitPlayerEyeObject(1435.0f, 70.0f, 120.0f, 225.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//本棚
	else if (HitPlayerEyeObject(335.0f, 75.0f, 270.0f, 260.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//本棚
	else if (HitPlayerEyeObject(615.0f, 75.0f, 270.0f, 260.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
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
	if (searchgameobject.robotneck == true)
	{
		getitem.itemrobot = true;
	}

	if (searchgameobject.light == true)
	{
		getitem.itemlight = true;
	}


	if (searchgameobject.bed == true && getitem.itemlight == true)
	{
		getitem.itemkey = true;
	}
	else if (searchgameobject.bed == true)
	{

	}


	if (searchgameobject.closet == true && getitem.itemkey == true)
	{
		getitem.itemenergy = true;
	}
	else if (searchgameobject.closet == true)
	{

	}

	if (searchgameobject.robot == true && getitem.itemenergy == true)
	{
		boyish.clear = true;
		searchgameobject.completerobot = true;
		getitem.itemrobot = false;
		getitem.itemenergy = false;
		getitem.boyishdoorkey = true;
		getitem.yuruhuwadoorkey = true;
		getitem.tunderedoorkey = true;
	}
	
}


