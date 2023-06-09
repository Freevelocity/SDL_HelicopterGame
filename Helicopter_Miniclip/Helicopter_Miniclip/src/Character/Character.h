#pragma once

#include "../Object/GameObject.h"
#include<string>

class Character : public GameObject
{
public:
	Character(Properties* p_Props) : GameObject(p_Props) {}
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;

protected:
	std::string m_Name;
};