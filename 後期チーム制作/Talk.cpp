#include "Talk.h"
#include "Text.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Robot.h"
#include "Bg.h"
#include <cstdio>
#include "Item.h"
#include "JK.h"
#include <string.h>
#include "Puzzle.h"

void DrawTalkObject(bool* touchobject, bool* tolkobject, char* text)
{
	if (*touchobject == true && *tolkobject == false)
	{
		*tolkobject = true;
		textbox.onspacekey = true;

	}
	else if (GetKeyDown(SPACE_KEY) == true && *tolkobject == true)
	{
		*tolkobject = false;

		textbox.onspacekey = false;

	}
	if (*tolkobject == true)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, text, FontSize::Regular, FontColor::White);
	}
}


void InitRobotLoadFile()
{
	textdata.robot_nexttext = false;

	if (moviebgdate.endmovie == true)
	{
		FILE* DescriptionFp;

		fopen_s(&DescriptionFp, "Res/テキスト/操作説明.txt", "r");

		fgets(textdata.robot_text, 1000, DescriptionFp);
		fclose(DescriptionFp);
	}
	else if (areadata.corridor == true)
	{
		FILE* BreakKyeFp;

		fopen_s(&BreakKyeFp, "Res/テキスト/鍵使用時.txt", "r");

		fgets(textdata.robot_text, 1000, BreakKyeFp);
		fclose(BreakKyeFp);
	}
#pragma region メイド会話
	else if (areadata.largeroom == true && maidrobot.talktype == 0)
	{
		FILE* MaidTalkFp_0;

		fopen_s(&MaidTalkFp_0, "Res/テキスト/メイド会話(鍵入手).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_0);
		fclose(MaidTalkFp_0);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 1)
	{
		FILE* MaidTalkFp_1;

		fopen_s(&MaidTalkFp_1, "Res/テキスト/メイド会話(パターン1).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_1);
		fclose(MaidTalkFp_1);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 2)
	{
		FILE* MaidTalkFp_2;

		fopen_s(&MaidTalkFp_2, "Res/テキスト/メイド会話(パターン2).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_2);
		fclose(MaidTalkFp_2);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 3)
	{
		FILE* MaidTalkFp_3;

		fopen_s(&MaidTalkFp_3, "Res/テキスト/メイド会話(パターン3).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_3);
		fclose(MaidTalkFp_3);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 4)
	{
		FILE* MaidTalkFp_4;

		fopen_s(&MaidTalkFp_4, "Res/テキスト/メイド会話(パターン4).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_4);
		fclose(MaidTalkFp_4);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 5)
	{
		FILE* MaidTalkFp_5;

		fopen_s(&MaidTalkFp_5, "Res/テキスト/メイド会話(パターン5).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_5);
		fclose(MaidTalkFp_5);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 6)
	{
		FILE* MaidTalkFp_6;

		fopen_s(&MaidTalkFp_6, "Res/テキスト/メイド会話(パターン6).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_6);
		fclose(MaidTalkFp_6);
	}
#pragma endregion

#pragma region ボーイッシュ執事会話
	if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 0)
	{
		FILE* SearchGameRobotFp;

		fopen_s(&SearchGameRobotFp, "Res/テキスト/ボーイッシュ執事システム.txt", "r");

		fgets(textdata.robot_text, 1000, SearchGameRobotFp);
		fclose(SearchGameRobotFp);
	}
	else if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 1)
	{
	    FILE* SearchGameRobotFp_1;
	    
	    fopen_s(&SearchGameRobotFp_1, "Res/テキスト/ボーイッシュ執事クリア時システム.txt", "r");
	    
	    fgets(textdata.robot_text, 1000, SearchGameRobotFp_1);
	    fclose(SearchGameRobotFp_1);
		searchgamerobot.talktype = 2;
	}
	else if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 2)
	{
		FILE* SearchGameRobotFp_2;

		fopen_s(&SearchGameRobotFp_2, "Res/テキスト/ボーイッシュ執事会話.txt", "r");

		fgets(textdata.robot_text, 1000, SearchGameRobotFp_2);
		fclose(SearchGameRobotFp_2);
	}
#pragma endregion
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 0)
	{
		FILE* PuzzleGameRobotFp;

		fopen_s(&PuzzleGameRobotFp, "Res/テキスト/ゆるふわ執事システム.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp);
		fclose(PuzzleGameRobotFp);
		
	}
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 1)
	{
		FILE* PuzzleGameRobotFp_1;

		fopen_s(&PuzzleGameRobotFp_1, "Res/テキスト/ゆるふわ執事クリア時システム.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp_1);
		fclose(PuzzleGameRobotFp_1);
		puzzlegamerobot.talktype = 2;
	}
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 2)
	{
		FILE* PuzzleGameRobotFp_2;

		fopen_s(&PuzzleGameRobotFp_2, "Res/テキスト/ゆるふわ執事会話.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp_2);
		fclose(PuzzleGameRobotFp_2);
	}

}

void InitJKLoadFile()
{
#pragma region ボーイッシュ
	if (areadata.searchgamearea == true && boyish.talktype == 0)
	{
		FILE* BoyishFp;

		fopen_s(&BoyishFp, "Res/テキスト/ボーイッシュシステム.txt", "r");

		fgets(textdata.jk_text, 1000, BoyishFp);
		fclose(BoyishFp);
		boyish.talktype = 1;
	}
	else if (areadata.searchgamearea == true && boyish.talktype == 1 && searchgameobject.completerobot == false)
	{
		FILE* BoyishFp_1;

		fopen_s(&BoyishFp_1, "Res/テキスト/ボーイッシュ会話(鍵未入手).txt", "r");

		fgets(textdata.jk_text, 1000, BoyishFp_1);
		fclose(BoyishFp_1);

	}
	else if (areadata.searchgamearea == true && boyish.talktype == 1 && searchgameobject.completerobot == true)
	{
		FILE* BoyishFp_2;

		fopen_s(&BoyishFp_2, "Res/テキスト/ボーイッシュクリア時システム.txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_2);
		fclose(BoyishFp_2);
		boyish.talktype = 2;
	}
	else if (areadata.searchgamearea == true && boyish.talktype == 2)
	{
		FILE* BoyishFp_3;

		fopen_s(&BoyishFp_3, "Res/テキスト/ボーイッシュ会話(救出後).txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_3);
		fclose(BoyishFp_3);
	}
	else if (areadata.corridor == true && boyish.clear == true)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/テキスト/ボーイッシュ会話(廊下).txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.largeroom == true && boyish.clear == true)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/テキスト/ボーイッシュ会話(大部屋).txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.largeroom == false && boyish.clear == true && boyish.heart == 3)
	{
		FILE* BoyishFp_Clear;

		fopen_s(&BoyishFp_Clear, "Res/テキスト/ボーイッシュ会話(クリア).txt", "r");

		fgets(textdata.jk_text, 5000, BoyishFp_Clear);
		fclose(BoyishFp_Clear);
	}
	else if (areadata.largeroom == false && boyish.clear == true && boyish.heart != 3)
	{
		FILE* BoyishFp_Clear2;

		fopen_s(&BoyishFp_Clear2, "Res/テキスト/ボーイッシュ会話(クリア好感度MIN).txt", "r");

		fgets(textdata.jk_text, 5000, BoyishFp_Clear2);
		fclose(BoyishFp_Clear2);
	}
#pragma endregion

#pragma region ゆるふわ
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 0)
	{
		FILE* YuruhuwaFp;

		fopen_s(&YuruhuwaFp, "Res/テキスト/ゆるふわシステム.txt", "r");

		fgets(textdata.jk_text, 1000, YuruhuwaFp);
		fclose(YuruhuwaFp);

		yuruhuwa.talktype = 1;
	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 1 && puzzle.goal_key == false)
	{
		FILE* YuruhuwaFp_1;

		fopen_s(&YuruhuwaFp_1, "Res/テキスト/ゆるふわ会話(鍵入手前).txt", "r");

		fgets(textdata.jk_text, 1000, YuruhuwaFp_1);
		fclose(YuruhuwaFp_1);

	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 1 && puzzle.goal_key == true)
	{
		FILE* YuruhuwaFp_2;

		fopen_s(&YuruhuwaFp_2, "Res/テキスト/ゆるふわクリア時システム.txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_2);
		fclose(YuruhuwaFp_2);
		
	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 2)
	{
		FILE* YuruhuwaFp_3;

		fopen_s(&YuruhuwaFp_3, "Res/テキスト/ゆるふわ会話(救出後).txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_3);
		fclose(YuruhuwaFp_3);
	}
	else if (areadata.corridor == true && yuruhuwa.clear == true)
	{
		FILE* YuruhuwaFp_4;

		fopen_s(&YuruhuwaFp_4, "Res/テキスト/ゆるふわ会話(廊下).txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_4);
		fclose(YuruhuwaFp_4);
	}
	else if (areadata.largeroom == true && yuruhuwa.clear == true)
	{
		FILE* YuruhuwaFp_5;

		fopen_s(&YuruhuwaFp_5, "Res/テキスト/ゆるふわ会話(大部屋).txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_5);
		fclose(YuruhuwaFp_5);
	}
	else if (areadata.largeroom == false && yuruhuwa.clear == true && yuruhuwa.heart == 3)
	{
		FILE* YuruhuwaFp_Clear;

		fopen_s(&YuruhuwaFp_Clear, "Res/テキスト/ゆるふわ会話(クリア好感度MAX).txt", "r");

		fgets(textdata.jk_text, 5000, YuruhuwaFp_Clear);
		fclose(YuruhuwaFp_Clear);
	}
	else if (areadata.largeroom == false && yuruhuwa.clear == true && yuruhuwa.heart != 3)
	{
	FILE* YuruhuwaFp_Clear2;

	fopen_s(&YuruhuwaFp_Clear2, "Res/テキスト/ゆるふわ会話(クリア好感度MIN).txt", "r");

	fgets(textdata.jk_text, 5000, YuruhuwaFp_Clear2);
	fclose(YuruhuwaFp_Clear2);
	}
#pragma endregion
}

void RobotLoadText()
{

	textdata.robot_oneline = NULL;
	textdata.robot_twoline = NULL;
	textdata.robot_threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	if (choicetexturedata.decision_2 == true)
	{
		textdata.robot_oneline = strtok(textdata.robot_text, ",");
		
	}
	else if (textdata.robot_nexttext == true)
	{
		textdata.robot_oneline = strtok(NULL, ",");
	}
	else
	{
		textdata.robot_oneline = strtok(textdata.robot_text, ",");
	}

	textdata.robot_twoline = strtok(NULL, ",");
	textdata.robot_threeline = strtok(NULL, ",");
}

void JKLoadText()
{

	textdata.jk_oneline = NULL;
	textdata.jk_twoline = NULL;
	textdata.jk_threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	//好感度
	if (choicetexturedata.decision_1 == true)
	{
		textdata.jk_oneline = strtok(NULL, ",");
		textdata.jk_twoline = strtok(NULL, ",");
		textdata.jk_threeline = strtok(NULL, ",");

		textdata.jk_lossoneline = strtok(NULL, ",");
		textdata.jk_losstwoline = strtok(NULL, ",");
		textdata.jk_lossthreeline = strtok(NULL, ",");
		choicetexturedata.decision_1 = false;
		boyish.heart++;
		yuruhuwa.heart++;

	}
	//好感度
	else if (choicetexturedata.decision_2 == true)
	{
		textdata.jk_lossoneline = strtok(NULL, ",");
		textdata.jk_losstwoline = strtok(NULL, ",");
		textdata.jk_lossthreeline = strtok(NULL, ",");

		textdata.jk_oneline = strtok(NULL, ",");
		textdata.jk_twoline = strtok(NULL, ",");
		textdata.jk_threeline = strtok(NULL, ",");
		choicetexturedata.decision_2 = false;
	}
	else if (textdata.jk_nexttext == true)
	{
  		textdata.jk_oneline = strtok(NULL, ",");
		textdata.jk_twoline = strtok(NULL, ",");
		textdata.jk_threeline = strtok(NULL, ",");
	}
	else
	{
		textdata.jk_oneline = strtok(textdata.jk_text, ",");
		textdata.jk_twoline = strtok(NULL, ",");
		textdata.jk_threeline = strtok(NULL, ",");
	}

}

void DrawRobotTalkText()
{
	DrawFont(300.0f, 760.0f, textdata.robot_oneline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 860.0f, textdata.robot_twoline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 960.0f, textdata.robot_threeline, FontSize::Regular, FontColor::White);
}

void DrawJKTalkText()
{
	

	if (displaydata.display_cleartext == false && areadata.cleararea == true)
	{
		DrawFont(400.0f, 460.0f, textdata.jk_oneline, FontSize::Regular, FontColor::White);
		DrawFont(400.0f, 560.0f, textdata.jk_twoline, FontSize::Regular, FontColor::White);
		DrawFont(400.0f, 660.0f, textdata.jk_threeline, FontSize::Regular, FontColor::White);
	}
	else if(boyish.end == true)
	{
		DrawFont(300.0f, 760.0f, textdata.jk_oneline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 860.0f, textdata.jk_twoline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 960.0f, textdata.jk_threeline, FontSize::Regular, FontColor::Yellow);
	}
	else
	{
		DrawFont(300.0f, 760.0f, textdata.jk_oneline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 860.0f, textdata.jk_twoline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 960.0f, textdata.jk_threeline, FontSize::Regular, FontColor::White);
	}
}

void DrawDescription()
{

	if (maidrobot.description == false && moviebgdate.endmovie == true)
	{
		UpDataDescriptionText();
		maidrobot.description = true;
		textbox.onspacekey = true;
	}
	else if (textdata.robot_threeline == NULL && maidrobot.description == true && moviebgdate.endmovie == false || choicetexturedata.decision_2 == true)
	{
		maidrobot.description = false;
		textbox.onspacekey = false;
		choicetexturedata.decision_2 = false;
		InitRobotLoadFile();
		
	}
	if (maidrobot.description == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline, "はい"))
		{
			DrawChoiceTexture();	
		}
	}

}

void UpDataDescriptionText()
{

	if (GetKeyDown(SPACE_KEY) == true && maidrobot.description == true)
	{
		if ((maidrobot.description == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
		}
		RobotLoadText();
		textdata.robot_nexttext = true;
	}
	if (moviebgdate.endmovie == true)
	{
		RobotLoadText();
		moviebgdate.endmovie = false;
		textdata.robot_nexttext = true;

	}
}

void DrawDoorTalk()
{
#pragma region ボーイッシュ扉会話
	//最初の鍵が壊れていない時
	if (corridorobject.boyishdoor == true && corridorobject.doortalk == false  && getitem.breakdoorkey == false)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//鍵を持っていない状態で最初の鍵が壊れているとき
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == false && getitem.boyishdoorkey == false && getitem.breakdoorkey == true)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//最初のの鍵を使った後同じ部屋で使うとき
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == false && getitem.boyishdoorkey == true)
	{
		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;
		textbox.onspacekey = false;
		displaydata.displaynext = true;
		areadata.searchgamearea = true;
		boyish.areachange = true;

	}
	//いいえを選択したとき
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.boyishdoor == true && corridorobject.doortalk == true
		&& getitem.boyishdoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;


	}
	//はいを選択したとき
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.boyishdoor == true && corridorobject.doortalk == true
		&& getitem.boyishdoorkey == true && textdata.robot_threeline == NULL)
	{
		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;

		getitem.tunderedoorkey = false;
		getitem.yuruhuwadoorkey = false;
		
		textbox.onspacekey = false;
		displaydata.displaynext = true;

		areadata.searchgamearea = true;
		areadata.searchtunderearea = false;
		areadata.searchyuruhuwaarea = false;

	}
	//他の扉でいいえをを選択したとき
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.boyishdoor == true && corridorobject.doortalk == true && getitem.boyishdoorkey != true)
	{
 		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;
		textbox.onspacekey = false;
		textdata.robot_nexttext = false;


	}

	if (corridorobject.boyishdoor == true && corridorobject.doortalk == true && getitem.boyishdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "ドアがある。鍵がかかっていて、入ることはできない。", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == true && getitem.boyishdoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline,"はい"))
		{
			DrawChoiceTexture();
		}
		
	}
