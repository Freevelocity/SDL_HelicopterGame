#pragma once
#include <string>
#include <iostream>

class Point
{
public:
	float X, Y;

public:
	Point(float p_x = 0, float p_y = 0) : X(p_x), Y(p_y) {}

public:
	// Point Addition eg v3 = v1 + v2
	inline Point operator+(const Point& v2) const
	{
		return Point(X + v2.X, Y + v2.Y);
	}

	inline friend Point operator+=(Point& p1, const Point& p2)
	{
		p1.X += p2.X;
		p1.Y += p2.Y;

		return p1;
	}

	// Point Subtraction eg v3 = v1 - v2
	inline Point operator-(const Point& v2) const
	{
		return Point(X - v2.X, Y - v2.Y);
	}
	inline friend Point operator-=(Point& p1, const Point& p2)
	{
		p1.X -= p2.X;
		p1.Y -= p2.Y;

		return p1;
	}

	// Point Mulitplication
	inline Point operator*(const float p_scaler) const
	{
		return Point(X * p_scaler, Y * p_scaler);
	}

	void Log(std::string msg = "")
	{
		std::cout << msg << "(X Y) = (" << X << " " << Y << ")" << std::endl;
	}
};