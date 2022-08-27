#include "StopCommand.h"

void StopCommand::execute() {
	int n = readNumOfAnimal();
	m_animals[n].stop();
}

int StopCommand::readNumOfAnimal() const {
	int n;
	std::cin >> n;
	return n;
}