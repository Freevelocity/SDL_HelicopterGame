#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "../Map/Layer.h"
#include "../Graphics/TextureManger.h"
class ImageLayer
{
public:
	ImageLayer(std::string p_TextiureID, int p_x, int p_y, float p_ScrollRatio = 1.0f, float p_ScaleX = 1.0f, float p_ScaleY = 1.0f);
	void QueryImage(std::string TextureID);


public:
	void SetScrollRatio(float p_ScrollRatio) { m_ScrollRatio = p_ScrollRatio; }
	void SetOffset(int p_x, int p_y) { m_OffsetX = p_x; m_OffsetY = p_y; }
	void SetRepeated(bool p_Repeated) { m_Repeated = p_Repeated; }
private:
	bool m_Repeated;
	float m_ScrollRatio;
	std::string m_TextureID;
	float m_ScaleX, m_ScaleY;
	int m_OffsetX, m_OffsetY;
	int m_ImgWidth, m_ImgHeight;
	SDL_RendererFlip m_Flip;

};

