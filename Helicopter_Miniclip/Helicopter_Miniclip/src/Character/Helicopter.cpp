#include "../Character/Helicopter.h"
#include "../Graphics/TextureManger.h"
#include "../Inputs/Input.h"
#include "../Camera/Camera.h"
#include "../Collision/CollisionHandler.h"
#include "../Obstacle/ObstacleBlocks.h"
#include "../Character/Bullet.h"
#include "../Physics/Math.h"
std::vector<Bullet> bulletArray;
Bullet bulletTmp;

Helicopter::Helicopter(Properties* p_Props) : Character(p_Props)
{
	
	m_Animation = new Animation;
	m_RigidBody = new RigidBody;
	m_Collider = new Collider();
	m_Collider->SetBuffer(-120, -100, 150, 200); // -50 . -30
	bulletTmp.m_Collider = new Collider();
	m_RigidBody->SetGravity(5);
	m_Animation->SetProps(m_TextureID,0,4,50,SDL_FLIP_NONE, 2, 2);

}


void Helicopter::PlayerStartFlying()
{
	m_IsFlying = true;
}


void Helicopter::Draw()
{
	m_Animation->Draw(m_Transform->X,m_Transform->Y,m_Width,m_Height); // This is using TextureManger DrawFrma

	for (int i = 0; i < bulletArray.size(); i++)
	{
		bulletArray[i].x += 10 * cos(bulletArray[i].angle);
		bulletArray[i].y += 10 * sin(bulletArray[i].angle);


		bulletArray[i].m_Collider->Set(bulletArray[i].x, bulletArray[i].y, 9, 5);
		TextureManger::GetInstance()->Draw(bulletTmp.m_TextureID, bulletArray[i].x, bulletArray[i].y, 18, 10, SDL_FLIP_NONE, 0.5, 0.5);

	}

	

	Vector2D cam = Camera::GetInstance()->GetPosition();
	SDL_Rect box = m_Collider->Get();
	box.x -= cam.X;
	box.y -= cam.Y;
	SDL_RenderDrawRect(Engine::Renderer, &box);
	
}
void Helicopter::Update(float dt)
{
		


	if (!m_IsFlying)
	{
		m_RigidBody->UnSetForce();

	}
	else
	{

		m_Score += ((m_Origin->X - m_Transform->X)/100);
		if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
		{
			m_RigidBody->ApplyForceY(15 * UPWARD);
			
		}


		m_RigidBody->Update(0.5);
		m_RigidBody->ApplyForceX(15);
		m_RigidBody->ApplyForceY(4 * DOWNWARD);

		m_Transform->TranslateX(m_RigidBody->Position().X);
		m_Transform->TranslateY(m_RigidBody->Position().Y);

	
		m_Collider->Set(m_Transform->X, m_Transform->Y, 128*2, 128*2);

		if (Input::GetInstance()->BulletFire())
		{
		
			ShootGun();

			
		}

		m_Origin->X = m_Transform->X + m_Width / 2;
		m_Origin->Y = m_Transform->Y + m_Height / 2;
		Helicopter::AnimationState();

		if (m_Score > m_HighScore)
		{
			m_HighScore = m_Score;
			
		}

		//std::cout << "Transfrom Y : " << m_Transform->Y << std::endl;

		PlayerBoundaries();
		m_Animation->Update();  // Loops throught the frames
	}
		
	

}


void Helicopter::PlayerBoundaries()
{
	if (m_Transform->Y > SCREEN_HEIGHT - 150)
	{

		m_Transform->Y = SCREEN_HEIGHT - 150;

	}
	if (m_Transform->Y < -90)
	{

		m_Transform->Y = -90;

	}

}
std::string Helicopter::GetScore()
{
	std::string s = std::to_string(m_HighScore);
	s = "HighScore: " + s;
	return s.c_str();
}

void Helicopter::AnimationState()
{
	if (!m_IsFlying)
	{
		m_Animation->SetProps("Player", 0, 1, 100,SDL_FLIP_NONE,1.5,1.5);

	}
}


void Helicopter::PlayerDeath()
{
	m_IsFlying = false;
	m_Score = 0;
}


void Helicopter::PlayerReset()
{
	m_Transform->X = m_StartX;
	m_Transform->Y = m_StartY;

	m_Origin->X = m_StartX;
	m_Origin->Y = m_StartY;

	m_Collider->Set(m_Transform->X, m_Transform->Y, 64, 64);

}




Vector2D Helicopter::PlaceManInPlane()
{
	m_ManX = m_Origin->X + 100-Camera::GetInstance()->GetPosition().X;
	m_ManY = m_Origin->Y + 50 -Camera::GetInstance()->GetPosition().Y;

	int mouseX = 0;
	int mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	m_BulletStartX = (m_Origin->X + 110);
	m_BulletStartY = (m_Origin->Y + 68);


	BulletDistanceX = mouseX - m_BulletStartX + Camera::GetInstance()->GetPosition().X; // Negates the Camera Effect on the Bullets
	BulletDistanceY = mouseY - m_BulletStartY + Camera::GetInstance()->GetPosition().Y;

	
	m_ManInPlaneRotation = Math::Clamp(atan2(BulletDistanceY, BulletDistanceX)*180/3.14,-20,27);
	BulletAngle = Math::Clamp(atan2(BulletDistanceY, BulletDistanceX),-0.70,0.70);

	//std::cout << "Transform  " << m_ManX  << std::endl;
	//SDL_RenderDrawLine(Engine::Renderer, m_BulletStartX, m_BulletStartY, mouseX, mouseY);

	return Vector2D(m_ManX, m_ManY);
}


void Helicopter::ShootGun()
{
	
	
	bulletTmp.angle = BulletAngle;
	bulletTmp.x = m_BulletStartX + 15 * cos(BulletAngle*0.1); // The +15 and 0.1 is to adjust the spread and location of the bullet
	bulletTmp.y = m_BulletStartY + 100 * sin(BulletAngle*0.1);
	bulletTmp.m_Collider->SetBuffer(0, 0, 0, 0);
	

	bulletArray.push_back(bulletTmp);
	//std::cout << "Bullet Array Size : " << bulletArray.size() << std::endl;
}


void Helicopter::Clean()
{
	TextureManger::GetInstance()->Clean();
}