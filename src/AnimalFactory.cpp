#include "AnimalFactory.h"


std::unique_ptr<Animal> AnimalFactory::create(const std::string& type, const std::string& name, const Location& loc) {
	auto it = AnimalFactory::getMap().find(type);
	if (it == AnimalFactory::getMap().end())
		return nullptr;
	
	return it->second(name, loc);
}

bool AnimalFactory::registerit(const std::string& name, pFnc f) {
	AnimalFactory::getMap().emplace(name, f);
	return true;
}