#pragma once
#include <vector>
#include <string>
#include "Dog.h"
#include "Command.h"
#include "AnimalsDS.h"

class Zoo{

public:

	Zoo();
	void run();

private:

	void add(const std::string&, std::unique_ptr<Command> command);
	void show() const;
	int getOptionFromUser() const;
	bool performAction(int n);

	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	
	AnimalsDS m_animals;

	void initializeAnimals();
	void initializeCommands();
};
