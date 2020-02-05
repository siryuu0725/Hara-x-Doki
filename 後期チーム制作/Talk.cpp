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



//�t�@�C���ǂݍ��݊֐�(���{)
void InitRobotLoadFile()
{
	textdata.robot_nexttext = false;

	if (moviebgdate.endmovie == true)
	{
		FILE* DescriptionFp;

		fopen_s(&DescriptionFp, "Res/�e�L�X�g/�������.txt", "r");

		fgets(textdata.robot_text, 1000, DescriptionFp);
		fclose(DescriptionFp);
	}
	else if (areadata.corridor == true)
	{
		FILE* BreakKyeFp;

		fopen_s(&BreakKyeFp, "Res/�e�L�X�g/���g�p��.txt", "r");

		fgets(textdata.robot_text, 1000, BreakKyeFp);
		fclose(BreakKyeFp);
	}
#pragma region ���C�h��b
	else if (areadata.largeroom == true && maidrobot.talktype == 0)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/�e�L�X�g/���C�h��b(������).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 1)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/�e�L�X�g/���C�h��b(�p�^�[��1).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 2)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/�e�L�X�g/���C�h��b(�p�^�[��2).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 3)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/�e�L�X�g/���C�h��b(�p�^�[��3).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 4)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/�e�L�X�g/���C�h��b(�p�^�[��4).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 5)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/�e�L�X�g/���C�h��b(�p�^�[��5).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 6)
	{
		FILE* MaidTalkFp;

		fopen_s(&MaidTalkFp, "Res/�e�L�X�g/���C�h��b(�p�^�[��6).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp);
		fclose(MaidTalkFp);
	}
#pragma endregion

#pragma region �{�[�C�b�V��������b
	if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 0)
	{
		FILE* SearchGameRobotFp;

		fopen_s(&SearchGameRobotFp, "Res/�e�L�X�g/�{�[�C�b�V�������V�X�e��.txt", "r");

		fgets(textdata.robot_text, 1000, SearchGameRobotFp);
		fclose(SearchGameRobotFp);
	}
	else if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 1)
	{
	    FILE* SearchGameRobotFp;
	    
	    fopen_s(&SearchGameRobotFp, "Res/�e�L�X�g/�{�[�C�b�V�������N���A���V�X�e��.txt", "r");
	    
	    fgets(textdata.robot_text, 1000, SearchGameRobotFp);
	    fclose(SearchGameRobotFp);
		searchgamerobot.talktype = 2;
	}
	else if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 2)
	{
		FILE* SearchGameRobotFp;

		fopen_s(&SearchGameRobotFp, "Res/�e�L�X�g/�{�[�C�b�V��������b.txt", "r");

		fgets(textdata.robot_text, 1000, SearchGameRobotFp);
		fclose(SearchGameRobotFp);
	}
#pragma endregion

#pragma region ���ӂ펷����b
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 0)
	{
		FILE* PuzzleGameRobotFp;

		fopen_s(&PuzzleGameRobotFp, "Res/�e�L�X�g/���ӂ펷���V�X�e��.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp);
		fclose(PuzzleGameRobotFp);
		
	}
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 1)
	{
		FILE* PuzzleGameRobotFp;

		fopen_s(&PuzzleGameRobotFp, "Res/�e�L�X�g/���ӂ펷���N���A���V�X�e��.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp);
		fclose(PuzzleGameRobotFp);
		puzzlegamerobot.talktype = 2;
	}
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && puzzlegamerobot.talktype == 2)
	{
		FILE* PuzzleGameRobotFp;

		fopen_s(&PuzzleGameRobotFp, "Res/�e�L�X�g/���ӂ펷����b.txt", "r");

		fgets(textdata.robot_text, 1000, PuzzleGameRobotFp);
		fclose(PuzzleGameRobotFp);
	}
#pragma endregion

