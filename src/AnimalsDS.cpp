#include "AnimalsDS.h"
#include "AnimalFactory.h"

#include <typeinfo>
#include <algorithm>
#include <experimental/vector>

Animal& AnimalsDS::operator[](size_t i) {
	if (i < 0 || i >= m_animals.size())
		std::cout << "Out of bounds\n";

	return *m_animals[i].get();
}

void AnimalsDS::emplace_back(std::string& type, std::string& name, Location& loc) {
	m_animals.emplace_back(AnimalFactory::create(type, name, loc));
}

void AnimalsDS::erase(int n) {
	m_animals.erase(m_animals.begin() + n);
}

void AnimalsDS::eraseAll(std::string& toDellete) {
	std::experimental::erase_if(m_animals, [&toDellete](auto& animal) {return typeid(*animal).name() == toDellete; });
}

void AnimalsDS::show() const {
	showAsAList();
	showAsAMap();
}

void AnimalsDS::showAsAList() const {
	drawDecoreation("=");
	for (int i = 0; i < m_animals.size(); i++) {
		std::cout << i << ": ";
		m_animals[i]->printDetails();
	}
}

void AnimalsDS::showAsAMap() const {
	auto map = createAnimalsMap();
	drawDecoreation("*");
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++)
			std::cout << map[i][j];
		std::cout << std::endl;
	}
	drawDecoreation("*");
}

std::vector < std::vector<char> > AnimalsDS::createAnimalsMap() const{
	std::vector < std::vector<char> > map(Location::m_maxRow, std::vector<char>(Location::m_maxCol, ' '));
	for (int i = 0; i < m_animals.size(); i++) {
		auto animal_location = m_animals[i]->getLocation();
		map[animal_location.m_row][animal_location.m_col] = m_animals[i]->getInitial();
	}
	return map;
}

void AnimalsDS::drawDecoreation(const std::string& decoration) const {
	for (int i = 0; i < Location::m_maxCol; i++)
		std::cout << decoration;
	std::cout << std::endl;
}

size_t AnimalsDS::size() const {
	return m_animals.size();
}