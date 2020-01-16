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


void InitLoadFile()
{
	textdata.nexttext = false;
	if (moviebgdate.endmovie == true)
	{
		FILE* DescriptionFp;

		fopen_s(&DescriptionFp, "Res/�e�L�X�g/�������.txt", "r");

		fgets(textdata.text, 1000, DescriptionFp);
		fclose(DescriptionFp);
	}
	else if (areadata.corridor == true)
	{
		FILE* BreakKyeFp;

		fopen_s(&BreakKyeFp, "Res/�e�L�X�g/���g�p��.txt", "r");

		fgets(textdata.text, 1000, BreakKyeFp);
		fclose(BreakKyeFp);
	}
	else if (maidrobot.talktype == 0)
	{
		FILE* MaidTalkFp_0;

		fopen_s(&MaidTalkFp_0, "Res/�e�L�X�g/���C�h��b(������).txt", "r");

		fgets(textdata.text, 1000, MaidTalkFp_0);
		fclose(MaidTalkFp_0);
	}
	else if (maidrobot.talktype == 1)
	{
		FILE* MaidTalkFp_1;

		fopen_s(&MaidTalkFp_1, "Res/�e�L�X�g/���C�h��b(�p�^�[��1).txt", "r");

		fgets(textdata.text, 1000, MaidTalkFp_1);
		fclose(MaidTalkFp_1);
	}
	else if (maidrobot.talktype == 2)
	{
		FILE* MaidTalkFp_2;

		fopen_s(&MaidTalkFp_2, "Res/�e�L�X�g/���C�h��b(�p�^�[��2).txt", "r");

		fgets(textdata.text, 1000, MaidTalkFp_2);
		fclose(MaidTalkFp_2);
	}
	else if (maidrobot.talktype == 3)
	{
		FILE* MaidTalkFp_3;

		fopen_s(&MaidTalkFp_3, "Res/�e�L�X�g/���C�h��b(�p�^�[��3).txt", "r");

		fgets(textdata.text, 1000, MaidTalkFp_3);
		fclose(MaidTalkFp_3);
	}
	else if (maidrobot.talktype == 4)
	{
		FILE* MaidTalkFp_4;

		fopen_s(&MaidTalkFp_4, "Res/�e�L�X�g/���C�h��b(�p�^�[��4).txt", "r");

		fgets(textdata.text, 1000, MaidTalkFp_4);
		fclose(MaidTalkFp_4);
	}
	else if (maidrobot.talktype == 5)
	{
		FILE* MaidTalkFp_5;

		fopen_s(&MaidTalkFp_5, "Res/�e�L�X�g/���C�h��b(�p�^�[��5).txt", "r");

		fgets(textdata.text, 1000, MaidTalkFp_5);
		fclose(MaidTalkFp_5);
	}
	else if (maidrobot.talktype == 6)
	{
		FILE* MaidTalkFp_6;

		fopen_s(&MaidTalkFp_6, "Res/�e�L�X�g/���C�h��b(�p�^�[��6).txt", "r");

		fgets(textdata.text, 1000, MaidTalkFp_6);
		fclose(MaidTalkFp_6);
	}
	else if (areadata.searchyuruhuwaarea == true)
	{
		FILE* fp;

		fopen_s(&fp, "Res/�e�L�X�g/���ӂ�V�X�e��.txt", "r");

		fgets(textdata.text, 1000, fp);
		fclose(fp);
	}


}

void LoadText()
{

	textdata.oneline = NULL;
	textdata.twoline = NULL;
	textdata.threeline = NULL;

	//memset(&textdata.oneline, '\0', 256);
	//memset(&textdata.twoline, '\0', 256);
	//memset(&textdata.threeline, '\0', 256);

	if (choicetexturedata.decision == true)
	{
		textdata.oneline = strtok(textdata.text, ",");
		
	}
	else if (textdata.nexttext == true)
	{
		textdata.oneline = strtok(NULL, ",");
	}
	else
	{
		textdata.oneline = strtok(textdata.text, ",");
	}

	textdata.twoline = strtok(NULL, ",");
	textdata.threeline = strtok(NULL, ",");
}

void DrawTalkText()
{
	DrawFont(300.0f, 760.0f, textdata.oneline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 860.0f, textdata.twoline, FontSize::Regular, FontColor::White);
	DrawFont(300.0f, 960.0f, textdata.threeline, FontSize::Regular, FontColor::White);
}

void DrawDescription()
{

	if (maidrobot.description == false && moviebgdate.endmovie == true)
	{
		maidrobot.description = true;
		textbox.onspacekey = true;
	}
	else if (textdata.threeline == NULL && maidrobot.description == true && moviebgdate.endmovie == false || choicetexturedata.decision == true)
	{
		maidrobot.description = false;
		textbox.onspacekey = false;
		
	}
	if (maidrobot.description == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawTalkText();
		if (strstr(textdata.oneline, "�͂�"))
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
		&& getitem.boyishdoorkey == true && choicetexturedata.decision == true)
	{
		corridorobject.doortalk = false;
		corridorobject.boyishdoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;


	}
	//�͂���I�������Ƃ�
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.boyishdoor == true && corridorobject.doortalk == true
		&& getitem.boyishdoorkey == true && textdata.threeline == NULL)
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
		textdata.nexttext = false;

	}

	if (corridorobject.boyishdoor == true && corridorobject.doortalk == true && getitem.boyishdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.boyishdoor == true && corridorobject.doortalk == true && getitem.boyishdoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawTalkText();
		if (strstr(textdata.oneline,"�͂�"))
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
		&& getitem.tunderedoorkey == true && choicetexturedata.decision == true)
	{
		corridorobject.doortalk = false;
		corridorobject.tunderedoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;

	}
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.tunderedoor == true && corridorobject.doortalk == true
		&& getitem.tunderedoorkey == true && textdata.threeline == NULL)
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
		textdata.nexttext = false;

	}
	if (corridorobject.tunderedoor == true && corridorobject.doortalk == true && getitem.tunderedoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.tunderedoor == true && corridorobject.doortalk == true && getitem.tunderedoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawTalkText();
		if (strstr(textdata.oneline, "�͂�"))
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
		&& getitem.yuruhuwadoorkey == true && choicetexturedata.decision == true)
	{
		corridorobject.doortalk = false;
		corridorobject.yuruhuwadoor = false;
		textbox.onspacekey = false;
		choicetexturedata.Choicepos = 1;


	}
	//�͂���I�������Ƃ�
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true
		&& getitem.yuruhuwadoorkey == true && textdata.threeline == NULL)
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
		textdata.nexttext = false;

	}
	if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true && getitem.yuruhuwadoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "�h�A������B�����������Ă��āA���邱�Ƃ͂ł��Ȃ��B", FontSize::Regular, FontColor::White);
	}
	else if (corridorobject.yuruhuwadoor == true && corridorobject.doortalk == true && getitem.yuruhuwadoorkey == true && getitem.breakdoorkey == false)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawTalkText();
		if (strstr(textdata.oneline, "�͂�"))
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
		if (choicetexturedata.decision == true)
		{
			InitLoadFile();
		}
		if (choicetexturedata.decision == true)
		{
			choicetexturedata.decision = false;
		}
		else if ((corridorobject.doortalk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision = true;
		}
		LoadText();
		textdata.nexttext = true;

	}
}

