#pragma once
#include "Directions.h"

class Animal{

public:

	Animal(const std::string&,const Location&);
	virtual ~Animal();

	virtual void printDetails() const = 0;
	Location getLocation() const;
	char getInitial() const;

	virtual void step() = 0;
	void stop();
	void move();
	
	void turnVertically();
	void turnHorizontally();
	
protected:

	bool getStop() const;
	std::string getName()const;

	void setDirection(Directions::direction&& direction);
	void setNumOfSteps(int);
	void setLocation(Location&& location);
	
	Location calculateSteps() const;

	bool checkHorizontalLimit(const Location&)const;
	bool checkVeticalLimit(const Location&)const;
	bool checkAndUpdateDirection(const Location& newLoc);

private:

	Location m_location;
	std::string m_name;
	Directions::direction m_direction;
	int m_numOfSteps = 0;
	bool m_stop;
};
