#pragma once
#include<unordered_map>
#include "Location.h"

class Directions{

public:

	enum class direction
	{
		left,
		right,
		up,
		down
	};

	static Directions& instance();
	const Location& getDirection(const direction&)const;

	direction drawDirection() const;

private:

	Directions();
	~Directions() = default;
	Directions(const Directions&) = default;
	Directions& operator =(const Directions&) = default;

	std::unordered_map<direction, Location> m_map_direction;

	void setDirections();
};