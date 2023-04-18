//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#ifndef SHAPES_EXAMPLE_1_ELLIPSE_H
#define SHAPES_EXAMPLE_1_ELLIPSE_H

#include "shape.h"

#include <string>
using std::string;

class Ellipse : public Shape{
protected:
	double _radiusA, _radiusB; // length of the semi-major and semi-minor axis
public:
	Ellipse(double radiusA, double radiusB);
	virtual string ToString()const;
	virtual double Area()const;
	virtual double Perimeter()const;
	double Eccentricity()const;
};


#endif //SHAPES_EXAMPLE_1_ELLIPSE_H
