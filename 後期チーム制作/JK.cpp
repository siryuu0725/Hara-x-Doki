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

Tundere tundere;
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

	LoadTexture("Res/�L����/�c���f�������G.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTalkTex);
	LoadTexture("Res/�L����/�c���f������.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex);

	LoadTexture("Res/�L����/���ӂ헧���G.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex);
	LoadTexture("Res/�L����/���ӂ킿��.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex);

	LoadTexture("Res/�L����/���у��{�p�[�c.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex);
	LoadTexture("Res/�L����/���ю���(�J�I�i�V).png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotTex);
	LoadTexture("Res/�L����/���ю���.png", TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameCompleteRobotTex);
	LoadTexture("Res/�L����/���ю���.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRobotTex);
	LoadTexture("Res/�L����/���ю���.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRobotTex);
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

void InitTundere()
{
	if (areadata.searchtunderearea == true)
	{
		tundere.pos_x = 1200.0f;
		tundere.pos_y = 240.0f;
		tundere.tu = 0.0f;
		tundere.tv = 0.0f;
		tundere.width = 64.0f;
		tundere.height = 128.0f;
		tundere.talk = false;

		if (tundere.clear == false)
		{
			tundere.talktype = 0;

			tundere.clear = false;
			tundere.heart = 0;
		}

	}
	if (areadata.corridor == true && tundere.unlock == true)
	{
		tundere.pos_x = 965.0f;
		tundere.pos_y = 450.0f;
		tundere.tu = 0.0f;
		tundere.tv = 0.0f;
		tundere.width = 64.0f;
		tundere.height = 128.0f;
		tundere.talk = false;
	}
	if (areadata.largeroom == true && tundere.unlock == true)
	{
		tundere.pos_x = 740.0f;
		tundere.pos_y = 690.0f;
		tundere.tu = 0.0f;
		tundere.tv = 0.0f;
		tundere.width = 64.0f;
		tundere.height = 128.0f;
		tundere.talk = false;
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
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.corridor == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
	}
	if (areadata.largeroom == true && yuruhuwa.unlock == true)
	{
		DrawUVTexture(yuruhuwa.pos_x, yuruhuwa.pos_y, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTex), yuruhuwa.width, yuruhuwa.height, yuruhuwa.tu, yuruhuwa.tv);
		
	}

}

void DrawTundere()
{
	if (areadata.searchtunderearea == true)
	{
		DrawUVTexture(tundere.pos_x, tundere.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex), tundere.width, tundere.height, tundere.tu, tundere.tv);
	}
	if (areadata.corridor == true && tundere.unlock == true)
	{
		DrawUVTexture(tundere.pos_x, tundere.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex), tundere.width, tundere.height, tundere.tu, tundere.tv);
	}
	if (areadata.largeroom == true && tundere.unlock == true)
	{
		DrawUVTexture(tundere.pos_x, tundere.pos_y, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTex), tundere.width, tundere.height, tundere.tu, tundere.tv);
	}

}
#pragma endregion

#pragma region Jk��b
void DrawTalkBoyish()
{
	//�e�����Ń{�[�C�b�V���ɘb���������Ƃ�
	if ((searchgameobject.boyish == true || corridorobject.boyish == true || largeroomobject.boyish == true) && boyish.talk == false)
	{
		if (boyish.clear == true)
		{
			boyish.unlock = true;
		}
		//�v���C���[�������Ă�������Ɍ���
		if (searchplayer.animetion_tv == 0.25f)
		{
			boyish.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{

			boyish.tu = 0.33f;
		}

		boyish.talk = true;
		textbox.onspacekey = true; //�v���C���[���~�߂Ă����t���O
	}
	//txt��NULL�̂Ƃ�
	else if (textdata.boyish_threeline == NULL && boyish.talk == true)
	{
		boyish.tu = 0.0f;
		boyish.talk = false;
		textbox.onspacekey = false;
		
		textdata.jk_nexttext = false;

		InitJKLoadFile();
		//�D���x�V�X�e��
		if (boyish.heart == 3)
		{
			getitem.tunderedoorkey = false;
			getitem.yuruhuwadoorkey = false;
		}
		else if (boyish.heart <= 2)
		{
			getitem.tunderedoorkey = true;
			getitem.yuruhuwadoorkey = true;
		}
	
	}
	if (boyish.talk == true)
	{
		//txt�Ɏw�肵�������񂪂������ꍇ
		if (strstr(textdata.boyish_oneline, "��������") || strstr(textdata.boyish_oneline, "�ȁA�i�c�i") || strstr(textdata.boyish_oneline, "�p�[�c�H")
			|| strstr(textdata.boyish_oneline, "�Ƃɂ����I") || strstr(textdata.boyish_oneline, "�����Ă��Ă�") || strstr(textdata.boyish_oneline, "���A��������")
			|| strstr(textdata.boyish_oneline, "�Ƃ����") || strstr(textdata.boyish_oneline, "�A�L������") || strstr(textdata.boyish_oneline, "�����Ȃ񂷂�")
			|| strstr(textdata.boyish_oneline, "�{���������I�H") || strstr(textdata.boyish_oneline, " �����A") || strstr(textdata.boyish_oneline, "���A����Ȃ���")
			|| strstr(textdata.boyish_twoline, "������[�I") || strstr(textdata.boyish_oneline, "����́A���������ǂ�") || strstr(textdata.boyish_oneline, "�ق��̕�����")
			|| strstr(textdata.boyish_oneline, "������Ƒ҂��Ă��������I") || strstr(textdata.boyish_oneline, "���̌�") || strstr(textdata.boyish_oneline, "�d�C��������"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(600.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkBoyishTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "�i�c�i", FontSize::Regular, FontColor::Yellow);
		}
		//txt�Ɏw�肵�������񂪂������ꍇ
		else if (strstr(textdata.boyish_oneline, "���������āA") || strstr(textdata.boyish_oneline, "�������v��")
			|| strstr(textdata.boyish_oneline, "�������") || strstr(textdata.boyish_oneline, "�N�̂���") || strstr(textdata.boyish_oneline, "�����B")
			|| strstr(textdata.boyish_oneline, "����Ńi�c�i"))
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
		if (strstr(textdata.boyish_oneline, "�������") || strstr(textdata.boyish_oneline, "�N�̂���") || strstr(textdata.boyish_oneline, "����"))
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
	else if (textdata.yuruhuwa_threeline == NULL && yuruhuwa.talk == true)
	{
		yuruhuwa.tu = 0.0f;
		yuruhuwa.talk = false;
		textbox.onspacekey = false;
		choicetexturedata.decision_2 = false;
		textdata.jk_nexttext = false;

		if (yuruhuwa.clear == true)
		{
			yuruhuwa.talktype = 2;

		}
 		InitJKLoadFile();

		if (yuruhuwa.heart == 3)
		{
			getitem.tunderedoorkey = false;
			getitem.boyishdoorkey = false;
		}
		else if (yuruhuwa.heart <= 2)
		{
			getitem.tunderedoorkey = true;
			getitem.boyishdoorkey = true;
		}
	}
	if (yuruhuwa.talk == true)
	{

		if (strstr(textdata.yuruhuwa_oneline, "���A����ɂ���") || strstr(textdata.yuruhuwa_oneline, "���F�B����") || strstr(textdata.yuruhuwa_oneline, "�n���J�ł�")
			|| strstr(textdata.yuruhuwa_oneline, "�V�c�W����") || strstr(textdata.yuruhuwa_oneline, "�킟") || strstr(textdata.yuruhuwa_oneline, "���肪�Ƃ��������܂�")
			|| strstr(textdata.yuruhuwa_oneline, "���F�B�Ȃ�") || strstr(textdata.yuruhuwa_oneline, "����H") || strstr(textdata.yuruhuwa_oneline, "���������Ƃ�")
			|| strstr(textdata.yuruhuwa_oneline, "�ӂӁA") || strstr(textdata.yuruhuwa_oneline, "�����A")|| strstr(textdata.yuruhuwa_oneline, "���ꂶ�Ⴀ")
			|| strstr(textdata.yuruhuwa_oneline, "�킩��܂���")|| strstr(textdata.yuruhuwa_oneline, "��������") || strstr(textdata.yuruhuwa_oneline, "����ł�")
			|| strstr(textdata.yuruhuwa_oneline, "�A�L�������")|| strstr(textdata.yuruhuwa_oneline, "�͂��B") || strstr(textdata.yuruhuwa_oneline, "����ɂ��Ă�")
			|| strstr(textdata.yuruhuwa_oneline, "���͂�����") || strstr(textdata.yuruhuwa_oneline, "������Ƒ҂��Ă��������I") || strstr(textdata.yuruhuwa_oneline, "����"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(350.0f, -50.0f, GetTexture(TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaTalkTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "�n���J", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.yuruhuwa_oneline, "���̓A�L��") || strstr(textdata.yuruhuwa_oneline, "�E�E�E�E�E")
			|| strstr(textdata.yuruhuwa_oneline, "�����B") || strstr(textdata.yuruhuwa_oneline, "���F�B����Ȃ�") || strstr(textdata.yuruhuwa_oneline, "���v")
			|| strstr(textdata.yuruhuwa_oneline, "����") || strstr(textdata.yuruhuwa_oneline, "������") || strstr(textdata.yuruhuwa_oneline, "����"))
		{
			
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "��l��", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.yuruhuwa_oneline, "�����A") || strstr(textdata.yuruhuwa_oneline, "�����"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
			DrawTexture(400.0f, 0.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameTalkRobot));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "�������{", FontSize::Regular, FontColor::Yellow);
		}
		else
		{
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
		}
		DrawJKTalkText();
		if (strstr(textdata.yuruhuwa_oneline, "���v") || strstr(textdata.yuruhuwa_oneline, "����") || strstr(textdata.yuruhuwa_oneline, "������"))
		{
			DrawChoiceTexture();
		}
	}
}

void DrawTalkTundere()
{
	if ((tundereobject.tundere == true || corridorobject.tundere == true || largeroomobject.tundere == true) && tundere.talk == false)
	{
		if (tundere.clear == true)
		{
			tundere.unlock = true;
		}

		if (searchplayer.animetion_tv == 0.25f)
		{
			tundere.tu = 0.65f;
		}
		if (searchplayer.animetion_tv == 0.75f)
		{

			tundere.tu = 0.33f;
		}

		tundere.talk = true;
		textbox.onspacekey = true;
	}
	else if (textdata.tundere_threeline == NULL && tundere.talk == true)
	{
		tundere.tu = 0.0f;
		tundere.talk = false;
		textbox.onspacekey = false;
		choicetexturedata.decision_2 = false;
		textdata.jk_nexttext = false;

		
		InitJKLoadFile();

		if (tundere.heart == 3)
		{
			getitem.yuruhuwadoorkey = false;
			getitem.boyishdoorkey = false;
		}
		else if (tundere.heart <= 2)
		{
			getitem.yuruhuwadoorkey = true;
			getitem.boyishdoorkey = true;
		}
	}
	if (tundere.talk == true)
	{

		if (strstr(textdata.tundere_oneline, "�������") || strstr(textdata.tundere_oneline, "�M������") || strstr(textdata.tundere_oneline, "�d�d�d����")
			|| strstr(textdata.tundere_oneline, "����I") || strstr(textdata.tundere_oneline, "�ʂɁd") || strstr(textdata.tundere_oneline, "�{����")
			|| strstr(textdata.tundere_oneline, "�ȁA�Ȃɂ�") || strstr(textdata.tundere_oneline, "�t�ɉ�����") || strstr(textdata.tundere_oneline, "����ɂ�")
			|| strstr(textdata.tundere_oneline, "���A���邳") || strstr(textdata.tundere_oneline, "�Ȃ�ł���") || strstr(textdata.tundere_oneline, "�ˁA�˂��A")
			|| strstr(textdata.tundere_oneline, "�ƁA���R�ˁI") || strstr(textdata.tundere_oneline, "�M�p����") || strstr(textdata.tundere_oneline, "�͂��[�A")
			|| strstr(textdata.tundere_oneline, "���āA") || strstr(textdata.tundere_oneline, "�Ȃ�ł�") || strstr(textdata.tundere_oneline, "������Ƒ҂��āI")
			|| strstr(textdata.tundere_oneline, "���ʂ̉�"))
		{
			DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

			DrawTexture(350.0f, -50.0f, GetTexture(TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereTalkTex));
			DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextBoxTex));
			DrawFont(100, 610, "�}�V��", FontSize::Regular, FontColor::Yellow);
		}
		else if (strstr(textdata.tundere_oneline, "���������I") || strstr(textdata.tundere_oneline, "������")
			|| strstr(textdata.tundere_oneline, "���v���H") || strstr(textdata.tundere_oneline, "����ł�") || strstr(textdata.tundere_oneline, "�N�̕�")
			|| strstr(textdata.tundere_oneline, "�����A"))
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
		if (strstr(textdata.tundere_oneline, "����ł�") || strstr(textdata.tundere_oneline, "�N�̕���") || strstr(textdata.tundere_oneline, "�����A"))
		{
			DrawChoiceTexture();
		}
	}
}


//���̉�b�֍s���֐�
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

		BoyishLoadText();
		
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

  		YuruhuwaLoadText();

		textdata.jk_nexttext = true;
	}
}

void UpDataTundereTalk()
{
	if (tundereobject.tundere == true || corridorobject.tundere == true || largeroomobject.tundere == true)
	{
		if (tundere.clear == false && tundere.talktype == 1)
		{
			InitJKLoadFile();
		}
		if ((tundere.talk == true && choicetexturedata.Choicepos == 1))
		{
			choicetexturedata.decision_1 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;
		}
		else if ((tundere.talk == true && choicetexturedata.Choicepos == 2))
		{
			choicetexturedata.decision_2 = true;
			choicetexturedata.Choicepos = 0;
			choicetexturedata.display = 0;

		}

		TundereLoadText();

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
	else if (textdata.boyish_threeline == NULL && boyish.talk == true)
	{
		boyish.talk = false;
		textbox.onspacekey = false;
		boyish.end = true;
		
	}
	if (boyish.talk == true)
	{
		if (displaydata.display_cleartext == true)
		{
			if (strstr(textdata.boyish_oneline, "�A�L������") || strstr(textdata.boyish_oneline, "���̎�") || strstr(textdata.boyish_oneline, "���ꂾ��")
				|| strstr(textdata.boyish_oneline, "���肪�Ƃ�"))
			{
				DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

				//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
				DrawFont(100, 610, "�i�c�i", FontSize::Regular, FontColor::Yellow);
			}
			else if (strstr(textdata.boyish_oneline, "��������") || strstr(textdata.boyish_oneline, "�\�\"))
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
	if (yuruhuwa.heart == 3)
	{
		if (areadata.cleararea == true && yuruhuwa.clear == true && yuruhuwa.talk == false)
		{
			yuruhuwa.talk = true;
			textbox.onspacekey = true;
		}
		else if (textdata.yuruhuwa_threeline == NULL && yuruhuwa.talk == true)
		{
			yuruhuwa.talk = false;
			textbox.onspacekey = false;
			yuruhuwa.end = true;

		}
		if (yuruhuwa.talk == true)
		{
			if (displaydata.display_cleartext == true)
			{
				if (strstr(textdata.yuruhuwa_oneline, "�킟�I") || strstr(textdata.yuruhuwa_oneline, "�ӂӂ�") || strstr(textdata.yuruhuwa_oneline, "�܂��A�L��"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

					//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
					DrawFont(100, 610, "�n���J", FontSize::Regular, FontColor::Yellow);
				}
				else if (strstr(textdata.yuruhuwa_oneline, "�����w��"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
					//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
					DrawFont(100, 610, "��l��", FontSize::Regular, FontColor::Yellow);
				}

			}

			DrawJKTalkText();
		}
	}
	
}

void DrawTalkClearTundere()
{
	if (tundere.heart == 3)
	{
		if (areadata.cleararea == true && tundere.clear == true && tundere.talk == false)
		{
			tundere.talk = true;
			textbox.onspacekey = true;
		}
		else if (textdata.tundere_threeline == NULL && tundere.talk == true)
		{
			tundere.talk = false;
			textbox.onspacekey = false;
			tundere.end = true;

		}
		if (tundere.talk == true)
		{
			if (displaydata.display_cleartext == true)
			{
				if (strstr(textdata.tundere_oneline, "�ȁA�Ȃɂ�") || strstr(textdata.tundere_oneline, "�͂��I�H") || strstr(textdata.tundere_oneline, "��������")
					|| strstr(textdata.tundere_oneline, "������"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));

					DrawFont(100, 610, "�}�V��", FontSize::Regular, FontColor::Yellow);
				}
				else if (strstr(textdata.tundere_oneline, "�N�̍D����") || strstr(textdata.tundere_oneline, "���A�Ȃ��"))
				{
					DrawTexture(0.0f, 600.0f, GetTexture(TEXTURE_SEARCH, LargeRoomCategoryTextureList::SearchTextnameTex));
					//DrawTexture(textbox.pos_x, textbox.pos_y, GetTexture(TEXTURE_SEARCH, SearchCategoryTextureList::SearchTextBoxTex));
					DrawFont(100, 610, "��l��", FontSize::Regular, FontColor::Yellow);
				}

			}

			DrawJKTalkText();
		}
	}
}

#pragma endregion
void UpDataClearText()
{

	if (GetKeyDown(SPACE_KEY) == true && boyish.clear == true)
	{
		
		if (strstr(textdata.boyish_oneline, "�āB"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		BoyishLoadText();

	}
	else if (GetKeyDown(SPACE_KEY) == true && yuruhuwa.clear == true)
	{

		if (strstr(textdata.boyish_oneline, "�t�B"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		BoyishLoadText();

	}
	else if (GetKeyDown(SPACE_KEY) == true && tundere.clear == true)
	{

		if (strstr(textdata.boyish_oneline, "�~�B"))
		{
			displaydata.display_cleartext = true;
		}
		textdata.jk_nexttext = true;

		BoyishLoadText();

	}
}