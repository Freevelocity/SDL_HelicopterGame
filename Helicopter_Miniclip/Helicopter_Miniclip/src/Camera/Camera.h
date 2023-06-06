#pragma once
#include<SDL.h>
#include "../Physics/Point.h"
#include "../Physics/Vector2D.h"
#include "../Core/Engine.h"
class Camera
{

public:
	static Camera* GetInstance();
	void Update(float dt);
	void CameraReset(float p_StartValueX, float p_StartValueY);
public:
	inline SDL_Rect GetViewBox() { return m_ViewBox; }
	inline Vector2D GetPosition() { return m_Position; }
	inline Vector2D GetStickyPosition() { return m_StickyCamera; }

public:
	inline void SetTarget(Point* p_Target) { m_Target = p_Target; }
private:
	Camera();
	Point* m_Target;
	Vector2D m_Position;
	SDL_Rect m_ViewBox;
	Vector2D m_StickyCamera;
	static Camera* m_CameraInstance;


};

