#include "Controll.hpp"
#include "Config.hpp"
#include "Input.hpp"

void Controll::player(Mob& u)
{
	if (Keyboard::push(VK_SPACE))
	{
		u.Jump();
	}
	else if (Keyboard::press('D'))
	{
		u.Dash(1);
	}
	else if (Keyboard::press('A'))
	{
		u.Dash(-1);
	}
	else if (Keyboard::push('E'))
	{
		u.FlyDash(1);
	}
	else if (Keyboard::push('Q'))
	{
		u.FlyDash(-1);
	}
	else if (Keyboard::push('X'))
	{
		u.FallKnock();
	}
	else if (Keyboard::push('C'))
	{
		u.Attack();
	}
}

void Controll::kame(Mob& u)
{
	if (u.prevVec.x == 0)
	{
		u.prevVec.x = -3.0f;
	}
	else if (u.prevVec.x < 0)
	{
		u.prevVec.x = -3.0f;
	}
	else if (u.prevVec.x > 0)
	{
		u.prevVec.x = 3.0f;
	}
	if (u.pos.x < 10)
	{
		u.prevVec.x = 3.0f;
	}
	else if (u.pos.x > common::width - 10)
	{
		u.prevVec.x = -3.0f;
	}
	u.vec.x = u.prevVec.x;
}
