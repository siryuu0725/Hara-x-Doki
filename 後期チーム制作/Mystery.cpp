#include "Mystery.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "Hit.h"

MysteryText mysterytext;
DecisionButton decisionbutton;
ProblemData problemdata;

void InitMysteryText()
{
	mysterytext.textcount = 1;
	mysterytext.textpos_x = 500.0f;
	mysterytext.textpos_y = 500.0f;
	mysterytext.textheight = 69.0f;
	mysterytext.textwidth = 69.0f;

	mysterytext.textboxheight = 840.0f;
	mysterytext.textboxwidth = 350.0f;

	mysterytext.problemtextpos_x = 800.0f;
	mysterytext.problemtextpos_y = 300.0f;

	mysterytext.decisiontext = false;
	mysterytext.correctanswer = false;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			mysterytext.text[i][j] = mysterytext.textcount;
			mysterytext.textcount++;
		}
	}
}

void InitDecisionButton()
{
	decisionbutton.pos_x = 1200.0f;
	decisionbutton.pos_y = 300.0f;

	decisionbutton.width = 210.0f;
	decisionbutton.height = 70.0f;

	decisionbutton.push = false;
}


void DrawMysteryBg()
{
	DrawBgTexture(GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgTex));
	DrawTexture(mysterytext.textpos_x, mysterytext.textpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextBoxTex));
	DrawTexture(mysterytext.problemtextpos_x, mysterytext.problemtextpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex));
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if (HitChoise(mysterytext.textpos_x + 70 * j, mysterytext.textpos_y + 70 * i, mysterytext.textwidth, mysterytext.textheight) == true)
			{
				DrawTexture(mysterytext.textpos_x + 5.0f + 70 * j, mysterytext.textpos_y + 5.0f + 70 * i, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextTex));
			}
			if (mysterytext.correctanswer == true)
			{
				DrawUVTexture(mysterytext.problemtextpos_x + 70, mysterytext.problemtextpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.text_tu, mysterytext.text_tv);
			}

		}
	}

	DrawTexture(mysterytext.textpos_x, mysterytext.textpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex));
	

	DrawTexture(decisionbutton.pos_x, decisionbutton.pos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDecisionButtonTex));

	


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
			
				mysterytext.correctanswer = true;
				mysterytext.text_tu = 0.09f * j;

				mysterytext.text_tv = 0.195f * i;
			}
			

		}
	}
}