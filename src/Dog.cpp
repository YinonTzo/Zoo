#include "Dog.h"

Dog::Dog(const std::string& name, const Location& location)
	:Animal(name, location)
{
	setNumOfSteps(3);
	//std::cout << " Dog c-tor\n";
}

Dog::~Dog()
{
	//std::cout << " Dog d-tor\n";
}

void Dog::step() {

	static bool back = false;

	if (!getStop()) {
	
		if (back) {
			setNumOfSteps(1);
			back = false;
		}
		else {
			setNumOfSteps(3);
			back = true;
		}
		
		Location newLoc = calculateSteps();
		while (checkAndUpdateDirection(newLoc))
			newLoc = calculateSteps();
	
		changeDirection();
		setLocation(std::move(newLoc));
	}
}

void Dog::printDetails() const {
	std::cout << Animal::getName() << " Dog " << Animal::getLocation() << std::endl;
}


void Dog::changeDirection() {
	Animal::turnHorizontally();
	Animal::turnVertically();
}

bool Dog::m_registerit = AnimalFactory::registerit("Dog", [](const std::string& name, const Location& loc) ->
	std::unique_ptr<Animal> {return std::make_unique<Dog>(name, loc); }
);
