//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#ifndef SHAPES_EXAMPLE_1_TRIANGLE_H
#define SHAPES_EXAMPLE_1_TRIANGLE_H

#include "shape.h"

#include <string>
using std::string;

class Triangle : public Shape{
	double _a, _b, _c;
public:
	Triangle(double a, double b, double c);
	virtual string ToString()const;
	virtual double Area()const;
	virtual double Perimeter()const;
	virtual double Hypotenuse()const;
	virtual double AngleAB()const;
	virtual double AngleBC()const;
	virtual double AngleAC()const;
};


#endif //SHAPES_EXAMPLE_1_TRIANGLE_H
