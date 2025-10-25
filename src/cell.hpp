#pragma once

namespace tcb {

class Cell {
private:
	int x_loc;
	int y_loc;

	enum class CellType {
		HOME,
		SHOP,
		WORK,
		ROAD,
	};

	CellType cell_type;

public:
	void set_x_loc(int x);
	int get_x_loc();
	void set_y_loc(int y);
	int get_y_loc();
};

}	// namespace tcb
