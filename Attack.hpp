#pragma once
#include "Object.hpp"

class Attack :public Object
{
	int duration;
	int value;
	Point<float> knockback;

public:
	Attack(float x, float y, float r, int duration, int value, float kx, float ky) :Object(x, y, r), duration(duration), value(value), knockback(kx, ky) {}
};

