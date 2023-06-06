#include "CollisionHandler.h"

CollisionHandler* CollisionHandler::m_CollisionInstance = nullptr;

CollisionHandler::CollisionHandler()
{

}



CollisionHandler* CollisionHandler::GetInstance()
{
	if (m_CollisionInstance == nullptr)
		m_CollisionInstance = new CollisionHandler();
	return m_CollisionInstance;
}


bool CollisionHandler::CheckCollision(SDL_Rect p_a, SDL_Rect p_b)
{
	bool x_overlaps = (p_a.x < p_b.x + p_b.w) && (p_a.x + p_a.w > p_b.x);
	bool y_overlaps = (p_a.y < p_b.y + p_b.h) && (p_a.y + p_a.h > p_b.y);

	return (x_overlaps && y_overlaps);

}