#include "Bg.h"
#include "Graphics.h"
#include "Texture.h"
#include "Player.h"

#define MOVIETEX_TU 0.0f
#define MOVITEXE_TV 0.45f
#define MOVIE_SPEED 0.001f
#define MOVIE_STOP_TIME 120

MovieBgData bgdate;
SearchAreaData areadata;
extern MoviePlayerDate movieplayer;

void InitBg()
{
	bgdate.Tu = MOVIETEX_TU;
	bgdate.Tv = MOVITEXE_TV;
	bgdate.movespeed = 0.002f;
	bgdate.stopcount = 0;
}

void InitArea()
{
	areadata.searcharea1 = true;
	areadata.searcharea2 = false;
	areadata.searchcriminalarea = false;
	areadata.searchgamearea = 0;
	areadata.searchtunderearea = false;
	areadata.searchyuruhuwaarea = false;
}

void DrawBg()
{
	DrawUVTexture(0.0f, 0.0f, GetTexture(TEXTURE_MOVIE, MovieCategoryTextureList::MovieBgTex), 1920, 2500, bgdate.Tu, bgdate.Tv);
}

void DrawTalkBg()
{
	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_TALK, TalkCategoryTextureList::TalkBgTex));
}

void DrawTundereBg()
{
	DrawBgTexture(GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRoomBgTex));
	DrawTexture(650.0f, 330.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCarpet));
	DrawTexture(450.0f, 840.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereBed));
	DrawTexture(1285.0f, 50.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCloset));
	DrawTexture(1000.0f, 625.f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDesk));
	DrawTexture(1255.0f, 630.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDoll));
	DrawTexture(450.0f, 225.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereFlowerpot));
	DrawTexture(450.0f, 610.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight));
	DrawTexture(655.0f, 150.f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereSofa));
	DrawTexture(455.0f, 65.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereWindow));

}

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
	DrawTexture(1330.0f, 780.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight));
	DrawTexture(1000.0f, 160.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaSofa));
	DrawTexture(520.0f, 25.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaWindow));

}

void DrawSearchBg()
{
	if (areadata.searcharea1 == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchBgTex));
	}
	else if (areadata.searcharea2 == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH2, Search2CategoryTextureList::Search2BgTex));
	}
	else if (areadata.searchgamearea == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBgTex));
	}
	else if (areadata.searchtunderearea == true)
	{
		DrawTundereBg();
	}
	else if (areadata.searchyuruhuwaarea == true)
	{
		DrawYuruhuwaBg();
	}
	else if (areadata.searchcriminalarea == true)
	{
		DrawBgTexture(GetTexture(TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRoomBgTex));
	}
}


//ムービー用背景移動
void UpDateBg()
{
	//プレイヤーが特定の位置に来た時
	if (movieplayer.Bg_pos == true)
	{
		//プレイヤーは動かず背景だけ移動
		bgdate.Tv -= bgdate.movespeed;
		movieplayer.pos_y += movieplayer.movespeed;


		if (bgdate.Tv <= 0.01f)
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
			bgdate.stopcount++;

			if (bgdate.stopcount == MOVIE_STOP_TIME)
			{
				bgdate.movespeed = -0.002f;
				movieplayer.movespeed -= 4.7;
			}

		}
		

		if (bgdate.Tv >= 0.5)//元の画面に戻った時
		{
			bgdate.movespeed = 0.0f;
			movieplayer.movespeed = 0.0f;
		
			movieplayer.moveanimesion = false;
		}
	}
	
}
