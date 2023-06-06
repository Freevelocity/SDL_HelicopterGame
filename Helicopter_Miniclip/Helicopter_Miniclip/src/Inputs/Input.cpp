#include "Input.h"
#include "../Core/Engine.h"
#include <iostream>


Input* Input::m_InputInstance = nullptr;

Input::Input()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::Listen()
{
	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
			case SDL_QUIT:
				Engine::GetInstance()->Quit();
				break;
			case SDL_KEYDOWN:
				KeyDown();
				break;
			case SDL_KEYUP:
				KeyUp();
				//std::cout << "Key is Up" << std::endl;
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_FireBullet = true;
				break;
			case SDL_MOUSEBUTTONUP:
				m_FireBullet = false;
				break;
		}	
	}


}
bool Input::GetKeyDown(SDL_Scancode p_key)
{
	if (m_KeyStates[p_key] == 1)  
	{
		return true;
	}
	return false;
}

void Input::KeyUp()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}
void Input::KeyDown()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}


Input* Input::GetInstance()
{
	if (m_InputInstance == nullptr)
		m_InputInstance = new Input();

	return m_InputInstance;
}
