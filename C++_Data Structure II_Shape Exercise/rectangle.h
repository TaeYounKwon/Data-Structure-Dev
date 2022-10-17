//
// Created by Arias Arevalo, Carlos on 4/22/20.
//

#ifndef SHAPES_EXAMPLE_1_RECTANGLE_H
#define SHAPES_EXAMPLE_1_RECTANGLE_H

#include "shape.h"
#include <string>
using std::string;

class Rectangle : virtual public Shape{
	double _base, _height;
public:
	Rectangle(double base, double height);
	virtual string ToString()const;
	virtual double Area()const;
	virtual double Perimeter()const;
};


#endif //SHAPES_EXAMPLE_1_RECTANGLE_H
