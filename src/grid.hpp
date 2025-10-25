#pragma once

#include "cell.hpp"

namespace tcb {
class Grid {
  private:
	const static int max_x = 100;
	const static int max_y = 100;

	Cell cells[max_x][max_y];

	int get_cell_x(Cell *cell);
	int get_cell_y(Cell *cell);

  public:
	void init_grid();

	Cell *get_cell(int x, int y);
	Cell *get_cell_north(Cell *cell);
	Cell *get_cell_east(Cell *cell);
	Cell *get_cell_south(Cell *cell);
	Cell *get_cell_west(Cell *cell);
};
}	// namespace tcb
