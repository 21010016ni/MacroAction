#include "Game.hpp"
#include "Config.hpp"
#include "Input.hpp"
#include "Particle.hpp"

#include "Draw.hpp"
#include "convert_string.hpp"

#include "Mob.hpp"
#include "Controll.hpp"

Draw display(0, 0, 0);

void Game::preset()
{
	//Particle::set<Dust>(20);
	Objects::list.emplace_back(new Mob(200.0f, 300.0f, 10.0f, Controll::player));
	Objects::list.emplace_back(new Mob(500.0f, 200.0f, 10.0f, Controll::kame));
}

Game::Message Game::update()
{
	if (Keyboard::push(VK_ESCAPE))
	{
		return Message::quit;
	}

	Objects::update();
	Particle::update();
	return Message::none;
}

void Game::draw()
{
	//for (int i = 0; i < 256; ++i)
	//{
	//	display.string(i / 16 * 32, i % 16 * 18, ext::vto<char8_t, int>(Keyboard::get(i)), 0xffffff);
	//}

	Objects::draw();
	Particle::draw();
}

