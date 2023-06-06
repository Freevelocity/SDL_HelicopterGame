#pragma once
#include<string>
#include "../Physics/Collider.h"
#include "../Physics/Transform.h"
#include "../Object/GameObject.h"
#include "../Graphics/TextureManger.h"


struct Bullet
{
	std::string m_TextureID = "Bullet";
	int x, y;
	int m_Width, m_Height;
	float angle;
	Collider* m_Collider;


};

