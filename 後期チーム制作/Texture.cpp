
#include <stdlib.h>
#include "Texture.h"

// カテゴリごとのテクスチャ保存用配列
static TEXTURE_DATE** g_TextureList[MAX_TEXTURE_] = { nullptr };

// カテゴリのテクスチャ最大サイズの配列
int TextureCaterogySize[] = {
	TitleCategoryTextureList::TitleTextureMax,
	HelpCategoryTextureList::HelpTextureMax,
	MovieCategoryTextureList::MovieTextureMax,
	TalkCategoryTextureList::TalkTextureMax,
	PuzzleGameCategoryTextureList::PuzzleGameTextureMax,
	GameClearCategoryTextureList::GameClearTextureMax,
	GameOverCategoryTextureList::GameOverTextureMax,
};

// IDチェック
bool IsCategoryRangeCheck(int category_id, int texture_id);

//テクスチャ初期化
void InitTexture()
{
	AllReleaseTexture();

	for (int i = 0; i < MAX_TEXTURE_; i++)
	{
		g_TextureList[i] = (TEXTURE_DATE**)malloc(sizeof(TEXTURE_DATE*) * TextureCaterogySize[i]);

		for (int j = 0; j < TextureCaterogySize[i]; j++)
		{
			g_TextureList[i][j] = (TEXTURE_DATE*)malloc(sizeof(TEXTURE_DATE));
			g_TextureList[i][j]->Texture = nullptr;
		}
	}
}

#pragma region テクスチャ解放
void ReleaseCategoryTexture(int release_category)
{
	if (g_TextureList[release_category] == nullptr)
	{
		return;
	}

	for (int i = 0; i < TextureCaterogySize[release_category]; i++)
	{
		if (g_TextureList[release_category][i]->Texture == nullptr)
		{
			continue;
		}

		g_TextureList[release_category][i]->Texture->Release();
		g_TextureList[release_category][i]->Texture = nullptr;
	}
}

void AllReleaseTexture()
{

	for (int i = 0; i < MAX_TEXTURE_; i++)
	{
		ReleaseCategoryTexture(i);

		free(g_TextureList[i]);
		g_TextureList[i] = nullptr;
	}
}
#pragma endregion

bool IsCategoryRangeCheck(int category_id, int texture_id)
{
	if (category_id <= -1 ||
		category_id >= MAX_TEXTURE_)
	{
		return false;
	}

	if (texture_id <= -1 ||
		texture_id >= TextureCaterogySize[category_id])
	{
		return false;
	}

	return true;
}

//テクスチャ読み込み
bool LoadTexture(const char* file_name, int id, int texture_id)
{
	if (IsCategoryRangeCheck(id, texture_id) == false)
	{
		return false;
	}

	return CreateTexture(file_name, g_TextureList[id][texture_id]);
}

TEXTURE_DATE* GetTexture(int category_id, int texture_id)
{
	if (IsCategoryRangeCheck(category_id, texture_id) == false)
	{
		return nullptr;
	}
	return g_TextureList[category_id][texture_id];
}