#pragma endregion

#pragma region ツンデレ扉会話
	if (corridorobject.tunderedoor == true && corridorobject.doortalk == false && getitem.breakdoorkey == false)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	else if (corridorobject.tunderedoor == true && corridorobject.doortalk == false && getitem.tunderedoorkey == false && getitem.breakdoorkey == true)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	else if (corridorobject.tunderedoor == true && corridorobject.doortalk == false && getitem.tunderedoorkey == true)
	{
		corridorobject.doortalk = false;
		corridorobject.tunderedoor = false;
		textbox.onspacekey = false;
		displaydata.displaynext = true;
		areadata.searchtunderearea = true;
	}
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.tunderedoor == true && corridorobject.doortalk == true
		&& getitem.tunderedoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.tunderedoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;


	}
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.tunderedoor == true && corridorobject.doortalk == true
		&& getitem.tunderedoorkey == true && textdata.robot_threeline == NULL)
	{
		corridorobject.doortalk = false;
		corridorobject.tunderedoor = false;

		getitem.boyishdoorkey = false;
		getitem.yuruhuwadoorkey = false;

		textbox.onspacekey = false;
		displaydata.displaynext = true;

		areadata.searchtunderearea = true;
		areadata.searchgamearea = false;
		areadata.searchyuruhuwaarea = false;

	}
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.tunderedoor == true && corridorobject.doortalk == true
		&& corridorobject.doortalk == true && getitem.tunderedoorkey != true)
	{
		corridorobject.doortalk = false;
		corridorobject.tunderedoor = false;
		textbox.onspacekey = false;
		textdata.robot_nexttext = false;


	}
	if (corridorobject.tunderedoor == true && corridorobject.doortalk == true && getitem.tunderedoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "ドアがある。鍵がかかっていて、入ることはできない。", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.tunderedoor == true && corridorobject.doortalk == true && getitem.tunderedoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline, "はい"))
		{
			DrawChoiceTexture();
		}
		
	}
