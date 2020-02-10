#include "Bg.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"
#include "Title.h"
#include "Hit.h"
#include "JK.h"
#include "Text.h"

#define MOVIETEX_TU 0.0f
#define MOVITEXE_TV 0.45f
#define MOVIE_SPEED 0.001f
#define MOVIE_STOP_TIME 120

TitleBgData titlebg;
MovieBgData moviebgdate;
SearchAreaData areadata;
extern MoviePlayerDate movieplayer;

void InitMovieBg()
{
	moviebgdate.Tu = MOVIETEX_TU;
	moviebgdate.Tv = MOVITEXE_TV;
	moviebgdate.movespeed = 0.002f;
	moviebgdate.stopcount = 0;

}

void InitArea()
{
	areadata.largeroom = true;
	areadata.corridor = false;
	areadata.searchcriminalarea = false;
	areadata.searchgamearea = false;
	areadata.searchtunderearea = false;
	areadata.searchyuruhuwaarea = false;
	areadata.cleararea = false;
}

void DrawTitleBg()
{
	DrawBgTexture(GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleBgTex));

	if (HitChoise(START_X, START_Y, START_X_SIZE, START_Y_SIZE) == true)
	{
		titlebg.choicestart = true;
	}
	else if (HitChoise(END_X, END_Y, END_X_SIZE, END_Y_SIZE) == true)
	{
		titlebg.choiceend = true;
	}
	else if(HitChoise(LIST_X, LIST_Y, LIST_X_SIZE, LIST_Y_SIZE) == true)
	{
		titlebg.choicelist = true;
	}
	else
	{
		titlebg.choicestart = false;
		titlebg.choiceend = false;
		titlebg.choicelist = false;
	}


	if (titlebg.choicestart == true)
	{
		DrawTexture(START_X, START_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleStartChoiceTex));
		DrawTexture(END_X, END_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex));
		DrawTexture(LIST_X, LIST_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleListTex));
	}
	if (titlebg.choiceend == true)
	{
		DrawTexture(START_X, START_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex));
		DrawTexture(END_X, END_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleEndChoiceTex));
		DrawTexture(LIST_X, LIST_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleListTex));
		
	}
	if (titlebg.choicelist == true)
	{
		DrawTexture(LIST_X, LIST_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleListChoiceTex));
		DrawTexture(START_X, START_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex));
		DrawTexture(END_X, END_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex));

	}
	else
	{
		DrawTexture(START_X, START_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleStartTex));
		DrawTexture(END_X, END_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleEndTex));
		DrawTexture(LIST_X, LIST_Y, GetTexture(TEXTURE_TITLE, TitleCategoryTextureList::TitleListTex));
	}

}

void DrawMovieBg()
{
	DrawUVTexture(0.0f, 0.0f, GetTexture(TEXTURE_MOVIE, MovieCategoryTextureList::MovieBgTex), 1920, 2500, moviebgdate.Tu, moviebgdate.Tv);
}


void DrawCorridorBg()
{
	DrawBgTexture(GetTexture(TEXTURE_SEARCH2, CorridorCategoryTextureList::Search2BgTex));
	DrawTexture(1435.0f, 395.0f,GetTexture(TEXTURE_SEARCH2, CorridorCategoryTextureList::Search2Door));
	DrawTexture(845.0f, 395.0f,GetTexture(TEXTURE_SEARCH2, CorridorCategoryTextureList::Search2Door));
	DrawTexture(230.0f, 395.0f,GetTexture(TEXTURE_SEARCH2, CorridorCategoryTextureList::Search2Door));
	
	DrawTexture(5.0f, 460.0f, GetTexture(TEXTURE_SEARCH2, CorridorCategoryTextureList::Search2Vase));

}
//家具の配置も一緒にやっている
void DrawTundereBg()
{
	DrawBgTexture(GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRoomBgTex));
	DrawTexture(650.0f, 330.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCarpet));
	DrawTexture(450.0f, 840.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereBed));
	DrawTexture(1285.0f, 50.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCloset));
	DrawTexture(1000.0f, 625.f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDesk));
	DrawTexture(1255.0f, 630.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDoll));
	DrawTexture(450.0f, 225.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereFlowerpot));
	DrawTexture(655.0f, 150.f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereSofa));
	DrawTexture(455.0f, 65.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereWindow));

}

