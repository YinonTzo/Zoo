#include "MoveCommand.h"


void MoveCommand::execute() {
	int n = readNumOfAnimal();
	m_animals[n].move();
	m_animals[n].step();
}

int MoveCommand::readNumOfAnimal() const {
	int n;
	std::cin >> n;
	return n;
}