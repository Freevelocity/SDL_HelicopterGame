#pragma once
// Can't Create A Singelaton of the Engine class (Not Sure why)  -> Come back to it --> Fixed it by creating the GetInstace() in the cpp file and putting the constructer there to
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define SCREEN_WIDTH 1280	
#define SCREEN_HEIGHT 720

class Engine
{

public:

	static Engine* GetInstance();
	void Init(const char* p_title, int p_width, int p_height, bool p_isFullscreen);
	void Events();
	void Update();
	void Render();
	void Clean();
	void Quit();

public:
	inline bool IsRunning() { return m_isRunning; }
public:
	static SDL_Renderer* Renderer; // Probably don't need this as the Engine is now a Singelaton

private:
	Engine();
	static Engine* m_EngineInstance;
	SDL_Window* m_Window;
	bool m_isRunning = false;

	
};

