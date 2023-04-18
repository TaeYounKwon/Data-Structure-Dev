//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#include "ellipse.h"

#include <string>
#include <sstream>
#include <cmath>
using std::string;
using std::stringstream;

Ellipse::Ellipse(double radiusA, double radiusB)
	:  _radiusA(radiusA), _radiusB(radiusB) {

}

string Ellipse::ToString() const {
	stringstream retVal;
	retVal << "{Ellipse " << Shape::ToString()
	       << ", a: " << _radiusA << ", b: " << _radiusB << "}";
	return retVal.str();
}

double Ellipse::Area() const {
	return PI * _radiusA * _radiusB;
}
/**
 * Calculates the Perimeter of the Ellipse.
 * Using: https://www.mathsisfun.com/geometry/ellipse-perimeter.html
 * This method will implement the third approximation (second by Ramanujan)
 * @return an approximate measure of the perimeter of the ellipse
 */
double Ellipse::Perimeter() const {
	double h = pow(_radiusA - _radiusB, 2.0) / pow(_radiusA + _radiusB, 2.0);
	return PI * (_radiusA + _radiusB) * (1 + ((3 * h) / (10 + sqrt(4 - 3 * h))));
}

double Ellipse::Eccentricity() const {
	return sqrt(pow(_radiusA, 2.0) - pow(_radiusB, 2.0)) / _radiusA;
}
