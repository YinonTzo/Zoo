#include "CreateAnimalCommand.h"

void CreateAnimalCommand::execute() {
	std::string type = readString();
	std::string name = readString();
	auto location = Location();

	m_animals.emplace_back(type, name, location);
}

std::string CreateAnimalCommand::readString() const {
	std::string str;
	std::cin >> str;
	return str;
}


