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



//ファイル読み込み関数(ロボ)
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
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/テキスト/メイド会話(鍵入手).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 1)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/テキスト/メイド会話(パターン1).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 2)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/テキスト/メイド会話(パターン2).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 3)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/テキスト/メイド会話(パターン3).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 4)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/テキスト/メイド会話(パターン4).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 5)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/テキスト/メイド会話(パターン5).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 6)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/テキスト/メイド会話(パターン6).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
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
	    FILE* SearchGameRobotFp;
	    
	    fopen_s(&SearchGameRobotFp, "Res/テキスト/ボーイッシュ執事クリア時システム.txt", "r");
	    
	    fgets(textdata.robot_text, 1000, SearchGameRobotFp);
	    fclose(SearchGameRobotFp);
		searchgamerobot.talktype = 2;
	}
	else if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 2)
	{
		FILE* SearchGameRobotFp;

		fopen_s(&SearchGameRobotFp, "Res/テキスト/ボーイッシュ執事会話.txt", "r");

		fgets(textdata.robot_text, 1000, SearchGameRobotFp);
		fclose(SearchGameRobotFp);
	}
#pragma endregion

#pragma region ゆるふわ執事会話
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 0)
	{
		FILE* PuzzleGameRobotFp;

		fopen_s(&PuzzleGameRobotFp, "Res/テキスト/ゆるふわ執事システム.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp);
		fclose(PuzzleGameRobotFp);
		
	}
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 1)
	{
		FILE* PuzzleGameRobotFp;

		fopen_s(&PuzzleGameRobotFp, "Res/テキスト/ゆるふわ執事クリア時システム.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp);
		fclose(PuzzleGameRobotFp);
		puzzlegamerobot.talktype = 2;
	}
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 2)
	{
		FILE* PuzzleGameRobotFp;

		fopen_s(&PuzzleGameRobotFp, "Res/テキスト/ゆるふわ執事会話.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp);
		fclose(PuzzleGameRobotFp);
	}
#pragma endregion

#pragma region ツンデレ執事会話
	else if (areadata.searchtunderearea == true && areadata.corridor == false && mysterygamerobot.talktype == 0)
	{
		FILE* MysteryGameRobotFp;

		fopen_s(&MysteryGameRobotFp, "Res/テキスト/ツンデレ執事システム.txt", "r");

		fgets(textdata.robot_text, 1000, MysteryGameRobotFp);
		fclose(MysteryGameRobotFp);

	}
	else if (areadata.searchtunderearea == true && areadata.corridor == false && mysterygamerobot.talktype == 1)
	{
		FILE* MysteryGameRobotFp;

		fopen_s(&MysteryGameRobotFp, "Res/テキスト/ツンデレ執事クリア時システム.txt", "r");

		fgets(textdata.robot_text, 1000, MysteryGameRobotFp);
		fclose(MysteryGameRobotFp);
		mysterygamerobot.talktype = 2;
	}
	else if (areadata.searchtunderearea == true && areadata.corridor == false && mysterygamerobot.talktype == 2)
	{
		FILE* MysteryGameRobotFp;

		fopen_s(&MysteryGameRobotFp, "Res/テキスト/ツンデレ執事会話.txt", "r");

		fgets(textdata.robot_text, 1000, MysteryGameRobotFp);
		fclose(MysteryGameRobotFp);
	}
#pragma endregion
}

