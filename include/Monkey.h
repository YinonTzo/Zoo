#pragma once

#include "AnimalFactory.h"

class Monkey :public Animal
{
public:
	Monkey(const std::string&, const Location&);
	~Monkey();

	virtual void step() override;

	virtual void printDetails() const override;

private:

	int drawSteps() const;

	static bool m_registerit;
	int m_maxTurns;
	int m_maxSteps;
};

