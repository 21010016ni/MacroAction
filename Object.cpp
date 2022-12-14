#include "Object.hpp"
#include "Field.hpp"

Point<float> Object::gravity(1.0f, 0.0f);

void Object::draw() const
{
	Field::draw.circle((Point<int>)pos, r, 0xffffff, true);
}

void Objects::update()
{
	for (auto i = list.begin(); i != list.cend();)
	{
		if (!((*i)->state & Object::State::freeze))
		{
			(*i)->update();
		}
		if ((*i)->state & Object::State::dead)
		{
			i = list.erase(i);
			continue;
		}
		++i;
	}
}

void Objects::draw()
{
	for (const auto& i : list)
	{
		if (!(i->state & Object::State::clear))
		{
			i->draw();
		}
	}
}

