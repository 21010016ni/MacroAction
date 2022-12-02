#include "Entity.hpp"

void Entity::update()
{
	if (count >= 0)
	{
		move();
		for (const auto& i : Objects::list)
		{
			if (id != i->id && collision(*i))
			{
				printf("ID:%d �� ID:%d�ɍU��\n", id, i->id);
				i->vec += knockback;
			}
		}
	}
	if (++count >= duration)
	{
		state |= State::dead;
	}
}

