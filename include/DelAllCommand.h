#pragma once
#include<vector>
#include "ActionsCommand.h"
#include "AnimalsDS.h"

class DelAllCommand :public ActionsCommand{

public:

	using ActionsCommand::ActionsCommand;
	virtual void execute() override;

private:

	std::string readType() const;
};
