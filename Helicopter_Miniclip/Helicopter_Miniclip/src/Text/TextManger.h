#pragma once
#include "../Core/Engine.h"
#include <vector>
#include <string>
class TextManger
{
public:
	static TextManger* GetInstance();
	void Init(std::string p_FilePlace, int p_Size);
	void Update(std::string p_UpdateMessage, SDL_Color p_FontColor, int p_ScreenLocationX, int p_ScreenLocationY);
	void Render();
	void Clear();
private:
	static TextManger* m_Instance;
	TTF_Font* m_Fonts;
	SDL_Texture* m_FontTexture;
	SDL_Surface* m_textSurface;
	SDL_Rect m_FontPlace;
};

