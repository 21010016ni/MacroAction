#pragma once
#include "Object.hpp"
#include <functional>
#include <queue>

class Mob : public Object
{
	bool interrupt;
	std::queue<std::pair<int, std::function<bool(Mob&)>>> command;

	bool Interrupt();

public:
	Point<float> prevVec;
	std::function<void(Mob&)> controll;

	Mob(float x, float y, float r, const std::function<void(Mob&)>& controll) :Object(x, y, r, 0), interrupt(true), prevVec(0.0f, 0.0f), controll(controll) {}

	void Dash(char d);
	void Jump();
	void FlyDash(char d);
	void FallKnock();
	void Attack();

	void update()override;
};

