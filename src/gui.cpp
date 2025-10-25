#include "gui.hpp"

#include <unistd.h>

namespace tcb {

Gui::Gui() {
	cursor_x = 0;
	cursor_y = 0;
	tool = Tool::SELECT;

	struct termios tio;
	tcgetattr(STDIN_FILENO, &tio);
	this->tio_orig = tio;
	tio.c_lflag &= !(ECHO & ICANON & IXON);
	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
}

Gui::~Gui() {
	tcsetattr(STDIN_FILENO, TCSANOW, &this->tio_orig);
}

InputAction Gui::input(InputButton button) {}

void Gui::draw(int width, int height) {}

}	// namespace tcb
