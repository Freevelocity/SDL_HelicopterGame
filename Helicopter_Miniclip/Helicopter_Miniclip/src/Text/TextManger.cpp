#include "TextManger.h"
#include <iostream>
TextManger* TextManger::m_Instance = nullptr;

TextManger* TextManger::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new TextManger();
	return m_Instance;
}


void TextManger::Init(std::string p_FilePlace, int p_Size)
{
	TTF_Init();	
	m_Fonts = TTF_OpenFont(p_FilePlace.c_str(), p_Size);


}


void TextManger::Update(std::string p_UpdateMessage, SDL_Color p_FontColor, int p_ScreenLocationX, int p_ScreenLocationY)
{
	
	m_textSurface = TTF_RenderText_Solid(m_Fonts, p_UpdateMessage.c_str(), p_FontColor);
	m_FontTexture = SDL_CreateTextureFromSurface(Engine::GetInstance()->Renderer, m_textSurface);
	m_FontPlace = { p_ScreenLocationX,p_ScreenLocationY,m_textSurface->w, m_textSurface->h };
	SDL_FreeSurface(m_textSurface);
	
}

void TextManger::Render()
{
	SDL_RenderCopy(Engine::GetInstance()->Renderer, m_FontTexture, NULL,&m_FontPlace);
	SDL_DestroyTexture(m_FontTexture);
}

void TextManger::Clear()
{
	
}