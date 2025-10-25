#include <cstdint>
#include <optional>
#include <vector>

namespace tcb {

typedef double GameTime;

struct Location {
	unsigned int x;
	unsigned int y;
};

class Person {
private:
	enum class GoalType {
		IDLE,
		HOME,
		SHOP,
		WORK,
		RECREATION,
	};

	struct Goal {
		GoalType goal_type;
		Location goal_location;
		GameTime until;
	};

	enum class TransportType {
		Walk,
		Bike,
		Car,
		Bus,
	};

	struct PathNode {
		TransportType tt;
		Location start;
		Location end;
	};

public:
	std::optional<Location> home;
	std::optional<Location> work;

	Location location;
	uint32_t count;
	Goal goal;

	std::vector<PathNode> path;
	uint32_t current_path_node;
	float current_node_progress;

	Person(Location start_location);

	void update(GameTime delta_time);
};

}	// namespace tcb