#pragma region �c���f��������b
	else if (areadata.searchtunderearea == true && areadata.corridor == false && mysterygamerobot.talktype == 0)
	{
		FILE* MysteryGameRobotFp;

		fopen_s(&MysteryGameRobotFp, "Res/�e�L�X�g/�c���f�������V�X�e��.txt", "r");

		fgets(textdata.robot_text, 1000, MysteryGameRobotFp);
		fclose(MysteryGameRobotFp);

	}
	else if (areadata.searchyuruhuwaarea == true && areadata.corridor == false && mysterygamerobot.talktype == 1)
	{
		FILE* MysteryGameRobotFp;

		fopen_s(&MysteryGameRobotFp, "Res/�e�L�X�g/�c���f�������N���A���V�X�e��.txt", "r");

		fgets(textdata.robot_text, 1000, MysteryGameRobotFp);
		fclose(MysteryGameRobotFp);
		puzzlegamerobot.talktype = 2;
	}
	else if (areadata.searchtunderearea == true && areadata.corridor == false && mysterygamerobot.talktype == 2)
	{
		FILE* MysteryGameRobotFp;

		fopen_s(&MysteryGameRobotFp, "Res/�e�L�X�g/���ӂ펷����b.txt", "r");

		fgets(textdata.robot_text, 1000, MysteryGameRobotFp);
		fclose(MysteryGameRobotFp);
	}
#pragma endregion
}

