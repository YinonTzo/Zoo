#include "Location.h"

/*Pic Location*/
Location::Location():
	Location(std::rand() % m_maxRow,
	std::rand() % m_maxCol){
	//std::cout << "defult Location c-tor\n";
}

Location::Location(int row, int col)
	:m_row(row), m_col(col){
	//std::cout << "row-col Location c-tor\n";
}

Location::Location(const Location& other)
	:Location(other.m_row, m_col = other.m_col){
	//std::cout << "copy Location c-tor\n";
}

Location::Location(Location&& other) noexcept
	:Location(std::move(other.m_row), std::move(other.m_col)){
	//std::cout << "move Location c-tor\n";
}

Location& Location::operator = (Location&& other)noexcept{
	//std::cout << "Location move assigment\n";
	m_col = std::move(other.m_col);
	m_row = std::move(other.m_row);
	return *this;
}

Location& Location::operator = (const Location&other) {
	this->m_row = other.m_row;
	this->m_col = other.m_col;
	return *this;
}

int Location::MaxCol() {
	return m_maxCol;
}

int Location::MaxRow() {
	return m_maxRow;
}

Location operator + (const Location& left, const Location& right){
	return {(left.m_row + right.m_row),
		(left.m_col + right.m_col)};
}

Location& operator += (Location& left, const Location& right) {
	 return left = left + right;
}

Location operator * (const Location& other, int val) {
	return { (val * other.m_row),
		(val * other.m_col) };
}

std::ostream& operator<<(std::ostream& output, const Location& loc) {
	output << "(" << loc.m_row << ", " << loc.m_col << ")";
	return output;
}
