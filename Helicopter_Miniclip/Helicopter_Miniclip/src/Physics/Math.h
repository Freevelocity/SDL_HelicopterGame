#pragma once

class Math
{
public:
	static float Clamp(float p_value, float p_min, float p_max)
	{
		if (p_value > p_max)
			return p_max;
		if (p_value < p_min)
			return p_min;
		return p_value;
	}


};