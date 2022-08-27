#pragma once
#include <iostream>

struct Location{

public:

	Location();
	Location(int row, int col);
	Location(const Location& other);
	Location(Location&& other) noexcept;

	static int MaxCol();
	static int MaxRow();

	Location& operator = (Location&& other) noexcept;
	Location& operator = (const Location& other);

	int m_row, m_col;
	static const int m_maxRow = 20;
	static const int m_maxCol = 40;
};


Location operator + (const Location&, const Location&);
Location& operator += (Location&, const Location&);
Location operator * (const Location&, int);
std::ostream& operator<<(std::ostream& output, const Location& );
