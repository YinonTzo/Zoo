#pragma once

#include "AnimalFactory.h"

class Lion :public Animal
{
public:
	Lion(const std::string&, const Location&s);
	~Lion();

	virtual void step() override;
	virtual void printDetails() const override;

private:
	static bool m_registerit;
};

