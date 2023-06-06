#include "ImageLayer.h"


ImageLayer::ImageLayer(std::string p_TextiureID, int p_x, int p_y, float p_ScrollRatio, float p_ScaleX, float p_ScaleY)
{
	m_TextureID = p_TextiureID;
	m_OffsetX = p_x;
	m_OffsetY = p_y;
	m_ScrollRatio = p_ScrollRatio;
	m_Repeated = true;
	m_ScaleX = p_ScaleX;
	m_ScaleY = p_ScaleY;
	QueryImage(m_TextureID);
}


//void ImageLayer::Render()
//{
//	TextureManger::GetInstance()->Draw(m_TextureID, m_OffsetX, m_OffsetY, m_ImgWidth, m_ImgHeight,m_Flip,m_ScaleX,m_ScaleY,0,m_ScrollRatio);
//}


void ImageLayer::QueryImage(std::string p_TextureID)
{
	SDL_Texture* texture = TextureManger::GetInstance()->GetTexture(m_TextureID);
	SDL_QueryTexture(texture, NULL, NULL, &m_ImgWidth, &m_ImgHeight);
}