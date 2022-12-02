#pragma once
#include "Object.hpp"

class Entity :public Object
{
	int count;

	int duration;
	int value;
	Point<float> knockback;

public:

	Entity(int id, float x, float y, float r, float vx, float vy, int duration, int value, float kx, float ky, int count = 0)
		:Object(id, x, y, r, 0), count(count), duration(duration), value(value), knockback(ky, kx) {
		vec = { vy,vx };
	}

	void update()override;
};

