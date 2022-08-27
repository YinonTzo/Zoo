#pragma once
#include<vector>
#include "ActionsCommand.h"

class KeepGoingCommand :public ActionsCommand{

public:

	using ActionsCommand::ActionsCommand;
	virtual void execute() override;
};
