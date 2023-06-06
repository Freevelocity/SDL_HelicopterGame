#include "../Obstacle/ObstacleBlocks.h"
#include "../Graphics/TextureManger.h"
#include "../Camera/Camera.h"
#include "../Collision/CollisionHandler.h"


bool Test = true;
void ObstacleBlocks::Draw()
{
	m_ScaleX = 4;
	m_ScaleY = 10;

	TextureManger::GetInstance()->Draw(m_TextureID, m_x, m_y, m_Width, m_Height, SDL_FLIP_NONE, m_ScaleX, m_ScaleY);
	
	SDL_Rect box = m_Collider->Get();
	m_BoxColliderReact = box;

	Vector2D cam = Camera::GetInstance()->GetPosition();
	SDL_Rect Box1 = m_OuterBoxCollider->Get();
	Box1.x -= cam.X;
	Box1.y -= cam.Y;
	SDL_RenderDrawRect(Engine::Renderer, &Box1);


}


Vector2D ObstacleBlocks::RandomSpawn()
{

	int ExtraValueX = ( (SCREEN_WIDTH/2 *m_VaryX) + m_PlayerColliderInfo.x);
	int ExtraValueY = (SCREEN_HEIGHT) - (m_Height * m_ScaleY);

	

	int RandomX = rand() % m_SpaceBetween + ExtraValueX;
	int RandomY = rand()% ExtraValueY;
	
	
	m_RandomDistance.X = RandomX;
	m_RandomDistance.Y = RandomY;


	//std::cout << "Random X : " << RandomX << std::endl;
	//std::cout << "Player Position X : " << m_PlayerColliderInfo.x << std::endl;
	//std::cout << "Extra Value : " << ExtraValueX << std::endl;



	return m_RandomValues =  Vector2D(RandomX, RandomY);

}

void ObstacleBlocks::Update()
{
	m_Collider->Set(m_x,m_y , m_Width * m_ScaleX, m_Height * m_ScaleY );
	m_OuterBoxCollider->Set(m_x, m_y, 200, (m_Height * m_ScaleY) + 50);


	if (m_x < Camera::GetInstance()->GetPosition().X - (m_Width* m_ScaleX) )
	{
		
		
			m_x = RandomSpawn().X;
			m_y = RandomSpawn().Y;
			//m_TurrentRange->Set(m_x, m_y - SCREEN_HEIGHT, -SCREEN_HEIGHT , SCREEN_WIDTH);
			Test = true;
			//std::cout << "Respawn Values X: " << m_x << " Y : " << m_y << std::endl;
			
			
		
		
		//std::cout << "Random Spawn Now" << std::endl;
	}


	



}



void ObstacleBlocks::DisplaceBox(ObstacleBlocks* p_OtherBox)
{
	if (CollisionHandler::GetInstance()->CheckCollision(m_OuterBoxCollider->Get(), p_OtherBox->m_OuterBoxCollider->Get()))
	{
		
		if (Test)
		{
			p_OtherBox->m_x = p_OtherBox->m_x + m_OuterBoxCollider->Get().w + 500;
			std::cout << "Value of Other Box X :  " << p_OtherBox->m_x << std::endl;
			std::cout << "Value of this Box X : " << m_x << std::endl;
			Test = false;
		}
	}
}

void ObstacleBlocks::Reset()
{
	m_x = m_StartBoxX;
	m_y = m_StartBoxY;
}


