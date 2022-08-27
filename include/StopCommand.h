#pragma once
#include<vector>
#include "ActionsCommand.h"

class StopCommand :public ActionsCommand{

public:

	using ActionsCommand::ActionsCommand;
	virtual void execute() override;

private:

	int readNumOfAnimal() const;
};