//ファイル読み込み関数(JK)
void InitJKLoadFile()
{
#pragma region ボーイッシュ
	if (areadata.searchgamearea == true && boyish.talktype == 0)
	{
		FILE* BoyishFp;

		fopen_s(&BoyishFp, "Res/テキスト/ボーイッシュシステム.txt", "r");

		fgets(textdata.boyish_text, 1000, BoyishFp);
		fclose(BoyishFp);
		boyish.talktype = 1;
	}
	else if (areadata.searchgamearea == true && boyish.talktype == 1 && searchgameobject.completerobot == false)
	{
		FILE* BoyishFp_1;

		fopen_s(&BoyishFp_1, "Res/テキスト/ボーイッシュ会話(鍵未入手).txt", "r");

		fgets(textdata.boyish_text, 1000, BoyishFp_1);
		fclose(BoyishFp_1);

	}
	else if (areadata.searchgamearea == true && boyish.talktype == 1 && searchgameobject.completerobot == true)
	{
		FILE* BoyishFp_2;

		fopen_s(&BoyishFp_2, "Res/テキスト/ボーイッシュクリア時システム.txt", "r");

		fgets(textdata.boyish_text, 2000, BoyishFp_2);
		fclose(BoyishFp_2);
		boyish.talktype = 2;
	}
	else if (areadata.searchgamearea == true && boyish.talktype == 2)
	{
		FILE* BoyishFp_3;

		fopen_s(&BoyishFp_3, "Res/テキスト/ボーイッシュ会話(救出後).txt", "r");

		fgets(textdata.boyish_text, 2000, BoyishFp_3);
		fclose(BoyishFp_3);
	}
	else if (areadata.corridor == true && boyish.clear == true && boyish.heart == 3)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/テキスト/ボーイッシュ会話(廊下).txt", "r");

		fgets(textdata.boyish_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.corridor == true && boyish.clear == true)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/テキスト/ボーイッシュ会話(廊下好感度MIN).txt", "r");

		fgets(textdata.boyish_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.largeroom == true && boyish.clear == true)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/テキスト/ボーイッシュ会話(大部屋).txt", "r");

		fgets(textdata.boyish_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.largeroom == false && boyish.clear == true && boyish.heart == 3)
	{
		FILE* BoyishFp_Clear;

		fopen_s(&BoyishFp_Clear, "Res/テキスト/ボーイッシュ会話(クリア).txt", "r");

		fgets(textdata.boyish_text, 5000, BoyishFp_Clear);
		fclose(BoyishFp_Clear);
	}
	else if (areadata.largeroom == false && boyish.clear == true && boyish.heart != 3 && areadata.cleararea == true)
	{
		FILE* BoyishFp_Clear2;

		fopen_s(&BoyishFp_Clear2, "Res/テキスト/ボーイッシュ会話(クリア好感度MIN).txt", "r");

		fgets(textdata.boyish_text, 5000, BoyishFp_Clear2);
		fclose(BoyishFp_Clear2);
	}
#pragma endregion

#pragma region ゆるふわ
	if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 0)
	{
		FILE* YuruhuwaFp;

		fopen_s(&YuruhuwaFp, "Res/テキスト/ゆるふわシステム.txt", "r");

		fgets(textdata.yuruhuwa_text, 1000, YuruhuwaFp);
		fclose(YuruhuwaFp);

		yuruhuwa.talktype = 1;
	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 1 && yuruhuwa.clear == false)
	{
		FILE* YuruhuwaFp_1;

		fopen_s(&YuruhuwaFp_1, "Res/テキスト/ゆるふわ会話(鍵入手前).txt", "r");

		fgets(textdata.yuruhuwa_text, 1000, YuruhuwaFp_1);
		fclose(YuruhuwaFp_1);

	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 1 && yuruhuwa.clear == true)
	{
		FILE* YuruhuwaFp_2;

		fopen_s(&YuruhuwaFp_2, "Res/テキスト/ゆるふわクリア時システム.txt", "r");

		fgets(textdata.yuruhuwa_text, 2000, YuruhuwaFp_2);
		fclose(YuruhuwaFp_2);
		
	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 2)
	{
		FILE* YuruhuwaFp_3;

		fopen_s(&YuruhuwaFp_3, "Res/テキスト/ゆるふわ会話(救出後).txt", "r");

		fgets(textdata.yuruhuwa_text, 2000, YuruhuwaFp_3);
		fclose(YuruhuwaFp_3);
	}
	else if (areadata.corridor == true && yuruhuwa.clear == true && yuruhuwa.heart == 3)
	{
		FILE* YuruhuwaFp_4;

		fopen_s(&YuruhuwaFp_4, "Res/テキスト/ゆるふわ会話(廊下).txt", "r");

		fgets(textdata.yuruhuwa_text, 2000, YuruhuwaFp_4);
		fclose(YuruhuwaFp_4);
	}
	else if (areadata.corridor == true && yuruhuwa.clear == true)
	{
	    FILE* YuruhuwaFp_4;
	    
	    fopen_s(&YuruhuwaFp_4, "Res/テキスト/ゆるふわ会話(廊下好感度MIN).txt", "r");
	    
	    fgets(textdata.yuruhuwa_text, 2000, YuruhuwaFp_4);
	    fclose(YuruhuwaFp_4);
	}
	else if (areadata.largeroom == true && yuruhuwa.clear == true)
	{
		FILE* YuruhuwaFp_5;

		fopen_s(&YuruhuwaFp_5, "Res/テキスト/ゆるふわ会話(大部屋).txt", "r");

		fgets(textdata.yuruhuwa_text, 2000, YuruhuwaFp_5);
		fclose(YuruhuwaFp_5);
	}
	else if (areadata.largeroom == false && yuruhuwa.clear == true && yuruhuwa.heart == 3)
	{
		FILE* YuruhuwaFp_Clear;

		fopen_s(&YuruhuwaFp_Clear, "Res/テキスト/ゆるふわ会話(クリア好感度MAX).txt", "r");

		fgets(textdata.yuruhuwa_text, 5000, YuruhuwaFp_Clear);
		fclose(YuruhuwaFp_Clear);
	}
	/*else if (areadata.largeroom == false && yuruhuwa.clear == true && yuruhuwa.heart != 3)
	{
	    FILE* YuruhuwaFp_Clear2;
	    
	    fopen_s(&YuruhuwaFp_Clear2, "Res/テキスト/ゆるふわ会話(クリア好感度MIN).txt", "r");
	    
	    fgets(textdata.jk_text, 5000, YuruhuwaFp_Clear2);
	    fclose(YuruhuwaFp_Clear2);
	}*/
