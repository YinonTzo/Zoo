#pragma once

#include <vector>
#include "AnimalFactory.h"

class AnimalsDS
{
public:
	
	Animal& operator[](size_t i);

	void emplace_back(std::string&, std::string&, Location&);
	void erase(int);
	void eraseAll(std::string&);
	void show() const;
	size_t size()const;

private:

	void showAsAList() const;
	void showAsAMap() const;
	void drawDecoreation(const std::string& decoration) const;
	std::vector < std::vector<char> > createAnimalsMap() const;

	std::vector<std::unique_ptr<Animal>> m_animals;
};
