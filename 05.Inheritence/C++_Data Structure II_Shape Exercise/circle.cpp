//
// Created by Arias Arevalo, Carlos on 4/22/20.
//


#include "ellipse.h"
#include "circle.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Circle::Circle(double radius): Ellipse(radius, radius) {

}

string Circle::ToString() const {
	stringstream retVal;
	retVal << "{Circle " << Ellipse::ToString() << "}";
	return retVal.str();
}

double Circle::Perimeter() const {
	//return 2 * PI * PI; // We are in trouble!
	return 2 * PI * _radiusA;
}
