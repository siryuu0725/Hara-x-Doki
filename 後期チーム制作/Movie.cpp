#include <stdio.h>
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"
#include "Bg.h"
#include "Text.h"

void InitMovieScene();

void MainMovieScene();

extern MoviePlayerDate movieplayer;

SceneId FinishMovieScene();


SceneId UpdateMovieScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitMovieScene();
		break;
	case SceneStep::MainStep:
		MainMovieScene();
		break;
	case SceneStep::EndStep:
		return FinishMovieScene();
		break;
	}

	return SceneId::MovieScene;
}

void DrawMovieScene()
{
	DrawMovieBg();
	DrawMoviePlayer();
}

void InitMovieScene()
{
	LoadTexture("Res/�O��.png", TEXTURE_MOVIE, MovieCategoryTextureList::MovieBgTex);
	LoadTexture("Res/�L����/��l�������t�@�C��.png", TEXTURE_MOVIE, MovieCategoryTextureList::MoviePlayerTex);
	InitMovieBg();
	InitMoviePlayer();
	
	ChangeSceneStep(SceneStep::MainStep);
}

void MainMovieScene()
{
	
	UpDateMoviePlayer();
	UpDateBg();
	
	if (movieplayer.pos_y < -200.0f)//��ʒ[�ɍs���ƕς��
	{
		moviebgdate.endmovie = true;
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishMovieScene()
{
	ReleaseCategoryTexture(TEXTURE_MOVIE);

	return SceneId::LargeRoomScene;

}
