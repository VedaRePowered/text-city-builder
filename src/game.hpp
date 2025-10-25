#pragma once

#include "grid.hpp"
#include "gui.hpp"

namespace tcb {

class Game {
	Gui gui;
	Grid grid;

public:
	Game();
	~Game();

	void input(InputButton button);
	void update(float delta_time);
	void draw(int width, int height);
};

}	// namespace tcd
