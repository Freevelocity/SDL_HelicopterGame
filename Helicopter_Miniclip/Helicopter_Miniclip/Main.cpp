
#include "src/Core/Engine.h"
#include "src/Timer/Timer.h"

int main(int argc, char** argv)
{
	
	Engine::GetInstance()->Init("Helicopter V1", SCREEN_WIDTH ,SCREEN_HEIGHT,false);

	while (Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
		Timer::GetInstance()->Tick();
	}
	Engine::GetInstance()->Clean();

	return 0;
}