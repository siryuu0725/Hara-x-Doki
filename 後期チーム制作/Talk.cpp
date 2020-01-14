#include "Talk.h"
#include "Text.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Robot.h"
#include "Bg.h"
#include <cstdio>
#include "Item.h"

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

		fopen_s(&DescriptionFp, "Res/テキスト/操作説明.txt", "r");

		fgets(textdata.text, 1000, DescriptionFp);
		fclose(DescriptionFp);
	}
	else if (areadata.corridor == true && getitem.breakdoorkey == true)
	{
		FILE* BreakKyeFp;

		fopen_s(&BreakKyeFp, "Res/テキスト/鍵使用時.txt", "r");

		fgets(textdata.text, 1000, BreakKyeFp);
		fclose(BreakKyeFp);
	}
	else if (areadata.searchyuruhuwaarea == true)
	{
		FILE* fp;

		fopen_s(&fp, "Res/テキスト/ゆるふわシステム.txt", "r");

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

	if (textdata.nexttext == true)
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
		if (displaydata.choicescenecounter == 1)
		{
			DrawChoiceTexture();
			displaydata.choicescenecounter = 0;
		}
	}

}

void DrawDoorTalk()
{
	if (corridorobject.door == true && corridorobject.doortalk == false)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;

	}
	else if (GetKeyDown(SPACE_KEY) == true && corridorobject.doortalk == true)
	{
		corridorobject.doortalk = false;
		corridorobject.door = false;
		textbox.onspacekey = false;

	}
	if (corridorobject.doortalk == true)
	{
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));

		DrawFont(500, 850, "ドアがある。鍵がかかっていて、入ることはできない。", FontSize::Regular, FontColor::White);
	}
}

void UpDataDoorText()
{
	if (GetKeyDown(SPACE_KEY) == true)
	{
		if ((corridorobject.doortalk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision = true;
		}
		LoadText();
		textdata.nexttext = true;
		displaydata.choicescenecounter++;
	}
}

void DrawDoorTalk2()
{

	if (corridorobject.doortalk == false && getitem.breakdoorkey == true)
	{
		corridorobject.doortalk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.threeline == NULL && corridorobject.doortalk == true || choicetexturedata.decision == true)
	{
		corridorobject.doortalk = false;
		textbox.onspacekey = false;
	}
	if (corridorobject.doortalk == true)
	{
		DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTalkMaidTex));
		DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
		DrawTalkText();
		if (displaydata.choicescenecounter == 4)
		{
			DrawChoiceTexture();
			displaydata.choicescenecounter = 0;
		}
	}

}