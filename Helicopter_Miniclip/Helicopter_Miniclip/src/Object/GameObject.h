#pragma once
#include <SDL.h>
#include "../Object/IObject.h"
#include "../Physics/Transform.h"
#include "../Physics/Point.h"


struct Properties // Pass this to the constructor of the GameObject
{
	Properties(std::string p_TextureID, float p_x, float p_y, int p_wdith, int p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE)
	{
		X = p_x;
		Y = p_y;
		TextureID = p_TextureID;
		Width = p_wdith;
		Height = p_height;
		Flip = p_flip;
	}

public:
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;

};


class GameObject : public IObject
{
public:
	GameObject(Properties* p_Props) : m_Width(p_Props->Width), m_Height(p_Props->Height), m_TextureID(p_Props->TextureID),m_Flip(p_Props->Flip) 
	{
		m_Transform = new Transform(p_Props->X, p_Props->Y);
		float px = p_Props->X + p_Props->Width;
		float py = p_Props->Y + p_Props->Height;
		std::cout << "px : " << px << " " << "py: " << py << std::endl;
		m_StartX = px;
		m_StartY = py;
		m_Origin = new Point(px,py);
	}
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;

public:
	inline Point* GetOrigin() { return m_Origin; }
protected:				// This is accessable from the class that inherits GameObject
	int m_StartX, m_StartY;
	Point* m_Origin;
	Transform* m_Transform;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};