#pragma once
#include<SDL.h>

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;


class Timer
{
public:
	static Timer* GetInstance();
	void Tick();
public:
	inline float GetDeltaTime() { return m_DeltaTime; }
private:
	Timer();
	static Timer* m_TimerInstance;
	float m_DeltaTime;
	float m_LastTime;
};


