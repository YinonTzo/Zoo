#pragma once

#include "Animal.h"

class AnimalFactory{

public:
	using pFnc = std::unique_ptr<Animal>(*)(const std::string& name, const Location& loc);
	static std::unique_ptr<Animal> create(const std::string& type, const std::string& name, const Location& loc);
	static bool registerit(const std::string& name, pFnc);

private:

	static auto& getMap() {
		static std::unordered_map<std::string, pFnc> createAnimalSMap;
		return createAnimalSMap;
	}
};