//�t�@�C���ǂݍ��݊֐�(JK)
void InitJKLoadFile()
{
#pragma region �{�[�C�b�V��
	if (areadata.searchgamearea == true && boyish.talktype == 0)
	{
		FILE* BoyishFp;

		fopen_s(&BoyishFp, "Res/�e�L�X�g/�{�[�C�b�V���V�X�e��.txt", "r");

		fgets(textdata.jk_text, 1000, BoyishFp);
		fclose(BoyishFp);
		boyish.talktype = 1;
	}
	else if (areadata.searchgamearea == true && boyish.talktype == 1 && searchgameobject.completerobot == false)
	{
		FILE* BoyishFp_1;

		fopen_s(&BoyishFp_1, "Res/�e�L�X�g/�{�[�C�b�V����b(��������).txt", "r");

		fgets(textdata.jk_text, 1000, BoyishFp_1);
		fclose(BoyishFp_1);

	}
	else if (areadata.searchgamearea == true && boyish.talktype == 1 && searchgameobject.completerobot == true)
	{
		FILE* BoyishFp_2;

		fopen_s(&BoyishFp_2, "Res/�e�L�X�g/�{�[�C�b�V���N���A���V�X�e��.txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_2);
		fclose(BoyishFp_2);
		boyish.talktype = 2;
	}
	else if (areadata.searchgamearea == true && boyish.talktype == 2)
	{
		FILE* BoyishFp_3;

		fopen_s(&BoyishFp_3, "Res/�e�L�X�g/�{�[�C�b�V����b(�~�o��).txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_3);
		fclose(BoyishFp_3);
	}
	else if (areadata.corridor == true && boyish.clear == true && boyish.heart == 3)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/�e�L�X�g/�{�[�C�b�V����b(�L��).txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.corridor == true && boyish.clear == true)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/�e�L�X�g/�{�[�C�b�V����b(�L���D���xMIN).txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.largeroom == true && boyish.clear == true)
	{
		FILE* BoyishFp_4;

		fopen_s(&BoyishFp_4, "Res/�e�L�X�g/�{�[�C�b�V����b(�啔��).txt", "r");

		fgets(textdata.jk_text, 2000, BoyishFp_4);
		fclose(BoyishFp_4);
	}
	else if (areadata.largeroom == false && boyish.clear == true && boyish.heart == 3)
	{
		FILE* BoyishFp_Clear;

		fopen_s(&BoyishFp_Clear, "Res/�e�L�X�g/�{�[�C�b�V����b(�N���A).txt", "r");

		fgets(textdata.jk_text, 5000, BoyishFp_Clear);
		fclose(BoyishFp_Clear);
	}
	else if (areadata.largeroom == false && boyish.clear == true && boyish.heart != 3 && areadata.cleararea == true)
	{
		FILE* BoyishFp_Clear2;

		fopen_s(&BoyishFp_Clear2, "Res/�e�L�X�g/�{�[�C�b�V����b(�N���A�D���xMIN).txt", "r");

		fgets(textdata.jk_text, 5000, BoyishFp_Clear2);
		fclose(BoyishFp_Clear2);
	}
#pragma endregion

#pragma region ���ӂ�
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 0)
	{
		FILE* YuruhuwaFp;

		fopen_s(&YuruhuwaFp, "Res/�e�L�X�g/���ӂ�V�X�e��.txt", "r");

		fgets(textdata.jk_text, 1000, YuruhuwaFp);
		fclose(YuruhuwaFp);

		yuruhuwa.talktype = 1;
	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 1 && yuruhuwa.clear == false)
	{
		FILE* YuruhuwaFp_1;

		fopen_s(&YuruhuwaFp_1, "Res/�e�L�X�g/���ӂ��b(������O).txt", "r");

		fgets(textdata.jk_text, 1000, YuruhuwaFp_1);
		fclose(YuruhuwaFp_1);

	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 1 && yuruhuwa.clear == true)
	{
		FILE* YuruhuwaFp_2;

		fopen_s(&YuruhuwaFp_2, "Res/�e�L�X�g/���ӂ�N���A���V�X�e��.txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_2);
		fclose(YuruhuwaFp_2);
		
	}
	else if (areadata.searchyuruhuwaarea == true && yuruhuwa.talktype == 2)
	{
		FILE* YuruhuwaFp_3;

		fopen_s(&YuruhuwaFp_3, "Res/�e�L�X�g/���ӂ��b(�~�o��).txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_3);
		fclose(YuruhuwaFp_3);
	}
	else if (areadata.corridor == true && yuruhuwa.clear == true && yuruhuwa.heart == 3)
	{
		FILE* YuruhuwaFp_4;

		fopen_s(&YuruhuwaFp_4, "Res/�e�L�X�g/���ӂ��b(�L��).txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_4);
		fclose(YuruhuwaFp_4);
	}
	else if (areadata.corridor == true && yuruhuwa.clear == true)
	{
	    FILE* YuruhuwaFp_4;
	    
	    fopen_s(&YuruhuwaFp_4, "Res/�e�L�X�g/���ӂ��b(�L���D���xMIN).txt", "r");
	    
	    fgets(textdata.jk_text, 2000, YuruhuwaFp_4);
	    fclose(YuruhuwaFp_4);
	}
	else if (areadata.largeroom == true && yuruhuwa.clear == true)
	{
		FILE* YuruhuwaFp_5;

		fopen_s(&YuruhuwaFp_5, "Res/�e�L�X�g/���ӂ��b(�啔��).txt", "r");

		fgets(textdata.jk_text, 2000, YuruhuwaFp_5);
		fclose(YuruhuwaFp_5);
	}
	else if (areadata.largeroom == false && yuruhuwa.clear == true && yuruhuwa.heart == 3)
	{
		FILE* YuruhuwaFp_Clear;

		fopen_s(&YuruhuwaFp_Clear, "Res/�e�L�X�g/���ӂ��b(�N���A�D���xMAX).txt", "r");

		fgets(textdata.jk_text, 5000, YuruhuwaFp_Clear);
		fclose(YuruhuwaFp_Clear);
	}
	else if (areadata.largeroom == false && yuruhuwa.clear == true && yuruhuwa.heart != 3)
	{
	    FILE* YuruhuwaFp_Clear2;
	    
	    fopen_s(&YuruhuwaFp_Clear2, "Res/�e�L�X�g/���ӂ��b(�N���A�D���xMIN).txt", "r");
	    
	    fgets(textdata.jk_text, 5000, YuruhuwaFp_Clear2);
	    fclose(YuruhuwaFp_Clear2);
	}
#pragma endregion

#pragma region �c���f��
	else if (areadata.searchtunderearea == true && tundere.talktype == 0)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f���V�X�e��.txt", "r");

	fgets(textdata.jk_text, 1000, TundereFp);
	fclose(TundereFp);

	tundere.talktype = 1;
	}
	else if (areadata.searchyuruhuwaarea == true && tundere.talktype == 1 && tundere.clear == false)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f����b(������O).txt", "r");

	fgets(textdata.jk_text, 1000, TundereFp);
	fclose(TundereFp);

	}
	else if (areadata.searchtunderearea == true && tundere.talktype == 1 && tundere.clear == true)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f���N���A���V�X�e��.txt", "r");

	fgets(textdata.jk_text, 2000, TundereFp);
	fclose(TundereFp);

	}
	else if (areadata.searchtunderearea == true && tundere.talktype == 2)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f����b(�~�o��).txt", "r");

	fgets(textdata.jk_text, 2000, TundereFp);
	fclose(TundereFp);
	}
	else if (areadata.corridor == true && tundere.clear == true && tundere.heart == 3)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f����b(�L���D���xMAX).txt", "r");

	fgets(textdata.jk_text, 2000, TundereFp);
	fclose(TundereFp);
	}
	else if (areadata.corridor == true && tundere.clear == true)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f����b(�L���D���xMIN).txt", "r");

	fgets(textdata.jk_text, 2000, TundereFp);
	fclose(TundereFp);
	}
	else if (areadata.largeroom == true && tundere.clear == true)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f����b(�啔��).txt", "r");

	fgets(textdata.jk_text, 2000, TundereFp);
	fclose(TundereFp);
	}
	else if (areadata.largeroom == false && tundere.clear == true && tundere.heart == 3)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f����b(�N���A�D���xMAX).txt", "r");

	fgets(textdata.jk_text, 5000, TundereFp);
	fclose(TundereFp);
	}
	else if (areadata.largeroom == false && tundere.clear == true && tundere.heart != 3)
	{
	FILE* TundereFp;

	fopen_s(&TundereFp, "Res/�e�L�X�g/�c���f����b(�N���A�D���xMIN).txt", "r");

	fgets(textdata.jk_text, 5000, TundereFp);
	fclose(TundereFp);
	}
