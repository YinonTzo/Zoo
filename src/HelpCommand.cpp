#include "HelpCommand.h"
#include<iostream>

void HelpCommand::execute() {

	std::cout << "Stop: Makes some animal to stop. Argumants: int which represnt the animal from the list\n";
	std::cout << "Move: Makes some animal to move. Argumants: int which represnt the animal from the list.";
	std::cout << "The animal will draw new direction, then make a move.\n";
	std::cout << "Create: Creates new animal. Arguments:Type of animal and name. The location and direction will be randomally.\n";
	std::cout << "Del: Deletes some animal from the list. Argumnt int which represnt the animal from the list.\n";
	std::cout << "DellAll: Deletes all animals of the same type. Argument: type (Lion, Monkey, Dog).\n";
	std::cout << "Help: Prints help.\n";
	std::cout << "Exit: Exit.\n";
	std::cout << "Makes all animals to keep going. (if some animal stoped, it will stay in same place.\n";
	std::cout << "All order must begin with the number which represnt it in the list.\n";
	std::cout << "for ex: The list is:\n1:create\n2:stop\nThe order will be: 1 Dog or 2 0 (it will stop the animal number 0).\n";
}