#pragma endregion

#pragma region ツンデレ
	if (areadata.searchtunderearea == true && tundere.talktype == 0)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレシステム.txt", "r");
	    
	    fgets(textdata.tundere_text, 1000, TundereFp);
	    fclose(TundereFp);
	    
	    tundere.talktype = 1;
	}
	else if (areadata.searchtunderearea == true && tundere.talktype == 1 && tundere.clear == false)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレ会話(鍵入手前).txt", "r");

		
	    
	    fgets(textdata.tundere_text, 1000, TundereFp);
	    fclose(TundereFp);

	}
	else if (areadata.searchtunderearea == true && tundere.talktype == 1 && tundere.clear == true)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレクリア時システム.txt", "r");
	    
	    fgets(textdata.tundere_text, 2000, TundereFp);
	    fclose(TundereFp);

		if (tundere.clear == true)
		{
			tundere.talktype = 2;

		}

	}
	else if (areadata.searchtunderearea == true && tundere.talktype == 2)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレ会話(救出後).txt", "r");
	    
	    fgets(textdata.tundere_text, 2000, TundereFp);
	    fclose(TundereFp);
	}
	else if (areadata.corridor == true && tundere.clear == true && tundere.heart == 3)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレ会話(廊下好感度MAX).txt", "r");
	    
	    fgets(textdata.tundere_text, 2000, TundereFp);
	    fclose(TundereFp);
	}
	else if (areadata.corridor == true && tundere.clear == true)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレ会話(廊下好感度MIN).txt", "r");
	    
	    fgets(textdata.tundere_text, 2000, TundereFp);
	    fclose(TundereFp);
	}
	else if (areadata.largeroom == true && tundere.clear == true)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレ会話(大部屋).txt", "r");
	    
	    fgets(textdata.tundere_text, 2000, TundereFp);
	    fclose(TundereFp);
	}
	else if (areadata.largeroom == false && tundere.clear == true && tundere.heart == 3)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレ会話(クリア好感度MAX).txt", "r");
	    
	    fgets(textdata.tundere_text, 5000, TundereFp);
	    fclose(TundereFp);
	}
	/*else if (areadata.largeroom == false && tundere.clear == true && tundere.heart != 3)
	{
	    FILE* TundereFp;
	    
	    fopen_s(&TundereFp, "Res/テキスト/ツンデレ会話(クリア好感度MIN).txt", "r");
	    
	    fgets(textdata.jk_text, 5000, TundereFp);
	    fclose(TundereFp);
	}*/
#pragma endregion
}

//テキスト変換(ロボ)
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

