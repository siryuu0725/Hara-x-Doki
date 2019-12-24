#include "Mystery.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "Hit.h"

MysteryText mysterytext;

void InitMysteryText()
{
	mysterytext.textcount = 1;
	mysterytext.textpos_x = 500.0f;
	mysterytext.textpos_y = 500.0f;
	mysterytext.textheight = 70.0f;
	mysterytext.textwidth = 70.0f;

	mysterytext.textboxheight = 840.0f;
	mysterytext.textboxwidth = 350.0f;

	mysterytext.problemtextpos_x = 800.0f;
	mysterytext.problemtextpos_y = 300.0f;

	mysterytext.decisiontext = false;
	mysterytext.correctanswer = false;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			mysterytext.text[i][j] = mysterytext.textcount;
			mysterytext.textcount++;
		}
	}
}

void DrawMysteryBg()
{
	DrawTexture(mysterytext.textpos_x, mysterytext.textpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgMax));
	DrawTexture(mysterytext.problemtextpos_x, mysterytext.problemtextpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextMax));
	if (mysterytext.correctanswer == true)
	{
		DrawTexture(mysterytext.problemtextpos_x + 70, mysterytext.problemtextpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextMax));
	}
}

void DrawMysteryChoiceText()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (HitChoise(mysterytext.textpos_x + 70 * j, mysterytext.textpos_y + 70 * i, mysterytext.textwidth, mysterytext.textheight) == true)
			{
				DrawTexture(mysterytext.textpos_x + 70 * j, mysterytext.textpos_y + 70 * i, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextMax));
			}

		}
	}
}

void UpDataChoiceText()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (HitChoise(mysterytext.textpos_x + 70 * j, mysterytext.textpos_y + 70 * i, mysterytext.textwidth, mysterytext.textheight) == true
				&& OnMouseDown(Left) == true)
			{
				mysterytext.decisiontext = true;
				if (i == 3 && j == 3)
				{
					mysterytext.correctanswer = true;
				}
			}

		}
	}
}