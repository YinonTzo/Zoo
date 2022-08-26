#include "KeepGoingCommand.h"


void KeepGoingCommand::execute() {
	for (int i = 0; i < m_animals.size(); i++)
		m_animals[i].step();
}
