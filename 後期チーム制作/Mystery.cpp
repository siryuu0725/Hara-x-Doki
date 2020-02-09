#include "Mystery.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "Hit.h"

MysteryText mysterytext;
Button button;
ProblemData problemdata;

void InitMysteryText()
{
	mysterytext.textcount = 1;
	mysterytext.textpos_x = 600.0f;
	mysterytext.textpos_y = 650.0f;
	mysterytext.textheight = 69.0f;
	mysterytext.textwidth = 69.0f;

	mysterytext.textboxheight = 840.0f;
	mysterytext.textboxwidth = 350.0f;

	mysterytext.problemtextpos_x = 200.0f;
	mysterytext.problemtextpos_y = 100.0f;

	mysterytext.problemanswer_x = 705.0f;
	mysterytext.problemanswer_y = 450.0f;

	mysterytext.decisiontext = false;
	mysterytext.correctanswer = false;

	mysterytext.oneproblem = false;
	mysterytext.twoproblem = false;


	mysterytext.nexttext = 0;


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			mysterytext.text[i][j] = mysterytext.textcount;
			mysterytext.textcount++;
		}
	}
}

void InitButton()
{
	button.decisionpos_x = 1500.0f;
	button.decisionpos_y = 500.0f;

	button.decisionwidth = 210.0f;
	button.decisionheight = 70.0f;

	button.deletepos_x = 1500.0f;
	button.deletepos_y = 200.0f;

	button.deletewidth = 210.0f;
	button.deleteheight = 70.0f;

	button.push = false;
}


void DrawMysteryBg()
{
	DrawBgTexture(GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgTex));
	DrawTexture(mysterytext.textpos_x, mysterytext.textpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextBoxTex));

	if (mysterytext.oneproblem == false && mysterytext.twoproblem == false)
	{
		DrawTexture(mysterytext.problemtextpos_x, mysterytext.problemtextpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex_1));
		DrawTexture(mysterytext.problemanswer_x, mysterytext.problemanswer_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblem_Answer_1));

	}
	else if (mysterytext.oneproblem == true && mysterytext.twoproblem == false)
	{
		DrawTexture(mysterytext.problemtextpos_x, mysterytext.problemtextpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex_2));
		DrawTexture(mysterytext.problemanswer_x, mysterytext.problemanswer_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblem_Answer_2));

	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if (HitChoise(mysterytext.textpos_x + 70 * j, mysterytext.textpos_y + 70 * i, mysterytext.textwidth, mysterytext.textheight) == true)
			{
				DrawTexture(mysterytext.textpos_x + 5.0f + 70 * j, mysterytext.textpos_y + 5.0f + 70 * i, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameChoiceTextTex));
			}
			if (mysterytext.correctanswer == true && mysterytext.nexttext >= 1)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 65.0f, mysterytext.problemanswer_y + 25.0f , GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.one_text_tu, mysterytext.one_text_tv);
			}
			if (mysterytext.correctanswer == true && mysterytext.nexttext >= 2)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 170.0f , mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.two_text_tu, mysterytext.two_text_tv);
			}
			if (mysterytext.correctanswer == true && mysterytext.nexttext >= 3)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 280.0f, mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.three_text_tu, mysterytext.three_text_tv);
			}
			if (mysterytext.correctanswer == true && mysterytext.nexttext >= 4)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 380.0f, mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.four_text_tu, mysterytext.four_text_tv);
			}
			if (mysterytext.correctanswer == true && mysterytext.nexttext >= 5&& mysterytext.oneproblem == true)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 465.0f, mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.five_text_tu, mysterytext.five_text_tv);
			}

		}
	}

	DrawTexture(mysterytext.textpos_x, mysterytext.textpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex));
	

	DrawTexture(button.decisionpos_x, button.decisionpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDecisionButtonTex));

	DrawTexture(button.deletepos_x, button.deletepos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDeleteButtonTex));


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

				if (mysterytext.nexttext == 0)
				{
					mysterytext.one_text_tu = 0.09f * j;

					mysterytext.one_text_tv = 0.195f * i;
					mysterytext.nexttext++;
				}
				else if (mysterytext.nexttext == 1)
				{
					mysterytext.two_text_tu = 0.09f * j;

					mysterytext.two_text_tv = 0.195f * i;
					mysterytext.nexttext++;
				}
				else if (mysterytext.nexttext == 2)
				{
					mysterytext.three_text_tu = 0.09f * j;

					mysterytext.three_text_tv = 0.195f * i;
					mysterytext.nexttext++;
				}
				else if (mysterytext.nexttext == 3)
				{
					mysterytext.four_text_tu = 0.09f * j;

					mysterytext.four_text_tv = 0.195f * i;
					mysterytext.nexttext++;

				}
				else if (mysterytext.nexttext == 4)
				{
					mysterytext.five_text_tu = 0.09f * j;

					mysterytext.five_text_tv = 0.195f * i;
					mysterytext.nexttext++;
				}
				
			}
			

		}
	}
}

void UpdataDelete()
{
	if (HitChoise(button.decisionpos_x, button.decisionpos_y, button.decisionwidth, button.decisionheight) == true)
	{
		mysterytext.nexttext = 0;
	}
}