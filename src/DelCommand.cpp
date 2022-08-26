#include "DelCommand.h"


void DelCommand::execute() {
	int n = readNumOfAnimal();
	m_animals.erase(n);
}
int DelCommand::readNumOfAnimal() const {
	int n;
	std::cin >> n;
	return n;
}