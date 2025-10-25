#pragma once

#include <termios.h>

namespace tcb {

enum class InputButton {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SELECT,
	BACK,
	RESIDENTIAL,
	COMMERCIAL,
	INDUSTRIAL,
	ROAD,
};

enum class InputAction {
	NONE,
	BUILD_RESIDENTIAL,
	BUILD_COMMERCIAL,
	BUILD_INDUSTRIAL,
	BUILD_ROAD,
};

class Gui {
	enum class Tool {
		SELECT,
		RESIDENTIAL,
		COMMERCIAL,
		INDUSTRIAL,
		ROAD,
	};

	struct termios tio_orig;

	int cursor_x, cursor_y;
	Tool tool;

public:
	Gui();
	~Gui();

	InputAction input(InputButton button);
	void draw(int width, int height);
};

}	// namespace tcd
