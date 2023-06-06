#pragma once

#include "../Physics/Vector2D.h"

class Transform {

public:
	float X, Y;
public:
	Transform(float p_x = 0,float p_y = 0) : X(p_x), Y(p_y) {}

	void Log(std::string msg = "")
	{
		std::cout << msg << "(X Y) = (" << X << " " << Y << ")" << std::endl;
	}

public: 
	inline void TranslateX(float p_x) { X += p_x; }
	inline void TranslateY(float p_y) { Y += p_y; }
	inline void Translate(Vector2D v) { X += v.X; Y += v.Y; }

};