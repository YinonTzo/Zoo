#include "Lion.h"

Lion::Lion(const std::string& name, const Location& location)
	:Animal(name, location)
{
	setNumOfSteps(2);
	//std::cout << " Lion c-tor\n";
}

Lion::~Lion()
{
	//std::cout << " Lion d-tor\n";
}

void Lion::step() {

	if (!getStop()) {

		Location newLoc = calculateSteps();
		while (checkAndUpdateDirection(newLoc))
			newLoc = calculateSteps();

		setLocation(std::move(newLoc));
	}
}

void Lion::printDetails() const {
	std::cout << Animal::getName() << " Lion " << Animal::getLocation() << std::endl;
}

bool Lion::m_registerit = AnimalFactory::registerit("Lion",[](const std::string& name, const Location& loc) ->
	std::unique_ptr<Animal> {return std::make_unique<Lion>(name, loc);}
);