#include "JK.h"
#include "Graphics.h"
#include "Texture.h"
#include "Bg.h"
#include "Robot.h"
#include "Item.h"
#include "Input.h"
#include "Text.h"
#include "Player.h"
#include "Talk.h"
#include "Puzzle.h"


Boyish boyish;
Yuruhuwa yuruhuwa;

//�L�����e�N�X�`���ǂݍ���
void LoadCharacter()
{
	LoadTexture("Res/�L����/��l�������t�@�C��.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchPlayerTex);

	LoadTexture("Res/�L����/���C�h_�����G.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomTalkMaidTex);
	LoadTexture("Res/�L����/���C�h_����.png", TEXTURE_SEARCH, LargeRoomCategoryTextureList::LargeRoomMaidRobotTex);

	LoadTexture("Res/�L����/�{�[�C�b�V������.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex);
	LoadTexture("Res/�L����/�{�[�C�b�V�������G.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex);

	LoadTexture("Res/�L����/���у��{�p�[�c.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex);
	LoadTexture("Res/�L����/���ю���(�J�I�i�V).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);
	LoadTexture("Res/�L����/���ю���.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameCompleteRobotTex);
	LoadTexture("Res/�L����/���ю���.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex);
	LoadTexture("Res/�L����/�����G���������Ȃ�.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot_NoNeckTex);
	LoadTexture("Res/�L����/�����G����.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot);
}

#pragma region Jk������
void InitBoyish()
{
	if (areadata.searchgamearea == true)
	{
		boyish.pos_x = 1040.0f;
		boyish.pos_y = 180.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;

		if (boyish.clear == false)
		{
			boyish.talktype = 0;
			boyish.clear = false;
			boyish.heart = 0;
		}
	}
	if (areadata.corridor == true && boyish.unlock == true)
	{
		boyish.pos_x = 1560.0f;
		boyish.pos_y = 450.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
	if (areadata.largeroom == true && boyish.unlock == true)
	{
		boyish.pos_x = 540.0f;
		boyish.pos_y = 170.0f;

		boyish.tu = 0.0f;
		boyish.tv = 0.0f;

		boyish.width = 64.0f;
		boyish.height = 128.0f;

		boyish.talk = false;
	}
}

void InitYuruhuwa()
{
	if (areadata.searchyuruhuwaarea == true)
	{
		yuruhuwa.pos_x = 1200.0f;
		yuruhuwa.pos_y = 240.0f;

		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;

		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;

		yuruhuwa.talk = false;

		if (yuruhuwa.clear == false)
		{
			yuruhuwa.talktype = 0;
			
			yuruhuwa.clear = false;
			yuruhuwa.heart = 0;
		}
		
	}
	if (areadata.corridor == true && yuruhuwa.unlock == true)
	{
		yuruhuwa.pos_x = 350.0f;
		yuruhuwa.pos_y = 450.0f;

		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
	if (areadata.largeroom == true && yuruhuwa.unlock == true)
	{
		yuruhuwa.pos_x = 1395.0f;
		yuruhuwa.pos_y = 250.0f;
		
		yuruhuwa.tu = 0.0f;
		yuruhuwa.tv = 0.0f;
		
		yuruhuwa.width = 64.0f;
		yuruhuwa.height = 128.0f;
		
		yuruhuwa.talk = false;
	}
}

#pragma endregion

#pragma region Jk�`��
void DrawBoyish()
{
	if (areadata.searchgamearea == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.corridor == true && boyish.unlock == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	if (areadata.largeroom == true && boyish.unlock == true)
	{
		DrawUVTexture(boyish.pos_x, boyish.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), boyish.width, boyish.height, boyish.tu, boyish.tv);
	}
	
}

void DrawYuruhuwa()
{
	if (areadata.searchyuruhuwaarea == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.corridor == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.largeroom == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameBoyishTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
		
	}

}

#pragma endregion

#pragma region Jk��b
void DrawTalkBoyish()
{
	if ((searchgameobject.boyish == true || corridorobject.boyish == true || largeroomobject.boyish == true) && boyish.talk == false)
	{
		if (boyish.clear == true)
		{
			boyish.unlock = true;
		}

		if (searchplayer.animetion_tv == 0.25f)
		{
			boyish.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{

			boyish.tu = 0.33f;
		}

		boyish.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && boyish.talk == true)
	{
		boyish.tu = 0.0f;
		boyish.talk = false;
		textbox.onspacekey = false;
		
		textdata.jk_nexttext = false;

		InitJKLoadFile();
	
	}
	if (boyish.talk == true)
	{
		
		if (strstr(textdata.jk_oneline, "��������") || strstr(textdata.jk_oneline, "�ȁA�i�c�i") || strstr(textdata.jk_oneline, "�p�[�c�H")
			|| strstr(textdata.jk_oneline, "�Ƃɂ����I") || strstr(textdata.jk_oneline, "�����Ă��Ă�") || strstr(textdata.jk_oneline, "���A��������")
			|| strstr(textdata.jk_oneline, "�Ƃ����") || strstr(textdata.jk_oneline, "�A�L������") || strstr(textdata.jk_oneline, "�����Ȃ񂷂�")
			|| strstr(textdata.jk_oneline, "�{���������I�H") || strstr(textdata.jk_oneline, " �����A") || strstr(textdata.jk_oneline, "���A����Ȃ���")
			|| strstr(textdata.jk_twoline, "������[�I") || strstr(textdata.jk_oneline, "����́A���������ǂ�") || strstr(textdata.jk_oneline, "�ق��̕�����")
			|| strstr(textdata.jk_oneline, "������Ƒ҂��Ă��������I") || strstr(textdata.jk_oneline, "���ꂳ������") || strstr(textdata.jk_oneline, "�d�C��������"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "�i�c�i", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.jk_oneline, "���������āA") || strstr(textdata.jk_oneline, "�������v��")
			|| strstr(textdata.jk_oneline, "�������") || strstr(textdata.jk_oneline, "�N�̂���") || strstr(textdata.jk_oneline, "�����B")
			|| strstr(textdata.jk_oneline, "����Ńi�c�i"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "��l��", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		}
		DrawJKTalkText();
		if (strstr(textdata.jk_oneline, "�������") || strstr(textdata.jk_oneline, "�N�̂���") || strstr(textdata.jk_oneline, "����"))
		{
			DrawChoiceTexture();
		}
		
		
		
	}
}

void DrawTalkYuruhuwa()
{
	if ((yuruhuwaobject.yuruhuwa == true || corridorobject.yuruhuwa == true || largeroomobject.yuruhuwa == true) && yuruhuwa.talk == false)
	{
		if (yuruhuwa.clear == true)
		{
			yuruhuwa.unlock = true;
		}

		if (searchplayer.animetion_tv == 0.25f)
		{
			yuruhuwa.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{

			yuruhuwa.tu = 0.33f;
		}

		yuruhuwa.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && yuruhuwa.talk == true)
	{
		yuruhuwa.tu = 0.0f;
		yuruhuwa.talk = false;
		textbox.onspacekey = false;
		choicetexturedata.decision_2 = false;
		textdata.jk_nexttext = false;

		if (puzzle.goal_key == true)
		{
			yuruhuwa.talktype = 2;

		}
 		InitJKLoadFile();

	}
	if (yuruhuwa.talk == true)
	{

		if (strstr(textdata.jk_oneline, "���A����ɂ���") || strstr(textdata.jk_oneline, "���F�B����") || strstr(textdata.jk_oneline, "�n���J�ł�")
			|| strstr(textdata.jk_oneline, "�V�c�W����") || strstr(textdata.jk_oneline, "�킟") || strstr(textdata.jk_oneline, "���肪�Ƃ��������܂�")
			|| strstr(textdata.jk_oneline, "���F�B�Ȃ�") || strstr(textdata.jk_oneline, "����H") || strstr(textdata.jk_oneline, "���������Ƃ�") 
			|| strstr(textdata.jk_oneline, "�ӂӁA") || strstr(textdata.jk_oneline, "�����A")|| strstr(textdata.jk_oneline, "���ꂶ�Ⴀ")
			|| strstr(textdata.jk_oneline, "�킩��܂���")|| strstr(textdata.jk_oneline, "��������") || strstr(textdata.jk_oneline, "����ł�") 
			|| strstr(textdata.jk_oneline, "�A�L�������")|| strstr(textdata.jk_oneline, "�͂��B") || strstr(textdata.jk_oneline, "����ɂ��Ă�") 
			|| strstr(textdata.jk_oneline, "���͂�����") || strstr(textdata.jk_oneline, "���̕���"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "�n���J", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.jk_oneline, "���̓A�L��") || strstr(textdata.jk_oneline, "�E�E�E�E�E")
			|| strstr(textdata.jk_oneline, "�����B") || strstr(textdata.jk_oneline, "���F�B����Ȃ�") || strstr(textdata.jk_oneline, "���v")
			|| strstr(textdata.jk_oneline, "����") || strstr(textdata.jk_oneline, "������") || strstr(textdata.jk_oneline, "����"))
		{
			
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "��l��", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.jk_oneline, "�����A") || strstr(textdata.jk_oneline, "�����"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(1000.0f, 100.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "����", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		}
		DrawJKTalkText();
		if (strstr(textdata.jk_oneline, "���v") || strstr(textdata.jk_oneline, "����") || strstr(textdata.jk_oneline, "������"))
		{
			DrawChoiceTexture();
		}
	}
}





void UpDataBoyishTalk()
{
	if (searchgameobject.boyish == true || corridorobject.boyish == true || largeroomobject.boyish == true)
	{
		if (searchgameobject.completerobot == true && boyish.talktype == 1)
		{
			InitJKLoadFile();
		}
		if ((boyish.talk == true && choicetexturedata.Choicepos == 1))
		{
			choicetexturedata.decision_1 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;
		}
		else if ((boyish.talk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;

		}

		JKLoadText();
		
		textdata.jk_nexttext = true;
	}
}

void UpDataYuruhuwaTalk()
{
	if (yuruhuwaobject.yuruhuwa == true || corridorobject.yuruhuwa == true || largeroomobject.yuruhuwa == true)
	{
		if (puzzle.goal_key == true && yuruhuwa.talktype == 1)
		{
			InitJKLoadFile();
		}
		if ((yuruhuwa.talk == true && choicetexturedata.Choicepos == 1))
		{
			choicetexturedata.decision_1 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;
		}
		else if ((yuruhuwa.talk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;

		}

  		JKLoadText();

		textdata.jk_nexttext = true;
	}
}


void DrawTalkClearBoyish()
{
	if (areadata.cleararea == true && boyish.clear == true && boyish.talk == false)
	{
		boyish.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && boyish.talk == true)
	{
		boyish.talk = false;
		textbox.onspacekey = false;
		boyish.end = true;
		
	}
	if (boyish.talk == true)
	{
		if (displaydata.display_cleartext == true)
		{
			if (strstr(textdata.jk_oneline, "�A�L������") || strstr(textdata.jk_oneline, "���̎�") || strstr(textdata.jk_oneline, "���ꂾ��")
				|| strstr(textdata.jk_oneline, "���肪�Ƃ�"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "�i�c�i", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.jk_oneline, "��������") || strstr(textdata.jk_oneline, "�\�\"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "��l��", FontSize::Regular, FontColor::Yellow);
			}
			
		}
		
		DrawJKTalkText();
	}
}

void DrawTalkClearYuruhuwa()
{
	if (areadata.cleararea == true && yuruhuwa.clear == true && yuruhuwa.talk == false)
	{
		yuruhuwa.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.jk_threeline == NULL && yuruhuwa.talk == true)
	{
		yuruhuwa.talk = false;
		textbox.onspacekey = false;
		yuruhuwa.end = true;

	}
	if (yuruhuwa.talk == true)
	{
		if (displaydata.display_cleartext == true)
		{
			if (strstr(textdata.jk_oneline, "�킟�I") || strstr(textdata.jk_oneline, "�ӂӂ�") || strstr(textdata.jk_oneline, "�܂��A�L��"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "�n���J", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.jk_oneline, "�����w��"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "��l��", FontSize::Regular, FontColor::Yellow);
			}

		}

		DrawJKTalkText();
	}
}


#pragma endregion
void UpDataClearText()
{

	if (GetKeyDown(SPACE_KEY) == true && boyish.clear == true)
	{
		
		if (strstr(textdata.jk_oneline, "�āB"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		JKLoadText();

	}
	else if (GetKeyDown(SPACE_KEY) == true && yuruhuwa.clear == true)
	{

		if (strstr(textdata.jk_oneline, "�t�B"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		JKLoadText();

	}
}