#pragma endregion
}

//�e�L�X�g�ϊ�(���{)
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

//�e�L�X�g�ϊ�(JK)
void JKLoadText()
{

	textdata.jk_oneline = NULL;
	textdata.jk_twoline = NULL;
	textdata.jk_threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	//�D���x
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
	//�D���x
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
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline, "�͂�"))
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
#pragma region �{�[�C�b�V������b
	//�ŏ��̌������Ă��Ȃ���
	if (corridorobject.boyishdoor == true && corridorobject.doortalk == false  && getitem.breakdoorkey == false)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//���������Ă��Ȃ���Ԃōŏ��̌������Ă���Ƃ�
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == false && getitem.boyishdoorkey == false && getitem.breakdoorkey == true)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//�ŏ��̂̌����g�����㓯�������Ŏg���Ƃ�
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == false && getitem.boyishdoorkey == true)
	{
		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;
		textbox.onspacekey = false;
		displaydata.displaynext = true;
		areadata.searchgamearea = true;
		boyish.areachange = true;

	}
	//��������I�������Ƃ�
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.boyishdoor == true && corridorobject.doortalk == true
		&& getitem.boyishdoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;


	}
	//�͂���I�������Ƃ�
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
	//���̔��ł���������I�������Ƃ�
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

		DrawFont(300, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == true && getitem.boyishdoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline,"�͂�"))
		{
			DrawChoiceTexture();
		}
		
	}
#pragma endregion

#pragma region �c���f������b
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

		DrawFont(300, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.tunderedoor == true && corridorobject.doortalk == true && getitem.tunderedoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline, "�͂�"))
		{
			DrawChoiceTexture();
		}
		
	}
#pragma endregion

#pragma region ���ӂ����b
	//�ŏ��̌������Ă��Ȃ���
	if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == false && getitem.breakdoorkey == false)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//���������Ă��Ȃ���Ԃōŏ��̌������Ă���Ƃ�
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == false && getitem.yuruhuwadoorkey == false && getitem.breakdoorkey == true)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	//�ŏ��̂̌����g�����㓯�������Ŏg���Ƃ�
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == false && getitem.yuruhuwadoorkey == true)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;
		textbox.onspacekey = false;
		displaydata.displaynext = true;

		yuruhuwa.areachange = true;
		areadata.searchyuruhuwaarea = true;
	}
	//��������I�������Ƃ�
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true
		&& getitem.yuruhuwadoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;


	}
	//�͂���I�������Ƃ�
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
	//���̔��ł���������I�������Ƃ�
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

		DrawFont(300, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true && getitem.yuruhuwadoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline, "�͂�"))
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

//�I�u�W�F�N�g��b�֐�
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

