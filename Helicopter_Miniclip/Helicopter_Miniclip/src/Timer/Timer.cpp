#include "Timer.h"
#include <iostream>

Timer* Timer::m_TimerInstance = nullptr;

Timer::Timer() {}

void Timer::Tick()
{
	m_DeltaTime = (SDL_GetTicks() - m_LastTime)*(TARGET_FPS/1000.0f);

	if (m_DeltaTime > TARGET_DELTATIME) // Always want Animation have constant flow
	{
		m_DeltaTime = TARGET_DELTATIME;
	}

	//std::cout << "DeltaTime : " << m_DeltaTime << std::endl;
	m_LastTime = SDL_GetTicks();
}

Timer* Timer::GetInstance()
{
	if (m_TimerInstance == nullptr)
		m_TimerInstance = new Timer();
	return m_TimerInstance;
}