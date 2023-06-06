#pragma once
#include <SDL.h>
#include <vector>
#include "../Core/Engine.h"

class CollisionHandler
{
public:
	bool CheckCollision(SDL_Rect p_a, SDL_Rect p_b);
	static CollisionHandler* GetInstance();

private:
	CollisionHandler();
	static CollisionHandler* m_CollisionInstance;

};

