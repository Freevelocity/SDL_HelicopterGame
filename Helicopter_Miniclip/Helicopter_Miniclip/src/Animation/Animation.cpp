#include "Animation.h"
#include "../Graphics/TextureManger.h"


void Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount; // This % m_FrameCount is so that it loops back on itself
}
void Animation::Draw(float p_Dstx, float p_Dsty, int p_spritewidth, int p_spriteheight)
{
	TextureManger::GetInstance()->DrawFrame(m_TextureID, p_Dstx, p_Dsty, p_spritewidth, p_spriteheight,m_SpriteRow,m_SpriteFrame,m_Flip,m_ScaleX,m_ScaleY);
}
void Animation::SetProps(std::string p_textureID, int p_spriteRow, int p_framecount, int p_animSpeed, SDL_RendererFlip p_flip, int p_ScaleX , int p_ScaleY)
{
	m_TextureID = p_textureID;
	m_SpriteRow = p_spriteRow;
	m_FrameCount = p_framecount;
	m_AnimSpeed = p_animSpeed;
	m_Flip = p_flip;
	m_ScaleX = p_ScaleX;
	m_ScaleY = p_ScaleY;
}