//
// Created by Arias Arevalo, Carlos on 4/22/20.
//
#include "triangle.h"

#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cassert>

using std::string;
using std::stringstream;
using std::max;

Triangle::Triangle(double a, double b, double c) : _a(a), _b(b), _c(c) {
	assert(a > 0 && b > 0 && c > 0);
}

string Triangle::ToString() const {
	stringstream retVal;
	retVal << "{Triangle " << Shape::ToString()
		   << " a = " << _a
		   << ", b = " << _b
		   << ", c = " << _c
		   << "}";
	return retVal.str();
}

double Triangle::Area() const {
	double s = (_a + _b + _c) / 2.0;
	return sqrt(s * (s - _a) * (s - _b) * (s - _c));
}

double Triangle::Perimeter() const {
	return _a + _b + _a;
}

double Triangle::Hypotenuse() const {
	return max(_a, max(_b, _c));
}
double FindAngle(double oppositeLength, double side1, double side2){
	return acos((pow(side1, 2) + pow(side2, 2) - pow(oppositeLength, 2)) / (2 * side1 * side2));
}
double Triangle::AngleAB() const {
	return FindAngle(_c, _a, _b);
}

double Triangle::AngleBC() const {
	return FindAngle(_a, _b, _c);
}

double Triangle::AngleAC() const {
	return FindAngle(_b, _a, _c);
}

