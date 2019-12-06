#include"Item.h"
#include "Graphics.h"
#include "Texture.h"
#include "Hit.h"
#include "Player.h"
#include "Robot.h"
#include "Input.h"

TouchObject tochobject;
RobotNeck neck;

void InitObject()
{
	tochobject.energy = false;
	tochobject.desk = false;
	tochobject.chair = false;
	tochobject.doll = false;
	tochobject.bed = false;
	tochobject.light = false;
	tochobject.flowerpot = false;
	tochobject.closet = false;
	tochobject.bookshelf = false;
}

void DrawRobotNeck()
{
	if (neck.get != true)
	{
		DrawTexture(700.0f, 500.0f, GetTexture(TEXTURE_SEARCH_GAME, SearchGameCategoryTextureList::SearchGameRobotNeckTex));

	}
}


//�w�i�ƉƋ�ʂ̂��ߊ֐���
void LoadTundereFurnitureTex()
{
	LoadTexture("Res/����(��).png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRoomBgTex);
	LoadTexture("Res/�J�[�y�b�g02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCarpet);
	LoadTexture("Res/��.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereWindow);
	LoadTexture("Res/�\�t�@.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereSofa);
	LoadTexture("Res/�ϗt�A��.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereFlowerpot);
	LoadTexture("Res/�\�y02.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereCloset);
	LoadTexture("Res/���C�g.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereRight);
	LoadTexture("Res/�x�b�h04.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereBed);
	LoadTexture("Res/�e�[�u��03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDesk);
	LoadTexture("Res/�ʂ������03.png", TEXTURE_TUNDERE_ROOM, TundereRoomCategoryTextureList::TundereDoll);
}
void LoadYuruhuwaFurnitureTex()
{
	LoadTexture("Res/����(��).png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRoomBgTex);
	LoadTexture("Res/�J�[�y�b�g03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCarpet);
	LoadTexture("Res/��.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaWindow);
	LoadTexture("Res/�\�t�@02.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaSofa);
	LoadTexture("Res/�\�y03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCloset);
	LoadTexture("Res/���C�g.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaRight);
	LoadTexture("Res/�x�b�h.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaBed);
	LoadTexture("Res/�e�[�u��03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDesk);
	LoadTexture("Res/�ʂ������03.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaDoll);
	LoadTexture("Res/���v.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaClock);
	LoadTexture("Res/�L���r�l�b�g.png", TEXTURE_YURUHUWA_ROOM, YuruhuwaRoomCategoryTextureList::YuruhuwaCabinet);
}

void LoadCriminalFurnitureTex()
{
	LoadTexture("Res/�Ɛl����.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRoomBgTex);
	LoadTexture("Res/�J�[�y�b�g.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRedCarpet);
	LoadTexture("Res/�J�[�y�b�g02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBuleCarpet);
	LoadTexture("Res/�J�[�y�b�g03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalGreenCarpet);
	LoadTexture("Res/�L���r�l�b�g.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCabinet);
	LoadTexture("Res/�\�y02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalCloset);
	LoadTexture("Res/���C�g.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalRight);
	LoadTexture("Res/�x�b�h04.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBed);
	LoadTexture("Res/�e�[�u��03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalDesk);
	LoadTexture("Res/���v.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalClock);
	LoadTexture("Res/�{�I03.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBookshelf);
	LoadTexture("Res/�{04.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook);
	LoadTexture("Res/�{02.png", TEXTURE_CRIMINAL_ROOM, CriminalRoomCategoryTextureList::CriminalBook2);
}


#pragma region �v���C���[�ƃI�u�W�F�N�g�̂����蔻��
void HitSearchObject()
{
	//��ʍ��[
	if (HitPlayerObject(0.0f, 0.0f, 155.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʍ���
	else if (HitPlayerObject(155.0f, 990.0f, 715.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE��
	else if (HitPlayerObject(960.0f, 990.0f, 770.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1730.0f, 550.0f, 185.0f, 525.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1730.0f, 0.0f, 185.0f, 450.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���C�h
	else if (HitPlayerObject(maidrobot.pos_x, maidrobot.pos_y, 64.0f, 128.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��e�[�u��
	else if (HitPlayerObject(720.0f, 380.0f, 460.0f, 360.0f) == true)
	{
		searchplayer.hit = true;	
	}
	//�֎q�P
	else if (HitPlayerObject(635.0f, 530.0f, 50.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q2
	else if (HitPlayerObject(830.0f, 780.0f, 50.0f, 30.0f) == true)
	{
	    searchplayer.hit = true;
	}
	//�֎q3
	else if (HitPlayerObject(1005.0f, 780.0f, 50.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q4
	else if (HitPlayerObject(1602.0f, 890.0f, 58.0f, 58.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�A�ؔ�
	else if (HitPlayerObject(155.0f, 885.0f, 100.0f, 105.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���v
	else if (HitPlayerObject(225.0f, 120.0f ,70.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�t�@�[
	else if (HitPlayerObject(705.0f, 140.0f, 515.0f, 135.0f) == true)
	{
		searchplayer.hit = true;	
	}
	//�d�b
	else if (HitPlayerObject(1395.0f, 185.0f, 65.0f, 100.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�Ɩ�
	else if (HitPlayerObject(1600.0f, 155.0f, 75.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	else
	{
		searchplayer.hit = false;
		searchplayer.eyehit = false;
	}
}

void HitSearchGameObject()
{
	//��ʍ��[
	if (HitPlayerObject(0.0f, 0.0f, 460.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʍ���
	else if (HitPlayerObject(460.0f, 1020.0f, 440.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE��
	else if (HitPlayerObject(975.0f, 1020.0f, 470.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1445.0f, 0.0f, 475.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���{�b�g
	else if (HitPlayerObject(searchgamerobot.pos_x + 20.0f, searchgamerobot.pos_y + 64.0f, searchgamerobot.width - 30.0f, searchgamerobot.height - 62.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��
	else if (HitPlayerObject(700.0f, 500.0f, 64.0f, 64.0f) == true && neck.get == false)
	{
		searchplayer.hit = true;
	}
	//�x�b�h
	else if (HitPlayerObject(480.0f, 755.0f, 255.0f, 146.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���e�[�u��
	else if (HitPlayerObject(480.0f, 910.0f, 50.0f, 65.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��e�[�u��
	else if (HitPlayerObject(1045.0f, 510.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q�P
	else if (HitPlayerObject(995.0f, 610.0f, 40.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q2
	else if (HitPlayerObject(1130.0f, 775.0f, 15.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q3
	else if (HitPlayerObject(1250.0f, 775.0f, 15.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�A�ؔ��ƏƖ�
	else if (HitPlayerObject(1175.0f, 95.0f, 270.0f, 190.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�y�Ɩ{�I
	else if (HitPlayerObject(460.0f, 35.0f, 450.0f, 255.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�ʂ������
	else if (HitPlayerObject(525.0f, 625.0f, 35.0f, 75.0f) == true)
	{
		searchplayer.hit = true;
	}
	else
	{
		searchplayer.hit= false;
	}
}

void HitTundereRoomObject()
{
	//��ʍ��[
	if (HitPlayerObject(0.0f, 0.0f, 460.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʍ���
	else if (HitPlayerObject(460.0f, 1020.0f, 440.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE��
	else if (HitPlayerObject(975.0f, 1020.0f, 470.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1445.0f, 0.0f, 475.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���{�b�g
	else if (HitPlayerObject(mysterygamerobot.pos_x + 20.0f, mysterygamerobot.pos_y + 64.0f, mysterygamerobot.width - 30.0f, mysterygamerobot.height - 62.0f) == true)
	{
		searchplayer.hit = true;
	}
	
	//�x�b�h
	else if (HitPlayerObject(465.0f, 865.0f, 265.0f, 146.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��e�[�u��
	else if (HitPlayerObject(1050.0f, 665.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q�P
	else if (HitPlayerObject(1130.0f, 930.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q2
	else if (HitPlayerObject(1250.0f, 930.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q3
	else if (HitPlayerObject(1380.0f, 770.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�A�ؔ�
	else if (HitPlayerObject(460.0f, 255.0f, 165.0f, 70.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�Ɩ�
	else if (HitPlayerObject(460.0f, 800.0f, 85.0f, 185.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�t�@
	else if (HitPlayerObject(695.0f, 170.0f, 245.0f, 110.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�y
	else if (HitPlayerObject(1305.0f, 80.0f, 120.0f, 225.0f) == true)
	{
		searchplayer.hit = true;
	}
	else
	{
		searchplayer.hit = false;
	}
}

void HitYuruhuwaRoomObject()
{
	//��ʍ��[
	if (HitPlayerObject(0.0f, 0.0f, 460.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʍ���
	else if (HitPlayerObject(460.0f, 1020.0f, 440.0f, 60.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE��
	else if (HitPlayerObject(975.0f, 1020.0f, 470.0f, 90.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��ʉE�[
	else if (HitPlayerObject(1445.0f, 0.0f, 475.0f, 1080.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���{�b�g
	else if (HitPlayerObject(puzzlegamerobot.pos_x + 20.0f, puzzlegamerobot.pos_y + 64.0f, puzzlegamerobot.width - 30.0f, puzzlegamerobot.height - 62.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�x�b�h
	else if (HitPlayerObject(475.0f, 745.0f, 145.0f, 255.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���e�[�u��
	else if (HitPlayerObject(1390.0f, 460.0f, 50.0f, 65.0f) == true)
	{
		searchplayer.hit = true;
	}
	//��e�[�u��
	else if (HitPlayerObject(460.0f, 260.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q�P
	else if (HitPlayerObject(550.0f, 525.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q2
	else if (HitPlayerObject(670.0f, 525.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�֎q3
	else if (HitPlayerObject(790.0f, 360.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�t�@
	else if (HitPlayerObject(1040.0f, 185.0f, 245.0f, 130.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�\�y
	else if (HitPlayerObject(870.0f, 70.0f, 125.0f, 245.0f) == true)
	{
		searchplayer.hit = true;
	}
	//���v
	else if (HitPlayerObject(1330.0f, 120.0f, 75.0f, 180.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�L���r�l�b�g
	else if (HitPlayerObject(1390.0f, 460.0f, 50.0f, 55.0f) == true)
	{
		searchplayer.hit = true;
	}
	//�Ɩ�
	else if (HitPlayerObject(1350.0f, 950.0f, 75.0f, 50.0f) == true)
	{
		searchplayer.hit = true;
	}
	
	else
	{
		searchplayer.hit = false;
	}
}
#pragma endregion 

#pragma region �v���C���[�̎��E�ƃI�u�W�F�N�g�̂����蔻��
void HitEyeSearchObject()
{
	//���C�h
	if (HitPlayerEyeObject(maidrobot.pos_x, maidrobot.pos_y, 64.0f, 128.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//��e�[�u��
	else if (HitPlayerEyeObject(720.0f, 380.0f, 460.0f, 360.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q�P
	else if (HitPlayerEyeObject(635.0f, 530.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q2
	else if(HitPlayerEyeObject(830.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q3
	else if (HitPlayerEyeObject(1005.0f, 780.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q4
	else if (HitPlayerEyeObject(1602.0f, 890.0f, 58.0f, 58.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�A�ؔ�
	else if (HitPlayerEyeObject(155.0f, 885.0f, 100.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//���v
	else if (HitPlayerEyeObject(225.0f, 120.0f, 70.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�\�t�@�[
	else if (HitPlayerEyeObject(705.0f, 140.0f, 515.0f, 135.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�d�b
	else if (HitPlayerEyeObject(1395.0f, 185.0f, 65.0f, 100.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�Ɩ�
	else if (HitPlayerEyeObject(1600.0f, 155.0f, 75.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	else
	{
		searchplayer.eyehit = false;
	}
}

void HitEyeSearchGameObject()
{
	//���{�b�g
	if (HitPlayerEyeObject(searchgamerobot.pos_x + 20.0f, searchgamerobot.pos_y + 64.0f, searchgamerobot.width - 30.0f, searchgamerobot.height - 42.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//��
	else if (HitPlayerEyeObject(700.0f, 500.0f, 64.0f, 64.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		neck.get = true;
	}
	//�x�b�h
	else if (HitPlayerEyeObject(480.0f, 755.0f, 265.0f, 146.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
		tochobject.bed = true;
	}
	//���e�[�u��
	else if(HitPlayerEyeObject(480.0f, 910.0f, 50.0f, 65.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.desk = true;
	}
	//��e�[�u��
	else if (HitPlayerEyeObject(1045.0f, 510.0f, 315.0f, 250.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q�P
	else if (HitPlayerEyeObject(990.0f, 610.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//�֎q2
	else if (HitPlayerEyeObject(1120.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//�֎q3
	else if (HitPlayerEyeObject(1240.0f, 775.0f, 40.0f, 40.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.chair = true;
	}
	//�A�ؔ��ƏƖ�
	else if (HitPlayerEyeObject(1175.0f, 185.0f, 175.0f, 105.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//�Ɩ�
	else if (HitPlayerEyeObject(1340.0f, 95.0f, 100.0f, 190.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//�\�y
	else if (HitPlayerEyeObject(460.0f, 35.0f, 125.0f, 255.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.light = true;
	}
	//�{�I
	else if (HitPlayerEyeObject(630.0f, 30.0f, 290.0f, 260.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		
		tochobject.bookshelf = true;
	}
	//�ʂ������
	else if (HitPlayerEyeObject(522.0f, 625.0f, 45.0f, 75.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		tochobject.doll = true;
	}
	else
	{
		tochobject.energy = false;
		tochobject.desk = false;
		tochobject.chair = false;
		tochobject.doll = false;
		tochobject.bed = false;
		tochobject.light = false;
		tochobject.flowerpot = false;
		tochobject.closet = false;
		tochobject.bookshelf = false;
		searchplayer.hit = false;
	}
}

void HitEyeTundereRoomObject()
{
	//���{�b�g
	if (HitPlayerEyeObject(mysterygamerobot.pos_x + 20.0f, mysterygamerobot.pos_y + 64.0f, mysterygamerobot.width - 30.0f, mysterygamerobot.height - 62.0f) == true
	    &&GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�x�b�h
	else if (HitPlayerEyeObject(465.0f, 865.0f, 265.0f, 146.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//��e�[�u��
	else if (HitPlayerEyeObject(1050.0f, 665.0f, 315.0f, 250.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q�P
	else if (HitPlayerEyeObject(1130.0f, 930.0f, 30.0f, 30.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q2
	else if (HitPlayerEyeObject(1250.0f, 930.0f, 30.0f, 30.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q3
	else if (HitPlayerEyeObject(1380.0f, 770.0f, 30.0f, 30.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�A�ؔ�
	else if (HitPlayerEyeObject(460.0f, 255.0f, 165.0f, 70.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�Ɩ�
	else if (HitPlayerEyeObject(460.0f, 800.0f, 85.0f, 185.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�\�t�@
	else if (HitPlayerEyeObject(695.0f, 170.0f, 245.0f, 110.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�\�y
	else if (HitPlayerEyeObject(1305.0f, 80.0f, 120.0f, 225.0f) == true && GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	else
	{
		searchplayer.eyehit = false;
	}
}

void HitEyeYuruhuwaRoomObject()
{
	//���{�b�g
	if (HitPlayerEyeObject(puzzlegamerobot.pos_x + 20.0f, puzzlegamerobot.pos_y + 64.0f, puzzlegamerobot.width - 30.0f, puzzlegamerobot.height - 62.0f) == true
		&& GetKeyDown(SPACE_KEY) == true)
	{
		searchplayer.eyehit = true;
	}
	//�x�b�h
	else if (HitPlayerEyeObject(475.0f, 745.0f, 145.0f, 255.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//���e�[�u��
	else if (HitPlayerEyeObject(1390.0f, 460.0f, 50.0f, 65.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//��e�[�u��
	else if (HitPlayerEyeObject(460.0f, 260.0f, 315.0f, 250.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q�P
	else if (HitPlayerEyeObject(540.0f, 525.0f, 30.0f, 30.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q2
	else if (HitPlayerEyeObject(660.0f, 525.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//�֎q3
	else if (HitPlayerEyeObject(790.0f, 360.0f, 35.0f, 30.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//�\�t�@
	else if (HitPlayerEyeObject(1040.0f, 185.0f, 245.0f, 130.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//�\�y
	else if (HitPlayerEyeObject(870.0f, 70.0f, 125.0f, 245.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//���v
	else if (HitPlayerEyeObject(1330.0f, 120.0f, 75.0f, 180.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//�L���r�l�b�g
	else if (HitPlayerEyeObject(1390.0f, 460.0f, 50.0f, 55.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	//�Ɩ�
	else if (HitPlayerEyeObject(1350.0f, 950.0f, 75.0f, 50.0f) == true)
	{
		searchplayer.eyehit = true;
	}
	else
	{
		searchplayer.eyehit = false;
	}
}

#pragma endregion 

void UpDataSearchGame()
{
	if (tochobject.light == true)
	{

	}
	if (tochobject.bed == true)
	{

	}
	else if (tochobject.bed == true && tochobject.light == true)
	{

	}
	if (tochobject.closet == true)
	{

	}
	else if (tochobject.bed == true && tochobject.light == true && tochobject.closet == true)
	{

	}
}


