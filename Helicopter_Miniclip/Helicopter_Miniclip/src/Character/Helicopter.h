#pragma once

#include "../Character/Character.h"
#include "../Animation/Animation.h"
#include "../Physics/RigidBody.h"
#include "../Physics/Collider.h"

class Helicopter : public Character
{
public:
	Helicopter(Properties* p_Props);
	virtual void Draw();
	virtual void Update(float dt);
	virtual void Clean();

	void PlayerDeath();
	void PlayerStartFlying();
	std::string GetScore();
	void PlayerReset();
	void PlayerBoundaries();

public: // Man in Plane
	Vector2D PlaceManInPlane();
	void ShootGun();
public:
	inline float GetManRotation() { return m_ManInPlaneRotation; }

public:
	inline SDL_Rect GetColliderReactInfo() { return m_Collider->Get(); }
	inline int GetStartX() { return m_StartX; }
	inline int GetStartY() { return m_StartY; }
	inline Transform* GetPlayerTransform() { return m_Transform; }
public:
	inline bool SetFlightTrue() { return m_IsFlying = true; }
private:
	void AnimationState();
private:
	bool m_IsFlying = true;
	int m_HighScore;
	float m_Score;
	Collider* m_Collider;
	Animation* m_Animation;
	RigidBody* m_RigidBody;



private: // Man In Plane Position
	int m_ManX, m_ManY;
	float m_ManInPlaneRotation;
	float m_BulletStartX, m_BulletStartY;
	float BulletAngle;
	float BulletDistanceX, BulletDistanceY;



};