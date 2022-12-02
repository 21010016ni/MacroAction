#include "Mob.hpp"
#include "Config.hpp"
#include "Entity.hpp"

bool Mob::Interrupt()
{
	if (interrupt)
	{
		while (!command.empty())
			command.pop();
		return true;
	}
	return false;
}

void Mob::Dash(char d)
{
	if (Interrupt())
	{
		if (d > 0)
		{
			command.emplace(1, [](Mob& u) {u.vec.x = 8.0f; return false; });
		}
		else if (d < 0)
		{
			command.emplace(1, [](Mob& u) {u.vec.x = -8.0f; return false; });
		}
	}
}

void Mob::Jump()
{
	if (Interrupt())
	{
		command.emplace(1, [](Mob& u) {if (u.vec.y > 0)u.vec.y = 0; u.vec.y -= 15.0f; return true; });
		command.emplace(2, [](Mob&) {return true; });
		command.emplace(17, [](Mob&) {return false; });
	}
}

void Mob::FlyDash(char d)
{
	if (Interrupt())
	{
		command.emplace(1, [](Mob& u) {u.vec.y = -15.0f; return true; });
		command.emplace(4, [](Mob&) {return true; });
		command.emplace(5, [](Mob&) {return false; });
		command.emplace(0, [](Mob& u) {u.vec.y = 0; return false; });
		if (d > 0)
			command.emplace(1, [](Mob& u) {u.vec.x = 20.0f; return false; });
		else if (d < 0)
			command.emplace(1, [](Mob& u) {u.vec.x = -20.0f; return false; });
		command.emplace(10, [](Mob& u) {u.vec.y = 0.0f; return true; });
		command.emplace(10, [](Mob&) {return false; });
	}
}

void Mob::FallKnock()
{
	if (Interrupt())
	{
		command.emplace(5, [](Mob& u) {u.vec.y = 0.0f; u.vec.x = 0.0f; return false; });
		command.emplace(5, [](Mob& u) {u.vec.y += 5.0f; return true; });
		command.emplace(20, [](Mob& u) {return false; });
	}
}

void Mob::Attack()
{
	Objects::list.emplace_back(new Entity(id, pos.x + 10.0f, pos.y, 5.0f, 6.0f, 0.0f, 10, 5, 10.0f, -5.0f));
}

void Mob::update()
{
	if (controll)
		controll(*this);

	vec += gravity;
	vec.x *= 0.9;
	if (command.empty())
	{
		interrupt = true;
	}
	while (!command.empty())
	{
		interrupt = command.front().second(*this);
		if (command.front().first <= 0)
		{
			command.pop();
			continue;
		}
		else if (--command.front().first <= 0)
			command.pop();
		break;
	}
	move();
	if (pos.y > common::height)
	{
		pos.y = common::height;
		vec.y = 0;
	}
	prevVec = vec;
}