//テキスト変換(JK)
void BoyishLoadText()
{

	textdata.boyish_oneline = NULL;
	textdata.boyish_twoline = NULL;
	textdata.boyish_threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	//好感度
	if (choicetexturedata.decision_1 == true)
	{
		textdata.boyish_oneline = strtok(NULL, ",");
		textdata.boyish_twoline = strtok(NULL, ",");
		textdata.boyish_threeline = strtok(NULL, ",");

		textdata.boyiah_lossoneline = strtok(NULL, ",");
		textdata.boyiah_losstwoline = strtok(NULL, ",");
		textdata.boyiah_lossthreeline = strtok(NULL, ",");
		choicetexturedata.decision_1 = false;
		if (tundere.clear == true)
		{
			boyish.heart = 0;
		}
		else if (yuruhuwa.clear == true)
		{
			boyish.heart = 0;
		}
		else
		{
			boyish.heart++;

		}
		



	}
	//好感度
	else if (choicetexturedata.decision_2 == true)
	{
		textdata.boyiah_lossoneline = strtok(NULL, ",");
		textdata.boyiah_losstwoline = strtok(NULL, ",");
		textdata.boyiah_lossthreeline = strtok(NULL, ",");

		textdata.boyish_oneline = strtok(NULL, ",");
		textdata.boyish_twoline = strtok(NULL, ",");
		textdata.boyish_threeline = strtok(NULL, ",");
		choicetexturedata.decision_2 = false;
	}
	else if (textdata.jk_nexttext == true)
	{
  		textdata.boyish_oneline = strtok(NULL, ",");
		textdata.boyish_twoline = strtok(NULL, ",");
		textdata.boyish_threeline = strtok(NULL, ",");
	}
	else
	{
		textdata.boyish_oneline = strtok(textdata.boyish_text, ",");
		textdata.boyish_twoline = strtok(NULL, ",");
		textdata.boyish_threeline = strtok(NULL, ",");
	}

}

void TundereLoadText()
{

	textdata.tundere_oneline = NULL;
	textdata.tundere_twoline = NULL;
	textdata.tundere_threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	//好感度
	if (choicetexturedata.decision_1 == true)
	{
		textdata.tundere_oneline = strtok(NULL, ",");
		textdata.tundere_twoline = strtok(NULL, ",");
		textdata.tundere_threeline = strtok(NULL, ",");

		textdata.tundere_lossoneline = strtok(NULL, ",");
		textdata.tundere_losstwoline = strtok(NULL, ",");
		textdata.tundere_lossthreeline = strtok(NULL, ",");
		choicetexturedata.decision_1 = false;
		
		if (boyish.clear == true)
		{
			tundere.heart = 0;
		}
		else if (yuruhuwa.clear == true)
		{
			tundere.heart = 0;
		}
		else
		{
			tundere.heart++;
		}


	}
	//好感度
	else if (choicetexturedata.decision_2 == true)
	{
		textdata.tundere_lossoneline = strtok(NULL, ",");
		textdata.tundere_losstwoline = strtok(NULL, ",");
		textdata.tundere_lossthreeline = strtok(NULL, ",");

		textdata.tundere_oneline = strtok(NULL, ",");
		textdata.tundere_twoline = strtok(NULL, ",");
		textdata.tundere_threeline = strtok(NULL, ",");
		choicetexturedata.decision_2 = false;
	}
	else if (textdata.jk_nexttext == true)
	{
		textdata.tundere_oneline = strtok(NULL, ",");
		textdata.tundere_twoline = strtok(NULL, ",");
		textdata.tundere_threeline = strtok(NULL, ",");
	}
	else
	{
		textdata.tundere_oneline = strtok(textdata.tundere_text, ",");
		textdata.tundere_twoline = strtok(NULL, ",");
		textdata.tundere_threeline = strtok(NULL, ",");
	}

}

