#pragma once
#include "AnimalsDS.h"
#include "Command.h"

class ActionsCommand :public Command{

public:

	ActionsCommand(AnimalsDS& animals);
	virtual void execute() = 0;
	virtual ~ActionsCommand() = default;

protected:

	AnimalsDS& m_animals;
};