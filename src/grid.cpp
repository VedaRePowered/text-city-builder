#include "grid.hpp"

namespace tcb {

void Grid::init_grid() {
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			cells[i][j].set_x_loc(i);
			cells[i][j].set_y_loc(j);
		}
	}
}

Cell *Grid::get_cell(int x, int y) {
	if (x >= 0 && y >= 0 && x < max_x && y < max_y) {
		return &cells[x][y];
	}

	return nullptr;
}

Cell *Grid::get_cell_north(Cell *cell) {
	return get_cell(cell->get_x_loc(), cell->get_y_loc() + 1);
}

Cell *Grid::get_cell_east(Cell *cell) {
	return get_cell(cell->get_x_loc() + 1, cell->get_y_loc());
}

Cell *Grid::get_cell_south(Cell *cell) {
	return get_cell(cell->get_x_loc(), cell->get_y_loc() - 1);
}

Cell *Grid::get_cell_west(Cell *cell) {
	return get_cell(cell->get_x_loc() - 1, cell->get_y_loc());
}

}	// namespace tcb
