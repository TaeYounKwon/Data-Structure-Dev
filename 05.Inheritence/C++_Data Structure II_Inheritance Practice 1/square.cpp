#include "rectangle.h"
#include "square.h"

#include <sstream>
#include <string>
using std::string;
using std::stringstream;

#include <iostream>
using std::cout;
using std::endl;

Square::Square(const Point& upperLeft, size_t side): Rectangle(upperLeft, side, side) {
	cout << "\t\tSquare::Square(" << side << ")" << endl;
}
Square::~Square(){
	cout << "\t\tSquare::~Square()" << endl;
}
string Square:: ToString()const{
	stringstream retVal;
	retVal <<  "Square: {width: " << Perimeter()/4 << "}";
	return retVal.str();
}
