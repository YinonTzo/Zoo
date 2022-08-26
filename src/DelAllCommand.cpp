#include "DelAllCommand.h"
#include "AnimalFactory.h"
#include <typeinfo>


void DelAllCommand::execute() {

	std::string toDellete = "class ";
	auto name = readType();
	toDellete += name;

	m_animals.eraseAll(toDellete);
}

std::string DelAllCommand::readType() const {
	std::string str;
	std::cin >> str;
	return str;
}
