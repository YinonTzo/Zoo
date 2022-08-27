#include "Zoo.h"
#include "MoveCommand.h"
#include "StopCommand.h"
#include "KeepGoingCommand.h"
#include "CreateAnimalCommand.h"
#include "DelCommand.h"
#include "DelAllCommand.h"
#include "HelpCommand.h"

Zoo::Zoo(){
	initializeCommands();
	initializeAnimals();
}

void Zoo::run(){
	int n;
	do {
		show();
		n = getOptionFromUser();
	} while (performAction(n));
}

void Zoo::add(const std::string& nameOption, std::unique_ptr<Command> command) {
	m_options.emplace_back(option(nameOption, std::move(command)));
}

void Zoo::show() const{
	for (size_t i = 0; i < m_options.size(); i++)
		std::cout << i << ": " << m_options[i].first << std::endl;
	std::cout << m_options.size() << ": " << "Exit\n";

	m_animals.show();
}

int Zoo::getOptionFromUser() const {
	int n;
	std::cin >> n;
	return n;
}

bool Zoo::performAction(int n) {
	if (n >= m_options.size() || n < 0)
		return false;
	m_options[n].second->execute();
	return true;
}

void Zoo::initializeAnimals() {
	std::string typeL = "Lion";
	std::string typeM = "Monkey";
	std::string typeD = "Dog";

	std::string lion = "Moffasa";
	std::string monkey = "Rafiki";
	std::string dog = "Toto";

	Location loc1 = Location();
	Location loc2 = Location();
	Location loc3 = Location();

	m_animals.emplace_back(typeL, lion, loc1);
	m_animals.emplace_back(typeM, monkey, loc2);
	m_animals.emplace_back(typeD, dog, loc3);
}

void Zoo::initializeCommands() {
	add("Move", std::make_unique<MoveCommand>(m_animals));
	add("stop", std::make_unique<StopCommand>(m_animals));
	add(". ", std::make_unique<KeepGoingCommand>(m_animals));
	add("del ", std::make_unique<DelCommand>(m_animals));
	add("delete all ", std::make_unique<DelAllCommand>(m_animals));
	add("create ", std::make_unique<CreateAnimalCommand>(m_animals));
	add("help ", std::make_unique<HelpCommand>());
}