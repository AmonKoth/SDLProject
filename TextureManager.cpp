#include "TextureManager.h"


bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
	if (tempSurface == 0)
	{
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height,
						SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect; 
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::ClearFromTextureMap(std::string textureID)
{
	m_textureMap.erase("id");
}


TextureManager* TextureManager::s_pInstance = 0;