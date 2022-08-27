#pragma once
#include<vector>
#include "ActionsCommand.h"

class CreateAnimalCommand :public ActionsCommand {

public:

	using ActionsCommand::ActionsCommand;
	virtual void execute() override;

private:

	std::string readString() const;
};
