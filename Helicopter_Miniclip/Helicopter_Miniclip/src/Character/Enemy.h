#pragma once
#include <SDL.h>
#include "../Character/Character.h"
#include "../Animation/Animation.h"
#include "../Physics/RigidBody.h"
#include "../Physics/Collider.h"
#include "../Obstacle/ObstacleBlocks.h"
#include "../Graphics/TextureManger.h"


class Enemy : public Character
{
public:
	Enemy(Properties* p_Props);

	void SetPosition(Vector2D p_Position = 0);
	void GunLogic(Transform* p_Player, float dt, SDL_Rect p_PlayerCollider);
	void PlayerDetection();
	virtual void Draw();
	virtual void Update(float dt);
	virtual void Clean();


	SDL_Rect m_playerBox;
private:

	Collider* m_TurrentRange;

	Animation* m_Animation;



	int m_GunPosX, m_GunPosY;
	int m_GunBulletX, m_GunBulletY;
	float m_GunShootSpeed = 5;
	bool m_IsShooting = false;
	float m_GunDistanceX, m_GunDistanceY;
	float m_GunRotation;

};

