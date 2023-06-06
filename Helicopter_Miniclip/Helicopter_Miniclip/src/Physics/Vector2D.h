#pragma once

#include<iostream>

class Vector2D
{
public:
	float X, Y;

public:
	Vector2D(float p_x = 0, float p_y = 0) : X(p_x), Y(p_y) {}

public:
	// Vector Addition eg v3 = v1 + v2
	inline Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(X + v2.X, Y + v2.Y);
	}
	// Vector Subtraction eg v3 = v1 - v2
	inline Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(X - v2.X, Y - v2.Y);
	}

	// Vector Mulitplication
	inline Vector2D operator*(const float p_scaler) const
	{
		return Vector2D(X * p_scaler, Y * p_scaler);
	}

	void Log(std::string msg = "")
	{
		std::cout << msg << "(X Y) = (" << X << " " << Y << ")" << std::endl;
	}
};