#pragma endregion

#pragma region ゆるふわ扉会話
	//最初の鍵が壊れていない時
	if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == false && getitem.breakdoorkey == false)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//鍵を持っていない状態で最初の鍵が壊れているとき
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == false && getitem.yuruhuwadoorkey == false && getitem.breakdoorkey == true)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//最初のの鍵を使った後同じ部屋で使うとき
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == false && getitem.yuruhuwadoorkey == true)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;
		textbox.onspacekey = false;
		displaydata.displaynext = true;

		yuruhuwa.areachange = true;
		areadata.searchyuruhuwaarea = true;
	}
	//いいえを選択したとき
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true
		&& getitem.yuruhuwadoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;


	}
	//はいを選択したとき
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true
		&& getitem.yuruhuwadoorkey == true && textdata.robot_threeline == NULL)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;

		getitem.tunderedoorkey = false;
		getitem.boyishdoorkey = false;

		textbox.onspacekey = false;
		displaydata.displaynext = true;

		areadata.searchyuruhuwaarea = true;
		areadata.searchgamearea = false;
		areadata.searchtunderearea = false;

	}
	//他の扉でいいえをを選択したとき
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true && getitem.yuruhuwadoorkey != true)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;
		textbox.onspacekey = false;
		textdata.robot_nexttext = false;

	}
	if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true && getitem.yuruhuwadoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "ドアがある。鍵がかかっていて、入ることはできない。", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true && getitem.yuruhuwadoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline, "はい"))
		{
			DrawChoiceTexture();
		}
		
	}
#pragma endregion
}

void UpDataDoorText()
{
	if (choicetexturedata.door_touch == true)
	{
		choicetexturedata.door_touch = false;
		if (choicetexturedata.decision_2 == true)
		{
			InitRobotLoadFile();
		}
		if (choicetexturedata.decision_2 == true)
		{
			choicetexturedata.decision_2 = false;
		}
		else if ((corridorobject.doortalk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
		}
		
		RobotLoadText();
		textdata.robot_nexttext = true;

	}
}

