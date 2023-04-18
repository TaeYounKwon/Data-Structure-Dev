//
// Created by Arias Arevalo, Carlos on 4/22/20.
//
#include "triangle.h"
#include "isosceles.h"

#include <string>
#include <sstream>
#include <cassert>
using std::string;
using std::stringstream;

Isosceles::Isosceles(double equalSidesLength, double otherSideLength)
	: Triangle(equalSidesLength, equalSidesLength, otherSideLength) {

}

string Isosceles::ToString() const {
	stringstream retVal;
	retVal << "{Isosceles " << Triangle::ToString() << "}";
	return retVal.str();
}