void YuruhuwaLoadText()
{

	textdata.yuruhuwa_oneline = NULL;
	textdata.yuruhuwa_twoline = NULL;
	textdata.yuruhuwa_threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	//好感度
	if (choicetexturedata.decision_1 == true)
	{
		textdata.yuruhuwa_oneline = strtok(NULL, ",");
		textdata.yuruhuwa_twoline = strtok(NULL, ",");
		textdata.yuruhuwa_threeline = strtok(NULL, ",");

		textdata.yuruhuwa_lossoneline = strtok(NULL, ",");
		textdata.yuruhuwa_losstwoline = strtok(NULL, ",");
		textdata.yuruhuwa_lossthreeline = strtok(NULL, ",");
		choicetexturedata.decision_1 = false;
		
		if (boyish.clear == true)
		{
			yuruhuwa.heart = 0;
		}
		else if (tundere.clear == true)
		{
			yuruhuwa.heart = 0;
		}
		else
		{
			yuruhuwa.heart++;
		}
	}
	//好感度
	else if (choicetexturedata.decision_2 == true)
	{
		textdata.yuruhuwa_lossoneline = strtok(NULL, ",");
		textdata.yuruhuwa_losstwoline = strtok(NULL, ",");
		textdata.yuruhuwa_lossthreeline = strtok(NULL, ",");

		textdata.yuruhuwa_oneline = strtok(NULL, ",");
		textdata.yuruhuwa_twoline = strtok(NULL, ",");
		textdata.yuruhuwa_threeline = strtok(NULL, ",");
		choicetexturedata.decision_2 = false;
	}
	else if (textdata.jk_nexttext == true)
	{
		textdata.yuruhuwa_oneline = strtok(NULL, ",");
		textdata.yuruhuwa_twoline = strtok(NULL, ",");
		textdata.yuruhuwa_threeline = strtok(NULL, ",");
	}
	else
	{
		textdata.yuruhuwa_oneline = strtok(textdata.yuruhuwa_text, ",");
		textdata.yuruhuwa_twoline = strtok(NULL, ",");
		textdata.yuruhuwa_threeline = strtok(NULL, ",");
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
	

	if (displaydata.display_cleartext == false && areadata.cleararea == true && boyish.talk == true)
	{
		DrawFont(300.0f, 460.0f, textdata.boyish_oneline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 560.0f, textdata.boyish_twoline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 660.0f, textdata.boyish_threeline, FontSize::Regular, FontColor::White);
	}
	else if (displaydata.display_cleartext == false && areadata.cleararea == true && tundere.talk == true)
	{
		DrawFont(300.0f, 460.0f, textdata.tundere_oneline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 560.0f, textdata.tundere_twoline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 660.0f, textdata.tundere_threeline, FontSize::Regular, FontColor::White);
	}
	else if (displaydata.display_cleartext == false && areadata.cleararea == true && yuruhuwa.talk == true)
	{
		DrawFont(300.0f, 460.0f, textdata.yuruhuwa_oneline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 560.0f, textdata.yuruhuwa_twoline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 660.0f, textdata.yuruhuwa_threeline, FontSize::Regular, FontColor::White);
	}

	else if (boyish.end == true)
	{
		DrawFont(300.0f, 760.0f, textdata.boyish_oneline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 860.0f, textdata.boyish_twoline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 960.0f, textdata.boyish_threeline, FontSize::Regular, FontColor::Yellow);
	}
	else if (tundere.end == true)
	{
		DrawFont(300.0f, 760.0f, textdata.tundere_oneline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 860.0f, textdata.tundere_twoline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 960.0f, textdata.tundere_threeline, FontSize::Regular, FontColor::Yellow);
	}
	else if (yuruhuwa.end == true)
	{
		DrawFont(300.0f, 760.0f, textdata.yuruhuwa_oneline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 860.0f, textdata.yuruhuwa_twoline, FontSize::Regular, FontColor::Yellow);
		DrawFont(300.0f, 960.0f, textdata.yuruhuwa_threeline, FontSize::Regular, FontColor::Yellow);
	}
	
	else if (boyish.talk == true)
	{
		DrawFont(300.0f, 760.0f, textdata.boyish_oneline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 860.0f, textdata.boyish_twoline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 960.0f, textdata.boyish_threeline, FontSize::Regular, FontColor::White);
	}
	else if (tundere.talk == true)
	{
		DrawFont(300.0f, 760.0f, textdata.tundere_oneline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 860.0f, textdata.tundere_twoline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 960.0f, textdata.tundere_threeline, FontSize::Regular, FontColor::White);
	}
	else if (yuruhuwa.talk == true)
	{
		DrawFont(300.0f, 760.0f, textdata.yuruhuwa_oneline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 860.0f, textdata.yuruhuwa_twoline, FontSize::Regular, FontColor::White);
		DrawFont(300.0f, 960.0f, textdata.yuruhuwa_threeline, FontSize::Regular, FontColor::White);
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

		DrawFont(300, 850, "ドアがある。鍵がかかっていて、入ることはできない。", FontSize::Regular, FontColor::White);
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

		DrawFont(300, 850, "ドアがある。鍵がかかっていて、入ることはできない。", FontSize::Regular, FontColor::White);
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

		DrawFont(300, 850, "ドアがある。鍵がかかっていて、入ることはできない。", FontSize::Regular, FontColor::White);
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

//オブジェクト会話関数
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

