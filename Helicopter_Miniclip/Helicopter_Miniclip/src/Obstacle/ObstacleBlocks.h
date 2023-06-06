#pragma once

#include <string>
#include "../Physics/Collider.h"
#include "../Physics/Transform.h"
#include "../Object/GameObject.h"
#include <vector>

class ObstacleBlocks
{
public:
	ObstacleBlocks(Properties* p_Props, float p_VaryX = 1.0f, float p_VaryY = 1.0f, int p_SpaceBetween = 1) : m_Width(p_Props->Width), m_Height(p_Props->Height), m_TextureID(p_Props->TextureID)
	{
		m_x = p_Props->X;
		m_y = p_Props->Y;
		m_StartBoxX = p_Props->X;
		m_StartBoxY = p_Props->Y;
		m_Collider = new Collider();
		m_Collider->SetBuffer(0, 0, 0, 0);
		m_OuterBoxCollider = new Collider();
		m_OuterBoxCollider->SetBuffer(72, 20, 0, 0);
		m_TurrentRange = new Collider();
		m_TurrentRange->SetBuffer(0, 0, 0, 0);
		m_VaryX = p_VaryX;
		m_VaryY = p_VaryY;
		m_SpaceBetween = p_SpaceBetween;
	}
	void Draw();
	void Update();
	void Reset();

	Vector2D RandomSpawn();
	void DisplaceBox(ObstacleBlocks* p_OtherBox);
	

private:

public:
	inline SDL_Rect GetColliderReactInfo() { return m_BoxColliderReact; }
	inline void PlayerPosition(SDL_Rect Player) { m_PlayerColliderInfo = Player; }
	

public:
	Vector2D m_RandomDistance;

	
private:
	std::string m_TextureID;
	int m_ScaleX, m_ScaleY;
	int m_StartBoxX, m_StartBoxY;
	int m_x, m_y;
	int m_Width, m_Height;


	SDL_Rect m_PlayerColliderInfo;
	SDL_Rect m_BoxColliderReact;
	SDL_Rect m_OtherBoxReact;
	Collider* m_Collider;
	Collider* m_OuterBoxCollider;
	Collider* m_TurrentRange;

	Vector2D m_RandomValues;
	float m_VaryX , m_VaryY;
	int m_SpaceBetween;
	
};