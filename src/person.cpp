#include "person.hpp"

namespace tcb {

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

Person::Person(Location start_location) {
	this->home = std::nullopt;
	this->work = std::nullopt;

	this->location = start_location;
	this->count = 1;
	this->goal = {GoalType::IDLE, start_location, (GameTime)0};

	this->path = {};
	this->current_path_node = 0;
	this->current_node_progress = 1.0;
}

void Person::update(GameTime delta_time) {
	// TODO
}

}	// namespace tcb
