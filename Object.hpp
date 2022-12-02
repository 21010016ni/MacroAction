#pragma once
#include <memory>
#include <list>
#include "Point.hpp"
#include "Draw.hpp"

class Object
{
public:
	enum State :unsigned char
	{
		alive = 0,
		dead = 1,
		active = 0,
		freeze = 2,
		display = 0,
		clear = 4,
	};

	static Draw d;
	static Point<float> gravity;

	static inline int sid = 0;

	int id;
	Point<float> pos;
	float r;
	Point<float> vec;
	unsigned char state;

	Object(float x, float y, float r, unsigned char state) :id(sid), pos(y, x), r(r), vec(0.0f, 0.0f), state(state) { ++sid; }
	Object(int id, float x, float y, float r, unsigned char state) :id(id), pos(y, x), r(r), vec(0.0f, 0.0f), state(state) {}

	void move() { pos += vec; }
	bool collision(const Object& t) { return pos.distance<float>(t.pos) < r + t.r; }

	virtual void update() = 0;
	virtual void draw()const;
};

class Objects
{
public:
	static inline std::list<std::shared_ptr<Object>> list;

	static void update();
	static void draw();
};

