#include <iostream>
#include "TextureManger.h"
#include "../Camera/Camera.h"

// Need to apply the camera to the background. So
TextureManger* TextureManger::m_TextureMangerInstance = nullptr;

void TextureManger::Load(std::string p_id, std::string p_fileName)
{
	SDL_Surface* surface = IMG_Load(p_fileName.c_str());
	if (surface == nullptr)
	{
		std::cout << "Failed to Load Texture. Error: " << SDL_GetError() << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::Renderer, surface);
	m_TextureMap[p_id] = texture;


}


void TextureManger::Draw(std::string p_id, int p_x, int p_y, int p_width, int p_height,SDL_RendererFlip p_flip,
	float p_ScaleX, float p_ScaleY, float p_Rotation, float p_speedRation)
{

	SDL_Rect srcRect = { 0,0,p_width,p_height }; // This starts from the top-right corner of the image
	Vector2D cam = Camera::GetInstance()->GetPosition() * p_speedRation;
	SDL_Rect dstRect = { p_x - cam.X ,p_y - cam.Y,srcRect.w * p_ScaleX ,srcRect.h * p_ScaleY };

	SDL_RenderCopyEx(Engine::Renderer, m_TextureMap[p_id], &srcRect, &dstRect, p_Rotation,nullptr,p_flip);


}

void TextureManger::DrawFrame(std::string p_id, int p_x, int p_y, int p_width, int p_height, int p_row, int p_frame, SDL_RendererFlip p_flip,
	float p_ScaleX, float p_ScaleY, float p_Rotation , float p_SpeedRatio)
{
	SDL_Rect srcRect = { p_width* p_frame , p_row * p_height  ,p_width,p_height }; // This starts from the top-right corner of the image
	Vector2D cam = Camera::GetInstance()->GetPosition() * p_SpeedRatio;
	SDL_Rect dstRect = { p_x - cam.X ,p_y-cam.Y,srcRect.w * p_ScaleX ,srcRect.h* p_ScaleY };

	SDL_RenderCopyEx(Engine::Renderer, m_TextureMap[p_id], &srcRect, &dstRect, p_Rotation, nullptr, p_flip);
}

void TextureManger::Drop(std::string p_id)
{
	SDL_DestroyTexture(m_TextureMap[p_id]);
	m_TextureMap.erase(p_id);
}
void TextureManger::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
	{
		SDL_DestroyTexture(it->second);
	}
	m_TextureMap.clear();


	std::cout << "Cleaned Texture" << std::endl;
}


TextureManger* TextureManger::GetInstance()
{
	
		if (m_TextureMangerInstance == nullptr)
			m_TextureMangerInstance = new TextureManger();


		return m_TextureMangerInstance;
	
}

TextureManger::TextureManger()
{}

