#pragma once

#include "../Core/Engine.h"

#include<SDL.h>
#include <SDL_image.h>
#include<string>
#include<map>



class TextureManger
{

public:
	
	void Load(std::string p_id,std::string p_fileName);
	void Drop(std::string p_id);
	void Clean();

	void Draw(std::string p_id, int p_x, int p_y, int p_width, int p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE,
		float p_ScaleX = 1.0f, float p_ScaleY = 1.0f, float p_Rotation = 0.0f, float p_speedRation = 1.0f); // Static Image
	void DrawFrame(std::string p_id, int p_x, int p_y, int p_width, int p_height,int p_row,int p_frame, SDL_RendererFlip p_flip = SDL_FLIP_NONE,
		float p_ScaleX = 1.0f, float p_ScaleY = 1.0f, float p_Rotation = 0.0f, float p_SpeedRatio = 1.0f); // Sprite Sheet

public:
	SDL_Texture* GetTexture(std::string p_TextureID) { return m_TextureMap[p_TextureID]; }

public:
	static TextureManger* GetInstance();


private:	
	TextureManger();
	static TextureManger *m_TextureMangerInstance;
	std::map<std::string, SDL_Texture*> m_TextureMap;

};

