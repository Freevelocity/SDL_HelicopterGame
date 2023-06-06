#pragma once

#include "../Physics/Vector2D.h"

#define UNI_MASS 1.0f;
#define Gravity 9.8f;

// #define FORWARD 1; ----> #define FORWARD 1 , because when you call it the (;) will be called aswell.

#define FORWARD 1
#define BACKWARD -1
#define UPWARD -1
#define DOWNWARD 1


class RigidBody
{
public:
	void Update(float dt)
	{
		m_Accelation.X = (m_Force.X + m_Friction.X) / m_Mass;
		m_Accelation.Y = (m_Gravity + m_Force.Y) / m_Mass;
		m_Velocity = m_Accelation * dt;
		m_Position = m_Velocity * dt;


		//std::cout << "Accelation in Y : " << m_Accelation.Y << std::endl;
	}

public:
	RigidBody() { m_Mass = UNI_MASS m_Gravity = Gravity }
	
public: // Setters
	inline void SetMass(float p_Mass) { m_Mass = p_Mass; }
	inline void SetGravity(float p_Gravity) { m_Gravity = p_Gravity; }

	inline void ApplyForce(Vector2D p_Force) { m_Force = p_Force; }
	inline void ApplyForceX(float p_Fx) { m_Force.X = p_Fx; }
	inline void ApplyForceY(float p_Fy) { m_Force.Y = p_Fy; }
	inline void UnSetForce() { m_Force = Vector2D(0, 0); }

	inline void ApplyFriction(Vector2D p_Friction) { m_Friction = p_Friction; }
	inline void UnSetFriction() { m_Friction = Vector2D(0, 0); }


public: // Getters
	inline float GetMass() { return m_Mass; }
	inline Vector2D Position() { return m_Position; }
	inline Vector2D Veloctiy() { return m_Velocity; }
	inline Vector2D Accelaration() { return m_Accelation; }

private:
	float m_Mass;
	float m_Gravity;

	Vector2D m_Force;
	Vector2D m_Friction;

	Vector2D m_Position;
	Vector2D m_Velocity;
	Vector2D m_Accelation;
};