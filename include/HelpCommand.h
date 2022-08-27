#pragma once
#include<vector>
#include "Command.h"

class HelpCommand :public Command{

public:

	using Command::Command;
	virtual void execute() override;
};
