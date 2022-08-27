#include "Animal.h"

Animal::Animal(const std::string& name, const Location& location)
	:m_location(location), m_name(name), m_stop(false),
	m_direction(Directions::instance().drawDirection()){
	//std::cout << "Animal c-tor\n";
}

Animal::~Animal(){
	//std::cout << "Animal d-tor\n";
}

Location Animal::getLocation() const {
	return m_location;
}

char Animal::getInitial() const {
	return m_name[0];
}

void Animal::stop() {
	m_stop = true;
}

void Animal::move() {
	m_direction = Directions::instance().drawDirection();
	m_stop = false;
}

void Animal::turnVertically() {
	if (m_direction == Directions::direction::up)
		m_direction = Directions::direction::down;
	else if (m_direction == Directions::direction::down)
		m_direction = Directions::direction::up;
}

void Animal::turnHorizontally() {
	if (m_direction == Directions::direction::left)
		m_direction = Directions::direction::right;
	else if (m_direction == Directions::direction::right)
		m_direction = Directions::direction::left;
}

bool Animal::getStop() const {
	return m_stop;
}

Location Animal::calculateSteps() const {
	return m_location + (Directions::instance().getDirection(m_direction) * m_numOfSteps);
}

void Animal::setDirection(Directions::direction&& direction) {
	m_direction = direction;
}

void Animal::setNumOfSteps(int numofSteps) {
	m_numOfSteps = numofSteps;
}

void Animal::setLocation(Location&& location) {
	m_location = location;
}

std::string Animal::getName()const{
	return m_name;
}

bool Animal::checkHorizontalLimit(const Location& newLoc)const {
	return (newLoc.m_col >= Location::m_maxCol || newLoc.m_col < 0);
}

bool Animal::checkVeticalLimit(const Location& newLoc)const {
	return (newLoc.m_row >= Location::m_maxRow || newLoc.m_row < 0);
}

bool Animal::checkAndUpdateDirection(const Location& newLoc) {
	if (checkHorizontalLimit(newLoc)) {
		Animal::turnHorizontally();
		return true;
	}
	if (checkVeticalLimit(newLoc)) {
		Animal::turnVertically();
		return true;
	}
	return false;
}