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
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, text, FontSize::Regular, FontColor::White);
	}
}


void InitRobotLoadFile()
{
	textdata.robot_nexttext = false;
#pragma region ���C�h��b
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
	else if (areadata.largeroom == true && maidrobot.talktype == 0)
	{
		FILE* MaidTalkFp_0;

		fopen_s(&MaidTalkFp_0, "Res/�e�L�X�g/���C�h��b(������).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_0);
		fclose(MaidTalkFp_0);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 1)
	{
		FILE* MaidTalkFp_1;

		fopen_s(&MaidTalkFp_1, "Res/�e�L�X�g/���C�h��b(�p�^�[��1).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_1);
		fclose(MaidTalkFp_1);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 2)
	{
		FILE* MaidTalkFp_2;

		fopen_s(&MaidTalkFp_2, "Res/�e�L�X�g/���C�h��b(�p�^�[��2).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_2);
		fclose(MaidTalkFp_2);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 3)
	{
		FILE* MaidTalkFp_3;

		fopen_s(&MaidTalkFp_3, "Res/�e�L�X�g/���C�h��b(�p�^�[��3).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_3);
		fclose(MaidTalkFp_3);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 4)
	{
		FILE* MaidTalkFp_4;

		fopen_s(&MaidTalkFp_4, "Res/�e�L�X�g/���C�h��b(�p�^�[��4).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_4);
		fclose(MaidTalkFp_4);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 5)
	{
		FILE* MaidTalkFp_5;

		fopen_s(&MaidTalkFp_5, "Res/�e�L�X�g/���C�h��b(�p�^�[��5).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_5);
		fclose(MaidTalkFp_5);
	}
	else if (areadata.largeroom == true && maidrobot.talktype == 6)
	{
		FILE* MaidTalkFp_6;

		fopen_s(&MaidTalkFp_6, "Res/�e�L�X�g/���C�h��b(�p�^�[��6).txt", "r");

		fgets(textdata.robot_text, 1000, MaidTalkFp_6);
		fclose(MaidTalkFp_6);
	}
#pragma endregion
	if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 0)
	{
		FILE* SearchGameRobotFp;

		fopen_s(&SearchGameRobotFp, "Res/�e�L�X�g/�{�[�C�b�V�������V�X�e��.txt", "r");

		fgets(textdata.robot_text, 1000, SearchGameRobotFp);
		fclose(SearchGameRobotFp);
	}
	else if (areadata.searchgamearea == true && areadata.corridor == false && searchgamerobot.talktype == 1)
	{
	    FILE* SearchGameRobotFp_1;
	    
	    fopen_s(&SearchGameRobotFp_1, "Res/�e�L�X�g/�{�[�C�b�V�������N���A���V�X�e��.txt", "r");
	    
	    fgets(textdata.robot_text, 1000, SearchGameRobotFp_1);
	    fclose(SearchGameRobotFp_1);
	}
	


}

void InitJKLoadFile()
{
	if (areadata.searchgamearea == true && boyish.talktype == 0)
	{
		FILE* BoyishFp;

		fopen_s(&BoyishFp, "Res/�e�L�X�g/�{�[�C�b�V���V�X�e��.txt", "r");

		fgets(textdata.jk_text, 1000, BoyishFp);
		fclose(BoyishFp);
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
	}
	else if (areadata.searchyuruhuwaarea == true)
	{
		FILE* fp;

		fopen_s(&fp, "Res/�e�L�X�g/���ӂ�V�X�e��.txt", "r");

		fgets(textdata.jk_text, 1000, fp);
		fclose(fp);
	}
}

void RobotLoadText()
{

	textdata.robot_oneline = NULL;
	textdata.robot_twoline = NULL;
	textdata.robot_threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	if (choicetexturedata.decision_1 == true)
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
	DrawFont(300.0f, 760.0f, textdata.jk_oneline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 860.0f, textdata.jk_twoline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 960.0f, textdata.jk_threeline, FontSize::Regular, FontColor::White);
}

void DrawDescription()
{

	if (maidrobot.description == false && moviebgdate.endmovie == true)
	{
		maidrobot.description = true;
		textbox.onspacekey = true;
	}
	else if (textdata.robot_threeline == NULL && maidrobot.description == true && moviebgdate.endmovie == false || choicetexturedata.decision_2 == true)
	{
		maidrobot.description = false;
		textbox.onspacekey = false;
		
	}
	if (maidrobot.description == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawRobotTalkText();
		if (strstr(textdata.robot_oneline, "�͂�"))
		{
			DrawChoiceTexture();
			
		}
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
	}
	//��������I�������Ƃ�
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.boyishdoor == true && corridorobject.doortalk == true
		&& getitem.boyishdoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;
		textbox.onspacekey = false;
		//choicetexturedata.Choicepos = 1;

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
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == true && getitem.boyishdoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
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
	}
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.tunderedoor == true && corridorobject.doortalk == true
		&& getitem.tunderedoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.tunderedoor = false;
		textbox.onspacekey = false;
		//choicetexturedata.Choicepos = 1;

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
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.tunderedoor == true && corridorobject.doortalk == true && getitem.tunderedoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
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
	}
	//��������I�������Ƃ�
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true
		&& getitem.yuruhuwadoorkey == true && choicetexturedata.decision_2 == true)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;
		textbox.onspacekey = false;
		//choicetexturedata.Choicepos = 1;


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
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true && getitem.yuruhuwadoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
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
	if (GetKeyDown(SPACE_KEY) == true)
	{
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

