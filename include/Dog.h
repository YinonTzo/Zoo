#pragma once

#include "AnimalFactory.h"

class Dog :public Animal
{
public:
	Dog(const std::string&, const Location&);
	~Dog();

	virtual void step() override;

	virtual void printDetails() const override;
	
private:
	static bool m_registerit;
	void changeDirection();
};

