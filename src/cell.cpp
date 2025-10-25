#include "cell.hpp"

namespace tcb {
void Cell::set_x_loc(int x) {
	x_loc = x;
}

int Cell::get_x_loc() {
	return x_loc;
}

void Cell::set_y_loc(int y) {
	y_loc = y;
}

int Cell::get_y_loc() {
	return y_loc;
}
}	// namespace tcb
