#include<iostream>
#include <vector>
#include "Engine.h"
#include "../Graphics/TextureManger.h"
#include "../Physics/Vector2D.h"
#include "../Physics/Transform.h"
#include "../Character/Helicopter.h"
#include "../Inputs/Input.h"
#include "../Timer/Timer.h"
#include "../Camera/Camera.h"
#include "../Map/ImageLayer.h"
#include "../Obstacle/ObstacleBlocks.h"
#include "../Collision/CollisionHandler.h"
#include "../Text/TextManger.h"
#include "../Character/Bullet.h"
#include "../Character/Enemy.h"

// Renderer Flags about how the renderer should work. 
// SDL_RENDERER_PRESENTVSYNC we want it to be syncronihed with framerate of our screen


Engine* Engine::m_EngineInstance = nullptr;
SDL_Renderer* Engine::Renderer = nullptr;
Helicopter* player = nullptr;
ObstacleBlocks* GrassBlock = nullptr;
ObstacleBlocks* GrassBlock2 = nullptr;
Enemy* Plane = nullptr;


Engine::Engine(){}

Engine* Engine::GetInstance()
{
	if (m_EngineInstance == nullptr)
		m_EngineInstance = new Engine();

	return m_EngineInstance;
}



void Engine::Init(const char* p_title, int p_width, int p_height, bool p_isFullscreen)
{
	int flags = 0;
	if (p_isFullscreen)
		flags = SDL_WINDOW_FULLSCREEN;


	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
	{
		std::cout << "Failed to Initialize. Error: " << SDL_GetError() << std::endl;
	}

	m_Window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_width, p_height, flags);

	if (m_Window == nullptr) // if Window was not created
	{
		std::cout << "Failed to Create Window. Error: " << SDL_GetError() << std::endl;
	}

	Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Renderer == nullptr) // if Render was not created
	{
		std::cout << "Failed to Create Renderer. Error: " << SDL_GetError() << std::endl;
	}

	if (TTF_Init() == -1)
	{
		std::cout << "Failed to Init TTF. Error: " << SDL_GetError() << std::endl;
	}
	

	TextureManger::GetInstance()->Load("Player", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/HelicopterAnimation.png");
	TextureManger::GetInstance()->Load("PlayerInPlane", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/ManInPlane.png");
	TextureManger::GetInstance()->Load("Bullet", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/Bullet.png");
	TextureManger::GetInstance()->Load("BackgroundMountain", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/BackgroundMountain.png");
	TextureManger::GetInstance()->Load("BackgroundMountain2", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/BackgroundMountain2.png");
	TextureManger::GetInstance()->Load("BackgroundMountainC", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/BackgroundMountain-C.png");
	TextureManger::GetInstance()->Load("BackgroundMountain2C", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/BackgroundMountain2-C.png");

	TextureManger::GetInstance()->Load("BackgroundSky", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/LevelsToThis.png");


	TextureManger::GetInstance()->Load("Block", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/ObBlock.png");
	TextureManger::GetInstance()->Load("Stand", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/Standt.png");
	TextureManger::GetInstance()->Load("Gun", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/Gun.png");
	TextureManger::GetInstance()->Load("TurrentBullet", "C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/gfx/TurretBullet.png");

	
	TextManger::GetInstance()->Init("C:/Users/moham/Desktop/C++ Games/Helicopter_Miniclip/Helicopter_Miniclip/Assests/fonts/Cocogoose2.ttf", 40);

	player = new Helicopter(new Properties("Player",100,200,128,128));
	GrassBlock = new ObstacleBlocks(new Properties("Block", 1280,  0, 18, 35));
	GrassBlock2 = new ObstacleBlocks(new Properties("Block", 1280, SCREEN_HEIGHT -200 , 18, 35),2,1,300);
	Plane = new Enemy(new Properties("Stand", 0, 0, 21, 16));
	

	Camera::GetInstance()->SetTarget(player->GetOrigin());
	
	m_isRunning = true;
}
void Engine::Events()
{
	Input::GetInstance()->Listen();



}
void Engine::Update()
{
	float dt = Timer::GetInstance()->GetDeltaTime();
	player->Update(dt);
	GrassBlock->Update();
	GrassBlock2->Update();
	GrassBlock->DisplaceBox(GrassBlock2);
	GrassBlock2->DisplaceBox(GrassBlock);
	GrassBlock->PlayerPosition(player->GetColliderReactInfo());
	GrassBlock2->PlayerPosition(player->GetColliderReactInfo());
	Plane->SetPosition(GrassBlock->m_RandomDistance);
	Plane->GunLogic(player->GetPlayerTransform(),dt,player->GetColliderReactInfo());
	
	if (CollisionHandler::GetInstance()->CheckCollision(player->GetColliderReactInfo(), GrassBlock->GetColliderReactInfo()))
	{
		player->PlayerDeath();
		if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			player->PlayerReset();
			//Camera::GetInstance()->CameraReset(player->GetStartX(), player->GetStartY());
			SDL_Delay(200);
			player->SetFlightTrue();
			GrassBlock->Reset();
			GrassBlock2->Reset();
			std::cout << "Done" << std::endl;
		}
	}
	if (CollisionHandler::GetInstance()->CheckCollision(player->GetColliderReactInfo(), GrassBlock2->GetColliderReactInfo()))
	{
		player->PlayerDeath();
		if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			player->PlayerReset();
			//Camera::GetInstance()->CameraReset(player->GetStartX(), player->GetStartY());
			SDL_Delay(200);
			player->SetFlightTrue();
			GrassBlock->Reset();
			GrassBlock2->Reset();
			std::cout << "Done" << std::endl;
		}
	
	}
	
	////std::cout << "ViewBox Postion: X ( " << Camera::GetInstance()->GetPosition().X << " )  : Y ( " << Camera::GetInstance()->GetPosition().Y << " ) " << std::endl;
	TextManger::GetInstance()->Update(player->GetScore(), {0,0,0,0}, 0, 0);
	Camera::GetInstance()->Update(dt);
}

void Engine::Render()
{
	SDL_RenderClear(Renderer);
	TextureManger::GetInstance()->Draw("BackgroundSky",Camera::GetInstance()->GetStickyPosition().X, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_FLIP_NONE, 1, 1, 0, 0);
	//TextureManger::GetInstance()->Draw("BackgroundMountain2", Camera::GetInstance()->GetStickyPosition().X, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_FLIP_NONE, 1, 1, 0, 0);
	//TextureManger::GetInstance()->Draw("BackgroundMountain", Camera::GetInstance()->GetStickyPosition().X, 0, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_FLIP_NONE,1, 1, 0, 0);
	//TextureManger::GetInstance()->Draw("BackgroundMountainC", Camera::GetInstance()->GetStickyPosition().X, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_FLIP_NONE, 1, 1, 0,0);
	//TextureManger::GetInstance()->Draw("BackgroundMountain2C", Camera::GetInstance()->GetStickyPosition().X, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_FLIP_NONE, 1, 1, 0, 0);
	GrassBlock->Draw();
	GrassBlock2->Draw();
	player->Draw();
	Plane->Draw();
	
	
	TextureManger::GetInstance()->Draw("PlayerInPlane",player->PlaceManInPlane().X, player->PlaceManInPlane().Y, 14, 18, SDL_FLIP_NONE, 2, 2, player->GetManRotation(), 0);
	//Bullets->Render();
	TextManger::GetInstance()->Render();
;

	SDL_RenderPresent(Renderer);
}


void Engine::Clean()
{
	TextureManger::GetInstance()->Clean();
	TextManger::GetInstance()->Clear();
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(Renderer);
	IMG_Quit();
	SDL_Quit();

}
void Engine::Quit()
{
	m_isRunning = false;
}