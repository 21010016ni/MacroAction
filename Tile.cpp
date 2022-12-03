#include "Tile.hpp"
#include <stdexcept>
#include <fstream>
#include <DxLib.h>
#include "Handle.hpp"

Tile::Norm::Norm(const char8_t* graph)
{
	path = graph;
	GetGraphSize(Handle::get(path, Handle::type::graph), &num.x, &num.y);
	num /= size;

	// data‚Ì‰Šú‰»
	data.resize(num.y * num.x);
}

Tile::Ret Tile::Norm::get(int id, int t)const
{
	if (data.size() <= id)
		throw std::out_of_range("out of range");
	return { Handle::get(path, Handle::type::graph),num(id) * size,data[id] };
}

Tile::Anim::Anim(const char8_t* graph, int pattern, unsigned char type) :pattern(pattern), type(type)
{
	path = graph;
	GetGraphSize(Handle::get(path, Handle::type::graph), &num.x, &num.y);
	num /= size;
	if (type & Mode::horizontal)
		num.y /= pattern;
	else
		num.x /= pattern;

	// data‚Ì‰Šú‰»
	data.resize(num.y * num.x);
}

Tile::Ret Tile::Anim::get(int id, int t)const
{
	if (data.size() <= id)
		throw std::out_of_range("out of range");
	auto buf = num(id);
	if (type & Mode::step)
	{
		t %= (pattern - 1) * 2;
		if (t >= pattern)
			t = (pattern - 1) * 2 - t;
	}
	else
		t %= pattern;
	if (type & Mode::horizontal)
		buf.y += num.y * t;
	else
		buf.x += num.x * t;
	return { Handle::get(path, Handle::type::graph),buf * size,data[id] };
}

void Tile::load(const char* file)
{

}

