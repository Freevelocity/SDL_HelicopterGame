#pragma once
#include <SDL.h>
class Menu
{

public:
	bool Init();
	bool Exit();
	void Update();
	void Render();

private:
	static void StartGame();
	static void Settings();
	static void Quit();

private:
	SDL_Renderer* m_Ctxt;
};

