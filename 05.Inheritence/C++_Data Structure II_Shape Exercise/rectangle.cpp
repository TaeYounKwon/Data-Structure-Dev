//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#include "rectangle.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Rectangle::Rectangle(double base, double height) :_base(base), _height(height){

}

string Rectangle::ToString() const {
	stringstream retVal;
	retVal << "{Rectangle " << Shape::ToString() << " base: " << _base << ", height: " << _height << "}";
	return retVal.str();
}

double Rectangle::Area() const {
	return _base * _height;
}

double Rectangle::Perimeter() const {
	return 2 * _base + 2 * _height;
}
