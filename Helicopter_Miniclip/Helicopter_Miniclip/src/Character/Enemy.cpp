#include "Enemy.h"
#include "../Physics/Math.h"
#include "Bullet.h"
#include "../Camera/Camera.h"
#include "../Collision/CollisionHandler.h"




std::vector<Bullet> bulletArray1;
Bullet bulletTmp1;


Enemy::Enemy(Properties* p_Props) : Character(p_Props)
{
	m_Animation = new Animation;
	m_Transform->X = 0;
	m_Transform->Y = 0;
	bulletTmp1.m_Collider = new Collider();
	m_TurrentRange = new Collider();
	m_TurrentRange->SetBuffer(0, 0, 0, 0);
	m_Animation->SetProps(m_TextureID, 0, 4, 50, m_Flip, 2, 2);
}


void Enemy::SetPosition(Vector2D p_Position)
{
	m_Transform->X = p_Position.X - 10;
	m_GunPosX = m_Transform->X + 15;

	
	//std::cout << "Plane Postion Y : " << p_Position.Y - (m_Height + 50) << std::endl;
	if (p_Position.Y - (m_Height + 50) > 10)
	{

		m_Transform->Y = p_Position.Y - (m_Height + 45);
		m_GunPosY = m_Transform->Y + 15;
		m_Flip = SDL_FLIP_NONE;
		
	
	}
	else
	{
		m_Flip = SDL_FLIP_VERTICAL;
		m_GunPosY = m_Transform->Y - 10;
		m_Transform->Y = p_Position.Y + (350);
	
	}
	Vector2D cam = Camera::GetInstance()->GetPosition();
	m_TurrentRange->Set(m_GunPosX, SCREEN_HEIGHT, -500, -1000);

}

void Enemy::GunLogic(Transform* p_Player, float dt, SDL_Rect p_PlayerCollider)
{

	m_GunDistanceX = m_GunPosX - p_Player->X;
	m_GunDistanceY = m_GunPosY - p_Player->Y;

	m_playerBox = p_PlayerCollider;
	PlayerDetection();
	m_GunRotation = Math::Clamp(atan2(m_GunDistanceY, m_GunDistanceX) * 180 / 3.14,-50,50);
	float GunAngle = atan2(m_GunDistanceY, m_GunDistanceX);
	//std::cout << m_IsShooting << std::endl;
	if (m_IsShooting)
	{
		bulletTmp1.angle = GunAngle;
		bulletTmp1.x = m_GunPosX - 15 * cos(GunAngle * 0.1); // The +15 and 0.1 is to adjust the spread and location of the bullet
		bulletTmp1.y = m_GunPosY - 100 * sin(GunAngle * 0.1);
		bulletTmp1.m_Collider->SetBuffer(0, 0, 0, 0);
		bulletArray1.push_back(bulletTmp1);
		m_GunShootSpeed = 0;
		
	}
	else
	{
		
		m_GunShootSpeed -= 0.01;
	}
	
	
}

void Enemy::PlayerDetection()
{
	/*std::cout << "Player Box Width : " << m_playerBox.x + m_playerBox.w << std::endl;
	std::cout << "Turrent Value X : " << m_TurrentRange->Get().x + m_TurrentRange->Get().w << std::endl;*/

	bool XoverLap = (m_playerBox.x + m_playerBox.w > m_TurrentRange->Get().x + m_TurrentRange->Get().w)
		&& (m_playerBox.x + m_playerBox.w < m_TurrentRange->Get().x);

	bool YOverLap = (m_playerBox.y + m_playerBox.h > m_TurrentRange->Get().y + m_TurrentRange->Get().h)
		&& (m_TurrentRange->Get().y + m_TurrentRange->Get().h > m_playerBox.y);
	if (XoverLap)
	{
		m_IsShooting = true;
	}
	else
	{
		m_IsShooting = false;
	}
	
}

void Enemy::Update(float dt)
{
	
}


void Enemy::Draw()
{
	TextureManger::GetInstance()->Draw(m_TextureID, m_Transform->X,m_Transform->Y, m_Width, m_Height, m_Flip, 4, 4);
	TextureManger::GetInstance()->Draw("Gun", m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Flip, 4, 4, m_GunRotation);
	for (int i = 0; i < bulletArray1.size(); i++)
	{
		bulletArray1[i].x -= 5 * cos(bulletArray1[i].angle);
		bulletArray1[i].y -= 5 * sin(bulletArray1[i].angle);


		bulletArray1[i].m_Collider->Set(bulletArray1[i].x, bulletArray1[i].y, 9, 5);
		TextureManger::GetInstance()->Draw("TurrentBullet", bulletArray1[i].x, bulletArray1[i].y, 18, 10, SDL_FLIP_NONE, 0.5, 0.5);

	}
	Vector2D cam = Camera::GetInstance()->GetPosition();
	SDL_Rect Box1 = m_TurrentRange->Get();
	Box1.x -= cam.X;
	Box1.y -= cam.Y;
	SDL_RenderDrawRect(Engine::Renderer, &Box1);
}
	

void Enemy::Clean()
{

}