//家具の配置も一緒にやっている
void DrawYuruhuwaBg()
{
	DrawBgTexture(GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRoomBgTex));
	DrawTexture(450.0f, 715.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaBed));
	DrawTexture(1385.0f, 455.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCabinet));
	DrawTexture(665.0f, 345.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCarpet));
	DrawTexture(850.0f, 50.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCloset));
	DrawTexture(1295.0f, 70.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaClock));
	DrawTexture(420.0f, 225.f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDesk));
	DrawTexture(1100.0f, 160.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDoll));
	DrawTexture(1000.0f, 160.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaSofa));
	DrawTexture(520.0f, 25.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaWindow));
	if (yuruhuwa.unlock == false)
	{
		DrawTexture(1230.0f, 340.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaFetters));
	}

}

void DrawCriminalBg()
{
	DrawBgTexture(GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRoomBgTex));
	DrawTexture(370.0f, 210.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRedCarpet));
	DrawTexture(300.0f, 540.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBuleCarpet));
	DrawTexture(990.0f, 535.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalGreenCarpet));
	DrawTexture(310.0f, 845.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBed));
	DrawTexture(335.0f, 845.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRight));
	DrawTexture(300.0f, 65.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBookshelf));
	DrawTexture(590.0f, 65.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBookshelf));
	DrawTexture(875.0f, 90.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalClock));
	DrawTexture(1410.0f, 50.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCloset));
	DrawTexture(320.0f, 460.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCabinet));
	DrawTexture(1110.0f, 700.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalDesk));
	DrawTexture(340.0f, 320.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook));
	DrawTexture(670.0f, 320.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook));
	DrawTexture(970.0f, 185.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalWorkbench));
	DrawTexture(1165.0f, 85.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotAllParts));
	DrawTexture(670.0f, 35.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotPartsArm));
	DrawTexture(1190.0f, 780.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotPartsHead));
	DrawTexture(1000.0f, 285.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotPartsLeg));
	DrawTexture(1280.0f, 260.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalPC));
	DrawTexture(985.0f, 75.0f, GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRobotDesign));
	DrawTexture(920.0f, 250.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex));
}

//エリア移動時に切り替え
void DrawSearchBg()
{
	if (areadata.largeroom == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomBgTex));
	}
	else if (areadata.corridor == true)
	{
		DrawCorridorBg();
	}
	else if (areadata.searchgamearea == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex));
		if (boyish.unlock == false)
		{
			DrawTexture(1070.0f, 280.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameFetters));
		}
	}																								 
	else if (areadata.searchtunderearea == true)
	{
		DrawTundereBg();
		if (tundere.unlock == false)
		{
			DrawTexture(tundere.pos_x+30.0f, tundere.pos_y+100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameFetters));
		}
	}
	else if (areadata.searchyuruhuwaarea == true)
	{
		DrawYuruhuwaBg();
		if (yuruhuwa.unlock == false)
		{
			DrawTexture(yuruhuwa.pos_x+60.0f, yuruhuwa.pos_y+110.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameFetters));
		}
	}
	else if (areadata.searchcriminalarea == true)
	{
		DrawCriminalBg();
	}
}


//ムービー用背景移動
void UpDateBg()
{
	//プレイヤーが特定の位置に来た時
	if (movieplayer.Bg_pos == true)
	{
		//プレイヤーは動かず背景だけ移動
		moviebgdate.Tv -= moviebgdate.movespeed;
		movieplayer.pos_y += movieplayer.movespeed;


		if (moviebgdate.Tv <= 0.01f)
		{
			moviebgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
			moviebgdate.stopcount++;

			if (moviebgdate.stopcount == MOVIE_STOP_TIME)
			{
				moviebgdate.movespeed = -0.002f;
				movieplayer.movespeed -= 4.7;
			}

		}
		

		if (moviebgdate.Tv >= 0.5)//元の画面に戻った時
		{
			moviebgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
		
			movieplayer.moveanimesion = false;
		}
	}
	
}

void GameClearBg()
{
	if (boyish.clear == true && boyish.heart == 3&& displaydata.display_cleartext == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::BoyishClearBgTex));
	}
	/*else if (tundere.clear == true && tundere.heart == 3)
	{
		DrawBgTexture(GetTexture(TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::TundereClearBgTex));
	}*/
	else if (yuruhuwa.clear == true && yuruhuwa.heart == 3)
	{
		DrawBgTexture(GetTexture(TEXTURE_GAME_CLEAR, GameClearCategoryTextureList::YuruhuwaClearBgTex));
	}
}
