#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL_image.h>
#include <SDL.h>
#include <iostream>
#include <map>

class TextureManager
{


public:
	~TextureManager() {}


	bool Load(std::string fileName, std::string id,	SDL_Renderer* pRenderer);
	
	void Draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	static TextureManager* s_pInstance;

	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:

	std::map<std::string, SDL_Texture*> m_textureMap;
	
	TextureManager() {}

};



typedef TextureManager TheTextureManager;


#endif // !TEXTURE_MANAGER_H
