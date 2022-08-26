#pragma once

#include<vector>
#include "ActionsCommand.h"

class MoveCommand :public ActionsCommand {

public:

	using ActionsCommand::ActionsCommand;
	virtual void execute() override;

private:
	int readNumOfAnimal() const;
};
