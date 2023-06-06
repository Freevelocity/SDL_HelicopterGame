#pragma once
#include <string>
#include <SDL.h>
class Animation
{

public:
	//Animation();
	void Update();
	void Draw(float p_x, float p_y, int p_spritewidth, int p_spriteheight);
	void SetProps(std::string p_texture2D, int p_spriteRow, int p_framecount, int p_animSpeed, SDL_RendererFlip p_flip = SDL_FLIP_NONE, int p_ScaleX = 1.0f,int p_ScaleY = 1.0f);

private:
	int m_SpriteRow, m_SpriteFrame;
	int m_AnimSpeed, m_FrameCount;
	int m_ScaleX, m_ScaleY;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};

