#include "Monkey.h"


Monkey::Monkey(const std::string& name, const Location& location)
	:Animal(name, location), m_maxTurns(5), m_maxSteps(2)
{
	setNumOfSteps(drawSteps());
	//std::cout << " Monkey c-tor\n";
}

Monkey::~Monkey()
{
	//std::cout << " Monkey d-tor\n";
}

void Monkey::step() {

	static int countTurns = 0;
	if (!getStop()) {
		if (countTurns % m_maxTurns == 0){
			Animal::setDirection(Directions::instance().drawDirection());
			setNumOfSteps(drawSteps());
		}

		Location newLoc = calculateSteps();
		if (checkAndUpdateDirection(newLoc))
			newLoc = calculateSteps();

		setLocation(std::move(newLoc));
		countTurns++;
	}
}

int Monkey::drawSteps() const {
	return (rand() % m_maxSteps) + 1;
}

void Monkey::printDetails() const {
	std::cout << Animal::getName() << " Monkey " << Animal::getLocation() << std::endl;
}

bool Monkey::m_registerit = AnimalFactory::registerit("Monkey", [](const std::string& name, const Location& loc) ->
	std::unique_ptr<Animal> {return std::make_unique<Monkey>(name, loc); }
);