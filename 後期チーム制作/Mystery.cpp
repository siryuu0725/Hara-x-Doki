#include "Mystery.h"
#include "Graphics.h"
#include "Texture.h"
#include "Input.h"
#include "Hit.h"
#include "JK.h"

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

	mysterytext.one_text = 0;
	mysterytext.two_text = 0;
	mysterytext.three_text = 0;
	mysterytext.four_text = 0;
	mysterytext.five_text = 0;

	

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

	button.decisiontext = false;
	button.answer = false;

	button.correct_answer = false;

}


void DrawMysteryBg()
{
	DrawBgTexture(GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameBgTex));
	DrawTexture(mysterytext.textpos_x, mysterytext.textpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextBoxTex));

	if (mysterytext.oneproblem == false)
	{
		DrawTexture(mysterytext.problemtextpos_x, mysterytext.problemtextpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblemTextTex_1));
		DrawTexture(mysterytext.problemanswer_x, mysterytext.problemanswer_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameProblem_Answer_1));

	}
	else if (mysterytext.oneproblem == true)
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
			if (button.answer == true && mysterytext.nexttext >= 1)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 65.0f, mysterytext.problemanswer_y + 25.0f , GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.one_text_tu, mysterytext.one_text_tv);
			}
			if (button.answer == true && mysterytext.nexttext >= 2)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 170.0f , mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.two_text_tu, mysterytext.two_text_tv);
			}
			if (button.answer == true && mysterytext.nexttext >= 3)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 280.0f, mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.three_text_tu, mysterytext.three_text_tv);
			}
			if (button.answer == true && mysterytext.nexttext >= 4)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 380.0f, mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.four_text_tu, mysterytext.four_text_tv);
			}
			if (button.answer == true && mysterytext.nexttext >= 5&& mysterytext.oneproblem == true)
			{
				DrawUVTexture(mysterytext.problemanswer_x + 490.0f, mysterytext.problemanswer_y + 25.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex), 70.0f, 70.0f, mysterytext.five_text_tu, mysterytext.five_text_tv);
			}

		}
	}

	DrawTexture(mysterytext.textpos_x, mysterytext.textpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameTextTex));
	

	DrawTexture(button.decisionpos_x, button.decisionpos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDecisionButtonTex));

	DrawTexture(button.deletepos_x, button.deletepos_y, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameDeleteButtonTex));


}

void DrawMysteryAnswerBg()
{
	

	
	if (button.correct_answer == true && button.decisiontext == true)
	{
		button.counter++;
		if (button.counter <= 60)
		{
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameCorrect_Answer));
		}
		else
		{
			button.decisiontext = false;
			button.correct_answer = false;
			button.counter = 0;

			if (mysterytext.twoproblem == true)
			{
				tundere.clear = true;
			}

		}
		
	}
	else if (button.correct_answer == false && button.decisiontext == true)
	{
		button.counter++;
		if (button.counter <= 60)
		{
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_MYSTERY, MysteryGameCategoryTextureList::MysteryGameIncorrect_Answer));
		}
		else
		{
			button.decisiontext = false;
			button.correct_answer = false;

			button.counter = 0;
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
			
				button.answer = true;

				if (mysterytext.nexttext == 0)
				{
					mysterytext.one_text_tu = 0.09f * j;

					mysterytext.one_text_tv = 0.195f * i;

					mysterytext.one_text = mysterytext.text[i][j];
					mysterytext.nexttext++;
				}
				else if (mysterytext.nexttext == 1)
				{
					mysterytext.two_text_tu = 0.09f * j;

					mysterytext.two_text_tv = 0.195f * i;
					mysterytext.two_text = mysterytext.text[i][j];

					mysterytext.nexttext++;
				}
				else if (mysterytext.nexttext == 2)
				{
					mysterytext.three_text_tu = 0.09f * j;

					mysterytext.three_text_tv = 0.195f * i;
					mysterytext.three_text = mysterytext.text[i][j];

					mysterytext.nexttext++;
				}
				else if (mysterytext.nexttext == 3)
				{
					mysterytext.four_text_tu = 0.09f * j;

					mysterytext.four_text_tv = 0.195f * i;
					mysterytext.four_text = mysterytext.text[i][j];

					mysterytext.nexttext++;

				}
				else if (mysterytext.nexttext == 4)
				{
					mysterytext.five_text_tu = 0.09f * j;

					mysterytext.five_text_tv = 0.195f * i;
					mysterytext.five_text = mysterytext.text[i][j];

					mysterytext.nexttext++;
				}
				
			}
			

		}
	}
}
void UpdataDecision()
{
	if (HitChoise(button.decisionpos_x, button.decisionpos_y, button.decisionwidth, button.decisionheight) == true
		&& OnMouseDown(Left) == true)
	{
		button.decisiontext = true;
		if (mysterytext.oneproblem == false
			&& mysterytext.one_text == 14 && mysterytext.two_text == 26 && mysterytext.three_text == 46 && mysterytext.four_text == 12)
		{
			mysterytext.oneproblem = true;
			button.correct_answer = true;
			mysterytext.nexttext = 0;
		}
		else if (mysterytext.oneproblem == true
			&& mysterytext.one_text == 14 && mysterytext.two_text == 54 && mysterytext.three_text == 3 && mysterytext.four_text == 12 && mysterytext.five_text == 54)
		{
			button.correct_answer = true;
			mysterytext.twoproblem = true;
			
			mysterytext.nexttext = 0;
		}
	}
}

void UpdataDelete()
{
	if (HitChoise(button.deletepos_x, button.deletepos_y, button.deletewidth, button.deleteheight) == true
		&& OnMouseDown(Left) == true)
	{
		mysterytext.nexttext = 0;
	}
}