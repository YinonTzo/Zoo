#include "Directions.h"
#include <cstdlib>

Directions::Directions(){
	setDirections();
}

Directions& Directions::instance() {
	static Directions inst;
	return inst;
}

const Location& Directions::getDirection(const direction& dir)const {
	return m_map_direction.at(dir);
}

Directions::direction Directions::drawDirection()const {
	return static_cast<direction> (std::rand()% sizeof(direction));
}

void Directions::setDirections() {
	m_map_direction.insert({ direction::right, std::move(Location(0, 1)) });
	m_map_direction.insert({ direction::left, std::move(Location(0, -1)) });
	m_map_direction.insert({ direction::up, std::move(Location(-1, 0)) });
	m_map_direction.insert({ direction::down, std::move(Location(1, 0)) });
}