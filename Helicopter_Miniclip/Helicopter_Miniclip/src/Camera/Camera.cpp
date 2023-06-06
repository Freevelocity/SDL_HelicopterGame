#include "Camera.h"


Camera* Camera::m_CameraInstance = nullptr;

Camera::Camera()
{
	m_ViewBox = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
}

Camera* Camera::GetInstance()
{
	if (m_CameraInstance == nullptr)
		m_CameraInstance = new Camera;
	return m_CameraInstance;
}



void Camera::Update(float dt)
{
	if (m_Target != nullptr)
	{
		m_ViewBox.x = m_Target->X - SCREEN_WIDTH / 2;
		m_ViewBox.y = m_Target->Y - SCREEN_HEIGHT / 2;
		//std::cout << "Camera Postion: X ( " << m_ViewBox.x << " )  : Y ( " << m_ViewBox.y << " ) " << std::endl;
		if (m_ViewBox.x < 0)
		{
			m_ViewBox.x = 0;
		}
		if (m_ViewBox.y < 0)
		{
			m_ViewBox.y = 0;
		}
		

		if (m_ViewBox.x > 100*SCREEN_WIDTH)
		{
			m_ViewBox.x = SCREEN_WIDTH;
			m_StickyCamera = Vector2D(m_ViewBox.x - m_Position.X, m_ViewBox.y - m_Position.Y);
		}
		if (m_ViewBox.y > (SCREEN_HEIGHT - m_ViewBox.h))
		{
			m_ViewBox.y = (SCREEN_HEIGHT - m_ViewBox.h);
		}

		m_Position = Vector2D(m_ViewBox.x, m_ViewBox.y);
		
	}
}


void Camera::CameraReset(float p_StartValueX, float p_StartValueY)
{
	m_ViewBox.x = p_StartValueX - SCREEN_WIDTH / 2;
	m_ViewBox.y = p_StartValueY - SCREEN_HEIGHT / 2;
	std::cout << "Camera Postion: X ( " << m_ViewBox.x << " )  : Y ( " << m_ViewBox.y << " ) " << std::endl;
}