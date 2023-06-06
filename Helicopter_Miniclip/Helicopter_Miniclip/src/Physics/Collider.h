#pragma once

#include<SDL.h>

class Collider
{
public:
	inline SDL_Rect Get() { return m_Box; }
	inline void SetBuffer(int p_x, int p_y, int p_w, int p_h) { m_Buffer = { p_x,p_y,p_w,p_h }; }
	void Set(int p_x, int p_y, int p_w, int p_h)
	{
		m_Box = { p_x - m_Buffer.x , p_y - m_Buffer.y , p_w - m_Buffer.w , p_h - m_Buffer.h };
	}

private:
	SDL_Rect m_Box;
	SDL_Rect m_Buffer;
};
