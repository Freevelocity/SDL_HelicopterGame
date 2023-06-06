#pragma once
#include<SDL.h>
class Input
{

public:
	static Input* GetInstance();
	void Listen();
	bool GetKeyDown(SDL_Scancode p_key);
public:
	inline bool BulletFire() { return m_FireBullet; }

private:
	Input();
	void KeyUp();
	void KeyDown();	


private:
	const Uint8* m_KeyStates;
	static Input* m_InputInstance;
	bool m_FireBullet;
};

